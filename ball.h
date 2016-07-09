#ifndef BALL
#define BALL

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPointF>
#include <QList>
#include "Player.h"

class Ball : public Player
{
public:
    Ball(QGraphicsItem* parent=0);
    void rotateToPoint(QPointF p);

public slots:
    void Move();

private:
    QList<QPointF> m_points;
    QPointF m_dest;
    int m_point_index;
};

#endif // BALL

