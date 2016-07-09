#include "playermenu.h"
#include "game.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>

extern Game* game;

PlayerMenu::PlayerMenu(Player* player, QWidget *parent) : QWidget(parent)
{
    if(player->pos().y()+250 > 768){
        setGeometry(player->pos().x()-100,player->pos().y()-250,100,250);
    }else{
        setGeometry(player->pos().x()+30,player->pos().y(),100,250);

    }

    QPushButton *button1 = new QPushButton("Dribble");
    QPushButton *button2 = new QPushButton("Pass");
    QPushButton *button3 = new QPushButton("Shoot");
    //        QPushButton *button4 = new QPushButton("");
    //        QPushButton *button5 = new QPushButton("Five");

    button1->setFixedHeight(50);
    button1->setFixedWidth(85);
    button2->setFixedHeight(50);
    button2->setFixedWidth(85);
    button3->setFixedHeight(50);
    button3->setFixedWidth(85);

//    button1->animateClick(100);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    //        layout->addWidget(button4);
    //        layout->addWidget(button5);

    setLayout(layout);

    connect(button1, SIGNAL(clicked()), game,SLOT(pickUpPlayer()));
    connect(button2, SIGNAL(clicked()), game, SLOT(makePass()));
}

void PlayerMenu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    pen.setColor(Qt::black);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setOpacity(.90);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRoundedRect(0,0,100,250,10,10);

    QWidget::paintEvent(event);
}

void PlayerMenu::mouseMoveEvent(QMouseEvent *event)
{

}
