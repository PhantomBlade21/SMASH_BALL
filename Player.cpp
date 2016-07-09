//The Player Class Page
//First Created 12/11/15
//

#include "Player.h"
#include <QBrush>
#include "game.h"

//****************Basic Object Creation and Deconstruction*********************//
//*****************************************************************************//
extern Game* game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
		m_Has_Ball = false;
        m_Owner = "Noone";
        m_currentHex = NULL;
	
		m_Pass_Counter = 0;
		m_Goal_Counter = 0;

		m_Health_Stat = 0;
        m_Speed_Stat = 5;
        m_Pass_Stat = 15;
		m_Shoot_Stat = 0;
		m_Block_Stat = 0;
		m_Steal_Stat = 0;
		m_Handle_Stat = 0;
		m_Recovery_Stat = 0;
		m_Open_Stat = 0;
		m_AP = 0;
		m_Tier = 0;

        m_X = 0;
        m_Y = 0;

        setPixmap(QPixmap(":MyFiles/Blue1.png"));
        setAcceptHoverEvents(true);

}

Player::Player(double x_pos, double y_pos) : QGraphicsPixmapItem()
{
    m_Has_Ball = false;
    m_Owner = "Noone";

    m_Pass_Counter = 0;
    m_Goal_Counter = 0;

    m_Health_Stat = 0;
    m_Speed_Stat = 5;
    m_Pass_Stat = 0;
    m_Shoot_Stat = 0;
    m_Block_Stat = 0;
    m_Steal_Stat = 0;
    m_Handle_Stat = 0;
    m_Recovery_Stat = 0;
    m_Open_Stat = 0;
    m_AP = 0;
    m_Tier = 0;
    m_X = 0;
    m_Y = 0;

    setPixmap(QPixmap(":MyFiles/PlayerBlue.jpg"));
    //m_Player = new QGraphicsEllipseItem(x_pos+5,y_pos-20,35,35);
    //game->addPlayer(m_Player);


//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(Qt::yellow);
//    m_Player->setBrush(brush);


}

Player::~Player()
{

}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton && game->getActivePlayer() == NULL && m_Owner == game->getWhosTurn()){
        game->displayBattleMenu(this);
//        game->setPlayerToPlace(this);
        game->setActivePlayer(this);
        game->originalPos = this->pos();
    }


//    if(game->getWhosTurn()== "Player1"){
//        QList<Player *> tempPlayer1 = game->getPlayer1Characters();
//        for(size_t i=0,n=tempPlayer1.size();i<n;i++){
//            if(this == tempPlayer1[i]){
//                game->pickUpPlayer(this);
//            }
//        }
    //    }
//    game->m_scene->mousePressEvent(event);
}

void Player::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    //setPixmap(QPixmap(":MyFiles/Blue2.png"));
//    m_Rect.setRect(this->x(),this->y(),32,32);

//    QPen pen;
//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(QColor(255,255,255,128));
//    game->m_scene->addRect(m_Rect,pen,brush);
}

void Player::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //setPixmap(QPixmap(":MyFiles/Blue1.png"));
}

void Player::findMovement()
{
    m_currentHex->findMovableRange(m_Speed_Stat);
}

//****************Basic Name functions*********************//
//*********************************************************//

void Player::set_Name(QString Name)
{
    m_Name = Name;
}

QString Player::get_Owner()
{
    return m_Owner;
}

void Player::set_Owner(QString owner)
{
    m_Owner = owner;
}

Hex *Player::getCurrentHex()
{
    return m_currentHex;
}

void Player::setCurrentHex(Hex *hex)
{
    m_currentHex = hex;
}

bool Player::getHasBall()
{
    return m_Has_Ball;
}

void Player::setHasBall(bool ball)
{
    m_Has_Ball = ball;
}

QString Player::get_Name()
{	
	return m_Name;
}

//****************All of the setter functions*********************//
//****************************************************************//
//Not sure how many of these will be used throughout the game.....//

