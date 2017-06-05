#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv ){
	double start = (double)getTickCount();
	double alpha = 1.0;
	int beta = 0;
	Mat img = imread(argv[1], IMREAD_COLOR);
	Mat out;
	cout << "Brightness: " ;
	cin >> beta;
	cout << "Contrast: " ;
	cin >> alpha;
	img.convertTo(out, -1, alpha, beta);
	double elapsed = ((double)getTickCount()-start)/getTickFrequency();
	cout << "Time taken " << elapsed << endl;
	namedWindow("Org Image", WINDOW_NORMAL);
	namedWindow("Modified Image", WINDOW_NORMAL);
	imshow("Org Image", img);
	imshow("Modified Image", out);
	waitKey(0);

	return 0;
}
