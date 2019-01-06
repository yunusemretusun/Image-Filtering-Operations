#include "imagebasicoperations.h"

imageBasicOperations::imageBasicOperations()
{

}

void imageBasicOperations::setImage(Mat selectedImage){
    this->selectedImage=selectedImage;
}
void imageBasicOperations::setLabelSize(int labelWidth, int labelHeight){
    if(labelHeight >0 && labelWidth >0){
        this->labelWidth=labelWidth;
        this->labelHeight=labelHeight;
    }
    else{
        this->labelHeight=539;
        this->labelWidth=237;
    }
}
int imageBasicOperations::getWidthLabel(){
    return this->labelWidth;
}
int imageBasicOperations::getHeightLabel(){
    return this->labelHeight;
}
QPixmap imageBasicOperations::convertToPixmap(Mat filteredImage){
    cvtColor(filteredImage, filteredImage, COLOR_BGR2RGB);
    return QPixmap::fromImage(QImage(filteredImage.data, filteredImage.cols, filteredImage.rows,filteredImage.step1(), QImage::Format_RGB888).scaled (labelWidth,labelHeight,Qt::KeepAspectRatio));
}
