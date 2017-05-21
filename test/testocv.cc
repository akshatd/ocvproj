#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv ){
	double start = (double)getTickCount();

	int scaleFactor = 0;
	stringstream s;
	s << argv[2];
	s >> scaleFactor;
	
	if(!s || !scaleFactor){
		cout<< "wtf are you typing"<<endl;
		return -1;
	}

	Mat img = imread(argv[1], IMREAD_COLOR);

	Mat lutable(1,256, CV_8U);
	uchar *ptr = lutable.ptr();
	for(int i=0; i<256; ++i){
		ptr[i] = (uchar)(scaleFactor * (i/scaleFactor));
	}

	Mat compressed;
	LUT(img, lutable, compressed);
	start = ((double)getTickCount() - start)/getTickFrequency();
	cout << "Times passed in seconds: " << start << endl;

	namedWindow("Org Image", WINDOW_NORMAL);
	namedWindow("Compressed Image", WINDOW_NORMAL);
	imshow("Org Image", img);
	imshow("Compressed Image", compressed);
	waitKey(0);

	/*
	image = imread( argv[1], IMREAD_COLOR );
	if( !image.data ){
		printf("No image data\n");
		return -1;
	}
	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);
	imwrite("./hel.jpg", gray_image);
	//cout << "original: " << image << endl << endl;
	//cout << "gray: " << gray_image << endl << endl;
	namedWindow("Org Image", WINDOW_NORMAL);
	namedWindow("Gray Image", WINDOW_NORMAL);
	imshow("Org Image", image);
	imshow("Gray Image", gray_image);
	waitKey(0);
	*/
	return 0;
}
