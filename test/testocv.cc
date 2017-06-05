#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv ){
	double start = (double)getTickCount();

	Mat img = imread(argv[1], IMREAD_COLOR);
	Mat img2 = imread(argv[2], IMREAD_COLOR);
	Mat out;
	addWeighted(img, 0.5, img2, 0.5, 0.0, out);
	double elapsed = ((double)getTickCount()-start)/getTickFrequency();
	cout << "Time taken " << elapsed << endl;
	namedWindow("Org Image", WINDOW_NORMAL);
	namedWindow("Modified Image", WINDOW_NORMAL);
	imshow("Org Image", img);
	imshow("Modified Image", out);
	waitKey(0);

	return 0;
}
