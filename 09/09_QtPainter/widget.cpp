#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击移动按钮 让图片移动
    posX = 0;
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        posX += 20;
        //手动调用绘图事件
        update();
    });

}

//绘图事件
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);

    if(posX>this->width()){
        posX = 0;
    }
    //设置画笔
    QPen pen(QColor(255,0,0));
    //设置画笔宽度
    pen.setWidth(3);
    //设置风格
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);

    //画刷
    QBrush brush(Qt::green);
    painter.setBrush(brush);

    //画线
    painter.drawLine(QPoint(0,0),QPoint(100,100));

    //画椭圆
    painter.drawEllipse(QPoint(100,100), 100, 50);

    //画矩形
    painter.drawRect(QRect(20,20,50,50));

    //写字
    painter.drawText(QRect(10,100,200,200),"Hello_World!");




}

Widget::~Widget()
{
    delete ui;
}

