#include "hex.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include "game.h"
#include <assert.h>

extern Game* game;

Hex::Hex(QGraphicsItem *parent){

    isPlayer1Offense = false;
    isPlayer2Offense = false;
    isPlayer1Defense = false;
    isPlayer2Defense = false;
    isMidfield = false;
    isMovable=false;

    isGoalHex=false;
    hasPlayer = false;
    x_Pos = 0;
    y_Pos = 0;
    m_Player = NULL;
    m_color = Qt::white;


//    m_q = 0;
//    m_r = 0;
//    m_s = 0;

//    assert(m_q + m_r + m_s == 0);

    // draw the polygon

    // points needed to draw hexagon: (1,0), (2,0), (3,1), (2,2), (1,2), (0,1)
    QVector<QPointF> hexPoints;
    hexPoints << QPointF(0,0.866024) << QPointF(1.5,0) << QPointF(3,0.866024) << QPointF(3,2.598071)
              << QPointF(1.5,3.464095) << QPointF(0,2.598071);

    // scale the points
    int SCALE_BY = 15;
    for (size_t i = 0, n = hexPoints.size(); i < n; i++){
        hexPoints[i] = hexPoints[i] * SCALE_BY;
    }

//    // create a polygon with the scaled points
    QPolygonF hexagon(hexPoints);
    createLines();
    // draw the poly
    setPolygon(hexagon);

}

void Hex::setGoalZone()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);
}

void Hex::createLines()
{
    QPointF hexCenter(x()+22.5+1,y()+25.981+1);
    QPointF finalPt(hexCenter.x()+45,hexCenter.y());
    QLineF ln(hexCenter,finalPt);

    for(size_t i=0,n=6;i<n;i++){
        QLineF lnCopy(ln);
        lnCopy.setAngle(60*i);
        QGraphicsLineItem* line = new QGraphicsLineItem(lnCopy,this);
        m_lines.append(line);
        line->setVisible(false);
    }
}

void Hex::createLines(const int distance)
{
    std::cout<< distance << std::endl;
    QPointF hexCenter(getXPos(),getYPos());
    std::cout<< "x: " << hexCenter.x() << " , y: " << hexCenter.y() << std::endl;
    QPointF finalPt(hexCenter.x()+(45*distance),hexCenter.y());
    QLineF ln(hexCenter,finalPt);

    for(size_t i=0,n=6;i<n;i++){
        QLineF lnCopy(ln);
        lnCopy.setAngle(60*i);
        QGraphicsLineItem* line = new QGraphicsLineItem(lnCopy,this);
        m_lines.append(line);
        line->setVisible(false);
    }
}

void Hex::findNeighbours()
{
    for(size_t i=0,n=m_lines.size();i<n;i++){
        QList<QGraphicsItem*> cItems = m_lines[i]->collidingItems();
        for(size_t j=0;j<cItems.size();j++){
            Hex* item = dynamic_cast<Hex*>(cItems[j]);
            if(cItems[j] != this && item){
                m_neighbours.append(item);
            }
        }
    }
}

void Hex::findMovableRange(const int distance)
{

    //std::cout<< "distance: " << distance <<std::endl;
    for(size_t i=0,n=m_lines.size();i<n;i++){
        //std::cout << "current length: " << m_lines[i]->line().length() <<std::endl;
        int temp = m_lines[i]->line().length();
        QLineF tempLine = m_lines[i]->line();
        tempLine.setLength(temp*distance);
        QGraphicsLineItem* line = new QGraphicsLineItem(tempLine,this);
        line->setVisible(false);
        m_movementRange.append(line);
//        m_lines[i]->line().setLength(temp*distance);
        //std::cout << "new length: " << m_lines[i]->line().length() <<std::endl;
    }

    for(size_t i=0,n=m_movementRange.size();i<n;i++){
        QList<QGraphicsItem*> cItems = m_movementRange[i]->collidingItems();
        for(size_t j=0;j<cItems.size();j++){
            Hex* item = dynamic_cast<Hex*>(cItems[j]);
            if(cItems[j] != this && item){
                m_neighbours.append(item);
            }
        }
    }

    for(size_t i=0,n=m_neighbours.size();i<n;i++){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(255,51,51,250));
        m_neighbours[i]->setBrush(brush);
        m_neighbours[i]->setIsMovable(true);
    }
}

