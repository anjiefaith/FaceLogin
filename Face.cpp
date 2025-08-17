// #include<opencv2/imgcodecs.hpp> //handles reading and writing images to disk, so loads and saves images
#include<opencv2/highgui.hpp> //provides functions for GUI, displays images in windows, etc
#include<opencv2/imgproc.hpp>//Image processing, like convert to greyscal, edge detection, bluring
#include<opencv2/objdetect.hpp> //Object detection function
#include<iostream>

using namespace std;
using namespace cv;

// void main(){

    
//     string path="WIN_20241218_23_32_18_Pro.jpg";
//     Mat image = imread(path); //Mat is for matrix, stores pixel data, imread is function that reads an image file
//     imshow("Window", image); //synatx imshow(window_name, Mat_image)
//     waitKey(0);



// }

void main() {
    VideoCapture video(0); //OpenCV class used to capture video
    CascadeClassifier detecter; //created objected called detecter, object detection model that uses haar cascade algorithm, can detect face, eyes, cars
    Mat image;
    detecter.load("C:/Users/anjol/OneDrive/Desktop/opencv/opencv/sources/data/haarcascades_cuda/haarcascade_frontalface_default.xml"); //loads trained data for face detection from file
    
   
    
    while (true)
    {   
        video.read(image);//capture the next frame from the video and stores it in the matrix image
        
        vector<Rect> faces; //container to hold resultes, x,y, width, height
        detecter.detectMultiScale(image, faces, 1.3, 5);

        for(int i=0; i<faces.size(); i++){
            rectangle(image, faces[i], Scalar(50, 50, 255), 3);//Draws a rectangle for each detected face onto the same image. face is the boundry
            rectangle(image, Point(0,0), Point(250,70), Scalar(50, 50, 255), FILLED);
            putText(image, "Faces Detected: " + to_string(faces.size()), Point(10,40), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(255,255));
        }

        imshow("Window", image);
        waitKey(1);// waits so window can rfresh so it's increment is one 1millisecond
        
    }
    

     

    

}
