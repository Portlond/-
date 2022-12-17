#include "widgetlab7.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    this->resize(640,640);
    this->setFixedSize(640,640);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(600,600);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,500,500);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    MoveItem *item = new MoveItem();
    item->setPos(50,
                 50);
    scene->addItem(item);

}



