#include "game.h"
#include "hexboard.h"
#include "button.h"
#include "Player.h"
#include "ball.h"
#include <QMenu>
#include <QtWidgets>

Game::Game(QWidget* parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1320,768);

    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0,0,1320,768);

    setScene(m_scene);
    playerToPlace=NULL;
    activePlayer=NULL;
    isMenu = false;

}

void Game::displayBattleMenu(Player* player)
{
    m_menu = new PlayerMenu(player,this);
    m_menu->show();
    isMenu = true;
}

void Game::startGame()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);

    m_scene->clear();
    m_scene->setBackgroundBrush(brush);

    hexboard = new HexBoard();
    hexboard->placeHexes(160,45,21,17);
    hexboard->setZones();
    m_ball = new Ball();

    m_whosTurn = QString("Player1");

    PlayerCreation();


}

void Game::startSetupMode()
{

}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    m_scene->addItem(panel);
}

void Game::drawGUI()
{
    // draw the right panel
    drawPanel(1000,55,295,658,Qt::white,1);

    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(startGame()));
    m_scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    m_scene->addItem(quitButton);
}

void Game::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Smash Ball"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    m_scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(startGame()));
    m_scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    m_scene->addItem(quitButton);

}

void Game::addPlayer(QGraphicsEllipseItem *player)
{
    m_scene->addItem(player);
}

void Game::nextPlayersTurn()
{
    if (getWhosTurn() == QString("Player1")){
        setWhosTurn(QString("Player2"));
    }
    else {
        setWhosTurn(QString("Player1"));
    }
}

void Game::PlayerCreation()
{
    QList<QList<Hex* > > tempRows = hexboard->getHexRows();

    for(size_t i=0,n=tempRows.size();i<n;i++){
        QList<Hex* > tempColumns = tempRows[i];
        for(size_t j=0,m=tempColumns.size();j<m;j++){
//            std::cout<< j << "\n" <<std::endl;
            if(i==2 && j==9){

                Player* player16 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player16);
                tempHex->setHasPlayer(true);
                player16->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player16->setCurrentHex(tempHex);
                m_scene->addItem(player16);
                m_player1Characters.append(player16);
                player16->set_Owner("Player1");

            }else if(i==2 && j==11){

                Player* player1 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player1);
                tempHex->setHasPlayer(true);
                player1->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player1->setCurrentHex(tempHex);
                m_scene->addItem(player1);
                m_player2Characters.append(player1);
                player1->set_Owner(QString("Player2"));


            }else if(i==8 && j==9){

                Player* player2 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player2);
                tempHex->setHasPlayer(true);
                player2->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player2->setCurrentHex(tempHex);
                m_scene->addItem(player2);
                m_player1Characters.append(player2);
                player2->set_Owner(QString("Player1"));
                player2->setHasBall(true);

                m_ball->setPos(tempHex->getXPos()+3, tempHex->getYPos()+3);
                m_ball->setCurrentHex(tempHex);
                m_ball->setScale(.5);
                m_scene->addItem(m_ball);


            }else if(i==8 && j==11){

                Player* player3 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player3);
                tempHex->setHasPlayer(true);
                player3->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player3->setCurrentHex(tempHex);
                m_scene->addItem(player3);
                m_player2Characters.append(player3);
                player3->set_Owner(QString("Player2"));

            }else if(i==14 && j==9){

                Player* player4 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player4);
                tempHex->setHasPlayer(true);
                player4->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player4->setCurrentHex(tempHex);
                m_scene->addItem(player4);
                m_player1Characters.append(player4);
                player4->set_Owner(QString("Player1"));

            }else if(i==14 && j==11){

                Player* player5 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player5);
                tempHex->setHasPlayer(true);
                player5->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player5->setCurrentHex(tempHex);
                m_scene->addItem(player5);
                m_player2Characters.append(player5);
                player5->set_Owner(QString("Player2"));

            }else if(i==5 && j==7){

                Player* player6 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player6);
                tempHex->setHasPlayer(true);
                player6->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player6->setCurrentHex(tempHex);
                m_scene->addItem(player6);
                m_player1Characters.append(player6);
                player6->set_Owner(QString("Player1"));

            }else if(i==5 && j==12){

                Player* player7 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player7);
                tempHex->setHasPlayer(true);
                player7->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player7->setCurrentHex(tempHex);
                m_scene->addItem(player7);
                m_player2Characters.append(player7);
                player7->set_Owner(QString("Player2"));

            }else if(i==11 && j==7){

                Player* player8 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player8);
                tempHex->setHasPlayer(true);
                player8->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player8->setCurrentHex(tempHex);
                m_scene->addItem(player8);
                m_player1Characters.append(player8);
                player8->set_Owner(QString("Player1"));

            }else if(i==11 && j==12){

                Player* player9 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player9);
                tempHex->setHasPlayer(true);
                player9->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player9->setCurrentHex(tempHex);
                m_scene->addItem(player9);
                m_player2Characters.append(player9);
                player9->set_Owner(QString("Player2"));

            }else if(i==8 && j==1){

                Player* player10 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player10);
                tempHex->setHasPlayer(true);
                player10->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player10->setCurrentHex(tempHex);
                m_scene->addItem(player10);
                m_player1Characters.append(player10);
                player10->set_Owner(QString("Player1"));

            }else if(i==8 && j==10){


            }else if(i==8 && j==19){

                Player* player11 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player11);
                tempHex->setHasPlayer(true);
                player11->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player11->setCurrentHex(tempHex);
                m_scene->addItem(player11);
                m_player2Characters.append(player11);
                player11->set_Owner(QString("Player2"));

            }else if(i==6 && j==4){

                Player* player12 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player12);
                tempHex->setHasPlayer(true);
                player12->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player12->setCurrentHex(tempHex);
                m_scene->addItem(player12);
                m_player1Characters.append(player12);
                player12->set_Owner(QString("Player1"));

            }else if(i==6 && j==16){

                Player* player13 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player13);
                tempHex->setHasPlayer(true);
                player13->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player13->setCurrentHex(tempHex);
                m_scene->addItem(player13);
                m_player2Characters.append(player13);
                player13->set_Owner(QString("Player2"));

            }else if(i==10 && j==4){

                Player* player14 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player14);
                tempHex->setHasPlayer(true);
                player14->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player14->setCurrentHex(tempHex);
                m_scene->addItem(player14);
                m_player1Characters.append(player14);
                player14->set_Owner(QString("Player1"));

            }else if(i==10 && j==16){

                Player* player15 = new Player();
                Hex* tempHex = tempRows[i][j];
                tempHex->setPlayer(player15);
                tempHex->setHasPlayer(true);
                player15->setPos(tempHex->getXPos()-15, tempHex->getYPos()-15);
                player15->setCurrentHex(tempHex);
                m_scene->addItem(player15);
                m_player2Characters.append(player15);
                player15->set_Owner(QString("Player2"));

            }
        }
    }
}

