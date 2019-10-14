//Librerias
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColor"
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

//Algunas varibles iniciales

//verificadores para el boton de hacer jugada
int verif1=0;
int verif2=0;
int verif3=0;
int verif4=0;

int cal[4];//Organizacion de la calificacion
int cal2[4];
int cal3[4];
int cal4[4];
int cal5[4];
int cal6[4];
int cal7[4];
int cal8[4];

int comb[4];//combinacion aleatoria
char colores[6][10]={"rojo","azul","amarillo","naranja","verde","morado"};//colores
char letras [6][2]={"A","B","C","D","F","G"};//letras
char numeros[6][2]={"1","2","3","4","5","6"};//numeros

//Contadores para los botones
int filas=0;//contador para las filas ocultas
int contc1=0; //Boton 1
int contc2=0; //Boton 2
int contc3=0; //Boton 3
int contc4=0; //Boton 4
int resty=50; //Movimiento en las coordenadas
//-------------------------------------------------------------------------------
//Funciones
void datoaleatorio(int com[4]){
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        com[i] = rand() % 6;
    }
    return;
}//Funciona correctamente


int verif(int n,int com[4]) { //Verifica si un numero se encuenta en el arreglo

    for (int i=0; i < 4; i++) {
        if (n == com[i]) {
            return 1;
        }
    }
    return 0;
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

//---------------------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calif(cal);
    calif(cal2);
    calif(cal3);
    calif(cal4);
    calif(cal5);
    calif(cal6);
    calif(cal7);
    calif(cal8);
    //Objetos ocultos
    //fila 1
    ui->boton1_1->setVisible(false);
    ui->boton2_1->setVisible(false);
    ui->boton3_1->setVisible(false);
    ui->boton4_1->setVisible(false);
    ui->ver1_1->setVisible(false);
    ui->ver2_1->setVisible(false);
    ui->ver3_1->setVisible(false);
    ui->ver4_1->setVisible(false);

    //fila 2
    ui->boton1_2->setVisible(false);
    ui->boton2_2->setVisible(false);
    ui->boton3_2->setVisible(false);
    ui->boton4_2->setVisible(false);
    ui->ver1_2->setVisible(false);
    ui->ver2_2->setVisible(false);
    ui->ver3_2->setVisible(false);
    ui->ver4_2->setVisible(false);

    //fila 3
    ui->boton1_3->setVisible(false);
    ui->boton2_3->setVisible(false);
    ui->boton3_3->setVisible(false);
    ui->boton4_3->setVisible(false);
    ui->ver1_3->setVisible(false);
    ui->ver2_3->setVisible(false);
    ui->ver3_3->setVisible(false);
    ui->ver4_3->setVisible(false);

    //fila 4
    ui->boton1_4->setVisible(false);
    ui->boton2_4->setVisible(false);
    ui->boton3_4->setVisible(false);
    ui->boton4_4->setVisible(false);
    ui->ver1_4->setVisible(false);
    ui->ver2_4->setVisible(false);
    ui->ver3_4->setVisible(false);
    ui->ver4_4->setVisible(false);

    //fila 5
    ui->boton1_5->setVisible(false);
    ui->boton2_5->setVisible(false);
    ui->boton3_5->setVisible(false);
    ui->boton4_5->setVisible(false);
    ui->ver1_5->setVisible(false);
    ui->ver2_5->setVisible(false);
    ui->ver3_5->setVisible(false);
    ui->ver4_5->setVisible(false);

    //fila 6
    ui->boton1_6->setVisible(false);
    ui->boton2_6->setVisible(false);
    ui->boton3_6->setVisible(false);
    ui->boton4_6->setVisible(false);
    ui->ver1_6->setVisible(false);
    ui->ver2_6->setVisible(false);
    ui->ver3_6->setVisible(false);
    ui->ver4_6->setVisible(false);

    //fila 7
    ui->boton1_7->setVisible(false);
    ui->boton2_7->setVisible(false);
    ui->boton3_7->setVisible(false);
    ui->boton4_7->setVisible(false);
    ui->ver1_7->setVisible(false);
    ui->ver2_7->setVisible(false);
    ui->ver3_7->setVisible(false);
    ui->ver4_7->setVisible(false);

    //fila 8
    ui->boton1_8->setVisible(false);
    ui->boton2_8->setVisible(false);
    ui->boton3_8->setVisible(false);
    ui->boton4_8->setVisible(false);
    ui->ver1_8->setVisible(false);
    ui->ver2_8->setVisible(false);
    ui->ver3_8->setVisible(false);
    ui->ver4_8->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_boton1_clicked()
{
    verif1=1;
    if(contc1==6){
        contc1=0;
    }
    if (contc1==0){
    ui->boton1->setIcon(QIcon(":/rojo.jpg"));

    }
    if (contc1==1){
    ui->boton1->setIcon(QIcon(":/azul.png"));
    }
    if (contc1==2){
    ui->boton1->setIcon(QIcon(":/amarillo.png"));
    }
    if (contc1==3){
    ui->boton1->setIcon(QIcon(":/naranja.jpg"));
    }
    if (contc1==4){
    ui->boton1->setIcon(QIcon(":/verde.png"));
    }
    if (contc1==5){
    ui->boton1->setIcon(QIcon(":/morado.png"));
    }
    contc1++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }
}

