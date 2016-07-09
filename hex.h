#ifndef HEX
#define HEX

#include <QGraphicsPolygonItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include "Player.h"
#include <QPaintEvent>

class Player;

class Hex: public QGraphicsPolygonItem
{
public:

    Hex(QGraphicsItem* parent=NULL);

    bool getHasPlayer();
    bool getIsMovable();
    unsigned int getXPos();
    unsigned int getYPos();
    bool getIsGoalHex();
    QList<Hex*> getNeighbours();
    QList<QGraphicsLineItem*> getMovement();

    void createLines();
    void createLines(int distance);
    void findNeighbours();
    void findMovableRange(const int distance);
    void makeVisible();
    void removeLists();
    void resetColors();
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setXPos(unsigned int x_pos);
    void setYPos(unsigned int y_pos);
    void setHasPlayer(bool b);
    void setGoalHexes();
    void setMiddleHex();
    void setGoalHex();
    void setGoalZone();
    void setPlayer(Player* player);
    void setPlayer1Offense();
    void setPlayer1Defense();
    void setPlayer2Offense();
    void setPlayer2Defense();
    void setMidfield();
    void setIsMovable(bool b);
    void setOriginalColor(QColor color);

    void setRowNumber(int row);
    void setColumnNumber(int column);
    int getRowNumber();
    int getColumnNumber();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);


    //bool operator == (Hex a,Hex b);
//    void captureNeighbours();

private:


    bool hasPlayer;
    bool isGoalHex;
    bool isPlayer1Offense;
    bool isPlayer2Offense;
    bool isPlayer1Defense;
    bool isPlayer2Defense;
    bool isMidfield;
    bool isMovable;

    unsigned int x_Pos;
    unsigned int y_Pos;
    QList<Hex*> m_neighbours;
    QList<QGraphicsLineItem*> m_lines;
    QList<QGraphicsLineItem*> m_movementRange;
    Player* m_Player;
    QPainter* m_painter;
    QColor m_color;

    int m_RowNumber;
    int m_ColumnNumber;

//    const int m_q, m_r,m_s;

//    QList<Hex*> neighbours;
//    bool isPlaced;
//    QString owner;

};

#endif // HEX

