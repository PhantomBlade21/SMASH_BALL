#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T00:42:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Smash_Ball
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    hexboard.cpp \
    hex.cpp \
    BallGuard.cpp \
    Defender.cpp \
    Forward.cpp \
    GoalKeeper.cpp \
    Player.cpp \
    PointGuard.cpp \
    button.cpp \
    playermenu.cpp \
    ball.cpp

HEADERS  += \
    game.h \
    hexboard.h \
    hex.h \
    Forward.h \
    GoalKeeper.h \
    PointGuard.h \
    BallGuard.h \
    Defender.h \
    Player.h \
    button.h \
    playermenu.h \
    ball.h

FORMS    +=

RESOURCES += \
    myresources.qrc
