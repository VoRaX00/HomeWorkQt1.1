#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()=="")
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
    double a,b,c;
    a = ui->lineEdit->text().toInt();
    b = ui->lineEdit_2->text().toInt();
    c = ui->lineEdit_3->text().toInt();
    double disc = qPow(b,2) - 4*a*c;
    if(disc>0 && a != 0)
    {
        double x1,x2;
        x1 = (-b + qSqrt(disc))/(2*a);
        x2 = (-b - qSqrt(disc))/(2*a);
        ui->lineEdit_4->setText(QString::number(x1));
        ui->lineEdit_5->setText(QString::number(x2));
    }
    else if(a == 0 && b!=0)
    {
        double x = (-c)/b;
        ui->lineEdit_4->setText(QString::number(x));
    }
    else if(disc<0)
    {
        //double x1,x2;
        int i = -1;
        QString x1 =QString::number(double(-b)/(2*a)) + "+"+QString::number(double(qSqrt(disc*i-1))/(2*a))+"i";
        QString x2 = QString::number(double(-b)/(2*a)) + "-"+QString::number(double(qSqrt(disc*i-1))/(2*a))+"i";
        ui->lineEdit_4->setText(x1);
        ui->lineEdit_5->setText(x2);
    }
    else if(disc == 0)
    {
        double x = (-b)/2*a;
        ui->lineEdit_4->setText(QString::number(x));
    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
