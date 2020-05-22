#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat frame, bgMat, subMat, bny_subMat;
	//VideoCapture capVideo(0);
	int cnt = 0;
	

	while (1)
	{
		VideoCapture capVideo(0);
		Mat grayMat;
		capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt == 0)
		{
			frame.copyTo(bgMat);
		}
		else
		{
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);

			imshow("b_subMat", bny_subMat);
			imshow("subMat", subMat);
			imshow("frame", frame);
			waitKey(0);
		}
		cnt++;
	}
}