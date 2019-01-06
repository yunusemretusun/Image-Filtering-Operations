#ifndef IMAGECLASS_H
#define IMAGECLASS_H
#include <QWidget>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

#include "imagefilteroperations.h"
#include "imagebasicoperations.h"

using namespace cv;
using namespace std;

class imageClass:public imageFilterOperations,public imageBasicOperations
{
protected:
     Mat selectedImage;

public:
   //getter and setter methods
   void setImage(Mat selectedImage);

   Mat getImage();
   imageClass();

};

#endif // IMAGECLASS_H
