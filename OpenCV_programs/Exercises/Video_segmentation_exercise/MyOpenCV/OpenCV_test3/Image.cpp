#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

void ImageDiff_simple();
void ImageDiff_video();

int main(int argc, char** argv)
{
	VideoCapture capture;

	if (argc == 2)
		capture.open(argv[1]);
	else
		capture.open("matlab_vid20c.avi");

	if (!capture.isOpened())
	{
		cout << "Cannot open!";
		return -1;
	}

	Mat frame, gray_frame, foreground, background;
	namedWindow("video", CV_WINDOW_AUTOSIZE);
	namedWindow("grayVideo", CV_WINDOW_AUTOSIZE);
	namedWindow("background", CV_WINDOW_AUTOSIZE);
	namedWindow("foreground", CV_WINDOW_AUTOSIZE);

	while (true)
	{
		capture >> frame;

		if (frame.empty())
			break;

		imshow("video", frame);

		// Convert to grayscale
		cvtColor(frame, gray_frame, CV_BGR2GRAY);
		imshow("gray_video", gray_frame);

		// Background image
		if (background.empty())
			background = gray_frame.clone();
		imshow("background", background);

		// Subtract input from background
		absdiff(background, gray_frame, foreground);

		// Threshold
		threshold(foreground, foreground, 70, 255, THRESH_BINARY);
		imshow("foreground", foreground);

		if ((char)waitKey(0) == 'q')
		{
			break;
		}
	}
	return 0;
}


void ImageDiff_simple()
{
	Mat src_img;
	Mat src2_img;
	Mat diff_img;
	src_img = imread("bin.png", 1);
	src2_img = imread("bin_v2.png", 1);

	cv::absdiff(src_img, src2_img, diff_img);

    imshow("Src1", src_img);
	imshow("Src2", src2_img);
	imshow("Diff", diff_img);
}

void ImageDiff_video()
{
	VideoCapture capture;

	capture.open("matlab_vid20c.avi");

	if (!capture.isOpened())
	{
		cout << "Cannot open!";
		return;
	}

	Mat frame, gray_frame, foreground, background;

	while (true)
	{
		capture >> frame;

		if (frame.empty())
			break;

		imshow("video", frame);

		// Convert to grayscale
		cvtColor(frame, gray_frame, CV_BGR2GRAY);
		imshow("gray_video", gray_frame);

		// Background image
		if (background.empty())
			background = gray_frame.clone();
		imshow("background", background);

		// Subtract input from background
		absdiff(background, gray_frame, foreground);

		// Threshold
		threshold(foreground, foreground, 70, 255, THRESH_BINARY);
		imshow("foreground", foreground);

		if ((char)waitKey(0) == 'q')
			break;
	}
}