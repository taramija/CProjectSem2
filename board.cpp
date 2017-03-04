#include "board.h"
#include <iostream>
#include <ctime>    //some comment
#include <stdlib.h>
#include <QDebug>
#include <QMouseEvent>
using namespace std;

//Tile function
//Tile::Tile(QWidget* parent) : QLabel(parent) {
//    connect(this, SIGNAL(leftClick()), this, SLOT(slotTileClick()));
//}

void Tile :: updateStatus(int statusCode){  //add picture using pixmap to the tile
    switch(statusCode){ //according to it's particular status
        case(1):{currentState = bomb;break;}
        case(2):{currentState = boom;break;}
        case(3):{currentState = checked;break;}
        case(4):{currentState = failed;break;}
        case(5):{currentState = flag;break; }
        case(6):{currentState = unchecked; break;}
    }
    this->setPixmap(QPixmap(currentState).scaled(size,size,Qt::KeepAspectRatio));
}

void Tile::mouseEvent(QMouseEvent* e){ // Assign action for mouse click events

    if(e->button() == Qt::RightButton){ // Right click event: trigger the flag

        qDebug() << "Right clicked!";

        // update the picture to code 6 if the flag is already on
        if(hasFlag){this->updateStatus(6);hasFlag=false;return;} //code 6 "unchecked"

        // update the picture to code 5 if the flag is not on
        if(!hasFlag){this->updateStatus(5);hasFlag=true;return;} //code 5 "flag"

    }else if(e->button() == Qt::LeftButton){ // Left click event

        if(!this->hasBomb){
            qDebug() << "Left clicked no Bomb!";
            this->updateStatus(3);

        }else{
            this->setTriggerState(true);
            emit leftClick();
        }
    }
}


//bool Tile :: event(QEvent *myEvent){
//    switch(myEvent->type()){
//        case(QEvent :: MouseButtonRelease):{   // Left click event
//            qDebug() << "Left Mouse Event";
//            emit leftClick();
//            break;
//        }
//        case(QEvent :: MouseButtonRelease):{   // Right click event
//            qDebug() << "Right Mouse Event";
//            emit rightClick();
//            break;
//        }
//    }
//    return QWidget::event(myEvent);
//}

//void Tile  :: slotLeftClick(){   // Implementation of Slot which will consume signal
//    qDebug() << "Left clicked!";
//    if(hasBomb){
//        this->updateStatus(2);
//    }
//}

//void Tile  :: slotRightClick(){   // Implementation of Slot which will consume signal
//    qDebug() << "Right clicked!";
//    if(hasFlag){this->updateStatus(6);hasFlag=false;return;}  //set flag
//    if(!hasFlag){this->updateStatus(5);hasFlag=true;return;} //unset flag
//}

//Board function
bool Board::setUpBoard(){

    //create 2d array made of Tiles
    tileSet = new Tile *[row];   //ini first dimension for the array

    for(int i = 0; i < row; ++i)
        tileSet[i] = new Tile[col];  //conduct 2nd dimension

    for(int j = 0; j < row; ++j){
        for(int k = 0; k < col; ++k){
            //use pointer to locate the current tile for convenience
            Tile *currentTile = &tileSet[i][j];

            //set size of the tile using property tileSize of the board
            currentTile.setSize(tileSize);

            //set default image interface for the whole board (code 6)
            currentTile.updateStatus(6); //code 6: "unchecked"

            //set position of each tile that form a 2d grid board
            //each tile position will increase by the size of 1 tile for every iteration
            currentTile.setGeometry(tileSize+tileSize*j,  //move the next tile horizontally
                                      tileSize+tileSize*k,  //move the next tile vertically
                                      tileSize,tileSize);   //indicate the size of the tile
        }
    }

//    // free dynamically allocated memory
//    for( int i = 0 ; i < row ; ++i )
//    {
//        delete [] tileSet[i] ;
//    }
//    delete [] tileSet ;

    return true;
}

//Initialize random bombs based on a given number
bool Board::setUpBomb(int numOfBomb){

    for(int i = 0; i < numOfBomb; ++i){ //allocate position for each bomb

        int randomPosX, randomPosY;

        srand( time(0));
        randomPosX = rand() % row; // Random row position
        randomPosY = rand() % col; // Random col position

        if(!tileSet[randomPosX][randomPosY].checkBomb()){   //check if this position is occupied
            tileSet[randomPosX][randomPosY].setBomb(true);
        }else{
            --i;    //redo the iteration if the random position is occupied
        }

    }

    return true;
}

//respond to Tile left click by listening to leftClick() signal
//reveal everything after the player lose the game
void Board::slotTileClick(){
    qDebug() << "left click Bomb triggered!";

    //loop through the whole board to update the
    //picture according to the state of the tile
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            Tile *currentTile = &tileSet[i][j];

            if(currentTile->checkBomb()){
                if(currentTile->checkBombTrigger())  //if this is the bomb the player triggered
                    currentTile->updateStatus(2);   //reveal it with red background picture
                else{
                    if(currentTile->checkFlag())    //if not, check the flag
                        //if the flag was on, mark it with "failed" sign
                        currentTile->updateStatus(4);
                    else
                        //if no flag, reveal the tile with normal bomb picture
                        currentTile->updateStatus(1);
                }
            }

            //keep the picture of every tiles left that has no flag, no bomb, no revelation

        }
    }

}

