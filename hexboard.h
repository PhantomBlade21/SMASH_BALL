#ifndef HEXBOARD
#define HEXBOARD

#include <QList>
#include "hex.h"

class HexBoard
{
public:
    HexBoard();

    QList<Hex*> getHexColumns();
    QList<QList<Hex *> > getHexRows();

    void placeHexes(int x, int y, int cols, int rows);
    void setZones();

private:
    void createHexColumn(int x, int y, int numOfRows);
    void createHexRow(int x, int y, int numOfColumns, int tempRowNumber, bool isOdd);


    QList<Hex*> hexColumns;
    QList<QList<Hex* > > hexRows;

    int numHexRows;

};

#endif // HEXBOARD

