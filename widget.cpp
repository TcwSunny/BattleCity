#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), scene(new Scene(this))
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene->setSceneRect(0, 0, 600, 340);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(600, 340);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

Widget::~Widget()
{
    delete ui;
}