void Hex::makeVisible()
{
    for(size_t i=0,n=m_lines.size();i<n;i++){
        m_lines[i]->setVisible(true);
    }
}

void Hex::removeLists()
{
    for(size_t i=0,n=m_neighbours.size();i<n;i++){
//        QBrush brush;
//        brush.setStyle(Qt::SolidPattern);
//        brush.setColor(QColor(255,255,255,255));
        Hex* tempHex = m_neighbours[i];
        tempHex->resetColors();
        tempHex->setIsMovable(false);
        //m_neighbours[i]->setBrush(brush);
        //m_neighbours[i]->setIsMovable(false);
    }
    return;
}

void Hex::resetColors()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(m_color);
    setBrush(brush);
}

//void Hex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QVector<QPointF> hexPoints;
//    hexPoints << QPointF(0,0.866024) << QPointF(1.5,0) << QPointF(3,0.866024) << QPointF(3,2.598071)
//              << QPointF(1.5,3.464095) << QPointF(0,2.598071);

//    // scale the points
//    int SCALE_BY = 15;
//    for (size_t i = 0, n = hexPoints.size(); i < n; i++){
//        hexPoints[i] = hexPoints[i] * SCALE_BY;
//    }

//    // create a polygon with the scaled points
//    QPolygonF hexagon(hexPoints);


//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(Qt::white);
//    painter->setBrush(brush);
//    painter->drawPolygon(hexagon);

////    painter->setBrush(brush);
////    painter->drawPolygon(hexagon);

//}

void Hex::setXPos(unsigned int x_pos)
{
    x_Pos = x_pos;
}

void Hex::setYPos(unsigned int y_pos)
{
    y_Pos = y_pos;
}

void Hex::setGoalHexes()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void Hex::setMiddleHex()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}

void Hex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        Player* tempPlayer = game->getPlayerToPlace();
        if(hasPlayer == false && tempPlayer){
            if(isMovable){
                game->placePlayer(this);
            }else{
                game->returnPlayer();
            }
        }
    }
    return;
//    QGraphicsView::mousePressEvent(event);
}

void Hex::setGoalHex()
{
    isGoalHex=true;
}

void Hex::setPlayer(Player *player)
{
    m_Player = player;
}

void Hex::setPlayer1Offense()
{
    isPlayer1Offense = true;
}

void Hex::setPlayer1Defense()
{
    isPlayer1Offense = true;
}

void Hex::setPlayer2Offense()
{
    isPlayer2Offense = true;
}

void Hex::setPlayer2Defense()
{
    isPlayer2Defense = true;
}

void Hex::setMidfield()
{
    isMidfield = true;
}

void Hex::setIsMovable(bool b)
{
    isMovable = b;
}

void Hex::setOriginalColor(QColor color)
{
    m_color = color;
}

void Hex::setRowNumber(int row)
{
    m_RowNumber = row;
}

void Hex::setColumnNumber(int column)
{
    m_ColumnNumber = column;
}

int Hex::getRowNumber()
{
    return m_RowNumber;
}

int Hex::getColumnNumber()
{
    return m_ColumnNumber;
}

bool Hex::getIsGoalHex()
{
    return isGoalHex;
}

QList<Hex *> Hex::getNeighbours()
{
    return m_neighbours;
}

QList<QGraphicsLineItem *> Hex::getMovement()
{
    return m_movementRange;
}

bool Hex::getHasPlayer()
{
    return hasPlayer;
}

bool Hex::getIsMovable()
{
    return isMovable;
}

unsigned int Hex::getXPos()
{
    return x_Pos;
}

unsigned int Hex::getYPos()
{
    return y_Pos;
}

void Hex::setHasPlayer(bool b)
{
    hasPlayer = b;
}
