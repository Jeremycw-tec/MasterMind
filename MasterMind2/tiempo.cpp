#include "Tiempo.h"

Tiempo::Tiempo(){
    h=0;
    m=0;
    s=0;
}

Tiempo::Tiempo(int hor,int min,int seg) {

    s=seg;
    h=hor;
    m=min;

}

void Tiempo::temporarizador(){

    int hor = h * 3600;
    int min = m * 60;
    int seg = s;
    int temtot = (hor + min + seg)+1;//Tiempo total +1 segundo
    hor = 0;
    min = 0;
    seg = 0;

    for (int i = 0; temtot >= 60; i++) {
        if (temtot >= 3600) {
            hor++;
            temtot -= 3600;
            continue;
        }
        if (temtot >= 60) {
            min++;
            temtot -= 60;
            continue;
        }
    }

    s = temtot;
    h = hor;
    m = min;
}

Tiempo::~Tiempo() {

}

//Cambio de datos
void Tiempo::ch(int hor) {
    h = hor;
}

void Tiempo::cm(int min) {
    m = min;
}
void Tiempo::cs(int seg) {
    s = seg;
}

//Retorna los datos
int Tiempo::mh()const  {
    return h;
}

int Tiempo::mm() const{
    return m;
}

int Tiempo::ms()const {
    return s;
}


void Tiempo::cronometro() {//-1 segundo
    int hor = h * 3600;
    int min = m * 60;
    int seg = s;
    int temtot = (hor + min + seg)-1;//Tiempo total -1 segundo
    hor = 0;
    min = 0;
    seg = 0;

    for (int i = 0; temtot >= 60; i++) {
        if (temtot >= 3600) {
            hor++;
            temtot -= 3600;
            continue;
        }
        if (temtot >= 60) {
            min++;
            temtot -= 60;
            continue;
        }
    }
    s = temtot;
    h = hor;
    m = min;
}

int Tiempo::tiempotot() {//retorna el tiempo total en segundos
    int hor = h * 3600;
    int min = m * 60;
    int seg = s;
    int temtot = (hor + min + seg);
    return temtot;
}

void Tiempo::ctiempo(int seg){//Recibe tiempo en segundos y determina h,m,s
    int hor=0;
    int min=0;

    for (int i = 0; seg >= 60; i++) {
        if (seg >= 3600) {
            hor++;
            seg -= 3600;
            continue;
        }
        if (seg >= 60) {
            min++;
            seg -= 60;
            continue;
        }
    }
    s=seg;
    h=hor;
    m=min;
}

