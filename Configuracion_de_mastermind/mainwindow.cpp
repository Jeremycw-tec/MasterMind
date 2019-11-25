#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Qdebug>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <tiempo.h>

using namespace std;

//valor inicial
config configuracion;
Tiempo reloj;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//deshabilita el boton de maximizar
    this->setFixedSize(QSize(653, 406));//deshabilita el cambio de dimensiones
    this->setWindowTitle("Configuracion de MasterMind");

    ui->horas->setEnabled(false);
    ui->minutos->setEnabled(false);
    ui->segundos->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Opciones del cronometro------------------------------------------------------
void MainWindow::on_rsi_clicked()//Valor 1
{


    ui->horas->setEnabled(false);
    ui->horas->setValue(0);

    ui->minutos->setEnabled(false);
    ui->minutos->setValue(0);

    ui->segundos->setEnabled(false);
    ui->segundos->setValue(0);

    configuracion.c_reloj(1);
}

void MainWindow::on_rno_clicked()//Valor 2
{


    ui->horas->setEnabled(false);
    ui->horas->setValue(0);

    ui->minutos->setEnabled(false);
    ui->minutos->setValue(0);

    ui->segundos->setEnabled(false);
    ui->segundos->setValue(0);

    configuracion.c_reloj(2);
}

void MainWindow::on_cpjugada_clicked()//Valor 3
{


    ui->horas->setEnabled(true);
    ui->minutos->setEnabled(true);
    ui->segundos->setEnabled(true);

    configuracion.c_reloj(3);
}

void MainWindow::on_cpjuego_clicked()//Valor 4
{


    ui->horas->setEnabled(true);
    ui->minutos->setEnabled(true);
    ui->segundos->setEnabled(true);

    configuracion.c_reloj(4);
}


void MainWindow::on_horas_valueChanged(int arg1)
{
    if (arg1>2){
        ui->horas->setValue(2);
    }
    reloj.ch(arg1);
}

void MainWindow::on_minutos_valueChanged(int arg1)
{
    if (arg1>59){
        ui->minutos->setValue(59);
    }
    reloj.cm(arg1);
}

void MainWindow::on_segundos_valueChanged(int arg1)
{
    if (arg1>59){
        ui->segundos->setValue(59);
    }
    reloj.cs(arg1);
}


//Opcion de la dificultad--------------------------------------------------
void MainWindow::on_dificultadop1_clicked()//1
{
    configuracion.c_dificultad(1);
}

void MainWindow::on_dificultadop2_clicked()//2
{
    configuracion.c_dificultad(2);
}

void MainWindow::on_dificultadop3_clicked()//3
{
    configuracion.c_dificultad(3);
}

//Opcion de repeticion

void MainWindow::on_repsi_clicked()//1
{
    configuracion.c_repeticion(1);
}

void MainWindow::on_repno_clicked()//2
{
    configuracion.c_repeticion(2);
}

//Opcion del elemento

void MainWindow::on_elementocolor_clicked()//1
{
    configuracion.c_elemento(1);
}

void MainWindow::on_elementoletra_clicked()//2
{
    configuracion.c_elemento(2);
}

void MainWindow::on_elementonumero_clicked()//3
{
    configuracion.c_elemento(3);
}

void MainWindow::on_elementodefinido_clicked()//4
{
    configuracion.c_elemento(4);
}


void MainWindow::on_guardar_clicked()
{
    QFile archivo("configuracion.txt");

    QString dificultad = QString::number(configuracion.g_dificultad());
    QString reloj=QString::number(configuracion.g_reloj());
    QString repeticion=QString::number(configuracion.g_repeticion());
    QString elementos=QString::number(configuracion.g_elemento());
    QString hor= QString::number(ui->horas->value());
    QString min= QString::number(ui->minutos->value());
    QString seg= QString::number(ui->segundos->value());

    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        datosArchivo << dificultad<<reloj<<repeticion<<elementos<<endl;
        datosArchivo<<hor<<endl;
        datosArchivo<<min<<endl;
        datosArchivo<<seg;

    }
    archivo.close();
    this->close();

}
