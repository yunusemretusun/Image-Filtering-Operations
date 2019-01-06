#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imageclass.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_selectPic_clicked();

    void on_makeBlur_clicked();

    void on_makeGaussianBlur_clicked();

    void on_makeSobel_clicked();

    void on_makeLaplacian_clicked();

    void on_makeDilation_clicked();

    void on_makeErosion_clicked();

    void on_elementValue_valueChanged(int value);

    void on_kernelValue_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    imageClass imageOperations;
    void setTheViewOfTheComponent(bool status,string filtreIsmi);

};

#endif // MAINWINDOW_H
