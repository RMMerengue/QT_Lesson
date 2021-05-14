#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionNew, &QAction::triggered, this,[=](){
        //对话框分类 模态对话框
        //模态对话框 不可以对其他窗口进行操作
        //非模态对话框 可以对其他窗口进行操作

        //模态对话框创建
        QDialog dlg(this);
        dlg.resize(120,30);

        dlg.exec();

        //非模态对话框创建
        QDialog * dlg2 = new QDialog(this);
        dlg2->resize(120,30);
        dlg2->show();
        //设置55号属性
        dlg2->setAttribute(Qt::WA_DeleteOnClose);

        //QMessageBox对话框
        //错误对话框
        QMessageBox::critical(this,"Error","Critical");
        //信息提示对话框
        QMessageBox::information(this, "Info", "info");
        //询问提示对话框
        if(QMessageBox::Save == QMessageBox::question(this,"Query","Question",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);){
            qDebug() << "Save";
        }else{
            qDebug() << "Cancel";
        }
        //警告提示对话框
        QMessageBox::warning(this, "Warning", "WARNING!");
        //颜色对话框
        QColor color = QColorDialog::getColor(Qt::red);
        qDebug() << color.red() << color.green() << color.blue();
        //文件对话框
//        QString fileName = QFileDialog::getOpenFileName(this, "Open File",PATH,"*.doc");
//        qDebug() << fileName;
        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("华文彩云",36));
        qDebug() << "Font" << font.family()
                 << "PointSize" << font.pointSize()
                 << "isBold" << font.bold()
                 << "isItalic" << font.italic();



    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

