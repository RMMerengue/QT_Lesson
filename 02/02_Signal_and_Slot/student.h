#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //自定义槽函数
    //需要声明 也需要有实现
    //可以有参数 可以发生重载
    void  treat();
    void  treat(QString foodName);
signals:




};

#endif // STUDENT_H