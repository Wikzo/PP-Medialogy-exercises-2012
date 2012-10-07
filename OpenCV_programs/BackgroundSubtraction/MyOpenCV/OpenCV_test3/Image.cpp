#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat BackgroundSubtraction(Mat background, Mat current, int threshold);
Mat ConvertColorImageToBlackWhite(Mat colorImage);

int boolHasCapturedFirstFrame = false;

int main()
{
	Mat colorImage;
	Mat gray;

	// Background subtraction
	Mat backgroundImage;
	Mat currentImage;
	Mat object; // the object to track

	VideoCapture capture;

	capture.open(0);

	// Initial frame
	while (backgroundImage.empty())
	{
	
		capture >> backgroundImage;
		cv::imshow("Background", backgroundImage);
		waitKey(100);
		//capture.release(); // dont

	}


	imwrite("background.jpg", backgroundImage);
	Mat localBackgroundImage = imread("background.jpg");

	// Tracking the object
	while (true)
	{
		capture >> currentImage;
		
		if ((char)waitKey(10) == 'q')
			break;

		object = BackgroundSubtraction(localBackgroundImage, currentImage, 50);
		cv::imshow("Current frame", currentImage);
		cv::imshow("Object", object);
	}
}

Mat ConvertColorImageToBlackWhite(Mat colorImage)
{
	// Mat(rows, columns, type)
	// rows = y = 300
	// cols = x = 600
	Mat grayScaleImage(colorImage.rows, colorImage.cols, CV_8UC1);

	// Check color image size and channels
	//cout << "colorImage rows: " << colorImage.rows << "; colorImage cols: " << colorImage.cols << endl;
	//cout << "colorImage channels: " << colorImage.channels() << endl;

	// Check grayscale image size and channels
	//cout << "\ngrayScaleImage rows: " << grayScaleImage.rows << "; grayScaleImage cols: " << grayScaleImage.cols << endl;
	//cout << "grayScaleImage channels: " << grayScaleImage.channels() << endl;

	// Formula for converting from color to grayscale (3.3, p. 30 in Introduction to Video and Image Processing book)
	// I = weightR * R + weightG * G + weightB * B

	// Common weight values used in TV production to calculate to grayscale
	float RedWeight = 0.299;
	float GreenWeight = 0.587;
	float BlueWeight = 0.114;
	
	//int yTemp = 199; // 299 = max
	//int xTemp = 299; // 599 = max
	//cout << endl << endl;
	//Vec3b val = colorImage.at<Vec3b>(yTemp, xTemp)[2];
	//cout << "val at [" << yTemp << ", " << xTemp << "]: " << (int)val(0) << endl;
	//rectangle(colorImage, Point(xTemp, yTemp), Point(xTemp+10, yTemp+10), CV_RGB(255, 0, 0), 3);


	//Iterate through all the pixels and apply the formula for grayscale
	for (int y = 0; y < colorImage.rows; y++) // rows
	{
		for (int x = 0; x < colorImage.cols; x++) // < ------------------------------ CANNOT BE BIGGER THAN 200!?!?
		{
			// Calculate grayscale value
			int grayValue = colorImage.at<cv::Vec3b>(y, x)[0] * BlueWeight
				+ colorImage.at<cv::Vec3b>(y, x)[1] * GreenWeight
				+ colorImage.at<cv::Vec3b>(y, x)[2] * RedWeight;

			// Print values
			//cout << "\n\n-------------\nx: " << x << " and y: " << y << endl;
			//cout << "grayValue: " << grayValue << endl;
			grayScaleImage.at<uchar>(y, x) = grayValue;

			//Vec3b val = grayScaleImage.at<Vec3b>(y, x);
			//cout << "Actual val: " << (int)val(0) << endl; // <------------- WORKS!!			

		}
	}	
	return grayScaleImage;
}

Mat BackgroundSubtraction(Mat background, Mat current, int threshold)
{
	// rows = y
	// cols = x
	
	// Make black-white
	//Mat background_bw = ConvertColorImageToBlackWhite(background);
	//Mat current_bw = ConvertColorImageToBlackWhite(current);
	//Mat object_bw = ConvertColorImageToBlackWhite(background);

	Mat background_bw = ConvertColorImageToBlackWhite(background);
	Mat current_bw = ConvertColorImageToBlackWhite(current);
	
	/*Mat background_bw, current_bw;
	cvtColor(background, background_bw, CV_RGB2GRAY);
	cvtColor(current, current_bw, CV_RGB2GRAY);*/

	Mat newObject(background_bw.rows, background_bw.cols, CV_8UC1);

	for (int y = 0; y < newObject.rows; y++)
	{
		for (int x = 0; x < newObject.cols; x++)
		{
			//newObject.at<Vec3b>(y, x)[0] = background.at<Vec3b>(y, x)[0] - current.at<Vec3b>(y, x)[0];
			//newObject.at<Vec3b>(y, x)[1] = background.at<Vec3b>(y, x)[1] - current.at<Vec3b>(y, x)[1];
			//newObject.at<Vec3b>(y, x)[2] = background.at<Vec3b>(y, x)[2] - current.at<Vec3b>(y, x)[2];

			//double difference = background_bw.at<uchar>(y, x) - current_bw.at<uchar>(y, x);
			//newObject.at<uchar>(y, x) = difference;

			int difference = background_bw.at<uchar>(y, x) - current_bw.at<uchar>(y, x);
			if (difference < 0)
				difference *= -1;

			if (difference <= threshold)
				difference = 0;
			else
				difference = 255;
			
			newObject.at<uchar>(y, x) = difference;

			//newObject.at<uchar>(y, x) = 255;
		}
	}

	return newObject;
}