#include "widget.h"
#include <QPushButton>
//Teacher老师类
//Student学生类
//下课后 老师会触发一个 饿了 的信号
//学生响应这个信号 并且 请老师吃饭
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->zt = new Teacher(this);
    this->st = new Student(this);

    //连接信号和槽
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
//    void(Student::*studentSlot)(QString) = &Student::treat;
//    connect(zt,teacherSignal,st,studentSlot);
//    classIsOver();
    QPushButton *btn = new QPushButton("Class over",this);
    resize(600,400);
    void(Teacher::*teacherSignal2)() = &Teacher::hungry;
    void(Student::*studentSlot2)() = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);
//信号可连接信号
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);
//可断开信号和槽
    disconnect(zt,teacherSignal2,st,studentSlot2);
//一个信号可以响应多个槽函数
//多个信号可以连接同一个槽函数
//信号和槽函数的参数类型 必须一一对应
//信号的参数个数 可以多于槽函数的参数个数，反之不可以，参数类型要一一对应

    QPushButton *btn2 = new QPushButton("aaa", this);
    QPushButton *btn3 = new QPushButton("aaa", this);
    [=](){
        btn2->setText("bbb");
        btn3->setText("bbb");
    }();
    //最常用的lambda使用
    QPushButton *btn4 = new QPushButton("aaa", this);
    btn4->move(100,0);
    connect(btn4,&QPushButton::clicked,this,[&](){
        btn4->setText("bbb");
    });



}

void Widget::classIsOver()
{
    //出发自定义信号
    //emit this->zt->hungry();
}
Widget::~Widget()
{
}

