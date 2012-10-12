#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

enum SobelDirection
{
	Diagonal_Right,
	Diagonal_Left,
	Vertical,
	Horizontal
};

const int THRESHOLD_GRAYSCALE = 133; // optimal value was found using ImageJ
const int THRESHOLD_SOBEL = 30; // found by experimenting

Mat ConvertColorImageToBlackWhite(Mat colorImage);
Mat MeanFilter(Mat input);
Mat ThresholdBlackWhiteImage(Mat blackWhiteImage, int threshold);
Mat SobelEdgeDetecting(Mat input, enum SobelDirection direction, bool useMeanFilterBeforeDoingEdgeDetecting, int threshold);
Mat AddTwoMatsTogether(Mat matA, Mat matB);
void SortValues(uchar* a, int size);

// max
void erosion(Mat input, int radius, Mat &output);
void dilation(Mat input, int radius, Mat &output);



int main()
{
	cout << "Edge detection using the Sobel kernel (and OpenCV to load images)" << endl;
	cout << "By Gustav Dahl - Medialogy 3rd semester 2012 - Aalborg University\n\n";
	// Load the image
    Mat colorImage = imread("dog.jpg");
    if (colorImage.empty()) 
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }

	cout << "Processing image. Please wait..." << endl;

	// Convert to black-white
	Mat gray = ConvertColorImageToBlackWhite(colorImage);

	// Threshold
	Mat threshold = ThresholdBlackWhiteImage(gray, THRESHOLD_GRAYSCALE);

	// Erode
	Mat myErosion = threshold.clone();
	Mat myDilation = threshold.clone();
	
	erosion(threshold, 1, myErosion);
	dilation(threshold, 1, myDilation);

	imshow("Original", gray);
	imshow("Erosion", myErosion);
	imshow("Dilation", myDilation);

    waitKey(0);
}

Mat ConvertColorImageToBlackWhite(Mat colorImage)
{
	// Mat(rows, columns, type)
	// rows = y = 300
	// cols = x = 600

	Mat grayScaleImage(colorImage.rows, colorImage.cols, CV_8UC1); // new image with only 1 channel

	// Formula for converting from color to grayscale (3.3, p. 30 in Introduction to Video and Image Processing book)
	// I = weightR * R + weightG * G + weightB * B

	// Common weight values used in TV production to calculate to grayscale
	float RedWeight = 0.299;
	float GreenWeight = 0.587;
	float BlueWeight = 0.114;
	

	// Iterate through all the pixels and apply the formula for grayscale
	for (int y = 0; y < colorImage.rows; y++) // rows
	{
		for (int x = 0; x < colorImage.cols; x++)
		{
			// Calculate grayscale value
			int grayValue = colorImage.at<cv::Vec3b>(y, x)[0] * BlueWeight
				+ colorImage.at<cv::Vec3b>(y, x)[1] * GreenWeight
				+ colorImage.at<cv::Vec3b>(y, x)[2] * RedWeight;

			// Apply the grayscale value (0-255)
			grayScaleImage.at<uchar>(y, x) = grayValue;		

		}
	}	
	return grayScaleImage;
}

Mat ThresholdBlackWhiteImage(Mat blackWhiteImage, int threshold)
{
	Mat image = blackWhiteImage.clone();

	// Loop through all pixels and set them to either 255 (white) or 0 (black) using the threhold value
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			if (image.at<uchar>(y, x) >= threshold)
				image.at<uchar>(y, x) = 255;
			else
				image.at<uchar>(y, x) = 0;
		}
	}

	return image;
}

// needs a BW thresholded image!
void erosion(Mat input, int radius, Mat &output)
{
	for(int x = radius; x < input.cols-radius; x++)
	{
		for(int y = radius; y < input.rows-radius; y++)
		{
			bool pixelIsaccepted = true;
			for(int filterX = x - radius; pixelIsaccepted && filterX <= x + radius; filterX++)
			{
				for(int filterY = y - radius; pixelIsaccepted && filterY <= y + radius; filterY++)
				{
					if (input.at<uchar>(filterY,filterX) == 0)
					{
						pixelIsaccepted = false;
					}
				}
			}
			if (pixelIsaccepted == true)
				output.at<uchar>(y,x) = 255;
			else
				output.at<uchar>(y,x) = 0;
		}
	}
}

// needs a BW thresholded image!
void dilation(Mat input, int radius, Mat &output)
{
	for(int x = radius; x < input.cols-radius; x++)
		{
			for(int y = radius; y < input.rows-radius; y++)
			{
				bool pixelIsaccepted = false;
				for(int filterX = x - radius; !pixelIsaccepted && filterX <= x + radius; filterX++)
				{
					for(int filterY = y - radius; !pixelIsaccepted && filterY <= y + radius; filterY++)
					{
						if (input.at<uchar>(filterY,filterX) == 255)
						{
							pixelIsaccepted = true;
						}
					}
				}
				if (pixelIsaccepted == true)
					output.at<uchar>(y,x) = 255;
				else
					output.at<uchar>(y,x) = 0;
			}
		}
}