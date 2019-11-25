//Librerias
#include <QFileDialog>
#include <QMediaPlayer>
#include <QFileInfo>//Esta biblioteca permite obtener informacion sobre los archivos que
                    //abriremos, como por ejemplo su ruta absoluta o relativa.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <cstdlib>
#include "Tiempo.h"
#include <windows.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "config.h"
#include <vector>
#include <QTimer>
#include <QDateTime>
#include <QApplication>
#include <QProcess>

#include <QMessageBox>

using namespace std;

//Algunas varibles iniciales
struct records{
    QString nombre;
    QString tj;
    QString combinacion;
    QString fecha;
    QString t1;
    QString t2;
    QString t3;
    QString t4;
    QString t5;
    QString t6;
    QString t7;
    QString t8;
};

struct jugadas{
    int b1;
    int b2;
    int b3;
    int b4;
};

int cambio=1;//cambio de la imagen de win o lose
int cargando=0;//detiene el tiempo mientras la partida carga o al inicio del juego
int saved=0;//si se guardo en la misma partida

//datos de saved==1
vector <jugadas>jugadasg;
vector <jugadas>calificaciong;
vector <Tiempo>tperjug2;//tiempo por jugada
int rg;
int r2g;
int contc1g=0;
int contc2g=0;
int contc3g=0;
int contc4g=0;

//datos guardados al ganar la partida
vector <Tiempo> tperjug;//tiempo por jugada
QString fecha;

//terminar juego
int terminar;

//Verifica si ha ganado el juego
int win=0;

//configuracion
config configuracion;

//vector para deshacer jugada

vector <jugadas> jug;//cada jugada especificamente (deshacer jugada)
vector <jugadas> jugfilas;//jugadas por fila
vector <jugadas> calificacion;//calificacion por fila

//verificadores para el boton de hacer jugada
int verif1=0;
int verif2=0;
int verif3=0;
int verif4=0;

//Organizacion de la calificacion
int cal[4];
int cal2[4];
int cal3[4];
int cal4[4];
int cal5[4];
int cal6[4];
int cal7[4];
int cal8[4];

int comb[4];//combinacion aleatoria

//Contadores para los botones
int filas=0;//contador para las filas ocultas
int contc1=0; //Boton 1
int contc2=0; //Boton 2
int contc3=0; //Boton 3
int contc4=0; //Boton 4
int resty=50; //Movimiento en las coordenadas

//Tiempo------------------------------------------------------------------------------
Tiempo r; //r = reloj
Tiempo r2;//para cronometro por jugada
Tiempo r3;//para guardar tiempo por jugada

void MainWindow::funcionActivacionTimer(){
    if (cargando==1){
        return;
    }
    if(r.tiempotot()==0 || win==1){//si el tiempo se acaba o el jugador gana

        //Perdida con cronometro por juego---------------------------------------
        if((configuracion.g_reloj()==4) & (win==0)){
            if(cambio==1){
                ui->winlose->setIcon(QIcon(":/juegoloseblack.png"));
                cambio=2;
                return;
            }
            if (cambio==2){
                ui->winlose->setIcon(QIcon(":/juegolosered.png"));
                cambio=1;
                return;
            }
        }
        //Perdida con cronometro por jugada-----------------------------------
        if ((configuracion.g_reloj()==3) & (win==0)){
            if(cambio==1){
                ui->winlose->setIcon(QIcon(":/jugadaloseblack.png"));
                cambio=2;
                return;
            }
            if (cambio==2){
                ui->winlose->setIcon(QIcon(":/jugadalosered.png"));
                cambio=1;
                return;
            }
        }

        //SI HA GANADO EL JUEGO-----------------------------------------
        if (cambio==1){
            ui->winlose->setIcon(QIcon(":/winblack.png"));
            cambio=2;
            return;
        }
        if (cambio==2){
            ui->winlose->setIcon(QIcon(":/wingreen.png"));
            cambio=1;
            return;
        }

    }

    //si termina el juego
    if ((configuracion.g_dificultad()==1) & (filas==8)){
        return;
    }
    if ((configuracion.g_dificultad()==2) & (filas==7)){
        return;
    }
    if ((configuracion.g_dificultad()==3) & (filas==6)){
        return;
    }

    //--------------------------------------------------------
    if (configuracion.g_reloj()==1){
        r.temporarizador();
    }
    if (configuracion.g_reloj()==3 || configuracion.g_reloj()==4 ){
        r.cronometro();
    }

    ui->hor->display(r.mh());
    ui->min->display(r.mm());
    ui->seg->display(r.ms());

    r3.temporarizador();//tiempo por jugada
}

void MainWindow::funcionActivacionTimer2(){
    if (cargando==1){
        return;
    }
    if(win==1){//SI EL JUGADOR GANA

        if (cambio==1){
            ui->winlose->setIcon(QIcon(":/winblack.png"));
            cambio=2;
            return;
        }
        if (cambio==2){
            ui->winlose->setIcon(QIcon(":/wingreen.png"));
            cambio=1;
            return;
        }
    }
    //si termina el juego----------------------------------
    if ((configuracion.g_dificultad()==1) & (filas==8)){
        return;
    }
    if ((configuracion.g_dificultad()==2) & (filas==7)){
        return;
    }
    if ((configuracion.g_dificultad()==3) & (filas==6)){
        return;
    }
    //-----------------------------------------------------
    r.temporarizador();
    r3.temporarizador();
    ui->hor->display(r.mh());
    ui->min->display(r.mm());
    ui->seg->display(r.ms());

}

void MainWindow::funcionActivacionTimer3(){
    if (cargando==1){
        return;
    }
    if(r.tiempotot()==0 || win==1){//si el tiempo se acaba o el jugador gana

        //Perdida con cronometro por juego---------------------------------------
        if((configuracion.g_reloj()==4) && (win==0)){
            ui->guardar->setEnabled(false);
            ui->cargar->setEnabled(false);
            ui->winlose->setVisible(true);
            ui->boton1->setVisible(false);
            ui->boton2->setVisible(false);
            ui->boton3->setVisible(false);
            ui->boton4->setVisible(false);
            ui->ver1->setVisible(false);
            ui->ver2->setVisible(false);
            ui->ver3->setVisible(false);
            ui->ver4->setVisible(false);
            ui->boton1->setEnabled(false);
            ui->boton2->setEnabled(false);
            ui->boton3->setEnabled(false);
            ui->boton4->setEnabled(false);
            ui->jugada->setEnabled(false);
            if(cambio==1){
                ui->winlose->setIcon(QIcon(":/juegoloseblack.png"));
                cambio=2;
                return;
            }
            if (cambio==2){
                ui->winlose->setIcon(QIcon(":/juegolosered.png"));
                cambio=1;
                return;
            }
        }

        //Perdida con cronometro por jugada-----------------------------------
        if ((configuracion.g_reloj()==3) && (win==0)){
            ui->guardar->setEnabled(false);
            ui->cargar->setEnabled(false);
            ui->winlose->setVisible(true);
            ui->boton1->setVisible(false);
            ui->boton2->setVisible(false);
            ui->boton3->setVisible(false);
            ui->boton4->setVisible(false);
            ui->ver1->setVisible(false);
            ui->ver2->setVisible(false);
            ui->ver3->setVisible(false);
            ui->ver4->setVisible(false);
            ui->boton1->setEnabled(false);
            ui->boton2->setEnabled(false);
            ui->boton3->setEnabled(false);
            ui->boton4->setEnabled(false);
            ui->jugada->setEnabled(false);
            if(cambio==1){
                ui->winlose->setIcon(QIcon(":/jugadaloseblack.png"));
                cambio=2;
                return;
            }
            if (cambio==2){
                ui->winlose->setIcon(QIcon(":/jugadalosered.png"));
                cambio=1;
                return;
            }
        }

        //SI HA GANADO EL JUEGO-----------------------------------------
        if (cambio==1 && win==1){
            ui->guardar->setEnabled(false);
            ui->cargar->setEnabled(false);
            ui->winlose->setVisible(true);
            ui->boton1->setVisible(false);
            ui->boton2->setVisible(false);
            ui->boton3->setVisible(false);
            ui->boton4->setVisible(false);
            ui->ver1->setVisible(false);
            ui->ver2->setVisible(false);
            ui->ver3->setVisible(false);
            ui->ver4->setVisible(false);
            ui->boton1->setEnabled(false);
            ui->boton2->setEnabled(false);
            ui->boton3->setEnabled(false);
            ui->boton4->setEnabled(false);
            ui->jugada->setEnabled(false);
            ui->winlose->setIcon(QIcon(":/winblack.png"));
            cambio=2;
            return;
        }
        if (cambio==2 && win==1){
            ui->guardar->setEnabled(false);
            ui->cargar->setEnabled(false);
            ui->winlose->setVisible(true);
            ui->boton1->setVisible(false);
            ui->boton2->setVisible(false);
            ui->boton3->setVisible(false);
            ui->boton4->setVisible(false);
            ui->ver1->setVisible(false);
            ui->ver2->setVisible(false);
            ui->ver3->setVisible(false);
            ui->ver4->setVisible(false);
            ui->boton1->setEnabled(false);
            ui->boton2->setEnabled(false);
            ui->boton3->setEnabled(false);
            ui->boton4->setEnabled(false);
            ui->jugada->setEnabled(false);
            ui->winlose->setIcon(QIcon(":/wingreen.png"));
            cambio=1;
            return;
        }
    }

    //si termina el juego----------------------------------
    if ((configuracion.g_dificultad()==1) & (filas==8)){
        return;
    }

    if ((configuracion.g_dificultad()==2) & (filas==7)){
        return;
    }

    if ((configuracion.g_dificultad()==3) & (filas==6)){
        return;
    }

    //-----------------------------------------------------
    if (configuracion.g_reloj()==1){
        qDebug()<<"entro"<<endl;
        r.temporarizador();
        r3.temporarizador();
        ui->hor->display(r.mh());
        ui->min->display(r.mm());
        ui->seg->display(r.ms());

    }

    if (configuracion.g_reloj()==3 || configuracion.g_reloj()==4 ){
        r.cronometro();
        r3.temporarizador();
        ui->hor->display(r.mh());
        ui->min->display(r.mm());
        ui->seg->display(r.ms());

    }

}
//Funciones--------------------------------------------------------------------------------
void datoaleatorio(int com[4]){
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        com[i] = rand() % 6;
    }
    return;
}

int verif(int n,int com[4]) { //Verifica si un numero se encuenta en el arreglo

    for (int i=0; i < 4; i++) {
        if (n == com[i]) {
            return 1;
        }
    }
    return 0;
}

void datoaleatoriosinrepeticion(int comb[4]){
    int i = 0;
    while (i < 4) {
        srand(time(NULL));
        int alea = rand() % 6;

        if(verif(alea,comb)==0){
            comb[i] = alea;
            i++;
        }
        continue;
    }

}

void calif(int com[4]) //Crea la organizacion aleatoria de la calificacion
{
    int i = 0;
    while (i < 4) {
        srand(time(NULL));
        int alea = 1+ rand() % 4;

        if(verif(alea,com)==0){
            com[i] = alea;
            i++;
        }
        continue;
    }
    return;
}

void fourdigits(int d, vector <jugadas>& j){ // divide un numero entero en cuatro digitos
    int digitos =d;
    jugadas jugada;

    jugada.b1=digitos/1000;
    digitos=digitos%1000;

    jugada.b2=digitos/100;
    digitos=digitos%100;

    jugada.b3=digitos/10;
    digitos=digitos%10;

    jugada.b4=digitos;

    j.push_back(jugada);
    return;
}

