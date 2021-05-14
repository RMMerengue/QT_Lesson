#include "mypushbutton.h"
#include <QDebug>
mypushbutton::mypushbutton(QWidget *parent) : QPushButton(parent)
{

}
mypushbutton::~mypushbutton()
{
    qDebug()<< "mypushbutton's deconstructor";
}
