#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //单选按钮 默认选中 男
    ui->rbtn_Man->setChecked(true);

    //点击女单选按钮 打印输出
    connect(ui->radioButton_2, &QRadioButton::clicked, [=](){
       qDebug() << "Choosed female";
    });
}

Widget::~Widget()
{
    delete ui;
}

