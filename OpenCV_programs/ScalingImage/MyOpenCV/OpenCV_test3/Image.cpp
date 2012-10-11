#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// P. 147 - Introduction to Video and Image Processing


Mat ScaleImage(float scaleX, float scaleY, Mat image);

int main()
{
    Mat im = imread("chrome.jpg");

	if (im.empty()) 
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }

	Mat scaleImage = ScaleImage(3, 3, im);
	imwrite("chrome_resized.jpg", scaleImage);

    imshow("Image", im);
	imshow("Scale", scaleImage);
    waitKey(0);
}

Mat ScaleImage(float scaleX, float scaleY, Mat image)
{
	// Mat(rows, columns, type)
	// rows = y
	// cols = x

	int output_height = image.rows * scaleY;
	int output_width = image.cols * scaleX;

	Mat output(output_height, output_width, CV_8UC3);

	for (int y = 0; y < output_height; y++)
	{
		for (int x = 0; x < output_width; x++)
		{
			float inputY = y/scaleY;
			float inputX = x/scaleX;

			output.at<Vec3b>(y, x) = image.at<Vec3b>(inputY, inputX);
		}
	}

	return output;
}