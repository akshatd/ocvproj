#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <dirent.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv ){
	string img_dir;
	if(argc < 2){
		cout << "Enter a path with images in it!" << endl;
		return -1;

	}else{
		img_dir = argv[1] ;
		cout << img_dir <<endl;
	}

	set<string> images_displayed;
	DIR *d;
	struct dirent *dir;
	Mat img;
	namedWindow("Current Frame", WINDOW_NORMAL);
	while(1){
		d = opendir(img_dir.c_str());
		while((dir = readdir(d)) != NULL){
			char *dot = strrchr(dir->d_name, '.');
			if ((dot && !strcmp(dot, ".jpg")) || (dot && !strcmp(dot, ".png"))){
				string img_path = img_dir +"/" + dir->d_name;
				if(images_displayed.insert(img_path).second){
					cout << dir->d_name << endl;
					img = imread(img_path, CV_LOAD_IMAGE_COLOR);
					imshow("Current Frame", img);
					waitKey(17);
				}
			}
		}
		closedir(d);
	}
	return 0;
}
