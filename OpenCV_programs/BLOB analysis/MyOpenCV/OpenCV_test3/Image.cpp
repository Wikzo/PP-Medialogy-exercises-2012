#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void StartRecursion(Mat input, Mat output, int tryNum, int objectNum, int y, int x);

int main()
{
    Mat original = imread("chrome.jpg", 0);
    if (original.empty()) 
    {
        cout << "Cannot load image!" << endl;
        return -1;
    }
	Mat clone = original.clone();

	for (int y = 0; y < clone.rows; y++)
	{
		for (int x = 0; x < clone.cols; x++)
		{
			clone.at<uchar>(y, x) = 0;
		}
	}

	StartRecursion(original, clone, 1, 1, 1, 1);
	imshow("Clone", clone);
	imshow("Original", original);
    waitKey(0);
}

void StartRecursion(Mat input, Mat output, int tryNum, int objectNum, int y, int x)
{
	if (tryNum == 0)
	{
		// burn this
		cout << "done" << endl;
		// return
		return;
	}
	else
	{
		if (input.at<uchar>(y, x+1) == 1) // Go left 1
		{
			StartRecursion(input, output, 1, objectNum, y, x+1);
			// Burn this
			output.at<uchar>(y, x) = 255;
		}
		else if (input.at<uchar>(y+1, x) == 1) // Go down 2
		{
			StartRecursion(input, output, 2, objectNum, y+1, x);
			// Burn this
			output.at<uchar>(y, x) = 255;
		}
		else if (input.at<uchar>(y, x-1) == 1) // Go Left 3
		{
			StartRecursion(input, output, 3, objectNum, y, x-1);
			// Burn this
			output.at<uchar>(y, x) = 255;
		}
		else if (input.at<uchar>(y-1, x) == 1) // Go Up 4
		{
			StartRecursion(input, output, 4, objectNum, y-1, x);
			// Burn this
			output.at<uchar>(y, x) = 255;
		}
		else // Has reached end
		{
			objectNum++;
			StartRecursion(input, output, 0, objectNum, y, x);
		}
	}
}