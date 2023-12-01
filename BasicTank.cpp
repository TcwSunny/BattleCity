#include "BasicTank.h"
#include <QRandomGenerator>
#include <Qtimer>

BasicTank::BasicTank()
{
    QPixmap pixmap(":/images/Images/Tank_Enemy1.png");
    pixmap = pixmap.scaled(QSize(32, 32));
    setPixmap(pixmap);

    setRotation(0);
    isChangingDirection = false;

    timer = new QTimer(this);//跟著Bullet Delete掉
    connect(timer, &QTimer::timeout, this, &BasicTank::move);//當發生time out時使用這個物件的move處理
    timer->start(100); // fires every 50ms
}

void BasicTank::move()
{
    if (x() >= 10 && x() <= 458 && y() >= 10 && y() <= 298){
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
            Rotate(newRotation);
            qDebug() << getRotation();
        }
    }
    isChangingDirection = false;
}