void MainWindow::on_boton2_clicked()
{
    verif2=1;
    if(contc2==6){
        contc2=0;
    }
    if (contc2==0){
    ui->boton2->setIcon(QIcon(":/rojo.jpg"));
    }
    if (contc2==1){
    ui->boton2->setIcon(QIcon(":/azul.png"));
    }
    if (contc2==2){
    ui->boton2->setIcon(QIcon(":/amarillo.png"));
    }
    if (contc2==3){
    ui->boton2->setIcon(QIcon(":/naranja.jpg"));
    }
    if (contc2==4){
    ui->boton2->setIcon(QIcon(":/verde.png"));
    }
    if (contc2==5){
    ui->boton2->setIcon(QIcon(":/morado.png"));
    }
    contc2++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }
}

void MainWindow::on_boton3_clicked()
{
    verif3=1;
    if(contc3==6){
        contc3=0;
    }
    if (contc3==0){
    ui->boton3->setIcon(QIcon(":/rojo.jpg"));
    }
    if (contc3==1){
    ui->boton3->setIcon(QIcon(":/azul.png"));
    }
    if (contc3==2){
    ui->boton3->setIcon(QIcon(":/amarillo.png"));
    }
    if (contc3==3){
    ui->boton3->setIcon(QIcon(":/naranja.jpg"));
    }
    if (contc3==4){
    ui->boton3->setIcon(QIcon(":/verde.png"));
    }
    if (contc3==5){
    ui->boton3->setIcon(QIcon(":/morado.png"));
    }
    contc3++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }
}

void MainWindow::on_boton4_clicked()
{
    verif4=1;
    if(contc4==6){
        contc4=0;
    }
    if (contc4==0){
    ui->boton4->setIcon(QIcon(":/rojo.jpg"));
    }
    if (contc4==1){
    ui->boton4->setIcon(QIcon(":/azul.png"));
    }
    if (contc4==2){
    ui->boton4->setIcon(QIcon(":/amarillo.png"));
    }
    if (contc4==3){
    ui->boton4->setIcon(QIcon(":/naranja.jpg"));
    }
    if (contc4==4){
    ui->boton4->setIcon(QIcon(":/verde.png"));
    }
    if (contc4==5){
    ui->boton4->setIcon(QIcon(":/morado.png"));
    }
    contc4++;
    if(verif1==1 && verif2==1 && verif3==1 && verif4==1){
        ui->jugada->setEnabled(true);
    }
}

void MainWindow::on_iniciar_clicked()
{
    datoaleatorio(comb);//creacion de la combinacion
    ui->iniciar->setEnabled(false);
    ui->boton1->setEnabled(true);
    ui->boton2->setEnabled(true);
    ui->boton3->setEnabled(true);
    ui->boton4->setEnabled(true);
    //ui->jugada->setEnabled(true);
}

