#ifndef TILE_H
#define TILE_H


class tile
{
public:
    //constructor
    tile();

    //destructor
    ~tile();

    //mutators
    void setBomb(bool status){ hasBomb = status; }

    //accessors
    bool checkBomb(){}

protected:
    bool hasBomb;
};

#endif // TILE_H
