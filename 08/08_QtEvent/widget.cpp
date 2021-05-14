#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //开启定时器
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    //创建定时器对象
    QTimer * timer1 = new QTimer(this);
    timer1->start(500);
    static int num = 0;
    //每隔0.5s 会抛出一个信号
    connect(timer1, &QTimer::timeout, [=](){
        //每隔0.5s 让label_4数字++

        ui->label_4->setText(QString::number(num++));
    });

    //点击暂停按钮 停止定时器
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        timer1->stop();
    });
    //点击继续按钮 继续定时器
    connect(ui->pushButton_2, &QPushButton::clicked,[=](){
        timer1->start(500);
    });
    //点击复位按钮 重置定时器
    connect(ui->pushButton_3, &QPushButton::clicked,[=](){
        num = 0;
        ui->label_4->setText(QString::number(num++));
        timer1->stop();
    });

    //给label添加事件过滤器 做更高级的拦截操作
    //1、给控件安装过滤器
    ui->label->installEventFilter(this);

}

//重写过滤器事件
bool Widget::eventFilter(QObject* obj, QEvent* e){
    if(obj==ui->label){
        if(e->type()==QEvent::MouseButtonPress){
            QMouseEvent *ev = static_cast<QMouseEvent *>(e);
            QString str = QString("事件过滤器 鼠标按下了 x = %1 y = %2 ").arg(ev->x()).arg(ev->y());
            qDebug() << str;
        }
    }
    //其他事件抛给父类
    return QWidget::eventFilter(obj,e);
}

//添加定时器事件
void Widget::timerEvent(QTimerEvent* e){
    //每隔1s 让label_2数字++
    if(e->timerId() == id1){
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    //每隔2s 让label_3数字++
    if(e->timerId()==id2){
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }
}


Widget::~Widget()
{
    delete ui;
}

