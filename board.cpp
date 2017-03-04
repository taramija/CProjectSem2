#include "board.h"
#include <iostream>
#include <ctime>    //some comment
#include <stdlib.h>
#include <QDebug>
using namespace std;

//Tile function
Tile::Tile(QWidget* parent) : QLabel(parent) {
    connect(this, SIGNAL(leftClick()), this, SLOT(slotTileClicked()));
    connect(this, SIGNAL(rightClick()), this, SLOT(slotTileClicked()));
}

void Tile :: updateStatus(int statusCode){
    switch(statusCode){
        case(1):{currentState = bomb;break;}
        case(2):{currentState = boom;break;}
        case(3):{currentState = checked;break;}
        case(4):{currentState = failed;break;}
        case(5):{currentState = flag;break; }
        case(6):{currentState = unchecked; break;}
    }
    this->setPixmap(QPixmap(currentState).scaled(5,5,Qt::KeepAspectRatio));
}

bool Tile :: event(QEvent *myEvent){
    switch(myEvent->type()){
        case(QEvent :: MouseButtonRelease):{   // Left click event
            qDebug() << "Left Mouse Event";
            emit leftClick();
            break;
        }
        case(QEvent :: MouseButtonRelease):{   // Right click event
            qDebug() << "Right Mouse Event";
            emit rightClick();
            break;
        }
    }
    return QWidget::event(myEvent);
}

void Tile  :: slotLeftClick(){   // Implementation of Slot which will consume signal
    qDebug() << "Left clicked!";
    if(hasBomb){
        this->updateStatus(2);
    }
}

void Tile  :: slotRightClick(){   // Implementation of Slot which will consume signal
    qDebug() << "Right clicked!";
    if(hasFlag){this->updateStatus(6);return;}  //set flag
    if(!hasFlag){this->updateStatus(5);return;} //unset flag
}

//Board function
bool board::setUpBoard(){
    tileSet = new Tile*[row];

    for(int i = 0; i < row; ++i){
        tileSet[i] = new Tile[col];
    }

    //set default status interface for the whole board (code 6)
    for(int j = 0; i < row; ++i){
        for(int k = 0; k < col; ++i){
            tileSet[j][k].updateStatus(6);
        }
    }
}

//Initialize random bombs based on a given number
bool board::setUpBomb(int numOfBomb){
    for(int i = 0; i < numOfBomb; ++i){
        int randomPosX, randomPosY;

        srand( time(0));
        randomPosX = rand() % row; // Random row position
        randomPosY = rand() % col; // Random col position

        if(!tileSet[randomPosX][randomPosY].hasBomb){
            tileSet[randomPosX][randomPosY].setBomb(true);
        }else{
            --i;
        }

    }
}