void llenarecord(records& winner){//v= veces, llena los tiempos por jugada del objeto tipo records
    for (int i=0;i<8;i++){

        if (i==0){
            if(i>(tperjug.size()-1)){
                winner.t1=" ";
                qDebug()<<"no"<<endl;
                continue;
            }
            winner.t1 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //------------------------------------------------------
        if (i==1){
            if(i>(tperjug.size()-1)){
                winner.t2=" ";
                continue;
            }
            winner.t2 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //--------------------------------------------------
        if (i==2){
            if(i>(tperjug.size()-1)){
                winner.t3=" ";
                continue;
            }
            winner.t3 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //----------------------------------------------
        if (i==3){
            if(i>(tperjug.size()-1)){
                winner.t4=" ";
                continue;
            }
            winner.t4 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //----------------------------------------
        if (i==4){
            if(i>(tperjug.size()-1)){
                winner.t5=" ";
                continue;
            }
            winner.t5 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //------------------------------------------
        if (i==5){
            if(i>(tperjug.size()-1)){
                winner.t6=" ";
                continue;
            }
            winner.t6 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //-------------------------------------------
        if (i==6){
            if(i>(tperjug.size()-1)){
                winner.t7=" ";
                continue;
            }
            winner.t7 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }

        //-------------------------------------
        if (i==7){
            if(i>(tperjug.size()-1)){
                winner.t8=" ";
                continue;
            }
            winner.t8 = QString::number(tperjug.at(i).mh()) + ":" + QString::number(tperjug.at(i).mm()) + ":" + QString::number(tperjug.at(i).ms());
            continue;
        }
    }
}

void escribirfacil(vector<records> r, int dif){
    if (dif==1){
        QFile facil("facil.txt");
        if(facil.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datos(&facil);

            for (int i=0;i<r.size();i++){
                datos << r.at(i).nombre << endl;
                datos << r.at(i).tj << endl;
                datos << r.at(i).combinacion << endl;
                datos << r.at(i).fecha << endl;
                datos << r.at(i).t1 << endl;
                datos << r.at(i).t2 << endl;
                datos << r.at(i).t3 << endl;
                datos << r.at(i).t4 << endl;
                datos << r.at(i).t5 << endl;
                datos << r.at(i).t6 << endl;
                datos << r.at(i).t7 << endl;
                datos << r.at(i).t8 << endl;
            }

        }
        facil.close();
    }

    if (dif==2){
        QFile medio("medio.txt");
        if(medio.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datos(&medio);

            for (int i=0;i<r.size();i++){
                datos << r.at(i).nombre << endl;
                datos << r.at(i).tj << endl;
                datos << r.at(i).combinacion << endl;
                datos << r.at(i).fecha << endl;
                datos << r.at(i).t1 << endl;
                datos << r.at(i).t2 << endl;
                datos << r.at(i).t3 << endl;
                datos << r.at(i).t4 << endl;
                datos << r.at(i).t5 << endl;
                datos << r.at(i).t6 << endl;
                datos << r.at(i).t7 << endl;
                datos << r.at(i).t8 << endl;
            }

        }
        medio.close();
    }

    if (dif==3){
        QFile dificil("dificil.txt");
        if(dificil.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream datos(&dificil);

            for (int i=0;i<r.size();i++){
                datos << r.at(i).nombre << endl;
                datos << r.at(i).tj << endl;
                datos << r.at(i).combinacion << endl;
                datos << r.at(i).fecha << endl;
                datos << r.at(i).t1 << endl;
                datos << r.at(i).t2 << endl;
                datos << r.at(i).t3 << endl;
                datos << r.at(i).t4 << endl;
                datos << r.at(i).t5 << endl;
                datos << r.at(i).t6 << endl;
                datos << r.at(i).t7 << endl;
                datos << r.at(i).t8 << endl;
            }

        }
        dificil.close();
    }
    return;
}

int stringtotime(QString t){

    Tiempo sec;
    int hms=0;
    QString h="";
    QString m="";
    QString s="";

    for (int i=0;i<t.size();i++){

        if (t[i]==":"){
            hms++;
            continue;
        }
        if(hms==0){
            h=h+t[i];
        }
        if(hms==1){
            m=m+t[i];
        }
        if(hms==2){
            s=s+t[i];
        }
    }

    int hor=h.toInt();
    int min=m.toInt();
    int seg=s.toInt();
    qDebug()<<h<<endl;
    qDebug()<<m<<endl;
    qDebug()<<s<<endl;

    sec.ch(hor);
    sec.cm(min);
    sec.cs(seg);

    qDebug()<<sec.tiempotot()<<endl;
    return sec.tiempotot();
}
//---------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MasterMind");
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//deshabilita el boton de maximizar
    this->setFixedSize(QSize(631, 639));//deshabilita el cambio de dimensiones

    reproductor = new QMediaPlayer(this); //Genera el objeto del reproductor en la ventana actual.

    //toma de elementos---------------------------------------------------------------------
    QFile conf(":/configuracion/configuracion.txt");   //abre el archivo de configuracion
    int datos;//Datos de la configuracion

    if(conf.open(QIODevice::ReadOnly)){

        int contador=0;
        //Toma de datos para la configuracion----------------------------
        QTextStream contenido(&conf);
        QString line=contenido.readLine();//lee la primera linea en la configuracion

        datos=line.toInt();//toInt() pasa de QString a int


        qDebug()<<"se abrio";
        qDebug()<<line;//muestra los datos tomados en str
        qDebug()<<datos;// muestra los datos en int

        //Toma de valores para el reloj-----------------------------
        while(!contenido.atEnd())
        {
            QString line = contenido.readLine();//iterador
            if (contador==0){
                r.ch(line.toInt());
                r2.ch(line.toInt());//r2 es auxiliar
            }
            if (contador==1){
                r.cm(line.toInt());
                r2.cm(line.toInt());
            }
            if (contador==2){
                r.cs(line.toInt());
                r2.cs(line.toInt());
            }
            contador++;
            qDebug() << line;
        }
        qDebug()<<r.mh();
        qDebug()<<r.mm();
        qDebug()<<r.ms();
    }


    configuracion.c_config(datos);
    qDebug()<<configuracion.g_dificultad();
    qDebug()<<configuracion.g_reloj();
    qDebug()<<configuracion.g_repeticion();
    qDebug()<<configuracion.g_elemento();

//-------------------------------------------------------------------------------

    jug.push_back({-1,-1,-1,-1});//creacion del vector para deshacer jugadas
    //creacion de las calificaciones
    calif(cal);
    calif(cal2);
    calif(cal3);
    calif(cal4);
    calif(cal5);
    calif(cal6);
    calif(cal7);
    calif(cal8);

    //configuracion del reloj--------------------------------------------------
    cargando=1;//Detiene el tiempo
    if(configuracion.g_reloj()==2){//si no hay reloj
       ui->hor->setEnabled(false);
       ui->min->setEnabled(false);
       ui->seg->setEnabled(false);
    }
    if(configuracion.g_reloj()==3 || configuracion.g_reloj()==4){
        ui->hor->display(r2.mh());
        ui->min->display(r2.mm());
        ui->seg->display(r2.ms());
    }

    //Activacion de los relojes ------------------------------------------------------------------------------
    //if (configuracion.g_reloj()==1){//si es temporarizador
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer3()));
    cronometro->start(1000);
    //}
    /*
    if (configuracion.g_reloj()==2){//si no hay tiempo
        QTimer *cronometro=new QTimer(this);
        connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer3()));
        cronometro->start(1000);

    }

    if(configuracion.g_reloj()==3 || configuracion.g_reloj()==4){//si es cronometro por jugada || juego
        QTimer *cronometro=new QTimer(this);
        connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
        cronometro->start(1000);

    }
    */

    //configuracion del elemento-------------------------------
    if (configuracion.g_elemento()==1){//colores
        ui->el1->setIcon(QIcon(":/rojo.png"));
        ui->el2->setIcon(QIcon(":/azul.png"));
        ui->el3->setIcon(QIcon(":/amarillo.png"));
        ui->el4->setIcon(QIcon(":/naranja.png"));
        ui->el5->setIcon(QIcon(":/verde.png"));
        ui->el6->setIcon(QIcon(":/morado.png"));
    }
    if (configuracion.g_elemento()==2){//letras
        ui->el1->setIcon(QIcon(":/A.png"));
        ui->el2->setIcon(QIcon(":/B.png"));
        ui->el3->setIcon(QIcon(":/C.png"));
        ui->el4->setIcon(QIcon(":/D.png"));
        ui->el5->setIcon(QIcon(":/E.png"));
        ui->el6->setIcon(QIcon(":/F.png"));
    }
    if (configuracion.g_elemento()==3){//numeros
        ui->el1->setIcon(QIcon(":/1.png"));
        ui->el2->setIcon(QIcon(":/2.png"));
        ui->el3->setIcon(QIcon(":/3.png"));
        ui->el4->setIcon(QIcon(":/4.png"));
        ui->el5->setIcon(QIcon(":/5.png"));
        ui->el6->setIcon(QIcon(":/6.png"));
    }
    if (configuracion.g_elemento()==4){//Naruto
        ui->el1->setIcon(QIcon(":/s.png"));
        ui->el2->setIcon(QIcon(":/k.png"));
        ui->el3->setIcon(QIcon(":/i.png"));
        ui->el4->setIcon(QIcon(":/r.png"));
        ui->el5->setIcon(QIcon(":/y.png"));
        ui->el6->setIcon(QIcon(":/t.png"));
    }

    //Objetos ocultos------------------------------------------------------

    ui->prueba->setVisible(false);
    ui->winlose->setVisible(false);
    //fila 1
    ui->boton1_1->setVisible(false);
    ui->boton2_1->setVisible(false);
    ui->boton3_1->setVisible(false);
    ui->boton4_1->setVisible(false);
    ui->ver1_1->setVisible(false);
    ui->ver2_1->setVisible(false);
    ui->ver3_1->setVisible(false);
    ui->ver4_1->setVisible(false);
    ui->jug1->setVisible(false);

    //fila 2
    ui->boton1_2->setVisible(false);
    ui->boton2_2->setVisible(false);
    ui->boton3_2->setVisible(false);
    ui->boton4_2->setVisible(false);
    ui->ver1_2->setVisible(false);
    ui->ver2_2->setVisible(false);
    ui->ver3_2->setVisible(false);
    ui->ver4_2->setVisible(false);
    ui->jug2->setVisible(false);

    //fila 3
    ui->boton1_3->setVisible(false);
    ui->boton2_3->setVisible(false);
    ui->boton3_3->setVisible(false);
    ui->boton4_3->setVisible(false);
    ui->ver1_3->setVisible(false);
    ui->ver2_3->setVisible(false);
    ui->ver3_3->setVisible(false);
    ui->ver4_3->setVisible(false);
    ui->jug3->setVisible(false);

    //fila 4
    ui->boton1_4->setVisible(false);
    ui->boton2_4->setVisible(false);
    ui->boton3_4->setVisible(false);
    ui->boton4_4->setVisible(false);
    ui->ver1_4->setVisible(false);
    ui->ver2_4->setVisible(false);
    ui->ver3_4->setVisible(false);
    ui->ver4_4->setVisible(false);
    ui->jug4->setVisible(false);

    //fila 5
    ui->boton1_5->setVisible(false);
    ui->boton2_5->setVisible(false);
    ui->boton3_5->setVisible(false);
    ui->boton4_5->setVisible(false);
    ui->ver1_5->setVisible(false);
    ui->ver2_5->setVisible(false);
    ui->ver3_5->setVisible(false);
    ui->ver4_5->setVisible(false);
    ui->jug5->setVisible(false);

    //fila 6
    ui->boton1_6->setVisible(false);
    ui->boton2_6->setVisible(false);
    ui->boton3_6->setVisible(false);
    ui->boton4_6->setVisible(false);
    ui->ver1_6->setVisible(false);
    ui->ver2_6->setVisible(false);
    ui->ver3_6->setVisible(false);
    ui->ver4_6->setVisible(false);
    ui->jug6->setVisible(false);
    //fila 7

    ui->boton1_7->setVisible(false);
    ui->boton2_7->setVisible(false);
    ui->boton3_7->setVisible(false);
    ui->boton4_7->setVisible(false);
    ui->ver1_7->setVisible(false);
    ui->ver2_7->setVisible(false);
    ui->ver3_7->setVisible(false);
    ui->ver4_7->setVisible(false);
    ui->jug7->setVisible(false);

    //fila 8
    ui->boton1_8->setVisible(false);
    ui->boton2_8->setVisible(false);
    ui->boton3_8->setVisible(false);
    ui->boton4_8->setVisible(false);
    ui->ver1_8->setVisible(false);
    ui->ver2_8->setVisible(false);
    ui->ver3_8->setVisible(false);
    ui->ver4_8->setVisible(false);
    ui->jug8->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_boton1_clicked()//Cambia los datos del boton 1
{

    verif1=1;
    if(contc1==6){
        contc1=0;
    }

    //si son colores--------------------------------
    if(configuracion.g_elemento()==1){
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/rojo.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/azul.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/naranja.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/verde.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/morado.png"));
        }
    }
    //si son letras--------------------------------------
    if(configuracion.g_elemento()==2){
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/A.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/B.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/C.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/D.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/E.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/F.png"));
        }
    }
    //si son numeros--------------------------------------
    if(configuracion.g_elemento()==3){
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/1.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/2.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/3.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/4.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/5.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/6.png"));
        }
    }
    //si son poderes oculares
    if(configuracion.g_elemento()==4){
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/s.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/k.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/i.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/r.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/y.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/t.png"));
        }
    }

    contc1++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }

    jug.push_back({contc1,contc2,contc3,contc4});
    //qDebug()<<jug.at(0).b1<<jug.at(0).b2<<jug.at(0).b3<<jug.at(0).b4;
}

void MainWindow::on_boton2_clicked()
{
    verif2=1;
    if(contc2==6){
        contc2=0;
    }

    //si son colores--------------------------------
    if(configuracion.g_elemento()==1){
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/rojo.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/azul.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/naranja.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/verde.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/morado.png"));
        }
    }

    //si son letras--------------------------------------
    if(configuracion.g_elemento()==2){
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/A.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/B.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/C.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/D.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/E.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/F.png"));
        }
    }

    //si son numeros--------------------------------------
    if(configuracion.g_elemento()==3){
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/1.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/2.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/3.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/4.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/5.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/6.png"));
        }
    }

    //si es poder ocular
    if(configuracion.g_elemento()==4){
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/s.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/k.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/i.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/r.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/y.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/t.png"));
        }
    }

    contc2++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }

    jug.push_back({contc1,contc2,contc3,contc4});
}

void MainWindow::on_boton3_clicked()
{

    verif3=1;
    if(contc3==6){
        contc3=0;
    }

    //si es color
    if (configuracion.g_elemento()==1){
        if (contc3==0){
        ui->boton3->setIcon(QIcon(":/rojo.png"));
        }
        if (contc3==1){
        ui->boton3->setIcon(QIcon(":/azul.png"));
        }
        if (contc3==2){
        ui->boton3->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc3==3){
        ui->boton3->setIcon(QIcon(":/naranja.png"));
        }
        if (contc3==4){
        ui->boton3->setIcon(QIcon(":/verde.png"));
        }
        if (contc3==5){
        ui->boton3->setIcon(QIcon(":/morado.png"));
        }
    }
    //Si es letra
    if (configuracion.g_elemento()==2){
        if (contc3==0){
        ui->boton3->setIcon(QIcon(":/A.png"));
        }
        if (contc3==1){
        ui->boton3->setIcon(QIcon(":/B.png"));
        }
        if (contc3==2){
        ui->boton3->setIcon(QIcon(":/C.png"));
        }
        if (contc3==3){
        ui->boton3->setIcon(QIcon(":/D.png"));
        }
        if (contc3==4){
        ui->boton3->setIcon(QIcon(":/E.png"));
        }
        if (contc3==5){
        ui->boton3->setIcon(QIcon(":/F.png"));
        }
    }
    //si es numero
    if (configuracion.g_elemento()==3){
        if (contc3==0){
        ui->boton3->setIcon(QIcon(":/1.png"));
        }
        if (contc3==1){
        ui->boton3->setIcon(QIcon(":/2.png"));
        }
        if (contc3==2){
        ui->boton3->setIcon(QIcon(":/3.png"));
        }
        if (contc3==3){
        ui->boton3->setIcon(QIcon(":/4.png"));
        }
        if (contc3==4){
        ui->boton3->setIcon(QIcon(":/5.png"));
        }
        if (contc3==5){
        ui->boton3->setIcon(QIcon(":/6.png"));
        }
    }
    //si es poder ocular
    if(configuracion.g_elemento()==4){
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/s.png"));
        }
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/k.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/i.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/r.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/y.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/t.png"));
        }
    }
    contc3++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }
    jug.push_back({contc1,contc2,contc3,contc4});
}

void MainWindow::on_boton4_clicked()
{

    verif4=1;
    if(contc4==6){
        contc4=0;
    }
    //color
    if(configuracion.g_elemento()==1){
        if (contc4==0){
        ui->boton4->setIcon(QIcon(":/rojo.png"));
        }
        if (contc4==1){
        ui->boton4->setIcon(QIcon(":/azul.png"));
        }
        if (contc4==2){
        ui->boton4->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc4==3){
        ui->boton4->setIcon(QIcon(":/naranja.png"));
        }
        if (contc4==4){
        ui->boton4->setIcon(QIcon(":/verde.png"));
        }
        if (contc4==5){
        ui->boton4->setIcon(QIcon(":/morado.png"));
        }
    }
    //letra
    if(configuracion.g_elemento()==2){
        if (contc4==0){
        ui->boton4->setIcon(QIcon(":/A.png"));
        }
        if (contc4==1){
        ui->boton4->setIcon(QIcon(":/B.png"));
        }
        if (contc4==2){
        ui->boton4->setIcon(QIcon(":/C.png"));
        }
        if (contc4==3){
        ui->boton4->setIcon(QIcon(":/D.png"));
        }
        if (contc4==4){
        ui->boton4->setIcon(QIcon(":/E.png"));
        }
        if (contc4==5){
        ui->boton4->setIcon(QIcon(":/F.png"));
        }
    }
    //numero
    if(configuracion.g_elemento()==3){
        if (contc4==0){
        ui->boton4->setIcon(QIcon(":/1.png"));
        }
        if (contc4==1){
        ui->boton4->setIcon(QIcon(":/2.png"));
        }
        if (contc4==2){
        ui->boton4->setIcon(QIcon(":/3.png"));
        }
        if (contc4==3){
        ui->boton4->setIcon(QIcon(":/4.png"));
        }
        if (contc4==4){
        ui->boton4->setIcon(QIcon(":/5.png"));
        }
        if (contc4==5){
        ui->boton4->setIcon(QIcon(":/6.png"));
        }
    }
    //si es poder ocular
    if(configuracion.g_elemento()==4){
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/s.png"));
        }
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/k.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/i.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/r.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/y.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/t.png"));
        }
    }


    contc4++;//aumento del boton
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }
    jug.push_back({contc1,contc2,contc3,contc4});
}

