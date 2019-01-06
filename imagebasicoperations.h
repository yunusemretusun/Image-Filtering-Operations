#ifndef IMAGEBASICOPERATIONS_H
#define IMAGEBASICOPERATIONS_H

#include <QWidget>
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class imageBasicOperations
{
private:
    Mat selectedImage;
    int labelWidth=237;
    int labelHeight=539;

public:
    imageBasicOperations();
    void setImage(Mat selectedImage);
    void setLabelSize(int labelWidth,int labelHeight);
    int getWidthLabel();
    int getHeightLabel();

    QPixmap convertToPixmap(Mat filteredImage);
    //resim döndürme,kırpma ve kontrast ayarı gibi işlemler bu sınıfta yapılabilir.
};

#endif // IMAGEBASICOPERATIONS_H
