#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QImage image("comando.jpg");
//    imageLabel->setPixmap(QPixmap::fromImage(image));

    Board board(10,10);
    board.setUpBoard();
//    board.setUpBomb(10);

//    for(int i=0; i<board.getRow(); ++i){
//        for(int j=0; j<board.getCol(); ++j){
//            Tile tile = board.tileSet[i][j];

//            QObject::connect(&tile, SIGNAL(leftClick()),&board, SLOT(slotTileClick()));
//        }
//    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*e)
{


}