void Player::set_Health(unsigned int Health)
{
	m_Health_Stat = Health;
}

void Player::set_Speed(unsigned int Speed)
{
	m_Speed_Stat = Speed;
}

void Player::set_Pass(unsigned int Pass)
{
	m_Pass_Stat = Pass;
}

void Player::set_Shoot(unsigned int Shoot)
{
	m_Shoot_Stat = Shoot;
}

void Player::set_Block(unsigned int Block)
{
	m_Block_Stat = Block;
}

void Player::set_Steal(unsigned int Steal)
{
	m_Steal_Stat = Steal;
}

void Player::set_Handle(unsigned int Handle)
{
	m_Handle_Stat = Handle;
}

void Player::set_Recovery(unsigned int Recovery)
{
	m_Recovery_Stat = Recovery;
}

void Player::set_Open(unsigned int Open)
{
	m_Open_Stat = Open;
}

void Player::set_AP(unsigned int AP)
{
	m_AP = AP;
}

void Player::set_Tier(unsigned int Tier)
{
	m_Tier = Tier;
}

void Player::set_X(unsigned int X)
{
    m_X = X;
}

void Player::set_Y(unsigned int Y)
{
    m_Y = Y;
}

void Player::set_X_Grid(int x_grid)
{
    m_X_Grid = x_grid;
}

void Player::set_Y_Grid(int y_grid)
{
    m_y_Grid = y_grid;
}



//****************All of the getter functions*********************//
//****************************************************************//

unsigned int Player::get_Health()
{
	return m_Health_Stat;
}

unsigned int Player::get_Speed()
{
	return m_Speed_Stat;
}

unsigned int Player::get_Pass()
{
	return m_Pass_Stat;
}

unsigned int Player::get_Shoot()
{
	return m_Shoot_Stat;
}

unsigned int Player::get_Block()
{
	return m_Block_Stat;
}

unsigned int Player::get_Steal()
{
	return m_Steal_Stat;
}

unsigned int Player::get_Handle()
{
	return m_Handle_Stat;
}

unsigned int Player::get_Recovery()
{
	return m_Recovery_Stat;
}

unsigned int Player::get_Open()
{
	return m_Open_Stat;
}

unsigned int Player::get_AP()
{
	return m_AP;
}

unsigned int Player::get_Tier()
{
	return m_Tier;
}

unsigned int Player::get_X()
{
    return m_X;
}

unsigned int Player::get_Y()
{
    return m_Y;
}


//****************Start of the different usable functions*************************************************************//
//********************************************************************************************************************//

void Player::Make_Pass()
{
	if(!m_Has_Ball)
	{	
		//cout<< "The player does not have the ball to make a pass.";	
		return;
	}else{
        if(Check_Health(5))
		{	
			Take_Health(5);
			m_Has_Ball == false;
			return;
		}
	}
	return;
}

void Player::Shoot_Ball()
{
	if(!m_Has_Ball)
	{	
		//cout<< "The player does not have the ball to make a shot.";	
		return;
	}else{
		if(Check_Health(10))
		{
			Take_Health(10);
			m_Has_Ball == false;
			return;
		}
	}
	return;
}

//****************All of the Health functions*********************//
//****************************************************************//

bool Player::Check_Health(unsigned int Cost)
{
	if((m_Health_Stat - Cost) < 0)
	{
		//cout<< "Insufficient Health for this action";
		return false;
	}else{
		return true;
	}
}

void Player::Take_Health(unsigned int Damage)
{
	if((m_Health_Stat - Damage) < 0)
	{
		m_Health_Stat == 0;
		//cout<< m_Name << " has no health left.";
		return;
	}else{
		m_Health_Stat = m_Health_Stat - Damage;
	}	
	return;
}

void Player::Recover_Health()
{
	m_Health_Stat = m_Health_Stat + m_Recovery_Stat;
}
