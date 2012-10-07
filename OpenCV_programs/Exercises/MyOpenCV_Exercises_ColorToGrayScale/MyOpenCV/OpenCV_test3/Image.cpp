#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main()
{
	Mat image;
	image = imread("c:/chrome.jpg", CV_LOAD_IMAGE_COLOR); // Read the image

	if (! image.data || image.empty()) // Check for valid image
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	Mat gray_image;
	cvtColor(image, gray_image, CV_RGB2GRAY); // Convert from color to grayscale

	imwrite("gray_crome.jpg", gray_image);

	// Show color picture
	namedWindow("RGB window", CV_WINDOW_AUTOSIZE);
	imshow("RGB window", image);

	// Show grayscale picture
	namedWindow("Grayscale window", CV_WINDOW_AUTOSIZE);
	imshow("Grayscale window", gray_image);

	waitKey(0);
	return 0;
}