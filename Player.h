//Header file for a Player character
//First test file as of 12/11/15
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <QGraphicsPolygonItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "hex.h"

class Hex;

using namespace std;
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
	public:

        Player(QGraphicsItem* parent=0);
        Player(double x_pos, double y_pos);
		//Player(string, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
		~Player();

        void mousePressEvent(QGraphicsSceneMouseEvent* event);
        void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

		void Make_Pass();
		void Take_Health(unsigned int);
		void Recover_Health();
		bool Check_Health(unsigned int);

        void Shoot_Ball();

        QString get_Name();
        void set_Name(QString name);
        QString get_Owner();
        void set_Owner(QString owner);
        Hex* getCurrentHex();
        void setCurrentHex(Hex* hex);

        bool getHasBall();
        void setHasBall(bool ball);

		unsigned int get_Health();
		unsigned int get_Speed();
		unsigned int get_Pass();
		unsigned int get_Shoot();
		unsigned int get_Block();
		unsigned int get_Steal();
		unsigned int get_Handle();
		unsigned int get_Recovery();
		unsigned int get_Open();
		unsigned int get_AP();
		unsigned int get_Tier();

		unsigned int get_X();
		unsigned int get_Y();

        unsigned int get_Pos();

		void set_Health(unsigned int);
		void set_Speed(unsigned int);
		void set_Pass(unsigned int);
		void set_Shoot(unsigned int);
		void set_Block(unsigned int);
		void set_Steal(unsigned int);
        void set_Handle(unsigned int);
		void set_Recovery(unsigned int);
		void set_Open(unsigned int);
		void set_AP(unsigned int);
		void set_Tier(unsigned int);

		void set_X(unsigned int);
		void set_Y(unsigned int);
        void set_X_Grid(int x_grid);
        void set_Y_Grid(int y_grid);

    public slots:
        void findMovement();
    protected:

		bool m_Has_Ball;
	
		unsigned int m_Pass_Counter;
		unsigned int m_Goal_Counter;

		unsigned int m_Health_Stat;
		unsigned int m_Speed_Stat;
		unsigned int m_Pass_Stat;
		unsigned int m_Shoot_Stat;
		unsigned int m_Block_Stat;
		unsigned int m_Steal_Stat;
		unsigned int m_Handle_Stat;
		unsigned int m_Recovery_Stat;
		unsigned int m_Open_Stat;
		unsigned int m_AP;
		unsigned int m_Tier;

        unsigned int m_X;
        unsigned int m_Y;
        int m_X_Grid;
        int m_y_Grid;

        Hex* m_currentHex;
        QRectF m_Rect;
        QString m_Name;
        QString m_Owner;
        QGraphicsEllipseItem* m_Player;
        QGraphicsPolygonItem* m_hitbox;


};

#endif