void Game::pickUpPlayer()
{
    playerToPlace = activePlayer;
    playerToPlace->getCurrentHex()->findMovableRange(playerToPlace->get_Speed());
    playerToPlace->setPixmap(QPixmap(":MyFiles/Blue2.png"));
    delete(m_menu);
    isMenu = false;
}

void Game::makePass()
{
    playerToPlace = activePlayer;
    playerToPlace->getCurrentHex()->findMovableRange(activePlayer->get_Pass());
    delete(m_menu);
    isMenu = false;
}

void Game::placePlayer(Hex* hex)
{
    if(playerToPlace->getHasBall()==true){
        playerToPlace->setPos(hex->getXPos()-15, hex->getYPos()-15);
        playerToPlace->setPixmap(QPixmap(":MyFiles/Blue1.png"));
        m_ball->setPos(hex->getXPos()+3, hex->getYPos()+3);
        hex->setHasPlayer(true);
        playerToPlace->getCurrentHex()->removeLists();
        playerToPlace->setCurrentHex(hex);
        playerToPlace=NULL;
        activePlayer=NULL;
    }else{
        playerToPlace->setPos(hex->getXPos()-15, hex->getYPos()-15);
        playerToPlace->setPixmap(QPixmap(":MyFiles/Blue1.png"));
        hex->setHasPlayer(true);
        playerToPlace->getCurrentHex()->removeLists();
        playerToPlace->setCurrentHex(hex);
        playerToPlace=NULL;
        activePlayer=NULL;
    }

//    delete(m_menu);

    //hex->removeLists();

    nextPlayersTurn();
}

void Game::returnPlayer()
{
    playerToPlace->setPos(originalPos);
    playerToPlace->setPixmap(QPixmap(":MyFiles/Blue1.png"));
    playerToPlace->getCurrentHex()->removeLists();
    playerToPlace->getCurrentHex()->resetColors();
    playerToPlace=NULL;
    activePlayer=NULL;
    //delete(m_menu);
    //isMenu = false;
}

void Game::addPlayer1Player(Player *player)
{
    m_player1Characters.append(player);
}

void Game::addPlayer2Player(Player *player)
{
    m_player2Characters.append(player);
}

void Game::setWhosTurn(QString Player)
{
    m_whosTurn = Player;
}

void Game::setPlayerToPlace(Player *player)
{
    playerToPlace = player;
}

void Game::setActivePlayer(Player *player)
{
    activePlayer = player;
}

void Game::setIsMenu(bool b)
{
    isMenu = b;
}

bool Game::getIsMenu()
{
    return isMenu;
}

Player *Game::getPlayerToPlace()
{
    return playerToPlace;
}

Player *Game::getActivePlayer()
{
    return activePlayer;
}

QList<Player *> Game::getPlayer1Characters()
{
    return m_player1Characters;
}

QList<Player *> Game::getPlayer2Characters()
{
    return m_player2Characters;
}

QString Game::getWhosTurn()
{
    return m_whosTurn;
}

//void Game::mouseMoveEvent(QMouseEvent *event)
//{
//    if(playerToPlace && isMenu == false){
//        playerToPlace->setPos(event->pos());
//    }

//    QGraphicsView::mouseMoveEvent(event);
//}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton){
        if(isMenu){
            delete(m_menu);
            isMenu = false;
            activePlayer = NULL;
        }else{
            if(playerToPlace){
                returnPlayer();
            }
        }

    }
    QGraphicsView::mousePressEvent(event);
}
