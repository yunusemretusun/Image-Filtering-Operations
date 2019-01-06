#ifndef IMAGEFILTEROPERATIONS_H
#define IMAGEFILTEROPERATIONS_H

#include <iostream>
#include <opencv4/opencv2/opencv.hpp>


using namespace cv;
using namespace std;

class imageFilterOperations{
private:

  int element=0;
  int kernel_size=0;

protected:
  Mat selectedImage;
  Mat resultImage;

public:
    //getter and setter methods
    void setElement(int element);
    void setKernelSize(int kernel_size);
    int getElement();
    int getKernelSize();
    Mat getImage();
    void setImage(Mat selectedImage);
    //----------------------------------

    //operations
    imageFilterOperations();
    Mat blurFilter();
    Mat gaussianFilter();
    Mat sobelFilter();
    Mat laplacianFilter();
    Mat erosionFilter();
    Mat dilationFilter();
    //---------------------------------

};

#endif // IMAGEFILTEROPERATIONS_H
