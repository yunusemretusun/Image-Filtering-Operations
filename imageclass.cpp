#include "imageclass.h"
#include "imagefilteroperations.h"

imageClass::imageClass()
{
}

void imageClass::setImage(Mat selectedImage){
    if(!selectedImage.empty())
        this->selectedImage=selectedImage;
        imageFilterOperations::setImage(selectedImage);
        imageBasicOperations::setImage(selectedImage);
}
Mat imageClass::getImage(){
    return this->selectedImage;
}