void MainWindow::on_jugada_clicked()
{
    ui->guardar->setEnabled(true);
    int combinacion[4]={contc1-1,contc2-1,contc3-1,contc4-1};

    //Datos cambiados de las filas
    if (configuracion.g_elemento()==1){//colores
        if(filas==0){//primera fila
            ui->boton1_1->setVisible(true);
            ui->boton2_1->setVisible(true);
            ui->boton3_1->setVisible(true);
            ui->boton4_1->setVisible(true);
            ui->ver1_1->setVisible(true);
            ui->ver2_1->setVisible(true);
            ui->ver3_1->setVisible(true);
            ui->ver4_1->setVisible(true);
            ui->jug1->setVisible(true);

            if (contc1-1==0){
            ui->boton1_1->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_1->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_1->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_1->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_1->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_1->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_1->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_1->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_1->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_1->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_1->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_1->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_1->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_1->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_1->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_1->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_1->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_1->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_1->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_1->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_1->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_1->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_1->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_1->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------------

        }

        if(filas==1){//segunda fila
            ui->boton1_2->setVisible(true);
            ui->boton2_2->setVisible(true);
            ui->boton3_2->setVisible(true);
            ui->boton4_2->setVisible(true);
            ui->ver1_2->setVisible(true);
            ui->ver2_2->setVisible(true);
            ui->ver3_2->setVisible(true);
            ui->ver4_2->setVisible(true);
            ui->jug2->setVisible(true);


            if (contc1-1==0){
            ui->boton1_2->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_2->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_2->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_2->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_2->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_2->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_2->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_2->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_2->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_2->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_2->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_2->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_2->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_2->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_2->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_2->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_2->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_2->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_2->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_2->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_2->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_2->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_2->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_2->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------------

        }

        if(filas==2){// tercera fila

            ui->boton1_3->setVisible(true);
            ui->boton2_3->setVisible(true);
            ui->boton3_3->setVisible(true);
            ui->boton4_3->setVisible(true);
            ui->ver1_3->setVisible(true);
            ui->ver2_3->setVisible(true);
            ui->ver3_3->setVisible(true);
            ui->ver4_3->setVisible(true);
            ui->jug3->setVisible(true);


            if (contc1-1==0){
            ui->boton1_3->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_3->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_3->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_3->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_3->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_3->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_3->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_3->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_3->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_3->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_3->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_3->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_3->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_3->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_3->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_3->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_3->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_3->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_3->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_3->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_3->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_3->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_3->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_3->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------------

        }

        if(filas==3){// cuarta fila

            ui->boton1_4->setVisible(true);
            ui->boton2_4->setVisible(true);
            ui->boton3_4->setVisible(true);
            ui->boton4_4->setVisible(true);
            ui->ver1_4->setVisible(true);
            ui->ver2_4->setVisible(true);
            ui->ver3_4->setVisible(true);
            ui->ver4_4->setVisible(true);
            ui->jug4->setVisible(true);


            if (contc1-1==0){
            ui->boton1_4->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_4->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_4->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_4->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_4->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_4->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_4->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_4->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_4->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_4->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_4->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_4->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_4->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_4->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_4->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_4->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_4->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_4->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_4->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_4->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_4->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_4->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_4->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_4->setIcon(QIcon(":/morado.png"));
            }
        }

        if(filas==4){//quinta fila
            ui->boton1_5->setVisible(true);
            ui->boton2_5->setVisible(true);
            ui->boton3_5->setVisible(true);
            ui->boton4_5->setVisible(true);
            ui->ver1_5->setVisible(true);
            ui->ver2_5->setVisible(true);
            ui->ver3_5->setVisible(true);
            ui->ver4_5->setVisible(true);
            ui->jug5->setVisible(true);


            if (contc1-1==0){
            ui->boton1_5->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_5->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_5->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_5->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_5->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_5->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_5->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_5->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_5->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_5->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_5->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_5->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_5->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_5->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_5->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_5->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_5->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_5->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_5->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_5->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_5->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_5->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_5->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_5->setIcon(QIcon(":/morado.png"));
            }
        }

        if(filas==5){//sexta fila
            ui->boton1_6->setVisible(true);
            ui->boton2_6->setVisible(true);
            ui->boton3_6->setVisible(true);
            ui->boton4_6->setVisible(true);
            ui->ver1_6->setVisible(true);
            ui->ver2_6->setVisible(true);
            ui->ver3_6->setVisible(true);
            ui->ver4_6->setVisible(true);
            ui->jug6->setVisible(true);


            if (contc1-1==0){
            ui->boton1_6->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_6->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_6->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_6->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_6->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_6->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_6->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_6->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_6->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_6->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_6->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_6->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_6->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_6->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_6->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_6->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_6->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_6->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_6->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_6->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_6->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_6->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_6->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_6->setIcon(QIcon(":/morado.png"));
            }
        }

        if(filas==6){//septima fila

            ui->boton1_7->setVisible(true);
            ui->boton2_7->setVisible(true);
            ui->boton3_7->setVisible(true);
            ui->boton4_7->setVisible(true);
            ui->ver1_7->setVisible(true);
            ui->ver2_7->setVisible(true);
            ui->ver3_7->setVisible(true);
            ui->ver4_7->setVisible(true);
            ui->jug7->setVisible(true);


            if (contc1-1==0){
            ui->boton1_7->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_7->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_7->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_7->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_7->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_7->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_7->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_7->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_7->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_7->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_7->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_7->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_7->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_7->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_7->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_7->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_7->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_7->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_7->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_7->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_7->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_7->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_7->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_7->setIcon(QIcon(":/morado.png"));
            }

        }

        if(filas==7){//octava fila

            ui->boton1_8->setVisible(true);
            ui->boton2_8->setVisible(true);
            ui->boton3_8->setVisible(true);
            ui->boton4_8->setVisible(true);
            ui->ver1_8->setVisible(true);
            ui->ver2_8->setVisible(true);
            ui->ver3_8->setVisible(true);
            ui->ver4_8->setVisible(true);
            ui->jug8->setVisible(true);


            if (contc1-1==0){
            ui->boton1_8->setIcon(QIcon(":/rojo.png"));
            }
            if (contc1-1==1){
            ui->boton1_8->setIcon(QIcon(":/azul.png"));
            }
            if (contc1-1==2){
            ui->boton1_8->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc1-1==3){
            ui->boton1_8->setIcon(QIcon(":/naranja.png"));
            }
            if (contc1-1==4){
            ui->boton1_8->setIcon(QIcon(":/verde.png"));
            }
            if (contc1-1==5){
            ui->boton1_8->setIcon(QIcon(":/morado.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_8->setIcon(QIcon(":/rojo.png"));
            }
            if (contc2-1==1){
            ui->boton2_8->setIcon(QIcon(":/azul.png"));
            }
            if (contc2-1==2){
            ui->boton2_8->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc2-1==3){
            ui->boton2_8->setIcon(QIcon(":/naranja.png"));
            }
            if (contc2-1==4){
            ui->boton2_8->setIcon(QIcon(":/verde.png"));
            }
            if (contc2-1==5){
            ui->boton2_8->setIcon(QIcon(":/morado.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_8->setIcon(QIcon(":/rojo.png"));
            }
            if (contc3-1==1){
            ui->boton3_8->setIcon(QIcon(":/azul.png"));
            }
            if (contc3-1==2){
            ui->boton3_8->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc3-1==3){
            ui->boton3_8->setIcon(QIcon(":/naranja.png"));
            }
            if (contc3-1==4){
            ui->boton3_8->setIcon(QIcon(":/verde.png"));
            }
            if (contc3-1==5){
            ui->boton3_8->setIcon(QIcon(":/morado.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_8->setIcon(QIcon(":/rojo.png"));
            }
            if (contc4-1==1){
            ui->boton4_8->setIcon(QIcon(":/azul.png"));
            }
            if (contc4-1==2){
            ui->boton4_8->setIcon(QIcon(":/amarillo.png"));
            }
            if (contc4-1==3){
            ui->boton4_8->setIcon(QIcon(":/naranja.png"));
            }
            if (contc4-1==4){
            ui->boton4_8->setIcon(QIcon(":/verde.png"));
            }
            if (contc4-1==5){
            ui->boton4_8->setIcon(QIcon(":/morado.png"));
            }


        }
    }
    if (configuracion.g_elemento()==2){//letras
        if(filas==0){//primera fila
            ui->boton1_1->setVisible(true);
            ui->boton2_1->setVisible(true);
            ui->boton3_1->setVisible(true);
            ui->boton4_1->setVisible(true);
            ui->ver1_1->setVisible(true);
            ui->ver2_1->setVisible(true);
            ui->ver3_1->setVisible(true);
            ui->ver4_1->setVisible(true);
            ui->jug1->setVisible(true);

            if (contc1-1==0){
            ui->boton1_1->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_1->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_1->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_1->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_1->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_1->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_1->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_1->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_1->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_1->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_1->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_1->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_1->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_1->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_1->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_1->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_1->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_1->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_1->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_1->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_1->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_1->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_1->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_1->setIcon(QIcon(":/F.png"));
            }

        }

        if(filas==1){//segunda fila
            ui->boton1_2->setVisible(true);
            ui->boton2_2->setVisible(true);
            ui->boton3_2->setVisible(true);
            ui->boton4_2->setVisible(true);
            ui->ver1_2->setVisible(true);
            ui->ver2_2->setVisible(true);
            ui->ver3_2->setVisible(true);
            ui->ver4_2->setVisible(true);
            ui->jug2->setVisible(true);


            if (contc1-1==0){
            ui->boton1_2->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_2->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_2->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_2->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_2->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_2->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_2->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_2->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_2->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_2->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_2->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_2->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_2->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_2->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_2->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_2->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_2->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_2->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_2->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_2->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_2->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_2->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_2->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_2->setIcon(QIcon(":/F.png"));
            }

        }

        if(filas==2){// tercera fila

            ui->boton1_3->setVisible(true);
            ui->boton2_3->setVisible(true);
            ui->boton3_3->setVisible(true);
            ui->boton4_3->setVisible(true);
            ui->ver1_3->setVisible(true);
            ui->ver2_3->setVisible(true);
            ui->ver3_3->setVisible(true);
            ui->ver4_3->setVisible(true);
            ui->jug3->setVisible(true);


            if (contc1-1==0){
            ui->boton1_3->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_3->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_3->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_3->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_3->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_3->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_3->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_3->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_3->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_3->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_3->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_3->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_3->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_3->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_3->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_3->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_3->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_3->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_3->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_3->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_3->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_3->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_3->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_3->setIcon(QIcon(":/F.png"));
            }

        }

        if(filas==3){// cuarta fila

            ui->boton1_4->setVisible(true);
            ui->boton2_4->setVisible(true);
            ui->boton3_4->setVisible(true);
            ui->boton4_4->setVisible(true);
            ui->ver1_4->setVisible(true);
            ui->ver2_4->setVisible(true);
            ui->ver3_4->setVisible(true);
            ui->ver4_4->setVisible(true);
            ui->jug4->setVisible(true);


            if (contc1-1==0){
            ui->boton1_4->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_4->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_4->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_4->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_4->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_4->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_4->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_4->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_4->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_4->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_4->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_4->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_4->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_4->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_4->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_4->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_4->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_4->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_4->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_4->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_4->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_4->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_4->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_4->setIcon(QIcon(":/F.png"));
            }


        }

        if(filas==4){//quinta fila
            ui->boton1_5->setVisible(true);
            ui->boton2_5->setVisible(true);
            ui->boton3_5->setVisible(true);
            ui->boton4_5->setVisible(true);
            ui->ver1_5->setVisible(true);
            ui->ver2_5->setVisible(true);
            ui->ver3_5->setVisible(true);
            ui->ver4_5->setVisible(true);
            ui->jug5->setVisible(true);


            if (contc1-1==0){
            ui->boton1_5->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_5->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_5->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_5->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_5->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_5->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_5->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_5->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_5->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_5->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_5->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_5->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_5->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_5->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_5->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_5->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_5->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_5->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_5->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_5->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_5->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_5->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_5->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_5->setIcon(QIcon(":/F.png"));
            }

        }

        if(filas==5){//sexta fila
            ui->boton1_6->setVisible(true);
            ui->boton2_6->setVisible(true);
            ui->boton3_6->setVisible(true);
            ui->boton4_6->setVisible(true);
            ui->ver1_6->setVisible(true);
            ui->ver2_6->setVisible(true);
            ui->ver3_6->setVisible(true);
            ui->ver4_6->setVisible(true);
            ui->jug6->setVisible(true);


            if (contc1-1==0){
            ui->boton1_6->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_6->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_6->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_6->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_6->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_6->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_6->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_6->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_6->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_6->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_6->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_6->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_6->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_6->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_6->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_6->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_6->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_6->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_6->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_6->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_6->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_6->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_6->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_6->setIcon(QIcon(":/F.png"));
            }

        }

        if(filas==6){//septima fila

            ui->boton1_7->setVisible(true);
            ui->boton2_7->setVisible(true);
            ui->boton3_7->setVisible(true);
            ui->boton4_7->setVisible(true);
            ui->ver1_7->setVisible(true);
            ui->ver2_7->setVisible(true);
            ui->ver3_7->setVisible(true);
            ui->ver4_7->setVisible(true);
            ui->jug7->setVisible(true);


            if (contc1-1==0){
            ui->boton1_7->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_7->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_7->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_7->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_7->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_7->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_7->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_7->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_7->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_7->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_7->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_7->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_7->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_7->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_7->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_7->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_7->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_7->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_7->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_7->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_7->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_7->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_7->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_7->setIcon(QIcon(":/F.png"));
            }

        }

        if(filas==7){//octava fila

            ui->boton1_8->setVisible(true);
            ui->boton2_8->setVisible(true);
            ui->boton3_8->setVisible(true);
            ui->boton4_8->setVisible(true);
            ui->ver1_8->setVisible(true);
            ui->ver2_8->setVisible(true);
            ui->ver3_8->setVisible(true);
            ui->ver4_8->setVisible(true);
            ui->jug8->setVisible(true);


            if (contc1-1==0){
            ui->boton1_8->setIcon(QIcon(":/A.png"));
            }
            if (contc1-1==1){
            ui->boton1_8->setIcon(QIcon(":/B.png"));
            }
            if (contc1-1==2){
            ui->boton1_8->setIcon(QIcon(":/C.png"));
            }
            if (contc1-1==3){
            ui->boton1_8->setIcon(QIcon(":/D.png"));
            }
            if (contc1-1==4){
            ui->boton1_8->setIcon(QIcon(":/E.png"));
            }
            if (contc1-1==5){
            ui->boton1_8->setIcon(QIcon(":/F.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_8->setIcon(QIcon(":/A.png"));
            }
            if (contc2-1==1){
            ui->boton2_8->setIcon(QIcon(":/B.png"));
            }
            if (contc2-1==2){
            ui->boton2_8->setIcon(QIcon(":/C.png"));
            }
            if (contc2-1==3){
            ui->boton2_8->setIcon(QIcon(":/D.png"));
            }
            if (contc2-1==4){
            ui->boton2_8->setIcon(QIcon(":/E.png"));
            }
            if (contc2-1==5){
            ui->boton2_8->setIcon(QIcon(":/F.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_8->setIcon(QIcon(":/A.png"));
            }
            if (contc3-1==1){
            ui->boton3_8->setIcon(QIcon(":/B.png"));
            }
            if (contc3-1==2){
            ui->boton3_8->setIcon(QIcon(":/C.png"));
            }
            if (contc3-1==3){
            ui->boton3_8->setIcon(QIcon(":/D.png"));
            }
            if (contc3-1==4){
            ui->boton3_8->setIcon(QIcon(":/E.png"));
            }
            if (contc3-1==5){
            ui->boton3_8->setIcon(QIcon(":/F.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_8->setIcon(QIcon(":/A.png"));
            }
            if (contc4-1==1){
            ui->boton4_8->setIcon(QIcon(":/B.png"));
            }
            if (contc4-1==2){
            ui->boton4_8->setIcon(QIcon(":/C.png"));
            }
            if (contc4-1==3){
            ui->boton4_8->setIcon(QIcon(":/D.png"));
            }
            if (contc4-1==4){
            ui->boton4_8->setIcon(QIcon(":/E.png"));
            }
            if (contc4-1==5){
            ui->boton4_8->setIcon(QIcon(":/F.png"));
            }
        }

    }
    if (configuracion.g_elemento()==3){//numeros
        if(filas==0){//primera fila
            ui->boton1_1->setVisible(true);
            ui->boton2_1->setVisible(true);
            ui->boton3_1->setVisible(true);
            ui->boton4_1->setVisible(true);
            ui->ver1_1->setVisible(true);
            ui->ver2_1->setVisible(true);
            ui->ver3_1->setVisible(true);
            ui->ver4_1->setVisible(true);
            ui->jug1->setVisible(true);

            if (contc1-1==0){
            ui->boton1_1->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_1->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_1->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_1->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_1->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_1->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_1->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_1->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_1->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_1->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_1->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_1->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_1->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_1->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_1->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_1->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_1->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_1->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_1->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_1->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_1->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_1->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_1->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_1->setIcon(QIcon(":/6.png"));
            }

        }

        if(filas==1){//segunda fila
            ui->boton1_2->setVisible(true);
            ui->boton2_2->setVisible(true);
            ui->boton3_2->setVisible(true);
            ui->boton4_2->setVisible(true);
            ui->ver1_2->setVisible(true);
            ui->ver2_2->setVisible(true);
            ui->ver3_2->setVisible(true);
            ui->ver4_2->setVisible(true);
            ui->jug2->setVisible(true);


            if (contc1-1==0){
            ui->boton1_2->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_2->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_2->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_2->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_2->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_2->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_2->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_2->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_2->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_2->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_2->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_2->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_2->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_2->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_2->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_2->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_2->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_2->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_2->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_2->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_2->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_2->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_2->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_2->setIcon(QIcon(":/6.png"));
            }

        }

        if(filas==2){// tercera fila

            ui->boton1_3->setVisible(true);
            ui->boton2_3->setVisible(true);
            ui->boton3_3->setVisible(true);
            ui->boton4_3->setVisible(true);
            ui->ver1_3->setVisible(true);
            ui->ver2_3->setVisible(true);
            ui->ver3_3->setVisible(true);
            ui->ver4_3->setVisible(true);
            ui->jug3->setVisible(true);


            if (contc1-1==0){
            ui->boton1_3->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_3->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_3->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_3->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_3->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_3->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_3->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_3->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_3->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_3->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_3->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_3->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_3->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_3->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_3->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_3->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_3->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_3->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_3->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_3->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_3->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_3->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_3->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_3->setIcon(QIcon(":/6.png"));
            }

        }

        if(filas==3){// cuarta fila

            ui->boton1_4->setVisible(true);
            ui->boton2_4->setVisible(true);
            ui->boton3_4->setVisible(true);
            ui->boton4_4->setVisible(true);
            ui->ver1_4->setVisible(true);
            ui->ver2_4->setVisible(true);
            ui->ver3_4->setVisible(true);
            ui->ver4_4->setVisible(true);
            ui->jug4->setVisible(true);


            if (contc1-1==0){
            ui->boton1_4->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_4->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_4->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_4->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_4->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_4->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_4->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_4->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_4->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_4->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_4->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_4->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_4->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_4->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_4->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_4->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_4->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_4->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_4->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_4->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_4->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_4->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_4->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_4->setIcon(QIcon(":/6.png"));
            }


        }

        if(filas==4){//quinta fila
            ui->boton1_5->setVisible(true);
            ui->boton2_5->setVisible(true);
            ui->boton3_5->setVisible(true);
            ui->boton4_5->setVisible(true);
            ui->ver1_5->setVisible(true);
            ui->ver2_5->setVisible(true);
            ui->ver3_5->setVisible(true);
            ui->ver4_5->setVisible(true);
            ui->jug5->setVisible(true);


            if (contc1-1==0){
            ui->boton1_5->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_5->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_5->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_5->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_5->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_5->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_5->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_5->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_5->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_5->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_5->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_5->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_5->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_5->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_5->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_5->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_5->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_5->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_5->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_5->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_5->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_5->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_5->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_5->setIcon(QIcon(":/6.png"));
            }

        }

        if(filas==5){//sexta fila
            ui->boton1_6->setVisible(true);
            ui->boton2_6->setVisible(true);
            ui->boton3_6->setVisible(true);
            ui->boton4_6->setVisible(true);
            ui->ver1_6->setVisible(true);
            ui->ver2_6->setVisible(true);
            ui->ver3_6->setVisible(true);
            ui->ver4_6->setVisible(true);
            ui->jug6->setVisible(true);


            if (contc1-1==0){
            ui->boton1_6->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_6->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_6->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_6->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_6->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_6->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_6->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_6->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_6->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_6->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_6->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_6->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_6->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_6->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_6->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_6->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_6->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_6->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_6->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_6->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_6->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_6->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_6->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_6->setIcon(QIcon(":/6.png"));
            }

        }

        if(filas==6){//septima fila

            ui->boton1_7->setVisible(true);
            ui->boton2_7->setVisible(true);
            ui->boton3_7->setVisible(true);
            ui->boton4_7->setVisible(true);
            ui->ver1_7->setVisible(true);
            ui->ver2_7->setVisible(true);
            ui->ver3_7->setVisible(true);
            ui->ver4_7->setVisible(true);
            ui->jug7->setVisible(true);


            if (contc1-1==0){
            ui->boton1_7->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_7->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_7->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_7->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_7->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_7->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_7->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_7->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_7->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_7->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_7->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_7->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_7->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_7->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_7->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_7->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_7->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_7->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_7->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_7->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_7->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_7->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_7->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_7->setIcon(QIcon(":/6.png"));
            }

        }

        if(filas==7){//octava fila

            ui->boton1_8->setVisible(true);
            ui->boton2_8->setVisible(true);
            ui->boton3_8->setVisible(true);
            ui->boton4_8->setVisible(true);
            ui->ver1_8->setVisible(true);
            ui->ver2_8->setVisible(true);
            ui->ver3_8->setVisible(true);
            ui->ver4_8->setVisible(true);
            ui->jug8->setVisible(true);


            if (contc1-1==0){
            ui->boton1_8->setIcon(QIcon(":/1.png"));
            }
            if (contc1-1==1){
            ui->boton1_8->setIcon(QIcon(":/2.png"));
            }
            if (contc1-1==2){
            ui->boton1_8->setIcon(QIcon(":/3.png"));
            }
            if (contc1-1==3){
            ui->boton1_8->setIcon(QIcon(":/4.png"));
            }
            if (contc1-1==4){
            ui->boton1_8->setIcon(QIcon(":/5.png"));
            }
            if (contc1-1==5){
            ui->boton1_8->setIcon(QIcon(":/6.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_8->setIcon(QIcon(":/1.png"));
            }
            if (contc2-1==1){
            ui->boton2_8->setIcon(QIcon(":/2.png"));
            }
            if (contc2-1==2){
            ui->boton2_8->setIcon(QIcon(":/3.png"));
            }
            if (contc2-1==3){
            ui->boton2_8->setIcon(QIcon(":/4.png"));
            }
            if (contc2-1==4){
            ui->boton2_8->setIcon(QIcon(":/5.png"));
            }
            if (contc2-1==5){
            ui->boton2_8->setIcon(QIcon(":/6.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_8->setIcon(QIcon(":/1.png"));
            }
            if (contc3-1==1){
            ui->boton3_8->setIcon(QIcon(":/2.png"));
            }
            if (contc3-1==2){
            ui->boton3_8->setIcon(QIcon(":/3.png"));
            }
            if (contc3-1==3){
            ui->boton3_8->setIcon(QIcon(":/4.png"));
            }
            if (contc3-1==4){
            ui->boton3_8->setIcon(QIcon(":/5.png"));
            }
            if (contc3-1==5){
            ui->boton3_8->setIcon(QIcon(":/6.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_8->setIcon(QIcon(":/1.png"));
            }
            if (contc4-1==1){
            ui->boton4_8->setIcon(QIcon(":/2.png"));
            }
            if (contc4-1==2){
            ui->boton4_8->setIcon(QIcon(":/3.png"));
            }
            if (contc4-1==3){
            ui->boton4_8->setIcon(QIcon(":/4.png"));
            }
            if (contc4-1==4){
            ui->boton4_8->setIcon(QIcon(":/5.png"));
            }
            if (contc4-1==5){
            ui->boton4_8->setIcon(QIcon(":/6.png"));
            }
        }
    }
    if (configuracion.g_elemento()==4){//poderes oculares
        if(filas==0){//primera fila
            ui->boton1_1->setVisible(true);
            ui->boton2_1->setVisible(true);
            ui->boton3_1->setVisible(true);
            ui->boton4_1->setVisible(true);
            ui->ver1_1->setVisible(true);
            ui->ver2_1->setVisible(true);
            ui->ver3_1->setVisible(true);
            ui->ver4_1->setVisible(true);
            ui->jug1->setVisible(true);

            if (contc1-1==0){
            ui->boton1_1->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_1->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_1->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_1->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_1->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_1->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_1->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_1->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_1->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_1->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_1->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_1->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_1->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_1->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_1->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_1->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_1->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_1->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_1->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_1->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_1->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_1->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_1->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_1->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==1){//segunda fila
            ui->boton1_2->setVisible(true);
            ui->boton2_2->setVisible(true);
            ui->boton3_2->setVisible(true);
            ui->boton4_2->setVisible(true);
            ui->ver1_2->setVisible(true);
            ui->ver2_2->setVisible(true);
            ui->ver3_2->setVisible(true);
            ui->ver4_2->setVisible(true);
            ui->jug2->setVisible(true);


            if (contc1-1==0){
            ui->boton1_2->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_2->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_2->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_2->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_2->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_2->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_2->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_2->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_2->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_2->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_2->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_2->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_2->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_2->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_2->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_2->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_2->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_2->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_2->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_2->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_2->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_2->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_2->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_2->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==2){// tercera fila

            ui->boton1_3->setVisible(true);
            ui->boton2_3->setVisible(true);
            ui->boton3_3->setVisible(true);
            ui->boton4_3->setVisible(true);
            ui->ver1_3->setVisible(true);
            ui->ver2_3->setVisible(true);
            ui->ver3_3->setVisible(true);
            ui->ver4_3->setVisible(true);
            ui->jug3->setVisible(true);


            if (contc1-1==0){
            ui->boton1_3->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_3->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_3->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_3->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_3->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_3->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_3->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_3->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_3->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_3->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_3->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_3->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_3->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_3->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_3->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_3->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_3->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_3->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_3->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_3->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_3->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_3->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_3->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_3->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==3){// cuarta fila

            ui->boton1_4->setVisible(true);
            ui->boton2_4->setVisible(true);
            ui->boton3_4->setVisible(true);
            ui->boton4_4->setVisible(true);
            ui->ver1_4->setVisible(true);
            ui->ver2_4->setVisible(true);
            ui->ver3_4->setVisible(true);
            ui->ver4_4->setVisible(true);
            ui->jug4->setVisible(true);


            if (contc1-1==0){
            ui->boton1_4->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_4->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_4->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_4->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_4->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_4->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_4->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_4->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_4->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_4->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_4->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_4->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_4->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_4->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_4->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_4->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_4->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_4->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_4->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_4->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_4->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_4->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_4->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_4->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==4){//quinta fila
            ui->boton1_5->setVisible(true);
            ui->boton2_5->setVisible(true);
            ui->boton3_5->setVisible(true);
            ui->boton4_5->setVisible(true);
            ui->ver1_5->setVisible(true);
            ui->ver2_5->setVisible(true);
            ui->ver3_5->setVisible(true);
            ui->ver4_5->setVisible(true);
            ui->jug5->setVisible(true);


            if (contc1-1==0){
            ui->boton1_5->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_5->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_5->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_5->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_5->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_5->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_5->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_5->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_5->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_5->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_5->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_5->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_5->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_5->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_5->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_5->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_5->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_5->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_5->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_5->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_5->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_5->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_5->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_5->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==5){//sexta fila
            ui->boton1_6->setVisible(true);
            ui->boton2_6->setVisible(true);
            ui->boton3_6->setVisible(true);
            ui->boton4_6->setVisible(true);
            ui->ver1_6->setVisible(true);
            ui->ver2_6->setVisible(true);
            ui->ver3_6->setVisible(true);
            ui->ver4_6->setVisible(true);
            ui->jug6->setVisible(true);


            if (contc1-1==0){
            ui->boton1_6->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_6->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_6->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_6->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_6->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_6->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_6->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_6->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_6->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_6->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_6->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_6->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_6->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_6->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_6->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_6->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_6->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_6->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_6->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_6->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_6->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_6->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_6->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_6->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==6){//septima fila

            ui->boton1_7->setVisible(true);
            ui->boton2_7->setVisible(true);
            ui->boton3_7->setVisible(true);
            ui->boton4_7->setVisible(true);
            ui->ver1_7->setVisible(true);
            ui->ver2_7->setVisible(true);
            ui->ver3_7->setVisible(true);
            ui->ver4_7->setVisible(true);
            ui->jug7->setVisible(true);


            if (contc1-1==0){
            ui->boton1_7->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_7->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_7->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_7->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_7->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_7->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_7->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_7->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_7->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_7->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_7->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_7->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_7->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_7->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_7->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_7->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_7->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_7->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_7->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_7->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_7->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_7->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_7->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_7->setIcon(QIcon(":/t.png"));
            }

        }

        if(filas==7){//octava fila

            ui->boton1_8->setVisible(true);
            ui->boton2_8->setVisible(true);
            ui->boton3_8->setVisible(true);
            ui->boton4_8->setVisible(true);
            ui->ver1_8->setVisible(true);
            ui->ver2_8->setVisible(true);
            ui->ver3_8->setVisible(true);
            ui->ver4_8->setVisible(true);
            ui->jug8->setVisible(true);


            if (contc1-1==0){
            ui->boton1_8->setIcon(QIcon(":/s.png"));
            }
            if (contc1-1==1){
            ui->boton1_8->setIcon(QIcon(":/k.png"));
            }
            if (contc1-1==2){
            ui->boton1_8->setIcon(QIcon(":/i.png"));
            }
            if (contc1-1==3){
            ui->boton1_8->setIcon(QIcon(":/r.png"));
            }
            if (contc1-1==4){
            ui->boton1_8->setIcon(QIcon(":/y.png"));
            }
            if (contc1-1==5){
            ui->boton1_8->setIcon(QIcon(":/t.png"));
            }
            //-------------------------------------------------------------
            if (contc2-1==0){
            ui->boton2_8->setIcon(QIcon(":/s.png"));
            }
            if (contc2-1==1){
            ui->boton2_8->setIcon(QIcon(":/k.png"));
            }
            if (contc2-1==2){
            ui->boton2_8->setIcon(QIcon(":/i.png"));
            }
            if (contc2-1==3){
            ui->boton2_8->setIcon(QIcon(":/r.png"));
            }
            if (contc2-1==4){
            ui->boton2_8->setIcon(QIcon(":/y.png"));
            }
            if (contc2-1==5){
            ui->boton2_8->setIcon(QIcon(":/t.png"));
            }
            //----------------------------------------------------------------
            if (contc3-1==0){
            ui->boton3_8->setIcon(QIcon(":/s.png"));
            }
            if (contc3-1==1){
            ui->boton3_8->setIcon(QIcon(":/k.png"));
            }
            if (contc3-1==2){
            ui->boton3_8->setIcon(QIcon(":/i.png"));
            }
            if (contc3-1==3){
            ui->boton3_8->setIcon(QIcon(":/r.png"));
            }
            if (contc3-1==4){
            ui->boton3_8->setIcon(QIcon(":/y.png"));
            }
            if (contc3-1==5){
            ui->boton3_8->setIcon(QIcon(":/t.png"));
            }
            //------------------------------------------------------------------
            if (contc4-1==0){
            ui->boton4_8->setIcon(QIcon(":/s.png"));
            }
            if (contc4-1==1){
            ui->boton4_8->setIcon(QIcon(":/k.png"));
            }
            if (contc4-1==2){
            ui->boton4_8->setIcon(QIcon(":/i.png"));
            }
            if (contc4-1==3){
            ui->boton4_8->setIcon(QIcon(":/r.png"));
            }
            if (contc4-1==4){
            ui->boton4_8->setIcon(QIcon(":/y.png"));
            }
            if (contc4-1==5){
            ui->boton4_8->setIcon(QIcon(":/t.png"));
            }
        }
    }


    //Calificacion por fila
    if (filas==0){
        jugadas obj={0,0,0,0};
        //1=negro, 2=blanco
        for (int i=0;i<4;i++){
            if (combinacion[i]==comb[i]){
                if(cal[i]==1){
                    ui->ver1_1->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal[i]==2){
                    ui->ver2_1->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal[i]==3){
                    ui->ver3_1->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal[i]==4){
                    ui->ver4_1->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal[i]==1){
                    ui->ver1_1->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal[i]==2){
                    ui->ver2_1->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal[i]==3){
                    ui->ver3_1->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal[i]==4){
                    ui->ver4_1->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);//se agrega el objeto creado
    }

    if (filas==1){
        jugadas obj={0,0,0,0};

        for (int i=0;i<4;i++){

            if (combinacion[i]==comb[i]){

                if(cal2[i]==1){
                    ui->ver1_2->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal2[i]==2){
                    ui->ver2_2->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal2[i]==3){
                    ui->ver3_2->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal2[i]==4){
                    ui->ver4_2->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal2[i]==1){
                    ui->ver1_2->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal2[i]==2){
                    ui->ver2_2->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal2[i]==3){
                    ui->ver3_2->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal2[i]==4){
                    ui->ver4_2->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    if (filas==2){
        jugadas obj={0,0,0,0};

        for (int i=0;i<4;i++){

            if (combinacion[i]==comb[i]){

                if(cal3[i]==1){
                    ui->ver1_3->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal3[i]==2){
                    ui->ver2_3->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal3[i]==3){
                    ui->ver3_3->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal3[i]==4){
                    ui->ver4_3->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal3[i]==1){
                    ui->ver1_3->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal3[i]==2){
                    ui->ver2_3->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal3[i]==3){
                    ui->ver3_3->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal3[i]==4){
                    ui->ver4_3->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    if (filas==3){
        jugadas obj={0,0,0,0};

        for (int i=0;i<4;i++){

            if (combinacion[i]==comb[i]){

                if(cal4[i]==1){
                    ui->ver1_4->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal4[i]==2){
                    ui->ver2_4->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal4[i]==3){
                    ui->ver3_4->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal4[i]==4){
                    ui->ver4_4->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal4[i]==1){
                    ui->ver1_4->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal4[i]==2){
                    ui->ver2_4->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal4[i]==3){
                    ui->ver3_4->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal4[i]==4){
                    ui->ver4_4->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    if (filas==4){
        jugadas obj = {0,0,0,0} ;

        for (int i=0;i<4;i++){

            if (combinacion[i]==comb[i]){
                if(cal5[i]==1){
                    ui->ver1_5->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal5[i]==2){
                    ui->ver2_5->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal5[i]==3){
                    ui->ver3_5->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal5[i]==4){
                    ui->ver4_5->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal5[i]==1){
                    ui->ver1_5->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal5[i]==2){
                    ui->ver2_5->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal5[i]==3){
                    ui->ver3_5->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal5[i]==4){
                    ui->ver4_5->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    if (filas==5){
        jugadas obj={0,0,0,0};

        for (int i=0;i<4;i++){

            if (combinacion[i]==comb[i]){

                if(cal6[i]==1){
                    ui->ver1_6->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal6[i]==2){
                    ui->ver2_6->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal6[i]==3){
                    ui->ver3_6->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal6[i]==4){
                    ui->ver4_6->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal6[i]==1){
                    ui->ver1_6->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal6[i]==2){
                    ui->ver2_6->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal6[i]==3){
                    ui->ver3_6->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal6[i]==4){
                    ui->ver4_6->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    if (filas==6){
        jugadas obj={0,0,0,0};

        for (int i=0;i<4;i++){

            if (combinacion[i]==comb[i]){
                if(cal7[i]==1){
                    ui->ver1_7->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal7[i]==2){
                    ui->ver2_7->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal7[i]==3){
                    ui->ver3_7->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal7[i]==4){
                    ui->ver4_7->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal7[i]==1){
                    ui->ver1_7->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal7[i]==2){
                    ui->ver2_7->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal7[i]==3){
                    ui->ver3_7->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal7[i]==4){
                    ui->ver4_7->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    if (filas==7){
        jugadas obj={0,0,0,0};

        for (int i=0;i<4;i++){
            if (combinacion[i]==comb[i]){
                if(cal8[i]==1){
                    ui->ver1_8->setIcon(QIcon(":/negro.png"));
                    obj.b1=1;
                    continue;
                }
                if(cal8[i]==2){
                    ui->ver2_8->setIcon(QIcon(":/negro.png"));
                    obj.b2=1;
                    continue;
                }
                if(cal8[i]==3){
                    ui->ver3_8->setIcon(QIcon(":/negro.png"));
                    obj.b3=1;
                    continue;
                }
                if(cal8[i]==4){
                    ui->ver4_8->setIcon(QIcon(":/negro.png"));
                    obj.b4=1;
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal8[i]==1){
                    ui->ver1_8->setIcon(QIcon(":/blanco.png"));
                    obj.b1=2;
                    continue;
                }
                if(cal8[i]==2){
                    ui->ver2_8->setIcon(QIcon(":/blanco.png"));
                    obj.b2=2;
                    continue;
                }
                if(cal8[i]==3){
                    ui->ver3_8->setIcon(QIcon(":/blanco.png"));
                    obj.b3=2;
                    continue;
                }
                if(cal8[i]==4){
                    ui->ver4_8->setIcon(QIcon(":/blanco.png"));
                    obj.b4=2;
                    continue;
                }
            }
        }
        calificacion.push_back(obj);
    }

    //reinicio de los tiempos por jugada
    tperjug.push_back(r3);// se agrega al vector
    r3.ctiempo(0);
    if (configuracion.g_reloj() == 3){//si es cronometro por jugada reinicia la cuenta regresiva
        r.ch(r2.mh());
        r.cm(r2.mm());
        r.cs(r2.ms());
    }

    //Verifica si el jugador ya gano
    if ((combinacion[0]==comb[0]) & (combinacion[1]==comb[1]) & (combinacion[2]==comb[2]) & (combinacion[3]==comb[3])){
        win=1;

        // Aplausos
        reproductor->setMedia(QUrl::fromLocalFile("C:/Users/Jerem/Desktop/Proyecto c++/Lista_Records/MasterMind2/aplausos.mp3"));//abre el audio.mp3
        reproductor->play();
        //Datos del record------------------------------------------------------------------
        records winner;

        //tiempo total de juego----------------------------------------------------
        Tiempo segundos;
        for(int i=0;i<tperjug.size();i++){
            segundos.ctiempo(segundos.tiempotot()+tperjug.at(i).tiempotot());
        }
        //-----------------------------------------------------------------------

        QDate date=QDate::currentDate();
        QTime hor=QTime::currentTime();

        //nombre
        winner.nombre=ui->nombre->text();

        //tiempo de juego
        winner.tj= QString::number(segundos.mh())+":"+QString::number(segundos.mm())+":"+QString::number(segundos.ms());

        //combinacion ganadora
        winner.combinacion= QString::number(comb[0]) + " " + QString::number (comb[1]) + " " + QString::number (comb[2]) + " " + QString::number (comb[3]);

        //Fecha
        winner.fecha= date.toString("yyyy/MM/dd") + " " + hor.toString("hh:mm:ss");

        //tiempos por jugada
        llenarecord(winner);

        if (configuracion.g_reloj()==1 || configuracion.g_reloj()==3 || configuracion.g_reloj()==4){
            if (configuracion.g_dificultad()==1){

                QFile facil(":/guardar/facil.txt");
                vector <records> record;

                if(facil.open(QIODevice::ReadOnly)){
                    QTextStream datos(&facil);
                    qDebug()<<"abierto"<<endl;
                    //tam de datos
                    int contador=0;
                    records obj;

                    while (!datos.atEnd()){//datos de los tops

                        QString line=datos.readLine();

                        if(contador==12){
                            contador=0;
                        }

                        if (contador==0){//nombre
                            obj.nombre=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==1){//tiempo jugado
                            obj.tj=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==2){//combinacion
                            obj.combinacion=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==3){//fecha
                            obj.fecha=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==4){//t1
                            obj.t1=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==5){//t2
                            obj.t2=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==6){//t3
                            obj.t3=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==7){//t4
                            obj.t4=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==8){//t5
                            obj.t5=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==9){//t6
                            obj.t6=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==10){//t7
                            obj.t7=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==11){//t8
                            obj.t8=line;
                            record.push_back(obj);
                        }

                        contador++;
                    }
                    qDebug()<<record.size()<<endl;
                }

                if (record.size()==3){
                    records obj1=record.at(0);
                    records obj2=record.at(1);
                    records obj3=record.at(2);

                    if (segundos.tiempotot() < stringtotime(obj1.tj)){
                        record.clear();
                        record.push_back(winner);
                        record.push_back(obj1);
                        record.push_back(obj2);
                        escribirfacil(record,1);
                    }

                    if (segundos.tiempotot() > stringtotime(obj1.tj) && segundos.tiempotot() < stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(winner);
                        record.push_back(obj2);
                        escribirfacil(record,1);
                    }

                    if (segundos.tiempotot() > stringtotime(obj2.tj) && segundos.tiempotot() < stringtotime(obj3.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(obj2);
                        record.push_back(winner);
                        escribirfacil(record,1);
                    }
                }

                if (record.size()==2){
                    records obj1=record.at(0);
                    records obj2=record.at(1);

                    if (segundos.tiempotot() < stringtotime(obj1.tj)){
                        record.clear();
                        record.push_back(winner);
                        record.push_back(obj1);
                        record.push_back(obj2);
                        escribirfacil(record,1);
                    }

                    if (segundos.tiempotot() > stringtotime(obj1.tj) && segundos.tiempotot() < stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(winner);
                        record.push_back(obj2);
                        escribirfacil(record,1);
                    }

                    if (segundos.tiempotot() > stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(obj2);
                        record.push_back(winner);
                        escribirfacil(record,1);
                    }

                }

                if (record.size()==1){

                    if (stringtotime(record.at(0).tj) < segundos.tiempotot()){
                        record.push_back(winner);
                        escribirfacil(record,1);
                    }
                    else {
                        records cambio=record.at(0);
                        record.clear();
                        record.push_back(winner);
                        record.push_back(cambio);
                        escribirfacil(record,1);
                    }

                }

                if (record.size()==0){
                    record.push_back(winner);
                    escribirfacil(record,1);
                }


            }

            if (configuracion.g_dificultad()==2){

                QFile medio(":/guardar/medio.txt");
                vector <records> record;

                if(medio.open(QIODevice::ReadOnly)){
                    QTextStream datos(&medio);
                    qDebug()<<"abierto"<<endl;

                    //tam de datos
                    int contador=0;
                    records obj;
                    while (!datos.atEnd()){//datos de los tops

                        QString line=datos.readLine();

                        if(contador==12){
                            contador=0;
                        }

                        if (contador==0){//nombre
                            obj.nombre=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==1){//tiempo jugado
                            obj.tj=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==2){//combinacion
                            obj.combinacion=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==3){//fecha
                            obj.fecha=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==4){//t1
                            obj.t1=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==5){//t2
                            obj.t2=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==6){//t3
                            obj.t3=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==7){//t4
                            obj.t4=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==8){//t5
                            obj.t5=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==9){//t6
                            obj.t6=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==10){//t7
                            obj.t7=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==11){//t8
                            obj.t8=line;
                            record.push_back(obj);
                        }

                        contador++;
                    }
                    qDebug()<<record.size()<<endl;
                }

                if (record.size()==3){
                    records obj1=record.at(0);
                    records obj2=record.at(1);
                    records obj3=record.at(2);


                    if (segundos.tiempotot() < stringtotime(obj1.tj)){
                        record.clear();
                        record.push_back(winner);
                        record.push_back(obj1);
                        record.push_back(obj2);
                        escribirfacil(record,2);
                    }

                    if (segundos.tiempotot() > stringtotime(obj1.tj) && segundos.tiempotot() < stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(winner);
                        record.push_back(obj2);
                        escribirfacil(record,2);
                    }

                    if (segundos.tiempotot() > stringtotime(obj2.tj) && segundos.tiempotot() < stringtotime(obj3.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(obj2);
                        record.push_back(winner);
                        escribirfacil(record,2);
                    }


                }

                if (record.size()==2){
                    records obj1=record.at(0);
                    records obj2=record.at(1);


                    if (segundos.tiempotot() < stringtotime(obj1.tj)){
                        record.clear();
                        record.push_back(winner);
                        record.push_back(obj1);
                        record.push_back(obj2);
                        escribirfacil(record,2);
                    }

                    if (segundos.tiempotot() > stringtotime(obj1.tj) && segundos.tiempotot() < stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(winner);
                        record.push_back(obj2);
                        escribirfacil(record,2);
                    }

                    if (segundos.tiempotot() > stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(obj2);
                        record.push_back(winner);
                        escribirfacil(record,2);
                    }

                }

                if (record.size()==1){

                    if (stringtotime(record.at(0).tj) < segundos.tiempotot()){
                        record.push_back(winner);
                        escribirfacil(record,2);
                    }
                    else {
                        records cambio=record.at(0);
                        record.clear();
                        record.push_back(winner);
                        record.push_back(cambio);
                        escribirfacil(record,2);
                    }

                }

                if (record.size()==0){
                    record.push_back(winner);
                    escribirfacil(record,2);
                }

            }

            if (configuracion.g_dificultad()==3){
                QFile dificil(":/guardar/dificil.txt");
                vector <records> record;

                if(dificil.open(QIODevice::ReadOnly)){
                    QTextStream datos(&dificil);
                    qDebug()<<"abierto"<<endl;
                    //tam de datos
                    int contador=0;
                    records obj;

                    while (!datos.atEnd()){//datos de los tops

                        QString line=datos.readLine();

                        if(contador==12){
                            contador=0;
                        }

                        if (contador==0){//nombre
                            obj.nombre=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==1){//tiempo jugado
                            obj.tj=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==2){//combinacion
                            obj.combinacion=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==3){//fecha
                            obj.fecha=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==4){//t1
                            obj.t1=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==5){//t2
                            obj.t2=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==6){//t3
                            obj.t3=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==7){//t4
                            obj.t4=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==8){//t5
                            obj.t5=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==9){//t6
                            obj.t6=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==10){//t7
                            obj.t7=line;
                            qDebug()<<line<<endl;
                        }
                        if (contador==11){//t8
                            obj.t8=line;
                            record.push_back(obj);
                        }

                        contador++;
                    }
                    qDebug()<<record.size()<<endl;
                }

                if (record.size()==3){
                    records obj1=record.at(0);
                    records obj2=record.at(1);
                    records obj3=record.at(2);

                    if (segundos.tiempotot() < stringtotime(obj1.tj)){
                        record.clear();
                        record.push_back(winner);
                        record.push_back(obj1);
                        record.push_back(obj2);
                        escribirfacil(record,3);
                    }

                    if (segundos.tiempotot() > stringtotime(obj1.tj) &&  segundos.tiempotot() < stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(winner);
                        record.push_back(obj2);
                        escribirfacil(record,3);
                    }

                    if (segundos.tiempotot() > stringtotime(obj2.tj) && segundos.tiempotot() < stringtotime(obj3.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(obj2);
                        record.push_back(winner);
                        escribirfacil(record,3);
                    }

                }

                if (record.size()==2){
                    records obj1=record.at(0);
                    records obj2=record.at(1);


                    if (segundos.tiempotot() < stringtotime(obj1.tj)){
                        record.clear();
                        record.push_back(winner);
                        record.push_back(obj1);
                        record.push_back(obj2);
                        escribirfacil(record,3);
                    }

                    if (segundos.tiempotot() > stringtotime(obj1.tj) && segundos.tiempotot() < stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(winner);
                        record.push_back(obj2);
                        escribirfacil(record,3);
                    }

                    if (segundos.tiempotot() > stringtotime(obj2.tj)){
                        record.clear();
                        record.push_back(obj1);
                        record.push_back(obj2);
                        record.push_back(winner);
                        escribirfacil(record,3);
                    }

                }

                if (record.size()==1){

                    if (stringtotime(record.at(0).tj) < segundos.tiempotot()){
                        record.push_back(winner);
                        escribirfacil(record,3);
                    }
                    else {
                        records cambio=record.at(0);
                        record.clear();
                        record.push_back(winner);
                        record.push_back(cambio);
                        escribirfacil(record,3);
                    }

                }

                if (record.size()==0){
                    record.push_back(winner);
                    escribirfacil(record,3);
                }

            }

        }
    }

    ui->boton1->setIcon(QIcon(":/gris.png"));
    ui->boton2->setIcon(QIcon(":/gris.png"));
    ui->boton3->setIcon(QIcon(":/gris.png"));
    ui->boton4->setIcon(QIcon(":/gris.png"));
    ui->ver1->setIcon(QIcon(":/gris.png"));
    ui->ver2->setIcon(QIcon(":/gris.png"));
    ui->ver3->setIcon(QIcon(":/gris.png"));
    ui->ver4->setIcon(QIcon(":/gris.png"));

    ui->boton1->setGeometry(100,410-resty,40,40);
    ui->boton2->setGeometry(170,410-resty,40,40);
    ui->boton3->setGeometry(240,410-resty,40,40);
    ui->boton4->setGeometry(310,410-resty,40,40);
    ui->ver1->setGeometry(370,410-resty,16,16);
    ui->ver2->setGeometry(370,430-resty,16,16);
    ui->ver3->setGeometry(390,410-resty,16,16);
    ui->ver4->setGeometry(390,430-resty,16,16);
    ui->jugada->setEnabled(false);

    //bloquea los botones y detiene el juego segun la dificultad
    if((filas==5) & (configuracion.g_dificultad()==3)){//si es dificil
        ui->guardar->setEnabled(false);
        ui->cargar->setEnabled(false);
        ui->boton1->setVisible(false);
        ui->boton2->setVisible(false);
        ui->boton3->setVisible(false);
        ui->boton4->setVisible(false);
        ui->ver1->setVisible(false);
        ui->ver2->setVisible(false);
        ui->ver3->setVisible(false);
        ui->ver4->setVisible(false);
        ui->boton1->setEnabled(false);
        ui->boton2->setEnabled(false);
        ui->boton3->setEnabled(false);
        ui->boton4->setEnabled(false);
        ui->jugada->setEnabled(false);
        filas++;
        return;
    }

    if ((filas==6) & (configuracion.g_dificultad()==2)){//si es medio
        ui->guardar->setEnabled(false);
        ui->cargar->setEnabled(false);
        ui->boton1->setVisible(false);
        ui->boton2->setVisible(false);
        ui->boton3->setVisible(false);
        ui->boton4->setVisible(false);
        ui->ver1->setVisible(false);
        ui->ver2->setVisible(false);
        ui->ver3->setVisible(false);
        ui->ver4->setVisible(false);
        ui->boton1->setEnabled(false);
        ui->boton2->setEnabled(false);
        ui->boton3->setEnabled(false);
        ui->boton4->setEnabled(false);
        ui->jugada->setEnabled(false);
        filas++;
        return;
    }

    if ((filas==7) & (configuracion.g_dificultad()==1)){//si es facil
        ui->guardar->setEnabled(false);
        ui->cargar->setEnabled(false);
        ui->boton1->setVisible(false);
        ui->boton2->setVisible(false);
        ui->boton3->setVisible(false);
        ui->boton4->setVisible(false);
        ui->ver1->setVisible(false);
        ui->ver2->setVisible(false);
        ui->ver3->setVisible(false);
        ui->ver4->setVisible(false);
        ui->boton1->setEnabled(false);
        ui->boton2->setEnabled(false);
        ui->boton3->setEnabled(false);
        ui->boton4->setEnabled(false);
        ui->jugada->setEnabled(false);
        filas++;
        return;
    }

    //agrega los datos de la fila en la que se esta jugando
    jugfilas.push_back({contc1,contc2,contc3,contc4});

    //reinicia los valores de los botones y de la verificacion(sirve para habilitar el boton jugada)
    contc1=0;
    contc2=0;
    contc3=0;
    contc4=0;
    verif1=0;
    verif2=0;
    verif3=0;
    verif4=0;

    resty+=50;//cambia la posicion de los botones en las coordenadas y

    filas++;//identifica en cual fila se encuentra el jugador para realizar la calificacion

    //reinicio del objeto jug para deshacer jugadas
    jug.clear();
    jug.push_back({-1,-1,-1,-1});

}

void MainWindow::on_iniciar_clicked()
{
    if (configuracion.g_reloj()==1 || configuracion.g_reloj()==2 || configuracion.g_reloj()==3 || configuracion.g_reloj()==4){//si existe uso del reloj
        cargando=0;
    }
    //creacion de la combinacion
    if(configuracion.g_repeticion()==1){//con repeticion
        datoaleatorio(comb);
        qDebug()<<comb[0];
        qDebug()<<comb[1];
        qDebug()<<comb[2];
        qDebug()<<comb[3];
    }
    if(configuracion.g_repeticion()==2){//sin repeticion
        datoaleatoriosinrepeticion(comb);
        qDebug()<<comb[0];
        qDebug()<<comb[1];
        qDebug()<<comb[2];
        qDebug()<<comb[3];
    }

    //-----------------------------------------------------------------------------------------
    ui->iniciar->setEnabled(false);
    ui->boton1->setEnabled(true);
    ui->boton2->setEnabled(true);
    ui->boton3->setEnabled(true);
    ui->boton4->setEnabled(true);

}

void MainWindow::on_deshacer_clicked()
{
    if (jug.size()==1){//no puede eliminar su primera posicion en el vector
        contc1=0;
        contc2=0;
        contc3=0;
        contc4=0;
        return;
    }

    jug.pop_back();

    contc1=jug.back().b1-1;
    if (jug.back().b1==-1){
        contc1=-1;
    }

    contc2=jug.back().b2-1;
    if (jug.back().b2==-1){
        contc2=-1;
    }

    contc3=jug.back().b3-1;
    if (jug.back().b3==-1){
        contc3=-1;
    }

    contc4=jug.back().b4-1;
    if (jug.back().b4==-1){
        contc4=-1;
    }



    //si son colores--------------------------------
    if(configuracion.g_elemento()==1){
        //boton1------------------------------------------------
        if (contc1==-1){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/rojo.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/azul.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/naranja.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/verde.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/morado.png"));
        }
        //boton2------------------------------------------------------
        if(contc2==-1){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/rojo.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/azul.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/naranja.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/verde.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/morado.png"));
        }
        //boton3-------------------------------------------------------
        if(contc3==-1){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/rojo.png"));
        }
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/azul.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/naranja.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/verde.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/morado.png"));
        }
        //boton4------------------------------------------------------
        if(contc4==-1){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/rojo.png"));
        }
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/azul.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/naranja.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/verde.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/morado.png"));
        }
    }

    //si son letras--------------------------------------
    if(configuracion.g_elemento()==2){
        //boton1-----------------------------------------------
        if(contc1==-1){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/A.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/B.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/C.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/D.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/E.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/F.png"));
        }
        //boton2---------------------------------------------
        if(contc2==-1){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/A.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/B.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/C.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/D.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/E.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/F.png"));
        }
        //boton3----------------------------------------------
        if(contc3==-1){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/A.png"));
        }
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/B.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/C.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/D.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/E.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/F.png"));
        }
        //boton4----------------------------------------------
        if(contc4==-1){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/A.png"));
        }
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/B.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/C.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/D.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/E.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/F.png"));
        }
    }

    //si son numeros--------------------------------------
    if(configuracion.g_elemento()==3){
        //boton1------------------------------------------
        if(contc1==-1){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/1.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/2.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/3.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/4.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/5.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/6.png"));
        }

        //boton2----------------------------------------
        if(contc2==-1){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/1.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/2.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/3.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/4.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/5.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/6.png"));
        }
        //boton3--------------------------------------
        if(contc3==-1){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/1.png"));
        }
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/2.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/3.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/4.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/5.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/6.png"));
        }
        //boton4----------------------------------------
        if(contc4==-1){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/1.png"));
        }
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/2.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/3.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/4.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/5.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/6.png"));
        }
    }

    //si son poderes oculares-------------------------------
    if(configuracion.g_elemento()==4){

        //boton1------------------------------------------
        if (contc1==-1){
            ui->boton1->setIcon(QIcon(":/gris.png"));
            verif1=0;
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/s.png"));
        }
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/k.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/i.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/r.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/y.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/t.png"));
        }

        //boton2----------------------------------------
        if(contc2==-1){
            ui->boton2->setIcon(QIcon(":/gris.png"));
            verif2=0;
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/s.png"));
        }
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/k.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/i.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/r.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/y.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/t.png"));
        }
        //boton3--------------------------------------
        if(contc3==-1){
            ui->boton3->setIcon(QIcon(":/gris.png"));
            verif3=0;
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/s.png"));
        }
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/k.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/i.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/r.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/y.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/t.png"));
        }
        //boton4----------------------------------------
        if(contc4==-1){
            ui->boton4->setIcon(QIcon(":/gris.png"));
            verif4=0;
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/s.png"));
        }
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/k.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/i.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/r.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/y.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/t.png"));
        }
    }

    contc1=jug.back().b1;
    if (jug.back().b1==-1){
       contc1=0;
       verif1=0;
    }

    contc2=jug.back().b2;
    if (jug.back().b2==-1){
       contc2=0;
       verif2=0;
    }

    contc3=jug.back().b3;
    if (jug.back().b3==-1){
       contc3=0;
       verif3=0;
    }

    contc4=jug.back().b4;
    if (jug.back().b4==-1){
       contc4=0;
       verif4=0;
    }

    if(verif1==0 || verif2==0 || verif3==0 || verif4==0){
        ui->jugada->setEnabled(false);
    }
}

void MainWindow::on_terminar_clicked()//LISTA reinicia el juego
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Aviso", "¿Desea terminar el juego actual?",QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
    }

    else {
        return;
    }

}

void MainWindow::on_nombre_returnPressed()
{
   QString texto=ui->nombre->text();
   if ((texto.size()<2) || (texto.size()>30)){
       return;
   }
   else{
       ui->nombre->setEnabled(false);
       ui->iniciar->setEnabled(true);
   }

}

void MainWindow::on_cargar_clicked()
{
    this->setVisible(false);
    cargando=1;

    //objetos ocultos---------------------------
    //fila 1
    ui->boton1_1->setVisible(false);
    ui->boton2_1->setVisible(false);
    ui->boton3_1->setVisible(false);
    ui->boton4_1->setVisible(false);
    ui->ver1_1->setVisible(false);
    ui->ver2_1->setVisible(false);
    ui->ver3_1->setVisible(false);
    ui->ver4_1->setVisible(false);
    ui->jug1->setVisible(false);

    //fila 2
    ui->boton1_2->setVisible(false);
    ui->boton2_2->setVisible(false);
    ui->boton3_2->setVisible(false);
    ui->boton4_2->setVisible(false);
    ui->ver1_2->setVisible(false);
    ui->ver2_2->setVisible(false);
    ui->ver3_2->setVisible(false);
    ui->ver4_2->setVisible(false);
    ui->jug2->setVisible(false);

    //fila 3
    ui->boton1_3->setVisible(false);
    ui->boton2_3->setVisible(false);
    ui->boton3_3->setVisible(false);
    ui->boton4_3->setVisible(false);
    ui->ver1_3->setVisible(false);
    ui->ver2_3->setVisible(false);
    ui->ver3_3->setVisible(false);
    ui->ver4_3->setVisible(false);
    ui->jug3->setVisible(false);

    //fila 4
    ui->boton1_4->setVisible(false);
    ui->boton2_4->setVisible(false);
    ui->boton3_4->setVisible(false);
    ui->boton4_4->setVisible(false);
    ui->ver1_4->setVisible(false);
    ui->ver2_4->setVisible(false);
    ui->ver3_4->setVisible(false);
    ui->ver4_4->setVisible(false);
    ui->jug4->setVisible(false);

    //fila 5
    ui->boton1_5->setVisible(false);
    ui->boton2_5->setVisible(false);
    ui->boton3_5->setVisible(false);
    ui->boton4_5->setVisible(false);
    ui->ver1_5->setVisible(false);
    ui->ver2_5->setVisible(false);
    ui->ver3_5->setVisible(false);
    ui->ver4_5->setVisible(false);
    ui->jug5->setVisible(false);

    //fila 6
    ui->boton1_6->setVisible(false);
    ui->boton2_6->setVisible(false);
    ui->boton3_6->setVisible(false);
    ui->boton4_6->setVisible(false);
    ui->ver1_6->setVisible(false);
    ui->ver2_6->setVisible(false);
    ui->ver3_6->setVisible(false);
    ui->ver4_6->setVisible(false);
    ui->jug6->setVisible(false);
    //fila 7

    ui->boton1_7->setVisible(false);
    ui->boton2_7->setVisible(false);
    ui->boton3_7->setVisible(false);
    ui->boton4_7->setVisible(false);
    ui->ver1_7->setVisible(false);
    ui->ver2_7->setVisible(false);
    ui->ver3_7->setVisible(false);
    ui->ver4_7->setVisible(false);
    ui->jug7->setVisible(false);

    //fila 8
    ui->boton1_8->setVisible(false);
    ui->boton2_8->setVisible(false);
    ui->boton3_8->setVisible(false);
    ui->boton4_8->setVisible(false);
    ui->ver1_8->setVisible(false);
    ui->ver2_8->setVisible(false);
    ui->ver3_8->setVisible(false);
    ui->ver4_8->setVisible(false);
    ui->jug8->setVisible(false);

    //configuracion de botones de juego-----------------------------------------------
    ui->boton1->setGeometry(100,410,40,40);
    ui->boton2->setGeometry(170,410,40,40);
    ui->boton3->setGeometry(240,410,40,40);
    ui->boton4->setGeometry(310,410,40,40);
    ui->ver1->setGeometry(370,410,16,16);
    ui->ver2->setGeometry(370,430,16,16);
    ui->ver3->setGeometry(390,410,16,16);
    ui->ver4->setGeometry(390,430,16,16);
    filas=0;
    resty=50;
    jug.clear();
    jug.push_back({-1,-1,-1,-1});//reinicio del vector para deshacer jugadas

    //si abre archivo de texto
    if(saved==0){
        vector <QString>verifcal;//verifica si la calificacion es 0000
        vector <QString>verifjug;//verifica si una jugada es 0000
        int botones=0;
        int combinacion=0;
        int config=0;
        int tiempo=0;
        int tiempoaux=0;
        QString nombre;
        jugfilas.clear();
        calificacion.clear();
        tperjug.clear();

        //jugadas de las filas
        int f1=0;
        int f2=0;
        int f3=0;
        int f4=0;
        int f5=0;
        int f6=0;
        int f7=0;

        //calificacion de las filas
        int c1=0;
        int c2=0;
        int c3=0;
        int c4=0;
        int c5=0;
        int c6=0;
        int c7=0;

        int contador=0;

        QFile guardado(":/guardar/guardado.txt");
        if(guardado.open(QIODevice::ReadOnly)){
            QTextStream datos(&guardado);

            //Toma de datos
            while (!datos.atEnd()){
                QString line=datos.readLine();

                if (contador == 0){
                    botones=line.toInt();
                }
                if (contador==1){//primera linea (combinacion)
                    combinacion=line.toInt();
                    qDebug()<<combinacion<<endl;
                }

                if (contador==2){//segunda linea (configuracion)
                    config=line.toInt();
                    qDebug()<<config<<endl;
                }

                if (contador==3){//tercera linea (tiempo)
                    tiempo=line.toInt();
                    qDebug()<<tiempo<<endl;
                }

                if (contador==4){//cuarta linea(tiempo auxiliar)
                    tiempoaux=line.toInt();
                    qDebug()<<tiempoaux<<endl;
                }

                if (contador==5){//quinta linea (nombre)
                    nombre=line;
                    qDebug()<<nombre<<endl;
                }

                if (contador == 6){
                    f1=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f1<<endl;
                }

                if (contador == 7){
                    f2=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f2<<endl;
                }

                if (contador == 8){
                    f3=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f3<<endl;
                }

                if (contador == 9){
                    f4=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f4<<endl;
                }

                if (contador == 10){
                    f5=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f5<<endl;
                }

                if (contador == 11){
                    f6=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f6<<endl;
                }

                if (contador == 12){
                    f7=line.toInt();
                    verifjug.push_back(line);
                    qDebug()<<f7<<endl;
                }

                if (contador == 13){
                    c1=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c1<<endl;
                }

                if (contador == 14){
                    c2=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c2<<endl;
                }

                if (contador == 15){
                    c3=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c3<<endl;
                }

                if (contador == 16){
                    c4=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c4<<endl;
                }

                if (contador == 17){
                    c5=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c5<<endl;
                }

                if (contador == 18){
                    c6=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c6<<endl;
                }

                if (contador == 19){
                    c7=line.toInt();
                    verifcal.push_back(line);
                    qDebug()<<c7<<endl;
                }

                if (contador==20){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }

                if (contador==21){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }

                if (contador==22){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }

                if (contador==23){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }

                if (contador==24){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }

                if (contador==25){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }

                if (contador==26){
                    Tiempo obj;
                    obj.ctiempo(line.toInt());
                    tperjug.push_back(obj);
                }
                qDebug()<<line;
                contador++;
            }
        }

        //botones
        contc1=(botones/1000);
        botones=botones%1000;

        contc2=(botones/100);
        botones=botones%100;

        contc3=(botones/10);
        botones=botones%10;

        contc4=botones;

        //combinacion
        comb[0]=(combinacion/1000);
        combinacion=combinacion%1000;

        comb[1]=(combinacion/100);
        combinacion=combinacion%100;

        comb[2]=(combinacion/10);
        combinacion=combinacion%10;

        comb[3]=combinacion;

        //configuracion
        configuracion.c_config(config);

        //configuracion del reloj
        r.ctiempo(tiempo);
        r2.ctiempo(tiempoaux);
        ui->hor->display(r.mh());
        ui->min->display(r.mm());
        ui->seg->display(r.ms());


        //nombre
        ui->nombre->setText(nombre);
        ui->nombre->setEnabled(false);

        //Datos de las jugadas

        fourdigits(f1,jugfilas);
        fourdigits(f2,jugfilas);
        fourdigits(f3,jugfilas);
        fourdigits(f4,jugfilas);
        fourdigits(f5,jugfilas);
        fourdigits(f6,jugfilas);
        fourdigits(f7,jugfilas);
        fourdigits(c1,calificacion);
        fourdigits(c2,calificacion);
        fourdigits(c3,calificacion);
        fourdigits(c4,calificacion);
        fourdigits(c5,calificacion);
        fourdigits(c6,calificacion);
        fourdigits(c7,calificacion);

        //elimina las jugadas que son 0 o que no existen o calificaciones
        for (int i=0;i<7;i++){
            int p=jugfilas.size()-1;
            if ((jugfilas.at(p).b1+jugfilas.at(p).b2+jugfilas.at(p).b3+jugfilas.at(p).b4)==0){
                jugfilas.erase(jugfilas.begin()+p);
                calificacion.erase(calificacion.begin()+p);
            }

        }

        //configuracion del elemento-------------------------------
        if (configuracion.g_elemento()==1){//colores
            ui->el1->setIcon(QIcon(":/rojo.png"));
            ui->el2->setIcon(QIcon(":/azul.png"));
            ui->el3->setIcon(QIcon(":/amarillo.png"));
            ui->el4->setIcon(QIcon(":/naranja.png"));
            ui->el5->setIcon(QIcon(":/verde.png"));
            ui->el6->setIcon(QIcon(":/morado.png"));
        }
        if (configuracion.g_elemento()==2){//letras
            ui->el1->setIcon(QIcon(":/A.png"));
            ui->el2->setIcon(QIcon(":/B.png"));
            ui->el3->setIcon(QIcon(":/C.png"));
            ui->el4->setIcon(QIcon(":/D.png"));
            ui->el5->setIcon(QIcon(":/E.png"));
            ui->el6->setIcon(QIcon(":/F.png"));
        }
        if (configuracion.g_elemento()==3){//numeros
            ui->el1->setIcon(QIcon(":/1.png"));
            ui->el2->setIcon(QIcon(":/2.png"));
            ui->el3->setIcon(QIcon(":/3.png"));
            ui->el4->setIcon(QIcon(":/4.png"));
            ui->el5->setIcon(QIcon(":/5.png"));
            ui->el6->setIcon(QIcon(":/6.png"));
        }
        if (configuracion.g_elemento()==4){//Naruto
            ui->el1->setIcon(QIcon(":/s.png"));
            ui->el2->setIcon(QIcon(":/k.png"));
            ui->el3->setIcon(QIcon(":/i.png"));
            ui->el4->setIcon(QIcon(":/r.png"));
            ui->el5->setIcon(QIcon(":/y.png"));
            ui->el6->setIcon(QIcon(":/t.png"));
        }

    }

    //si carga en la misma partida
    if(saved==1){

        //jugadas y calificaciones------------------------------
        jugfilas = jugadasg;
        calificacion =calificaciong;
        tperjug=tperjug2;
        //botones----------------------------
        contc1=contc1g;
        contc2=contc2g;
        contc3=contc3g;
        contc4=contc4g;

        //tiempo--------------------------
        r.ctiempo(rg);
        r2.ctiempo(r2g);
        ui->hor->display(r.mh());
        ui->min->display(r.mm());
        ui->seg->display(r.ms());

    }

    //creando jugadas
    for (int i=0;i<jugfilas.size();i++){

            if (configuracion.g_elemento()==1){//colores
                if(i==0){//primera fila
                    ui->boton1_1->setVisible(true);
                    ui->boton2_1->setVisible(true);
                    ui->boton3_1->setVisible(true);
                    ui->boton4_1->setVisible(true);
                    ui->ver1_1->setVisible(true);
                    ui->ver2_1->setVisible(true);
                    ui->ver3_1->setVisible(true);
                    ui->ver4_1->setVisible(true);
                    ui->jug1->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                        ui->boton1_1->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                        ui->boton1_1->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                        ui->boton1_1->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                        ui->boton1_1->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                        ui->boton1_1->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                        ui->boton1_1->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                        ui->boton2_1->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                        ui->boton2_1->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                        ui->boton2_1->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                        ui->boton2_1->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                        ui->boton2_1->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                        ui->boton2_1->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                        ui->boton3_1->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                        ui->boton3_1->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                        ui->boton3_1->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_1->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                        ui->boton3_1->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                        ui->boton3_1->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                        ui->boton4_1->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_1->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                        ui->boton4_1->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                        ui->boton4_1->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                        ui->boton4_1->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                        ui->boton4_1->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------------

                }

                if(i==1){//segunda fila
                    ui->boton1_2->setVisible(true);
                    ui->boton2_2->setVisible(true);
                    ui->boton3_2->setVisible(true);
                    ui->boton4_2->setVisible(true);
                    ui->ver1_2->setVisible(true);
                    ui->ver2_2->setVisible(true);
                    ui->ver3_2->setVisible(true);
                    ui->ver4_2->setVisible(true);
                    ui->jug2->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_2->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_2->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_2->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_2->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_2->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_2->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_2->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_2->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_2->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_2->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_2->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_2->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_2->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_2->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_2->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_2->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_2->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_2->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_2->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_2->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_2->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_2->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_2->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_2->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------------

                }

                if(i==2){// tercera fila

                    ui->boton1_3->setVisible(true);
                    ui->boton2_3->setVisible(true);
                    ui->boton3_3->setVisible(true);
                    ui->boton4_3->setVisible(true);
                    ui->ver1_3->setVisible(true);
                    ui->ver2_3->setVisible(true);
                    ui->ver3_3->setVisible(true);
                    ui->ver4_3->setVisible(true);
                    ui->jug3->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_3->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_3->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_3->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_3->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_3->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_3->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_3->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_3->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_3->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_3->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_3->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_3->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_3->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_3->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_3->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_3->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_3->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_3->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_3->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_3->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_3->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_3->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_3->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_3->setIcon(QIcon(":/morado.png"));
                    }

                }

                if(i==3){// cuarta fila

                    ui->boton1_4->setVisible(true);
                    ui->boton2_4->setVisible(true);
                    ui->boton3_4->setVisible(true);
                    ui->boton4_4->setVisible(true);
                    ui->ver1_4->setVisible(true);
                    ui->ver2_4->setVisible(true);
                    ui->ver3_4->setVisible(true);
                    ui->ver4_4->setVisible(true);
                    ui->jug4->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_4->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_4->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_4->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_4->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_4->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_4->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_4->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_4->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_4->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_4->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_4->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_4->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_4->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_4->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_4->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_4->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_4->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_4->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_4->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_4->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_4->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_4->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_4->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_4->setIcon(QIcon(":/morado.png"));
                    }
                }

                if(i==4){//quinta fila
                    ui->boton1_5->setVisible(true);
                    ui->boton2_5->setVisible(true);
                    ui->boton3_5->setVisible(true);
                    ui->boton4_5->setVisible(true);
                    ui->ver1_5->setVisible(true);
                    ui->ver2_5->setVisible(true);
                    ui->ver3_5->setVisible(true);
                    ui->ver4_5->setVisible(true);
                    ui->jug5->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_5->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_5->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_5->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_5->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_5->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_5->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_5->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_5->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_5->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_5->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_5->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_5->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_5->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_5->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_5->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_5->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_5->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_5->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_5->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_5->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_5->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_5->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_5->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_5->setIcon(QIcon(":/morado.png"));
                    }
                }

                if(i==5){//sexta fila
                    ui->boton1_6->setVisible(true);
                    ui->boton2_6->setVisible(true);
                    ui->boton3_6->setVisible(true);
                    ui->boton4_6->setVisible(true);
                    ui->ver1_6->setVisible(true);
                    ui->ver2_6->setVisible(true);
                    ui->ver3_6->setVisible(true);
                    ui->ver4_6->setVisible(true);
                    ui->jug6->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_6->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_6->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_6->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_6->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_6->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_6->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_6->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_6->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_6->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_6->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_6->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_6->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_6->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_6->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_6->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_6->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_6->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_6->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_6->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_6->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_6->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_6->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_6->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_6->setIcon(QIcon(":/morado.png"));
                    }
                }

                if(i==6){//septima fila
                    ui->boton1_7->setVisible(true);
                    ui->boton2_7->setVisible(true);
                    ui->boton3_7->setVisible(true);
                    ui->boton4_7->setVisible(true);
                    ui->ver1_7->setVisible(true);
                    ui->ver2_7->setVisible(true);
                    ui->ver3_7->setVisible(true);
                    ui->ver4_7->setVisible(true);
                    ui->jug7->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_7->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_7->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_7->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_7->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_7->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_7->setIcon(QIcon(":/morado.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_7->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_7->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_7->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_7->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_7->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_7->setIcon(QIcon(":/morado.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_7->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_7->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_7->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_7->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_7->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_7->setIcon(QIcon(":/morado.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_7->setIcon(QIcon(":/rojo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_7->setIcon(QIcon(":/azul.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_7->setIcon(QIcon(":/amarillo.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_7->setIcon(QIcon(":/naranja.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_7->setIcon(QIcon(":/verde.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_7->setIcon(QIcon(":/morado.png"));
                    }

                }

            }
            if (configuracion.g_elemento()==2){//letras
                if(i==0){//primera fila
                    ui->boton1_1->setVisible(true);
                    ui->boton2_1->setVisible(true);
                    ui->boton3_1->setVisible(true);
                    ui->boton4_1->setVisible(true);
                    ui->ver1_1->setVisible(true);
                    ui->ver2_1->setVisible(true);
                    ui->ver3_1->setVisible(true);
                    ui->ver4_1->setVisible(true);
                    ui->jug1->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_1->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_1->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_1->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_1->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_1->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_1->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_1->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_1->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_1->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_1->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_1->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_1->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_1->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_1->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_1->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_1->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_1->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_1->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_1->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_1->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_1->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_1->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_1->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_1->setIcon(QIcon(":/F.png"));
                    }

                }

                if(i==1){//segunda fila
                    ui->boton1_2->setVisible(true);
                    ui->boton2_2->setVisible(true);
                    ui->boton3_2->setVisible(true);
                    ui->boton4_2->setVisible(true);
                    ui->ver1_2->setVisible(true);
                    ui->ver2_2->setVisible(true);
                    ui->ver3_2->setVisible(true);
                    ui->ver4_2->setVisible(true);
                    ui->jug2->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_2->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_2->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_2->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_2->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_2->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_2->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_2->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_2->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_2->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_2->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_2->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_2->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_2->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_2->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_2->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_2->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_2->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_2->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_2->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_2->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_2->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_2->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_2->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_2->setIcon(QIcon(":/F.png"));
                    }
                }

                if(i==2){// tercera fila

                    ui->boton1_3->setVisible(true);
                    ui->boton2_3->setVisible(true);
                    ui->boton3_3->setVisible(true);
                    ui->boton4_3->setVisible(true);
                    ui->ver1_3->setVisible(true);
                    ui->ver2_3->setVisible(true);
                    ui->ver3_3->setVisible(true);
                    ui->ver4_3->setVisible(true);
                    ui->jug3->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_3->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_3->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_3->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_3->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_3->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_3->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_3->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_3->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_3->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_3->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_3->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_3->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_3->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_3->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_3->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_3->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_3->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_3->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_3->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_3->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_3->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_3->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_3->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_3->setIcon(QIcon(":/F.png"));
                    }

                }

                if(i==3){// cuarta fila

                    ui->boton1_4->setVisible(true);
                    ui->boton2_4->setVisible(true);
                    ui->boton3_4->setVisible(true);
                    ui->boton4_4->setVisible(true);
                    ui->ver1_4->setVisible(true);
                    ui->ver2_4->setVisible(true);
                    ui->ver3_4->setVisible(true);
                    ui->ver4_4->setVisible(true);
                    ui->jug4->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_4->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_4->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_4->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_4->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_4->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_4->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_4->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_4->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_4->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_4->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_4->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_4->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_4->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_4->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_4->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_4->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_4->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_4->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_4->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_4->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_4->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_4->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_4->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_4->setIcon(QIcon(":/F.png"));
                    }

                }

                if(i==4){//quinta fila
                    ui->boton1_5->setVisible(true);
                    ui->boton2_5->setVisible(true);
                    ui->boton3_5->setVisible(true);
                    ui->boton4_5->setVisible(true);
                    ui->ver1_5->setVisible(true);
                    ui->ver2_5->setVisible(true);
                    ui->ver3_5->setVisible(true);
                    ui->ver4_5->setVisible(true);
                    ui->jug5->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_5->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_5->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_5->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_5->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_5->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_5->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_5->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_5->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_5->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_5->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_5->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_5->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_5->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_5->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_5->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_5->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_5->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_5->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_5->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_5->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_5->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_5->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_5->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_5->setIcon(QIcon(":/F.png"));
                    }

                }

                if(i==5){//sexta fila
                    ui->boton1_6->setVisible(true);
                    ui->boton2_6->setVisible(true);
                    ui->boton3_6->setVisible(true);
                    ui->boton4_6->setVisible(true);
                    ui->ver1_6->setVisible(true);
                    ui->ver2_6->setVisible(true);
                    ui->ver3_6->setVisible(true);
                    ui->ver4_6->setVisible(true);
                    ui->jug6->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_6->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_6->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_6->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_6->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_6->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_6->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_6->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_6->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_6->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_6->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_6->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_6->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_6->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_6->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_6->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_6->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_6->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_6->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_6->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_6->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_6->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_6->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_6->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_6->setIcon(QIcon(":/F.png"));
                    }

                }

                if(i==6){//septima fila

                    ui->boton1_7->setVisible(true);
                    ui->boton2_7->setVisible(true);
                    ui->boton3_7->setVisible(true);
                    ui->boton4_7->setVisible(true);
                    ui->ver1_7->setVisible(true);
                    ui->ver2_7->setVisible(true);
                    ui->ver3_7->setVisible(true);
                    ui->ver4_7->setVisible(true);
                    ui->jug7->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_7->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_7->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_7->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_7->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_7->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_7->setIcon(QIcon(":/F.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_7->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_7->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_7->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_7->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_7->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_7->setIcon(QIcon(":/F.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_7->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_7->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_7->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_7->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_7->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_7->setIcon(QIcon(":/F.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_7->setIcon(QIcon(":/A.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_7->setIcon(QIcon(":/B.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_7->setIcon(QIcon(":/C.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_7->setIcon(QIcon(":/D.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_7->setIcon(QIcon(":/E.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_7->setIcon(QIcon(":/F.png"));
                    }

                }

            }
            if (configuracion.g_elemento()==3){//numeros
                if(i==0){//primera fila
                    ui->boton1_1->setVisible(true);
                    ui->boton2_1->setVisible(true);
                    ui->boton3_1->setVisible(true);
                    ui->boton4_1->setVisible(true);
                    ui->ver1_1->setVisible(true);
                    ui->ver2_1->setVisible(true);
                    ui->ver3_1->setVisible(true);
                    ui->ver4_1->setVisible(true);
                    ui->jug1->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_1->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_1->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_1->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_1->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_1->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_1->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_1->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_1->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_1->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_1->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_1->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_1->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_1->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_1->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_1->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_1->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_1->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_1->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_1->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_1->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_1->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_1->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_1->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_1->setIcon(QIcon(":/6.png"));
                    }

                }

                if(i==1){//segunda fila
                    ui->boton1_2->setVisible(true);
                    ui->boton2_2->setVisible(true);
                    ui->boton3_2->setVisible(true);
                    ui->boton4_2->setVisible(true);
                    ui->ver1_2->setVisible(true);
                    ui->ver2_2->setVisible(true);
                    ui->ver3_2->setVisible(true);
                    ui->ver4_2->setVisible(true);
                    ui->jug2->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_2->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_2->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_2->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_2->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_2->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_2->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_2->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_2->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_2->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_2->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_2->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_2->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_2->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_2->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_2->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_2->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_2->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_2->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_2->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_2->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_2->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_2->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_2->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_2->setIcon(QIcon(":/6.png"));
                    }

                }

                if(i==2){// tercera fila

                    ui->boton1_3->setVisible(true);
                    ui->boton2_3->setVisible(true);
                    ui->boton3_3->setVisible(true);
                    ui->boton4_3->setVisible(true);
                    ui->ver1_3->setVisible(true);
                    ui->ver2_3->setVisible(true);
                    ui->ver3_3->setVisible(true);
                    ui->ver4_3->setVisible(true);
                    ui->jug3->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_3->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_3->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_3->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_3->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_3->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_3->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_3->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_3->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_3->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_3->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_3->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_3->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_3->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_3->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_3->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_3->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_3->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_3->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_3->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_3->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_3->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_3->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_3->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_3->setIcon(QIcon(":/6.png"));
                    }
                }

                if(i==3){// cuarta fila

                    ui->boton1_4->setVisible(true);
                    ui->boton2_4->setVisible(true);
                    ui->boton3_4->setVisible(true);
                    ui->boton4_4->setVisible(true);
                    ui->ver1_4->setVisible(true);
                    ui->ver2_4->setVisible(true);
                    ui->ver3_4->setVisible(true);
                    ui->ver4_4->setVisible(true);
                    ui->jug4->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_4->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_4->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_4->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_4->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_4->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_4->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_4->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_4->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_4->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_4->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_4->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_4->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_4->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_4->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_4->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_4->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_4->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_4->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_4->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_4->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_4->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_4->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_4->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_4->setIcon(QIcon(":/6.png"));
                    }

                }

                if(i==4){//quinta fila
                    ui->boton1_5->setVisible(true);
                    ui->boton2_5->setVisible(true);
                    ui->boton3_5->setVisible(true);
                    ui->boton4_5->setVisible(true);
                    ui->ver1_5->setVisible(true);
                    ui->ver2_5->setVisible(true);
                    ui->ver3_5->setVisible(true);
                    ui->ver4_5->setVisible(true);
                    ui->jug5->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_5->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_5->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_5->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_5->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_5->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_5->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_5->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_5->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_5->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_5->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_5->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_5->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_5->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_5->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_5->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_5->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_5->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_5->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_5->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_5->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_5->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_5->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_5->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_5->setIcon(QIcon(":/6.png"));
                    }
                }

                if(i==5){//sexta fila
                    ui->boton1_6->setVisible(true);
                    ui->boton2_6->setVisible(true);
                    ui->boton3_6->setVisible(true);
                    ui->boton4_6->setVisible(true);
                    ui->ver1_6->setVisible(true);
                    ui->ver2_6->setVisible(true);
                    ui->ver3_6->setVisible(true);
                    ui->ver4_6->setVisible(true);
                    ui->jug6->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_6->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_6->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_6->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_6->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_6->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_6->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_6->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_6->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_6->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_6->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_6->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_6->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_6->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_6->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_6->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_6->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_6->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_6->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_6->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_6->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_6->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_6->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_6->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_6->setIcon(QIcon(":/6.png"));
                    }

                }

                if(i==6){//septima fila

                    ui->boton1_7->setVisible(true);
                    ui->boton2_7->setVisible(true);
                    ui->boton3_7->setVisible(true);
                    ui->boton4_7->setVisible(true);
                    ui->ver1_7->setVisible(true);
                    ui->ver2_7->setVisible(true);
                    ui->ver3_7->setVisible(true);
                    ui->ver4_7->setVisible(true);
                    ui->jug7->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_7->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_7->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_7->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_7->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_7->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_7->setIcon(QIcon(":/6.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_7->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_7->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_7->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_7->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_7->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_7->setIcon(QIcon(":/6.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_7->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_7->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_7->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_7->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_7->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_7->setIcon(QIcon(":/6.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_7->setIcon(QIcon(":/1.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_7->setIcon(QIcon(":/2.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_7->setIcon(QIcon(":/3.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_7->setIcon(QIcon(":/4.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_7->setIcon(QIcon(":/5.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_7->setIcon(QIcon(":/6.png"));
                    }

                }


            }
            if (configuracion.g_elemento()==4){//poderes oculares
                //skiryt
                if(i==0){//primera fila
                    ui->boton1_1->setVisible(true);
                    ui->boton2_1->setVisible(true);
                    ui->boton3_1->setVisible(true);
                    ui->boton4_1->setVisible(true);
                    ui->ver1_1->setVisible(true);
                    ui->ver2_1->setVisible(true);
                    ui->ver3_1->setVisible(true);
                    ui->ver4_1->setVisible(true);
                    ui->jug1->setVisible(true);

                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_1->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_1->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_1->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_1->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_1->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_1->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_1->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_1->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_1->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_1->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_1->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_1->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_1->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_1->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_1->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_1->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_1->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_1->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_1->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_1->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_1->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_1->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_1->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_1->setIcon(QIcon(":/t.png"));
                    }

                }

                if(i==1){//segunda fila
                    ui->boton1_2->setVisible(true);
                    ui->boton2_2->setVisible(true);
                    ui->boton3_2->setVisible(true);
                    ui->boton4_2->setVisible(true);
                    ui->ver1_2->setVisible(true);
                    ui->ver2_2->setVisible(true);
                    ui->ver3_2->setVisible(true);
                    ui->ver4_2->setVisible(true);
                    ui->jug2->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_2->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_2->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_2->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_2->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_2->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_2->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_2->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_2->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_2->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_2->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_2->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_2->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_2->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_2->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_2->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_2->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_2->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_2->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_2->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_2->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_2->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_2->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_2->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_2->setIcon(QIcon(":/t.png"));
                    }

                }

                if(i==2){// tercera fila

                    ui->boton1_3->setVisible(true);
                    ui->boton2_3->setVisible(true);
                    ui->boton3_3->setVisible(true);
                    ui->boton4_3->setVisible(true);
                    ui->ver1_3->setVisible(true);
                    ui->ver2_3->setVisible(true);
                    ui->ver3_3->setVisible(true);
                    ui->ver4_3->setVisible(true);
                    ui->jug3->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_3->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_3->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_3->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_3->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_3->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_3->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_3->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_3->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_3->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_3->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_3->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_3->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_3->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_3->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_3->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_3->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_3->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_3->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_3->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_3->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_3->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_3->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_3->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_3->setIcon(QIcon(":/t.png"));
                    }
                }

                if(i==3){// cuarta fila

                    ui->boton1_4->setVisible(true);
                    ui->boton2_4->setVisible(true);
                    ui->boton3_4->setVisible(true);
                    ui->boton4_4->setVisible(true);
                    ui->ver1_4->setVisible(true);
                    ui->ver2_4->setVisible(true);
                    ui->ver3_4->setVisible(true);
                    ui->ver4_4->setVisible(true);
                    ui->jug4->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_4->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_4->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_4->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_4->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_4->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_4->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_4->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_4->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_4->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_4->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_4->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_4->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_4->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_4->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_4->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_4->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_4->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_4->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_4->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_4->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_4->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_4->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_4->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_4->setIcon(QIcon(":/t.png"));
                    }

                }

                if(i==4){//quinta fila
                    ui->boton1_5->setVisible(true);
                    ui->boton2_5->setVisible(true);
                    ui->boton3_5->setVisible(true);
                    ui->boton4_5->setVisible(true);
                    ui->ver1_5->setVisible(true);
                    ui->ver2_5->setVisible(true);
                    ui->ver3_5->setVisible(true);
                    ui->ver4_5->setVisible(true);
                    ui->jug5->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_5->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_5->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_5->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_5->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_5->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_5->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_5->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_5->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_5->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_5->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_5->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_5->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_5->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_5->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_5->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_5->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_5->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_5->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_5->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_5->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_5->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_5->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_5->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_5->setIcon(QIcon(":/t.png"));
                    }
                }

                if(i==5){//sexta fila
                    ui->boton1_6->setVisible(true);
                    ui->boton2_6->setVisible(true);
                    ui->boton3_6->setVisible(true);
                    ui->boton4_6->setVisible(true);
                    ui->ver1_6->setVisible(true);
                    ui->ver2_6->setVisible(true);
                    ui->ver3_6->setVisible(true);
                    ui->ver4_6->setVisible(true);
                    ui->jug6->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_6->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_6->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_6->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_6->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_6->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_6->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_6->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_6->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_6->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_6->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_6->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_6->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_6->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_6->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_6->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_6->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_6->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_6->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_6->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_6->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_6->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_6->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_6->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_6->setIcon(QIcon(":/t.png"));
                    }

                }

                if(i==6){//septima fila

                    ui->boton1_7->setVisible(true);
                    ui->boton2_7->setVisible(true);
                    ui->boton3_7->setVisible(true);
                    ui->boton4_7->setVisible(true);
                    ui->ver1_7->setVisible(true);
                    ui->ver2_7->setVisible(true);
                    ui->ver3_7->setVisible(true);
                    ui->ver4_7->setVisible(true);
                    ui->jug7->setVisible(true);


                    if ((jugfilas.at(i).b1)-1==0){
                    ui->boton1_7->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==1){
                    ui->boton1_7->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==2){
                    ui->boton1_7->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==3){
                    ui->boton1_7->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==4){
                    ui->boton1_7->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b1)-1==5){
                    ui->boton1_7->setIcon(QIcon(":/t.png"));
                    }
                    //-------------------------------------------------------------
                    if ((jugfilas.at(i).b2)-1==0){
                    ui->boton2_7->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==1){
                    ui->boton2_7->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==2){
                    ui->boton2_7->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==3){
                    ui->boton2_7->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==4){
                    ui->boton2_7->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b2)-1==5){
                    ui->boton2_7->setIcon(QIcon(":/t.png"));
                    }
                    //----------------------------------------------------------------
                    if ((jugfilas.at(i).b3)-1==0){
                    ui->boton3_7->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==1){
                    ui->boton3_7->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==2){
                    ui->boton3_7->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==3){
                    ui->boton3_7->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==4){
                    ui->boton3_7->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b3)-1==5){
                    ui->boton3_7->setIcon(QIcon(":/t.png"));
                    }
                    //------------------------------------------------------------------
                    if ((jugfilas.at(i).b4)-1==0){
                    ui->boton4_7->setIcon(QIcon(":/s.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==1){
                    ui->boton4_7->setIcon(QIcon(":/k.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==2){
                    ui->boton4_7->setIcon(QIcon(":/i.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==3){
                    ui->boton4_7->setIcon(QIcon(":/r.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==4){
                    ui->boton4_7->setIcon(QIcon(":/y.png"));
                    }
                    if ((jugfilas.at(i).b4)-1==5){
                    ui->boton4_7->setIcon(QIcon(":/t.png"));
                    }

                }

            }

            ui->boton1->setGeometry(100,410-resty,40,40);
            ui->boton2->setGeometry(170,410-resty,40,40);
            ui->boton3->setGeometry(240,410-resty,40,40);
            ui->boton4->setGeometry(310,410-resty,40,40);
            ui->ver1->setGeometry(370,410-resty,16,16);
            ui->ver2->setGeometry(370,430-resty,16,16);
            ui->ver3->setGeometry(390,410-resty,16,16);
            ui->ver4->setGeometry(390,430-resty,16,16);

            filas++;//cambia el numero de fila
            resty=resty+50;//cambia la posicion de los botones de juego
        }

    //creando calificacion
    for (int i=0;i<calificacion.size();i++){
        //fila 1
        if (i==0){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_1->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_1->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_1->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_1->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_1->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_1->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_1->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_1->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_1->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_1->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_1->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_1->setIcon(QIcon(":/blanco.png"));
            }

        }

        //fila 2
        if (i==1){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_2->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_2->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_2->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_2->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_2->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_2->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_2->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_2->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_2->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_2->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_2->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_2->setIcon(QIcon(":/blanco.png"));
            }
        }

        //fila 3
        if (i==2){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_3->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_3->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_3->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_3->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_3->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_3->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_3->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_3->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_3->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_3->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_3->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_3->setIcon(QIcon(":/blanco.png"));
            }
        }

        //fila 4
        if (i==3){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_4->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_4->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_4->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_4->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_4->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_4->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_4->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_4->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_4->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_4->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_4->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_4->setIcon(QIcon(":/blanco.png"));
            }
        }

        //fila 5
        if (i==4){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_5->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_5->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_5->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_5->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_5->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_5->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_5->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_5->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_5->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_5->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_5->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_5->setIcon(QIcon(":/blanco.png"));
            }
        }

        //fila 6
        if (i==5){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_6->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_6->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_6->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_6->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_6->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_6->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_6->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_6->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_6->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_6->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_6->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_6->setIcon(QIcon(":/blanco.png"));
            }
        }

        //fila 7
        if (i==6){
            //color gris-----------------------------------------
            if(calificacion.at(i).b1==0){
                ui->ver1_7->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b2==0){
                ui->ver2_7->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b3==0){
                ui->ver3_7->setIcon(QIcon(":/gris.png"));
            }
            if(calificacion.at(i).b4==0){
                ui->ver4_7->setIcon(QIcon(":/gris.png"));
            }

            //color negro----------------------------------------
            if(calificacion.at(i).b1==1){
                ui->ver1_7->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b2==1){
                ui->ver2_7->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b3==1){
                ui->ver3_7->setIcon(QIcon(":/negro.png"));
            }
            if(calificacion.at(i).b4==1){
                ui->ver4_7->setIcon(QIcon(":/negro.png"));
            }

            //color blanco-------------------------------------
            if(calificacion.at(i).b1==2){
                ui->ver1_7->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b2==2){
                ui->ver2_7->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b3==2){
                ui->ver3_7->setIcon(QIcon(":/blanco.png"));
            }
            if(calificacion.at(i).b4==2){
                ui->ver4_7->setIcon(QIcon(":/blanco.png"));
            }
        }

    }

    //apariencia de los botones de juego
    if (configuracion.g_elemento()==1){
        //boton1------------------------------------------------
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/rojo.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/azul.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/naranja.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/verde.png"));
        }
        if (contc1==6){
            ui->boton1->setIcon(QIcon(":/morado.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        //boton 2-----------------------------------------------------
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/rojo.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/azul.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/naranja.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/verde.png"));
        }
        if (contc2==6){
            ui->boton2->setIcon(QIcon(":/morado.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        //boton 3-------------------------------------------------------
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/rojo.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/azul.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/naranja.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/verde.png"));
        }
        if (contc3==6){
            ui->boton3->setIcon(QIcon(":/morado.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        //boton 4---------------------------------------------------
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/rojo.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/azul.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/naranja.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/verde.png"));
        }
        if (contc4==6){
            ui->boton4->setIcon(QIcon(":/morado.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
    }

    if (configuracion.g_elemento()==2){
        //boton1----------------------------------------
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/A.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/B.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/C.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/D.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/E.png"));
        }
        if (contc1==6){
            ui->boton1->setIcon(QIcon(":/F.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        //boton 2----------------------------------------------
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/A.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/B.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/C.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/D.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/E.png"));
        }
        if (contc2==6){
            ui->boton2->setIcon(QIcon(":/F.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        //boton 3----------------------------------------------
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/A.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/B.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/C.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/D.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/E.png"));
        }
        if (contc3==6){
            ui->boton3->setIcon(QIcon(":/F.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        //boton 4-----------------------------------------------
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/A.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/B.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/C.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/D.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/E.png"));
        }
        if (contc4==6){
            ui->boton4->setIcon(QIcon(":/F.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
    }

    if (configuracion.g_elemento()==3){
        //boton1------------------------------------------
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/1.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/2.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/3.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/4.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/5.png"));
        }
        if (contc1==6){
            ui->boton1->setIcon(QIcon(":/6.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        //boton 2---------------------------------------------
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/1.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/2.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/3.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/4.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/5.png"));
        }
        if (contc2==6){
            ui->boton2->setIcon(QIcon(":/6.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        //boton 3----------------------------------------
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/1.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/2.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/3.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/4.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/5.png"));
        }
        if (contc3==6){
            ui->boton3->setIcon(QIcon(":/6.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        //boton 4---------------------------------------
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/1.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/2.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/3.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/4.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/5.png"));
        }
        if (contc4==6){
            ui->boton4->setIcon(QIcon(":/6.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
    }

    if (configuracion.g_elemento()==4){
        //boton1----------------------------------------------
        if (contc1==1){
            ui->boton1->setIcon(QIcon(":/s.png"));
        }
        if (contc1==2){
            ui->boton1->setIcon(QIcon(":/k.png"));
        }
        if (contc1==3){
            ui->boton1->setIcon(QIcon(":/i.png"));
        }
        if (contc1==4){
            ui->boton1->setIcon(QIcon(":/r.png"));
        }
        if (contc1==5){
            ui->boton1->setIcon(QIcon(":/y.png"));
        }
        if (contc1==6){
            ui->boton1->setIcon(QIcon(":/t.png"));
        }
        if (contc1==0){
            ui->boton1->setIcon(QIcon(":/gris.png"));
        }
        //boton 2-------------------------------------------------
        if (contc2==1){
            ui->boton2->setIcon(QIcon(":/s.png"));
        }
        if (contc2==2){
            ui->boton2->setIcon(QIcon(":/k.png"));
        }
        if (contc2==3){
            ui->boton2->setIcon(QIcon(":/i.png"));
        }
        if (contc2==4){
            ui->boton2->setIcon(QIcon(":/r.png"));
        }
        if (contc2==5){
            ui->boton2->setIcon(QIcon(":/y.png"));
        }
        if (contc2==6){
            ui->boton2->setIcon(QIcon(":/t.png"));
        }
        if (contc2==0){
            ui->boton2->setIcon(QIcon(":/gris.png"));
        }
        //boton 3---------------------------------------------------
        if (contc3==1){
            ui->boton3->setIcon(QIcon(":/s.png"));
        }
        if (contc3==2){
            ui->boton3->setIcon(QIcon(":/k.png"));
        }
        if (contc3==3){
            ui->boton3->setIcon(QIcon(":/i.png"));
        }
        if (contc3==4){
            ui->boton3->setIcon(QIcon(":/r.png"));
        }
        if (contc3==5){
            ui->boton3->setIcon(QIcon(":/y.png"));
        }
        if (contc3==6){
            ui->boton3->setIcon(QIcon(":/t.png"));
        }
        if (contc3==0){
            ui->boton3->setIcon(QIcon(":/gris.png"));
        }
        //boton 4---------------------------------------------------
        if (contc4==1){
            ui->boton4->setIcon(QIcon(":/s.png"));
        }
        if (contc4==2){
            ui->boton4->setIcon(QIcon(":/k.png"));
        }
        if (contc4==3){
            ui->boton4->setIcon(QIcon(":/i.png"));
        }
        if (contc4==4){
            ui->boton4->setIcon(QIcon(":/r.png"));
        }
        if (contc4==5){
            ui->boton4->setIcon(QIcon(":/y.png"));
        }
        if (contc4==6){
            ui->boton4->setIcon(QIcon(":/t.png"));
        }
        if (contc4==0){
            ui->boton4->setIcon(QIcon(":/gris.png"));
        }
    }

    //bloqueo de botones
    ui->boton1->setEnabled(false);
    ui->boton2->setEnabled(false);
    ui->boton3->setEnabled(false);
    ui->boton4->setEnabled(false);
    ui->prueba->setVisible(true);
    ui->prueba->setEnabled(true);
    ui->cargar->setEnabled(false);
    ui->guardar->setEnabled(false);
    ui->deshacer->setEnabled(false);
    ui->iniciar->setEnabled(false);
    ui->jugada->setEnabled(false);
    ui->hor->setEnabled(false);
    ui->min->setEnabled(false);
    ui->seg->setEnabled(false);

    this->setVisible(true);
}

void MainWindow::on_guardar_clicked()
{
    //guarda las variables
    saved=1;
    jugadasg=jugfilas;//almacena las jugadas
    calificaciong=calificacion;//almacena la calificacion
    rg = r.tiempotot();//almacena el tiempo
    r2g = r2.tiempotot();//almanena el tiempo auxiliar
    contc1g=contc1;
    contc2g=contc2;
    contc3g=contc3;
    contc4g=contc4;
    tperjug2=tperjug;//almacena los tiempos por jugada actuales
    //---------------------------------------------
    QFile guardado("guardado.txt");

    //datos de los botones
    QString botones=QString::number(contc1)+QString::number(contc2)+QString::number(contc3)+QString::number(contc4);

    //datos de la combinacion
    QString combinacion=QString::number(comb[0])+QString::number(comb[1])+QString::number(comb[2])+QString::number(comb[3]);

    //datos de la configuracion-------------------------------------------------
    QString dificultad = QString::number(configuracion.g_dificultad());
    QString reloj=QString::number(configuracion.g_reloj());
    QString repeticion=QString::number(configuracion.g_repeticion());
    QString elementos=QString::number(configuracion.g_elemento());

    //datos del tiempo-----------------------------------------------------
    QString tiempo=QString::number(r.tiempotot());
    QString tiempoaux=QString::number(r2.tiempotot());

    //datos del jugador
    QString nombre=ui->nombre->text();

    //jugadas de las filas
    QString f1="";
    QString f2="";
    QString f3="";
    QString f4="";
    QString f5="";
    QString f6="";
    QString f7="";

    //calificacion de las filas
    QString c1="";
    QString c2="";
    QString c3="";
    QString c4="";
    QString c5="";
    QString c6="";
    QString c7="";

    int tam=0;//tamaño del vector

    //asignacion de los valores a las jugadas y calificaciones
    for (int i=0;i<7;i++){

        //solamente se puede guardar si se ha realizado almenos una jugada
        if (i==0){
            f1=f1+QString::number(jugfilas.at(i).b1);
            f1=f1+QString::number(jugfilas.at(i).b2);
            f1=f1+QString::number(jugfilas.at(i).b3);
            f1=f1+QString::number(jugfilas.at(i).b4);

            c1=c1+QString::number(calificacion.at(i).b1);
            c1=c1+QString::number(calificacion.at(i).b2);
            c1=c1+QString::number(calificacion.at(i).b3);
            c1=c1+QString::number(calificacion.at(i).b4);
        }
        if (i==1){
            if (tam>(jugfilas.size()-1)){
                f2=f2+"0";
                c2=c2+"0";
                continue;
            }
            f2=f2+QString::number(jugfilas.at(i).b1);
            f2=f2+QString::number(jugfilas.at(i).b2);
            f2=f2+QString::number(jugfilas.at(i).b3);
            f2=f2+QString::number(jugfilas.at(i).b4);

            c2=c2+QString::number(calificacion.at(i).b1);
            c2=c2+QString::number(calificacion.at(i).b2);
            c2=c2+QString::number(calificacion.at(i).b3);
            c2=c2+QString::number(calificacion.at(i).b4);
        }
        if (i==2){
            if (tam>(jugfilas.size()-1)){
                f3=f3+"0";
                c3=c3+"0";
                continue;
            }
            f3=f3+QString::number(jugfilas.at(i).b1);
            f3=f3+QString::number(jugfilas.at(i).b2);
            f3=f3+QString::number(jugfilas.at(i).b3);
            f3=f3+QString::number(jugfilas.at(i).b4);

            c3=c3+QString::number(calificacion.at(i).b1);
            c3=c3+QString::number(calificacion.at(i).b2);
            c3=c3+QString::number(calificacion.at(i).b3);
            c3=c3+QString::number(calificacion.at(i).b4);
        }
        if (i==3){
            if (tam>(jugfilas.size()-1)){
                f4=f4+"0";
                c4=c4+"0";
                continue;
            }
            f4=f4+QString::number(jugfilas.at(i).b1);
            f4=f4+QString::number(jugfilas.at(i).b2);
            f4=f4+QString::number(jugfilas.at(i).b3);
            f4=f4+QString::number(jugfilas.at(i).b4);

            c4=c4+QString::number(calificacion.at(i).b1);
            c4=c4+QString::number(calificacion.at(i).b2);
            c4=c4+QString::number(calificacion.at(i).b3);
            c4=c4+QString::number(calificacion.at(i).b4);
        }
        if (i==4){
            if (tam>(jugfilas.size()-1)){
                f5=f5+"0";
                c5=c5+"0";
                continue;
            }
            f5=f5+QString::number(jugfilas.at(i).b1);
            f5=f5+QString::number(jugfilas.at(i).b2);
            f5=f5+QString::number(jugfilas.at(i).b3);
            f5=f5+QString::number(jugfilas.at(i).b4);

            c5=c5+QString::number(calificacion.at(i).b1);
            c5=c5+QString::number(calificacion.at(i).b2);
            c5=c5+QString::number(calificacion.at(i).b3);
            c5=c5+QString::number(calificacion.at(i).b4);
        }
        if (i==5){
            if (tam>(jugfilas.size()-1)){
                f6=f6+"0";
                c6=c6+"0";
                continue;
            }
            f6=f6+QString::number(jugfilas.at(i).b1);
            f6=f6+QString::number(jugfilas.at(i).b2);
            f6=f6+QString::number(jugfilas.at(i).b3);
            f6=f6+QString::number(jugfilas.at(i).b4);

            c6=c6+QString::number(calificacion.at(i).b1);
            c6=c6+QString::number(calificacion.at(i).b2);
            c6=c6+QString::number(calificacion.at(i).b3);
            c6=c6+QString::number(calificacion.at(i).b4);
        }
        if (i==6){
            if (tam>(jugfilas.size()-1)){
                f7=f7+"0";
                c7=c7+"0";
                continue;
            }
            f7=f7+QString::number(jugfilas.at(i).b1);
            f7=f7+QString::number(jugfilas.at(i).b2);
            f7=f7+QString::number(jugfilas.at(i).b3);
            f7=f7+QString::number(jugfilas.at(i).b4);

            c7=c7+QString::number(calificacion.at(i).b1);
            c7=c7+QString::number(calificacion.at(i).b2);
            c7=c7+QString::number(calificacion.at(i).b3);
            c7=c7+QString::number(calificacion.at(i).b4);
        }

        tam++;
    }

    if(guardado.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream datosguardados(&guardado);
        datosguardados << botones << endl;
        datosguardados << combinacion <<  endl;
        datosguardados << dificultad << reloj << repeticion << elementos << endl;
        datosguardados << tiempo <<endl;
        datosguardados << tiempoaux <<endl;
        datosguardados << nombre <<endl;

        datosguardados << f1 << endl;
        datosguardados << f2 << endl;
        datosguardados << f3 << endl;
        datosguardados << f4 << endl;
        datosguardados << f5 << endl;
        datosguardados << f6 << endl;
        datosguardados << f7 << endl;

        datosguardados << c1 << endl;
        datosguardados << c2 << endl;
        datosguardados << c3 << endl;
        datosguardados << c4 << endl;
        datosguardados << c5 << endl;
        datosguardados << c6 << endl;
        datosguardados << c7 << endl;

        for (int i=0;i<tperjug.size();i++){//guarda los tiempos por jugada
            datosguardados << QString::number(tperjug.at(i).tiempotot())<<endl;
        }
    }
    guardado.close();
}

void MainWindow::on_prueba_clicked()//boton de continuar
{
    verif1=0;
    verif2=0;
    verif3=0;
    verif4=0;
    ui->boton1->setEnabled(true);
    ui->boton2->setEnabled(true);
    ui->boton3->setEnabled(true);
    ui->boton4->setEnabled(true);
    ui->prueba->setVisible(false);
    ui->prueba->setEnabled(false);
    ui->cargar->setEnabled(true);
    ui->guardar->setEnabled(true);
    ui->deshacer->setEnabled(true);
    ui->iniciar->setEnabled(false);

    if(contc1>0){
        verif1=1;
    }
    if(contc2>0){
        verif2=1;
    }
    if(contc3>0){
        verif3=1;
    }
    if(contc4>0){
        verif4=1;
    }
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }

    if (configuracion.g_reloj()==1 || configuracion.g_reloj()==3 || configuracion.g_reloj()==4){
        ui->hor->setEnabled(true);
        ui->min->setEnabled(true);
        ui->seg->setEnabled(true);
    }
    cargando=0;
}

void MainWindow::on_ayuda_clicked()
{
    QProcess::startDetached( "cmd /Q /C start C:/Users/Jerem/Desktop/manual.pdf" );

}
