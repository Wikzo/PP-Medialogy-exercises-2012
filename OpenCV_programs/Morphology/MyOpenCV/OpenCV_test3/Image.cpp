#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat Threshold(Mat image, int threshold);
Mat Erosion(Mat image);

int main()
{
    Mat im = imread("chrome.jpg", 0); // 0 is grayscale
	Mat threshold = Threshold(im, 180);
	imwrite("chrome_threshold.jpg", threshold);

	Mat erosion = Erosion(threshold);
	//erosion = Erosion(erosion);
	

    if (im.empty()) 
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }
	imshow("Original", im);
    imshow("Threshold", threshold);
	imshow("Erosion", erosion);
    waitKey(0);
}

Mat Threshold(Mat image, int threshold)
{
	Mat output = image.clone();

	for (int y = 0; y < output.rows; y++)
	{
		for (int x = 0; x < output.cols; x++)
		{
			if (output.at<uchar>(y, x) < threshold)
				output.at<uchar>(y, x) = 0;
			else
				output.at<uchar>(y, x) = 255;
		}
	}

	return output;
}

Mat Erosion(Mat image) // Fit
{
	Mat output = image.clone();

	// Go through all pixels
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			int counter = 0;
			// go through the kernel
			for (int j = y-1; j < (y+2); j++)
			{
				for (int h = x-1; h < (x+2); h++)
				{
					if (j > 0 && h > 0) // no negative values
					{
						if (j < image.rows && h < image.cols) // no outside of bounds values
							if (image.at<uchar>(j, h) == 255)
								counter++;
					}
				}
			}

			// Set pixels
			if (counter == 9)
				output.at<uchar>(y, x) = 255;
			else
				output.at<uchar>(y, x) = 0;
		}
	}


	return output;

}