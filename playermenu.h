#ifndef PLAYERMENU
#define PLAYERMENU

#include <QWidget>
#include "Player.h"

class PlayerMenu :public QWidget
{
public:

    PlayerMenu(Player* player, QWidget* parent=0);

protected:

    void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // PLAYERMENU

