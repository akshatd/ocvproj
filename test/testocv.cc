#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv ){
	double start = (double)getTickCount();

	Mat img = imread(argv[1], IMREAD_COLOR);
	Mat mod;

	Mat kernel = (Mat_<char>(3,3) << 0,-1,0,
					-1,5,-1,
					0,-1,0);

	filter2D(img, mod, img.depth(), kernel);

	double elapsed = ((double)getTickCount()-start)/getTickFrequency();
	cout << "Time taken " << elapsed << endl;
	namedWindow("Org Image", WINDOW_NORMAL);
	namedWindow("Modified Image", WINDOW_NORMAL);
	imshow("Org Image", img);
	imshow("Modified Image", mod);
	waitKey(0);

	return 0;
}
