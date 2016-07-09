#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include "hexboard.h"
#include "Player.h"
#include "playermenu.h"
#include "ball.h"
#include <QList>
#include <QMenu>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);

    void displayBattleMenu(Player *player);
    void displayMainMenu();
    void displayGameOverMenu();
    void addPlayer(QGraphicsEllipseItem *player);
    void nextPlayersTurn();

    void PlayerCreation();
    void placePlayer(Hex *hex);
    void returnPlayer();

    void addPlayer1Player(Player* player);
    void addPlayer2Player(Player* player);

    void setWhosTurn(QString Player);
    void setPlayerToPlace(Player* player);
    void setActivePlayer(Player* player);
    void setIsMenu(bool b);
    bool getIsMenu();
    Player* getPlayerToPlace();
    Player* getActivePlayer();
    QList<Player *> getPlayer1Characters();
    QList<Player *> getPlayer2Characters();
    QString getWhosTurn();

    //contextMenuEvent(QGraphicsSceneContextMenuEvent * event) Q_DECL_OVERRIDE;
    //void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

    QGraphicsScene* m_scene;
    HexBoard* hexboard;
    QPointF originalPos;
    PlayerMenu* m_menu;
    Ball* m_ball;
public slots:
    void startGame();
    void pickUpPlayer();
    void makePass();

private:

    void drawPanel(int x, int y, int width, int height, QColor color, double Opacity);
    void drawGUI();
    void startSetupMode();

    //QAction *exitAct;

    QString m_whosTurn;
    int numHexesChanged;
    QList<Player* > m_player1Characters;
    QList<Player* > m_player2Characters;
    int numPlayers;
    Player* playerToPlace;
    Player* activePlayer;
    bool isMenu;


};

#endif // GAME

