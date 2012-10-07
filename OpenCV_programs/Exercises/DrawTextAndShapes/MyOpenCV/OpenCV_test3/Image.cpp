#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat src_img;
	src_img = imread(argc >= 2 ? argv[1] : "chrome.jpg", 1); // 1 = color

	if(!src_img.data || src_img.empty())
		cerr << "Problem loading image" << endl;
	
	Mat newImage = src_img.clone();

	for (int y = 1; y < newImage.rows-1; y++)
	{
		for (int x = 0; x < newImage.cols; x++)
		{
			float temp = newImage.at<cv::Vec3b>(y, x)[0] * 0.114 + newImage.at<cv::Vec3b>(y, x)[1] * 0.587 + newImage.at<cv::Vec3b>(y, x)[2] * 0.299;

			newImage.at<cv::Vec3b>(y, x)[0] = temp;
			newImage.at<cv::Vec3b>(y, x)[1] = temp;
			newImage.at<cv::Vec3b>(y, x)[2] = temp;
		}
	}

	// new image TEST
	int width = 700;
	int height = 500;
	//Mat newImage(height, width, CV_8UC3);
	/*for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			newImage.at<cv::Vec3b>(y, x)[0] = 20; // 0 = blue
			newImage.at<cv::Vec3b>(y, x)[1] = 255; // 1 = green
			newImage.at<cv::Vec3b>(y, x)[2] = 50; // 2 = red
		}
	}*/

	
	
	namedWindow("Test", CV_WINDOW_AUTOSIZE);
	imshow("Test", newImage);

	
	//namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	//imshow("Original image", src_img);

	rectangle(src_img, Point(100, 100), Point(800, 600), CV_RGB(255, 0, 0), 3);
	rectangle(src_img, Point(15, 50), Point(400, 700), CV_RGB(55, 255, 0), 3);

	line(src_img, Point(100, 200), Point(400, 400), CV_RGB(0, 255, 255), 3);
	circle(src_img, Point(100, 200), 60, CV_RGB(0, 30, 255), 3);
	circle(src_img, Point(0, 200), 60, CV_RGB(255, 30, 0), 3);
	putText(src_img, "Chrome is a browser :D", Point(10, 30), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255), 4, 8, false);

	namedWindow("Output image", CV_WINDOW_AUTOSIZE);
	imshow("Output image", src_img);

	//hey comment

	waitKey(0);

	return 0;

}