void MainWindow::on_jugada_clicked()
{

    int combinacion[4]={contc1-1,contc2-1,contc3-1,contc4-1};

    if(filas==0){//Cambia los datos de los elementos de la primera fila
        ui->boton1_1->setVisible(true);
        ui->boton2_1->setVisible(true);
        ui->boton3_1->setVisible(true);
        ui->boton4_1->setVisible(true);
        ui->ver1_1->setVisible(true);
        ui->ver2_1->setVisible(true);
        ui->ver3_1->setVisible(true);
        ui->ver4_1->setVisible(true);

        if (contc1-1==0){
        ui->boton1_1->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc1-1==1){
        ui->boton1_1->setIcon(QIcon(":/azul.png"));
        }
        if (contc1-1==2){
        ui->boton1_1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc1-1==3){
        ui->boton1_1->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc1-1==4){
        ui->boton1_1->setIcon(QIcon(":/verde.png"));
        }
        if (contc1-1==5){
        ui->boton1_1->setIcon(QIcon(":/morado.png"));
        }
        //-------------------------------------------------------------
        if (contc2-1==0){
        ui->boton2_1->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc2-1==1){
        ui->boton2_1->setIcon(QIcon(":/azul.png"));
        }
        if (contc2-1==2){
        ui->boton2_1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc2-1==3){
        ui->boton2_1->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc2-1==4){
        ui->boton2_1->setIcon(QIcon(":/verde.png"));
        }
        if (contc2-1==5){
        ui->boton2_1->setIcon(QIcon(":/morado.png"));
        }
        //----------------------------------------------------------------
        if (contc3-1==0){
        ui->boton3_1->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc3-1==1){
        ui->boton3_1->setIcon(QIcon(":/azul.png"));
        }
        if (contc3-1==2){
        ui->boton3_1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc3-1==3){
        ui->boton3_1->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc3-1==4){
        ui->boton3_1->setIcon(QIcon(":/verde.png"));
        }
        if (contc3-1==5){
        ui->boton3_1->setIcon(QIcon(":/morado.png"));
        }
        //------------------------------------------------------------------
        if (contc4-1==0){
        ui->boton4_1->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc4-1==1){
        ui->boton4_1->setIcon(QIcon(":/azul.png"));
        }
        if (contc4-1==2){
        ui->boton4_1->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc4-1==3){
        ui->boton4_1->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc4-1==4){
        ui->boton4_1->setIcon(QIcon(":/verde.png"));
        }
        if (contc4-1==5){
        ui->boton4_1->setIcon(QIcon(":/morado.png"));
        }
        //----------------------------------------------------------------------
        for (int i=0;i<4;i++){
            if (combinacion[i]==comb[i]){
                if(cal[i]==0){
                    ui->ver1_1->setIcon(QIcon(":/negro.png"));
                    continue;
                }
                if(cal[i]==1){
                    ui->ver2_1->setIcon(QIcon(":/negro.png"));
                    continue;
                }
                if(cal[i]==3){
                    ui->ver3_1->setIcon(QIcon(":/negro.png"));
                    continue;
                }
                if(cal[i]==4){
                    ui->ver4_1->setIcon(QIcon(":/negro.png"));
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal[i]==0){
                    ui->ver1_1->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
                if(cal[i]==1){
                    ui->ver2_1->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
                if(cal[i]==3){
                    ui->ver3_1->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
                if(cal[i]==4){
                    ui->ver4_1->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
            }
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

        if (contc1-1==0){
        ui->boton1_2->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc1-1==1){
        ui->boton1_2->setIcon(QIcon(":/azul.png"));
        }
        if (contc1-1==2){
        ui->boton1_2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc1-1==3){
        ui->boton1_2->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc1-1==4){
        ui->boton1_2->setIcon(QIcon(":/verde.png"));
        }
        if (contc1-1==5){
        ui->boton1_2->setIcon(QIcon(":/morado.png"));
        }
        //-------------------------------------------------------------
        if (contc2-1==0){
        ui->boton2_2->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc2-1==1){
        ui->boton2_2->setIcon(QIcon(":/azul.png"));
        }
        if (contc2-1==2){
        ui->boton2_2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc2-1==3){
        ui->boton2_2->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc2-1==4){
        ui->boton2_2->setIcon(QIcon(":/verde.png"));
        }
        if (contc2-1==5){
        ui->boton2_2->setIcon(QIcon(":/morado.png"));
        }
        //----------------------------------------------------------------
        if (contc3-1==0){
        ui->boton3_2->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc3-1==1){
        ui->boton3_2->setIcon(QIcon(":/azul.png"));
        }
        if (contc3-1==2){
        ui->boton3_2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc3-1==3){
        ui->boton3_2->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc3-1==4){
        ui->boton3_2->setIcon(QIcon(":/verde.png"));
        }
        if (contc3-1==5){
        ui->boton3_2->setIcon(QIcon(":/morado.png"));
        }
        //------------------------------------------------------------------
        if (contc4-1==0){
        ui->boton4_2->setIcon(QIcon(":/rojo.jpg"));
        }
        if (contc4-1==1){
        ui->boton4_2->setIcon(QIcon(":/azul.png"));
        }
        if (contc4-1==2){
        ui->boton4_2->setIcon(QIcon(":/amarillo.png"));
        }
        if (contc4-1==3){
        ui->boton4_2->setIcon(QIcon(":/naranja.jpg"));
        }
        if (contc4-1==4){
        ui->boton4_2->setIcon(QIcon(":/verde.png"));
        }
        if (contc4-1==5){
        ui->boton4_2->setIcon(QIcon(":/morado.png"));
        }
        //----------------------------------------------------------------------
        for (int i=0;i<4;i++){
            if (combinacion[i]==comb[i]){

                if(cal2[i]==0){
                    ui->ver1_2->setIcon(QIcon(":/negro.png"));
                    continue;
                }
                if(cal2[i]==1){
                    ui->ver2_2->setIcon(QIcon(":/negro.png"));
                    continue;
                }
                if(cal2[i]==3){
                    ui->ver3_2->setIcon(QIcon(":/negro.png"));
                    continue;
                }
                if(cal2[i]==4){
                    ui->ver4_2->setIcon(QIcon(":/negro.png"));
                    continue;
                }

            }

            if (verif(combinacion[i],comb)==true){
                if(cal2[i]==0){
                    ui->ver1_2->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
                if(cal2[i]==1){
                    ui->ver2_2->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
                if(cal2[i]==3){
                    ui->ver3_2->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
                if(cal2[i]==4){
                    ui->ver4_2->setIcon(QIcon(":/blanco.png"));
                    continue;
                }
            }
        }
    }


    ui->boton1->setIcon(QIcon(":/gris.jpg"));
    ui->boton2->setIcon(QIcon(":/gris.jpg"));
    ui->boton3->setIcon(QIcon(":/gris.jpg"));
    ui->boton4->setIcon(QIcon(":/gris.jpg"));
    ui->ver1->setIcon(QIcon(":/gris.jpg"));
    ui->ver2->setIcon(QIcon(":/gris.jpg"));
    ui->ver3->setIcon(QIcon(":/gris.jpg"));
    ui->ver4->setIcon(QIcon(":/gris.jpg"));

    ui->boton1->setGeometry(110,510-resty,40,40);
    ui->boton2->setGeometry(180,510-resty,40,40);
    ui->boton3->setGeometry(250,510-resty,40,40);
    ui->boton4->setGeometry(320,510-resty,40,40);
    ui->ver1->setGeometry(380,510-resty,16,16);
    ui->ver2->setGeometry(380,530-resty,16,16);
    ui->ver3->setGeometry(400,510-resty,16,16);
    ui->ver4->setGeometry(400,530-resty,16,16);
    ui->jugada->setEnabled(false);

    contc1=0;
    contc2=0;
    contc3=0;
    contc4=0;
    verif1=0;
    verif2=0;
    verif3=0;
    verif4=0;
    resty+=50;
    filas++;
}
