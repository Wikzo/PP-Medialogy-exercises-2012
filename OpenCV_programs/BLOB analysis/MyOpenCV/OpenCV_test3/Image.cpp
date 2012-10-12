#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat ThresholdBlackWhiteImage(Mat blackWhiteImage, int threshold);
bool NextPixelAvailableAndNotBurned(Mat input, bool burned[][], int yDir, int xDir, int corY, int corX);
void GrassFire(Mat input, Mat &output, bool burned[][]);

int main()
{
    Mat original = imread("chrome.jpg", 0);
    if (original.empty()) 
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }
	original = ThresholdBlackWhiteImage(original, 180);
	Mat clone = original.clone();

	for (int y = 0; y < clone.rows; y++)
	{
		for (int x = 0; x < clone.cols; x++)
		{
			clone.at<uchar>(y, x) = 0;
		}
	}

	bool** pixelBurns = new bool*[clone.rows];
	for (int j = 0; j < clone.rows; j++)
		pixelBurns[j] = new bool[clone.cols];

	GrassFire(original, clone, pixelBurns);

	imshow("Clone", clone);
	imshow("Original", original);
    waitKey(0);
}

void GrassFire(Mat input, Mat &output, bool burned[][], int direction)
{
	// Loop through all pixels
	for (int y = 0; y < input.rows; y++)
	{
		for (int x = 0; x < input.cols; x++)
		{
			if (NextPixelAvailableAndNotBurned(input, burned, y, x, 0, 0) == true)
				burned[y][x] = true; // burn current
		}
	}
}

void BurnLeft(Mat input, bool burned[][], int y, int x, int direction)
{
	// Go left
	if (NextPixelAvailableAndNotBurned(input, burned, y, x, 0, direction) == true)
	{
		// burn this
		burned[y][x+1] == true;

		// call next left
		BurnLeft(input, burned, y, x);
	}
	else
		return;
}

bool NextPixelAvailableAndNotBurned(Mat input, bool burned[][], int yDir, int xDir, int corY, int corX)
{
	if (input.at<uchar>(corY + yDir, corX + xDir) == 255)
	{
		if (burned[corY + yDir][corX + xDir] == false)
			return true;
		else
			return false;
	}
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