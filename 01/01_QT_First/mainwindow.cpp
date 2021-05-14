#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "mypushbutton.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton;
//    btn->show();
    btn->setParent(this);
    btn->setText("Hello_QT!");
    QPushButton *btn2 = new QPushButton("Second", this);
    btn2->move(100, 100);
    btn->resize(100,30);
    btn2->resize(60,30);

    setWindowTitle("First_Window");
    setFixedSize(600, 400);

    mypushbutton * myBtn = new mypushbutton;
    myBtn->setParent(this);
    myBtn->setText("MyButton");
    myBtn->move(300,200);
    myBtn->resize(100,30);

    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);


}

MainWindow::~MainWindow()
{
    delete ui;
}

