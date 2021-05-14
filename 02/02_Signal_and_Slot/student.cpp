#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "Invite teacher to have lunch";
}

void Student::treat(QString foodName)
{
    qDebug() << "Invite teacher to have lunch, teacher wants " << foodName.toUtf8().data();

}
