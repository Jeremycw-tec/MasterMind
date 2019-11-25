#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPdfWriter>
#include <QFile>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Mejores MM");
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//deshabilita el boton de maximizar
    this->setFixedSize(QSize(256, 422));//deshabilita el cambio de dimensiones
    QVector<QString> LND;
    QVector<QString> LNM;
    QVector<QString> LNF;
    QVector<QString> LTD;
    QVector<QString> LTM;
    QVector<QString> LTF;

    QFile file1(":/MasterMind2/guardar/dificil.txt");
    if (file1.open(QIODevice::ReadOnly))
    {

       int cont=1;
       int top=0;
       QTextStream in(&file1);
       while (!in.atEnd()||top==3)
       {
           if(cont==6){cont=1;}
           QString line = in.readLine();
           switch (cont) {
           case 1:
               LND.append(line);
               break;
           case 2:
               LTD.append(line);//Imprime tiempo
               break;
           case 5://Espaciado para mantener el formato y orden
               for (int i = 0; i < 8; ++i) {
                   if(i!=7){line = in.readLine();}
               }
               break;
           }
           top++;
           cont++;

       }
       file1.close();
    }

    QFile file2(":/MasterMind2/guardar/medio.txt");
    if (file2.open(QIODevice::ReadOnly))
    {
       int cont=1;
       int top=0;
       QTextStream in(&file2);
       while (!in.atEnd()||top==3)
       {
           if(cont==6){cont=1;}
           QString line = in.readLine();
           switch (cont) {
           case 1:
               LNM.append(line);
               break;
           case 2:
               LTM.append(line);//Imprime tiempo
               break;
           case 5://Espaciado para mantener el formato y orden
               for (int i = 0; i < 8; ++i) {
                   if(i!=7){line = in.readLine();}
               }
               break;
           }
           top++;
           cont++;

       }
       file2.close();
    }


    QFile file3(":/MasterMind2/guardar/facil.txt");
    if (file3.open(QIODevice::ReadOnly))
    {
       int cont=1;
       int top=0;
       QTextStream in(&file3);
       while (!in.atEnd()||top==3)
       {
           if(cont==6){cont=1;}
           QString line = in.readLine();
           switch (cont) {
           case 1:
               LNF.append(line);
               break;
           case 2:
               LTF.append(line);//Imprime tiempo
               break;
           case 5://Espaciado para mantener el formato y orden
               for (int i = 0; i < 8; ++i) {
                   if(i!=7){line = in.readLine();}
               }
               break;
           }
           top++;
           cont++;
       }
       file1.close();
    }
    //Cambio de labels

    for (int i = 0; i < LND.size(); ++i) {
        if(i==0){ui->label_Nombre1_1->setText(LND[i]);}
        if(i==1){ui->label_Nombre1_2->setText(LND[i]);}
        if(i==2){ui->label_Nombre1_3->setText(LND[i]);}
    }
    for (int i = 0; i < LNM.size(); ++i) {
        if(i==0){ui->label_Nombre2_1->setText(LNM[i]);}
        if(i==1){ui->label_Nombre2_2->setText(LNM[i]);}
        if(i==2){ui->label_Nombre2_3->setText(LNM[i]);}
    }
    for (int i = 0; i < LNF.size(); ++i) {
        if(i==0){ui->label_Nombre3_1->setText(LNF[i]);}
        if(i==1){ui->label_Nombre3_2->setText(LNF[i]);}
        if(i==2){ui->label_Nombre3_3->setText(LNF[i]);}
    }
    for (int i = 0; i < LTD.size(); ++i) {
        if(i==0){ui->label_Tiempo1_1->setText(LTD[i]);}
        if(i==1){ui->label_Tiempo1_2->setText(LTD[i]);}
        if(i==2){ui->label_Tiempo1_3->setText(LTD[i]);}
    }
    for (int i = 0; i < LTM.size(); ++i) {
        if(i==0){ui->label_Tiempo2_1->setText(LTM[i]);}
        if(i==1){ui->label_Tiempo2_2->setText(LTM[i]);}
        if(i==2){ui->label_Tiempo2_3->setText(LTM[i]);}
    }
    for (int i = 0; i < LTF.size(); ++i) {
        if(i==0){ui->label_Tiempo3_1->setText(LTF[i]);}
        if(i==1){ui->label_Tiempo3_2->setText(LTF[i]);}
        if(i==2){ui->label_Tiempo3_3->setText(LTF[i]);}
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked(){
    QPdfWriter pdf("Records.pdf");
    QPainter painter(&pdf);

    painter.setPen(Qt::black);
    painter.drawText(100,0,"RECORDS: NIVEL DIFÍCIL");
    painter.drawText(500,200,"JUGADOR");
    painter.drawText(1500,200,"TIEMPO");
    painter.drawText(2500,200,"COMBINACIÓN");
    painter.drawText(3500,200,"FECHA/HORA DEL JUEGO");
    painter.drawText(5500,200,"T/J");
    int salto=400;
    QFile file1(":/MasterMind2/guardar/dificil.txt");
    if (file1.open(QIODevice::ReadOnly))
    {
       int cont=1;
       int num=1;
       QTextStream in(&file1);
       while (!in.atEnd())
       {
           if(cont==6){cont=1;salto=salto+200;}
           QString line = in.readLine();
           switch (cont) {
           case 1:
               painter.drawText(250,salto,QString::number(num)+" - ");
               painter.drawText(500,salto,line);
               num++;
               break;
           case 2:
               painter.drawText(1500,salto,line);
               break;
           case 3:
               painter.drawText(2500,salto,line);
               break;
           case 4:
               painter.drawText(3500,salto,line);
               break;
           case 5:
               for (int i = 0; i < 8; ++i) {
                   if(line!=" "){ painter.drawText(5500,salto,line);salto=salto+200;}
                   if(i!=7){line = in.readLine();}
               }
               break;
           }
           cont++;

       }
       file1.close();
    }


    salto=salto+500;
    painter.setPen(Qt::black);
    painter.drawText(100,salto,"RECORDS: NIVEL MEDIO");
    salto=salto+200;
    painter.drawText(500,salto,"JUGADOR");
    painter.drawText(1500,salto,"TIEMPO");
    painter.drawText(2500,salto,"COMBINACIÓN");
    painter.drawText(3500,salto,"FECHA/HORA DEL JUEGO");
    painter.drawText(5500,salto,"T/J");
    salto=salto+200;

    QFile file2(":/MasterMind2/guardar/medio.txt");
    if (file2.open(QIODevice::ReadOnly))
    {
       int cont=1;
       int num=1;
       QTextStream in(&file2);
       while (!in.atEnd())
       {
           if(cont==6){cont=1;salto=salto+200;}
           QString line = in.readLine();
           switch (cont) {
           case 1:
               painter.drawText(250,salto,QString::number(num)+" - ");
               painter.drawText(500,salto,line);
               num++;
               break;
           case 2:
               painter.drawText(1500,salto,line);
               break;
           case 3:
               painter.drawText(2500,salto,line);
               break;
           case 4:
               painter.drawText(3500,salto,line);
               break;
           case 5:
               for (int i = 0; i < 8; ++i) {
                   if(line!=" "){ painter.drawText(5500,salto,line);salto=salto+200;}
                   if(i!=7){line = in.readLine();}
               }
               break;
           }
           cont++;
       }
       file2.close();
    }
    salto=salto+500;
    painter.setPen(Qt::black);
    painter.drawText(100,salto,"RECORDS: NIVEL FACIL");
    salto=salto+200;
    painter.drawText(500,salto,"JUGADOR");
    painter.drawText(1500,salto,"TIEMPO");
    painter.drawText(2500,salto,"COMBINACIÓN");
    painter.drawText(3500,salto,"FECHA/HORA DEL JUEGO");
    painter.drawText(5500,salto,"T/J");
    salto=salto+200;

    QFile file3(":/MasterMind2/guardar/facil.txt");
    if (file3.open(QIODevice::ReadOnly))
    {
       int cont=1;
       int num=1;
       QTextStream in(&file3);
       while (!in.atEnd())
       {
           if(cont==6){cont=1;salto=salto+200;}
           QString line = in.readLine();
           switch (cont) {
           case 1:
               painter.drawText(250,salto,QString::number(num)+" - ");
               painter.drawText(500,salto,line);
               num++;
               break;
           case 2:
               painter.drawText(1500,salto,line);
               break;
           case 3:
               painter.drawText(2500,salto,line);
               break;
           case 4:
               painter.drawText(3500,salto,line);
               break;
           case 5:
               for (int i = 0; i < 8; ++i) {
                   if(line!=" "){ painter.drawText(5500,salto,line);salto=salto+200;}
                   if(i!=7){line = in.readLine();}
               }
               break;
           }
           cont++;
       }
       file3.close();
    } 
}
