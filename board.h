#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QLabel>
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class MainWindow;

//Class Tile
class Tile : public QLabel
{
    Q_OBJECT

    public:
        //constructor
        Tile(MainWindow* parent=0):QLabel(parent){
            bomb = "D://CProject/MineSweeper/images/bomb.png";             //code 1
            boom = "D://CProject/MineSweeper/images/boom.png";             //code 2
            checked = "D://CProject/MineSweeper/images/checked.png";       //code 3
            failed = "D://CProject/MineSweeper/images/failed.png";         //code 4
            flag = "D://CProject/MineSweeper/images/flag.png";             //code 5
            unchecked = "D://CProject/MineSweeper/images/unchecked.png";   //code 6
            currentState = unchecked;
//            this->setMouseTracking(true);
        }

        //destructor
        ~Tile(){}
        //copy instance
        Tile( const Tile& other, MainWindow* parent=0):QLabel(parent){
            setSize(other.checkFlag());
            setBomb(other.checkBomb());
            setTriggerState(other.checkBombTrigger());

            setBombUrl(other.getBombUrl());
            setBoomUrl(other.getBoomUrl());
            setCheckedUrl(other.getCheckedUrl());
            setFailedUrl(other.getFailedUrl());
            setFlagUrl(other.getFlagUrl());
            setUncheckedUrl(other.getUncheckedUrl());
            setCurrentState(other.getCurrentState());
        }

        //mutators
        void setSize(int newSize){ size = newSize; }
        void setBomb(bool newStatus){ hasBomb = newStatus; }
        void setTriggerState(bool newStatus){ bombTriggered = newStatus; }

        void setBombUrl(const char* newUrl){ bomb = newUrl; }
        void setBoomUrl(const char* newUrl){ boom = newUrl; }
        void setCheckedUrl(const char* newUrl){ checked = newUrl; }
        void setFailedUrl(const char* newUrl){ failed = newUrl; }
        void setFlagUrl(const char* newUrl){ flag = newUrl; }
        void setUncheckedUrl(const char* newUrl){ unchecked = newUrl; }
        void setCurrentState(const char* newCurrentState){ currentState = newCurrentState; }

        //accessors
        int getSize() const { return size; }
        bool checkBomb() const { return hasBomb; }
        bool checkFlag() const { return hasFlag; }
        bool checkBombTrigger() const { return bombTriggered; }

        const char* getBombUrl() const { return bomb ; }
        const char* getBoomUrl() const { return boom; }
        const char* getCheckedUrl() const { return checked; }
        const char* getFailedUrl() const { return failed ; }
        const char* getFlagUrl() const { return flag; }
        const char* getUncheckedUrl() const { return unchecked; }
        const char* getCurrentState() const { return currentState; }

        //functions
        void updateStatus(int);     //change the image of the tile base on list of code below
        void mouseEvent(QMouseEvent* e);    //handle mouse click events

    signals:
        void leftClick();       // left click signal (when the bomb is triggerd to reveal the board)

    protected:
        int size;
        bool hasBomb;
        bool hasFlag;
        bool bombTriggered;
//        bool event(QEvent *myEvent);    //mouse handler function

        //declare preset images link for different case
        const char *bomb;             //code 1
        const char *boom;             //code 2
        const char *checked;       //code 3
        const char *failed;         //code 4
        const char *flag;             //code 5
        const char *unchecked;   //code 6

        const char *currentState;  //will be set one of the state above
};

//Class Board
    class Board : public QObject
    {
        Q_OBJECT

        public:
            //constructor
            Board();
            Board(int iniRow, int iniCol, int iniTileSize = 10){
                row = iniRow;
                col = iniCol;
                tileSize = iniTileSize;
            }

            //destructor
            ~Board(){}

            //mutators
            void setRow(int newRow){ row = newRow; }
            void setCol(int newCol){ col = newCol; }

            //accessors
            int getRow() const { return row; }
            int getCol() const { return col; }
            Tile** getTileSet() const { return tileSet; }

            //functions
            bool setUpBoard();  //create array of labels and fill them with default picture
            bool setUpBomb(int); //randomly allocate the bomb based on a given number
//            bool checkTile(int, int);

        public slots:
            void slotTileClick();    // the board listen to Tile's left click signal

        protected:
            int row, col;
            int tileSize;
            Tile** tileSet; //variable to store tiles of the board

    };



#endif // BOARD_H
