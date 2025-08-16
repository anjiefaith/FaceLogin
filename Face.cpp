// #include<opencv2/imgcodecs.hpp> //handles reading and writing images to disk, so loads and saves images
#include<opencv2/highgui.hpp> //provides functions for GUI, displays images in windows, etc
#include<opencv2/imgproc.hpp>//Image processing, like convert to greyscal, edge detection, bluring
#include<opencv2/objdetect.hpp> //Object detection function
#include<iostream>

using namespace std;
using namespace cv;

void main(){
    string path="WIN_20241218_23_32_18_Pro.jpg";
    Mat image = imread(path); //Mat is for matrix, stores pixel data, imread is function that reads an image file
    imshow("Window", image); //synatx imshow(window_name, Mat_image)
    waitKey(0);

}