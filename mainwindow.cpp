#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include "stdlib.h"
#include <iostream>
#include <QDebug>
#include <QPainter>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    label->setGeometry(5+5*i,
//                       5+5*j,
//                       5,5);

//    QImage image("comando.jpg");
//    imageLabel->setPixmap(QPixmap::fromImage(image));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*e)
{
    //QPainter painter(this);

}

void MainWindow::on_newBtn_clicked()
{
    Board board(10,10);
    board.setUpBoard();
    board.setUpBomb(10);

// set the signal-slot connection between tiles and board
    for(int i=0; i<board.getRow(); ++i){
        for(int j=0; j<board.getCol(); ++j){
//            Tile** tileSet = **board.getTileSet();

//            for(int i = 0; i < row; ++i)
//                tileSet[i] = **board.getTileSet();

//            Tile = board.getTileSet();
//            qDebug() << tileSet;
//            cout << **tileSet;
//            Tile tile = *(*(tileSet+j) + i);



//            Tile tile = *(*(board.getTileSet()+j)+i);

//            QObject::connect(&tile, SIGNAL(leftClick()),&board, SLOT(slotTileClick()));

//            update();
        }
    }
}
