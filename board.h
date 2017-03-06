#include <QObject>
#include <QLabel>

#ifndef BOARD_H
#define BOARD_H


//Class Tile
class Tile : public QLabel
{
    Q_OBJECT

    public:
        //constructor
        Tile(){
            currentState = unchecked;
//            this->setMouseTracking(true);
        }

        //destructor
        ~Tile(){}

        //mutators
        void setSize(int size){ size = size; }
        void setBomb(bool status){ hasBomb = status; }
        void setTriggerState(bool status){ bombTriggered = status; }

        //accessors
        bool checkBomb() const { return hasBomb; }
        bool checkFlag() const { return hasFlag; }
        bool checkBombTrigger() const { return bombTriggered; }

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
        const char *bomb = "D://CProject/MineSweeper/images/bomb.png";             //code 1
        const char *boom = "D://CProject/MineSweeper/images/boom.png";             //code 2
        const char *checked = "D://CProject/MineSweeper/images/checked.png";       //code 3
        const char *failed = "D://CProject/MineSweeper/images/failed.png";         //code 4
        const char *flag = "D://CProject/MineSweeper/images/flag.png";             //code 5
        const char *unchecked = "D://CProject/MineSweeper/images/unchecked.png";   //code 6

        const char *currentState;  //will be set one of the state above
};

//Class Board
    class Board : public QObject
    {
        Q_OBJECT

        public:
            //constructor
            Board();
            Board(int row, int col, int tileSize = 10){
                row = row;
                col = col;
                tileSize = tileSize;
            }

            //destructor
            ~Board(){}

            //mutators
            void setRow(int row){ row = row; }
            void setCol(int col){ col = col; }

            //accessors
            int getRow() const { return row; }
            int getCol() const { return col; }

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
