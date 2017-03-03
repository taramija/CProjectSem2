#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QImage image("comando.jpg");
//    imageLabel->setPixmap(QPixmap::fromImage(image));

    ui->label->setPixmap(QPixmap("D://CProject/MineSweeper/img.jpg").scaled(100,100,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*e)
{


}
