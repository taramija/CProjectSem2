#include <QLabel>

#ifndef BOARD_H
#define BOARD_H


//Class Tile
class Tile : public QLabel
{


    public:
        //constructor
        Tile(char currentState = unchecked);

        //destructor
        ~Tile();

        //mutators
        void setBomb(bool status){ hasBomb = status; }

        //accessors
        bool checkBomb() const { return hasBomb; }

        //functions
        void triggerFlag(){
            if(hasFlag){
                hasFlag = false;
                return;
            }else{
                hasFlag = true;
                return;
            }
        }
        void updateStatus(int);

    signals:
        void leftClick();       // Signal to emit
        void rightClick();       // Signal to emit

    public slots:
        void slotLeftClick();    // Slot which will consume signal
        void slotRightClick();    // Slot which will consume signal


    protected:
        bool hasBomb;
        bool hasFlag;
        bool event(QEvent *myEvent);

        char bomb = "D://CProject/MineSweeper/images/bomb.png";             //code 1
        char boom = "D://CProject/MineSweeper/images/boom.png";             //code 2
        char checked = "D://CProject/MineSweeper/images/checked.png";       //code 3
        char failed = "D://CProject/MineSweeper/images/failed.png";         //code 4
        char flag = "D://CProject/MineSweeper/images/flag.png";             //code 5
        char unchecked = "D://CProject/MineSweeper/images/unchecked.png";   //code 6

        char currentState;
};

//Class Board
    class board
    {
        public:
            //constructor
            board();
            board(int row, int col){
                row = row;
                col = col;
            }

            //destructor
            ~board();

            //mutators
            bool setRow(int row){ row = row; }
            bool setCol(int col){ row = col; }

            //accessors
            int getRow() const { return row; }
            int getCol() const { return col; }

            //functions
            bool setUpBoard();
            bool setUpBomb(int);

            bool checkTile(int, int);


        protected:
            int row, col;
            Tile** tileSet;

    };



#endif // BOARD_H
