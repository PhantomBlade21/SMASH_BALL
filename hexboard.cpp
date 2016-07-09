#include "hexboard.h"
#include "game.h"
#include <QBrush>

extern Game * game;

HexBoard::HexBoard()
{
    numHexRows=0;
}

QList<Hex *> HexBoard::getHexColumns()
{
    return hexColumns;
}

QList<QList<Hex *> > HexBoard::getHexRows()
{
    return hexRows;
}

void HexBoard::placeHexes(int x, int y, int cols, int rows)
{

    float X_SHIFT = 1.5*15;
    float Y_SHIFT = 2.598071*15;
    bool isOdd = false;

    for (size_t i = 0, n = rows; i < n; i++)
    {
        int temp_Cols = cols;
        int tempRowNumber = i;
        isOdd = false;
        if (i % 2 == 0){ // even row
            X_SHIFT = 1.5*15;
        }
        else{ // odd row
            X_SHIFT = 0;
            isOdd=true;
        }
        numHexRows++;
        createHexRow(x+X_SHIFT,y+Y_SHIFT*i,temp_Cols,tempRowNumber,isOdd);
//        hexRows.append(hexColumns);
    }
}

void HexBoard::createHexRow(int x, int y, int numOfColumns, int tempRowNumber, bool isOdd)
{
    QList<Hex* > tempColumns;
    if(isOdd == true){
        for(size_t i=0,n=numOfColumns;i<n;i++)
        {
            if(i!=0){
                Hex* hex = new Hex();
                hex->setPos(x+(3*i*15),y);
                hex->setXPos(hex->pos().x()+22.5+1);
                hex->setYPos(hex->pos().y()+25.981+1);

//                std::cout<<"The center of hex X: " << hex->getXPos() << "\n" <<std::endl;
//                std::cout<<"The center of hex Y: " << hex->getYPos() << "\n" <<std::endl;

                hex->setColumnNumber(i-1);
                hex->setRowNumber(tempRowNumber);
                tempColumns.append(hex);
                //hexColumns.append(hex);
                hex->setZValue(0);
                game->m_scene->addItem(hex);
//                if(numHexRows>6 && numHexRows<12 && (i==1 || i==20)){
//                    hex->setGoalHexes();
//                    hex->setGoalHex();
//                }
                //hex->setGoalZone();
            }

        }
    }else{
        for(size_t i=0,n=numOfColumns;i<n;i++)
        {
            Hex* hex = new Hex();
            hex->setPos(x+(3*15*i),y);
            hex->setXPos(hex->pos().x()+(22.5+1));
            hex->setYPos(hex->pos().y()+(25.981+1));

//            std::cout<<"The center of hex X: " << hex->getXPos() << "\n" <<std::endl;
//            std::cout<<"The center of hex Y: " << hex->getYPos() << "\n" <<std::endl;

            hex->setColumnNumber(i);
            hex->setRowNumber(tempRowNumber);
            tempColumns.append(hex);
            //hexColumns.append(hex);
            hex->setZValue(0);
            game->m_scene->addItem(hex);
//            if(numHexRows>6 && numHexRows<12 && (i==0 || i==20)){
//                hex->setGoalHexes();
//                hex->setGoalHex();
//            }else if(numHexRows%2 == 1 && i==10){
//                hex->setMiddleHex();
//            }
            //hex->setGoalZone();
        }
    }

    hexRows.append(tempColumns);
}

void HexBoard::setZones()
{
    for(size_t i=0,n=hexRows.size();i<n;i++){
        QList<Hex *> tempColumns = hexRows[i];
        for(size_t j=0,m=tempColumns.size();j<m;j++){
            if((j==5) || (i%2==0 && j==15) || (i%2==1 && j==14) ){
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::yellow);
                tempColumns[j]->setBrush(brush);
                tempColumns[j]->setOriginalColor(brush.color());
            }else if((i%2)==0 && (j==10)){
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::blue);
                tempColumns[j]->setBrush(brush);
                tempColumns[j]->setOriginalColor(brush.color());
            }else if(i>5 && i<11 && (j==0)){
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::red);
                tempColumns[j]->setBrush(brush);
                tempColumns[j]->setOriginalColor(brush.color());
            }else if((i==6 || i==8 || i==10) && j==20){
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::red);
                tempColumns[j]->setBrush(brush);
                tempColumns[j]->setGoalHex();
                tempColumns[j]->setOriginalColor(brush.color());
            }else if((i==7 || i==9) && j==19){
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::red);
                tempColumns[j]->setBrush(brush);
                tempColumns[j]->setGoalHex();
                tempColumns[j]->setOriginalColor(brush.color());
            }else{
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(Qt::white);
                tempColumns[j]->setBrush(brush);
                tempColumns[j]->setOriginalColor(brush.color());

            }

            if(j<6){
                tempColumns[j]->setPlayer1Defense();
                tempColumns[j]->setPlayer2Offense();
            }else if(j>5 && ((i%2==0 && j<15) || (i%2==1 && j<14))){
                tempColumns[j]->setMidfield();
            }else if((1%2==0 && j>14) || (1%2==1 && j>13)){
                tempColumns[j]->setPlayer1Offense();
                tempColumns[j]->setPlayer2Defense();
            }
        }
    }
}

