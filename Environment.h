#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMetaObject>

class Environment:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enum MapType{mapBrick, mapWater, mapTree, mapCastle};

    Environment();
    void setMapState(MapType state);
    MapType getMapState();
    void setBrick();
    void setWater();
    void setTree();
    void setCastle();
private:
    MapType environmentState;
};

#endif // ENVIRONMENT_H
