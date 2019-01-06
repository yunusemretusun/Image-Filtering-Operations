#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv4/opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "imagefilteroperations.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTheViewOfTheComponent(false,""); //make component invisible
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTheViewOfTheComponent(bool status,string filtreIsmi){

    ui->makeBlur->setVisible(status);
    ui->makeDilation->setVisible(status);
    ui->makeErosion->setVisible(status);
    ui->makeGaussianBlur->setVisible(status);
    ui->makeSobel->setVisible(status);
    ui->makeLaplacian->setVisible(status);
    ui->labelFilters->setVisible(status);
    ui->ayarlar->setVisible(false);

    if(filtreIsmi=="blur" ||filtreIsmi=="gaussianBlur"){
        ui->ayarlar->setVisible(true);
        ui->elementName->setVisible(false);
        ui->elementValue->setVisible(false);
    }
    else if(filtreIsmi=="sobel" ||filtreIsmi=="laplacian"){
        ui->ayarlar->setVisible(false);
    }
    else if(filtreIsmi=="dilation" ||filtreIsmi=="erosion"){
        ui->ayarlar->setVisible(true);
        ui->elementName->setVisible(true);
        ui->elementValue->setVisible(true);
    }

}
void MainWindow::on_selectPic_clicked()
{
      //code for browse picture
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Resim (*.png *.xpm *.jpg *.jpeg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,tr("Resim Seçiniz"), "/home", tr("Resim Uzantısı (*.png *.jpg *.bmp *.jpeg)"));

    if (!fileName.isEmpty())
     {

         string path=(fileName.toUtf8().constData());
         imageOperations.setImage(cv::imread(path));   //set image to filter
         ui->labelPicture->setPixmap(imageOperations.convertToPixmap(imageOperations.getImage()));
         setTheViewOfTheComponent(true,""); //Make push button visible
      }
}
void MainWindow::on_makeBlur_clicked()
{
    setTheViewOfTheComponent(true,"blur");
    Mat blurFilteredImage=imageOperations.blurFilter();
    ui->labelResult->setPixmap(imageOperations.convertToPixmap(blurFilteredImage));
    ui->labelFiltrelenmis->setText(QString( " Blur Filtresi"));
}
void MainWindow::on_makeGaussianBlur_clicked()
{
    setTheViewOfTheComponent(true,"gaussianBlur");
    Mat gaussianBlurFiltered=imageOperations.gaussianFilter();
    ui->labelResult->setPixmap(imageOperations.convertToPixmap(gaussianBlurFiltered));
    ui->labelFiltrelenmis->setText(QString( " GaussianBlur Filtresi"));
}
void MainWindow::on_makeSobel_clicked()
{
   setTheViewOfTheComponent(true,"sobel");
   Mat sobelFilteredImage=imageOperations.sobelFilter();
   ui->labelResult->setPixmap(imageOperations.convertToPixmap(sobelFilteredImage));
   ui->labelFiltrelenmis->setText(QString( " Sobel Filtresi"));
}
void MainWindow::on_makeLaplacian_clicked()
{
    setTheViewOfTheComponent(true,"laplacian");
    Mat laplacianFilteredImage=imageOperations.laplacianFilter();
    ui->labelResult->setPixmap(imageOperations.convertToPixmap(laplacianFilteredImage));
    ui->labelFiltrelenmis->setText(QString( " Laplacian Filtresi"));
}
void MainWindow::on_makeDilation_clicked()
{
    setTheViewOfTheComponent(true,"dilation");
    Mat dilationFilteredImage=imageOperations.dilationFilter();
    ui->labelResult->setPixmap(imageOperations.convertToPixmap(dilationFilteredImage));
    ui->labelFiltrelenmis->setText(QString( " Dilation Filtresi"));
}
void MainWindow::on_makeErosion_clicked()
{
    setTheViewOfTheComponent(true,"erosion");
    Mat erosionFiltered=imageOperations.erosionFilter();
    ui->labelResult->setPixmap(imageOperations.convertToPixmap(erosionFiltered));
    ui->labelFiltrelenmis->setText(QString( " Erasion Filtresi"));
}
void MainWindow::on_elementValue_valueChanged(int value)
{
    imageOperations.setElement(value);
    ui->elementName->setText(QString( "Element: "+QLocale().toString(value)+"\n 0: Rect \n 1: Cross \n 2: Ellipse"));
}
void MainWindow::on_kernelValue_valueChanged(int value)
{
    imageOperations.setKernelSize(value);
    ui->kernelLabel->setText(QString( "Kernel boyutu: "+QLocale().toString(value)));
}
