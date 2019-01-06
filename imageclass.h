#ifndef IMAGECLASS_H
#define IMAGECLASS_H
#include <QWidget>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include "imagefilteroperations.h"

using namespace cv;
using namespace std;

class imageClass:public imageFilterOperations
{
protected:
     Mat selectedImage;
     int labelWidth=237;
     int labelHeight=539;
public:
   //getter and setter methods
   void setImage(Mat selectedImage);
   void setLabelSize(int labelWidth,int labelHeight);
   int getWidthLabel();
   int getHeightLabel();
   Mat getImage();
   //----------------------


   //operations
   imageClass();
   QPixmap convertToPixmap(Mat filteredImage);
   //----------------------
};

#endif // IMAGECLASS_H
