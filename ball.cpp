#include "ball.h"
#include "game.h"
#include <QTimer>
#include <qmath.h>

extern Game* game;

Ball::Ball(QGraphicsItem *parent)
{
    m_Owner = "Noone";
    m_currentHex = NULL;

    m_X = 0;
    m_Y = 0;

    setPixmap(QPixmap(":MyFiles/Soccerball.png"));
    setAcceptHoverEvents(true);
}

