#include "imagefilteroperations.h"

using namespace cv;
using namespace std;

imageFilterOperations::imageFilterOperations()
{

}

void imageFilterOperations::setElement(int element){
    this->element=element;
}

void imageFilterOperations::setKernelSize(int kernel_size){
    this->kernel_size=kernel_size;
}

int imageFilterOperations::getKernelSize(){
    return kernel_size;
}

int imageFilterOperations::getElement(){

    return element;
}

Mat imageFilterOperations::getImage(){
    return this->selectedImage;
}
void imageFilterOperations::setImage(Mat selectedImage){
    this->selectedImage=selectedImage;

}
Mat imageFilterOperations::blurFilter(){

    for(int i = 1; i <getKernelSize()+2; i = i + 2){
         blur(selectedImage, resultImage, Size( i, i ),Point(-1,-1));
    }

    cvtColor(resultImage, resultImage, COLOR_BGR2RGB);
    return resultImage;
}

Mat imageFilterOperations::gaussianFilter(){
    for ( int i = 1; i <getKernelSize()+2; i = i + 2 ){
        GaussianBlur( selectedImage, resultImage, Size( i, i ), 0, 0 );
    }
     cvtColor(resultImage, resultImage, COLOR_BGR2RGB);
     return resultImage;
}

Mat imageFilterOperations::sobelFilter(){
    Mat grayImage,grad_x,grad_y,abs_grad_x,abs_grad_y;

    int scale=1;
    int delta=0;
    int ddepth=CV_16S;

    GaussianBlur(selectedImage,selectedImage,Size(3,3),0,0,BORDER_DEFAULT);
    cvtColor(selectedImage,grayImage,COLOR_BGR2GRAY);

    Sobel(grayImage,grad_x,ddepth,1,0,3,scale,delta,BORDER_DEFAULT);
    Sobel( grayImage, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );

    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );

    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, resultImage );
    cvtColor(resultImage, resultImage, COLOR_BGR2RGB);
    return resultImage;

}

Mat imageFilterOperations::laplacianFilter(){
    int kernel = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    Mat grayImage;

    /// Remove noise by blurring with a Gaussian filter
     GaussianBlur( selectedImage, selectedImage, Size(3,3), 0, 0, BORDER_DEFAULT );

     /// Convert the image to grayscale
     cvtColor( selectedImage, grayImage, COLOR_BGR2GRAY );
     Laplacian( grayImage, resultImage, ddepth, kernel, scale, delta, BORDER_DEFAULT );
     convertScaleAbs( resultImage, resultImage );
     cvtColor(resultImage, resultImage, COLOR_BGR2RGB);
     return resultImage;
}

Mat imageFilterOperations::dilationFilter(){
    int dilation_type;

    if(getElement()== 0)
        dilation_type = MORPH_RECT;
    else if(getElement()== 1)
        dilation_type = MORPH_CROSS;
    else if(getElement()== 2)
        dilation_type = MORPH_ELLIPSE;

    Mat structuringElement = getStructuringElement( dilation_type,
                                         Size( 2*getKernelSize() + 1, 2*getKernelSize()+1 ),
                                         Point( getKernelSize(), getKernelSize() ) );

    dilate(selectedImage,resultImage,structuringElement);
    cvtColor(resultImage, resultImage, COLOR_BGR2RGB);
    return resultImage;
}

Mat imageFilterOperations::erosionFilter(){

    int  erosion_type;

      if(getElement()== 0)
          erosion_type = MORPH_RECT;
      else if(getElement()== 1)
          erosion_type = MORPH_CROSS;
      else if(getElement()== 2)
          erosion_type = MORPH_ELLIPSE;

    Mat structuringElement = getStructuringElement( erosion_type,Size( 2*getKernelSize() + 1, 2*getKernelSize()+1 ),Point(getKernelSize(), getKernelSize() ));

    erode( selectedImage, resultImage, structuringElement );
    cvtColor(resultImage, resultImage, COLOR_BGR2RGB);
    return resultImage;
}
