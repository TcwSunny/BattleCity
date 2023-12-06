#include "FastTank.h"
#include <QRandomGenerator>
#include <Qtimer>
#include "Brick.h"
#include "Water.h"
#include <QGraphicsScene>

FastTank::FastTank()
{
    QPixmap pixmap(":/images/Images/Tank_Enemy2.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

    setRotation(0);
    isChangingDirection = false;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FastTank::move);//當發生time out時使用這個物件的move處理
    timer->start(50);

}



void FastTank::move()
{
    if (x() >= 10 && x() <= 458 && y() >= 10 && y() <= 298){
        // Check for collisions with bricks
        QList<QGraphicsItem *> collidingItemsList = collidingItems();
        foreach(QGraphicsItem* item, collidingItemsList) {
            if (dynamic_cast<Brick*>(item) or dynamic_cast<Water*>(item)) {
                // Collided with a brick, change direction

                if(getRotation()==0 or getRotation()==360){
                    setPos(x(), y() + 4);
                } else if (getRotation() == 90) {
                    setPos(x() - 4, y()); // 向右移動 4 個單位
                } else if (getRotation() == 180) {
                    setPos(x(), y() - 4); // 向下移動 4 個單位
                } else if (getRotation() == 270) {
                    setPos(x() + 4, y()); // 向左移動 4 個單位
                }
                int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
                while(newRotation == getRotation()){ //改善tank重複撞牆的窘境
                    newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
                }
                Rotate(newRotation);
                return;
            }
        }
        int probToRotate = QRandomGenerator::global()->bounded(0, 50) ;
        if(probToRotate == 1){ //讓basicTank有隨機轉彎的機會
            int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            Rotate(newRotation);
        }
        if (getRotation() == 0 or getRotation() == 360) {
            setPos(x(), y() - 4); // 向上移動 4 個單位
        } else if (getRotation() == 90) {
            setPos(x() + 4, y()); // 向右移動 4 個單位
        } else if (getRotation() == 180) {
            setPos(x(), y() + 4); // 向下移動 4 個單位
        } else if (getRotation() == 270) {
            setPos(x() - 4, y()); // 向左移動 4 個單位
        }
    } else {
        qDebug()<<isChangingDirection;
        if (x() < 10){
            setPos(10,y());
        }else if (x() > 458){
            setPos(458,y());
        }else if(y() < 10){
            setPos(x(),10);
        }else if(y() > 298){
            setPos(x(),298);
        }
        if (!isChangingDirection) {
            isChangingDirection = true;
            int newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            while(newRotation == getRotation()){ //改善tank重複撞牆的窘境
                newRotation = QRandomGenerator::global()->bounded(0, 4) * 90;
            }
             Rotate(newRotation);
        }
    }
    isChangingDirection = false;
}
