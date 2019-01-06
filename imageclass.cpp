#include "imageclass.h"
#include "imagefilteroperations.h"

imageClass::imageClass()
{
}

void imageClass::setImage(Mat selectedImage){
    if(!selectedImage.empty())
        this->selectedImage=selectedImage;
        imageFilterOperations::setImage(selectedImage);
}
void imageClass::setLabelSize(int labelWidth, int labelHeight){
    if(labelHeight >0 && labelWidth >0){
        this->labelWidth=labelWidth;
        this->labelHeight=labelHeight;
    }
    else{
        this->labelHeight=539;
        this->labelWidth=237;
    }
}
int imageClass::getWidthLabel(){
    return this->labelWidth;
}
int imageClass::getHeightLabel(){
    return this->labelHeight;
}
Mat imageClass::getImage(){
    return this->selectedImage;
}
QPixmap imageClass::convertToPixmap(Mat filteredImage){
    cvtColor(filteredImage, filteredImage, COLOR_BGR2RGB);
    return QPixmap::fromImage(QImage(filteredImage.data, filteredImage.cols, filteredImage.rows,filteredImage.step1(), QImage::Format_RGB888).scaled (labelWidth,labelHeight,Qt::KeepAspectRatio));
}

