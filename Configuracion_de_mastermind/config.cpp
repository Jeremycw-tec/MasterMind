#include "config.h"
config::config()
{
    dificultad=1;
    reloj=1;
    repeticion=1;
    elemento=1;
}

config::config(int d,int r, int r2, int e){
    dificultad=d;
    reloj=r;
    repeticion=r2;
    elemento=e;
}

config::~config(){

}

//Cambio de datos----------------------------------------------------------------------------
void config::c_dificultad(int d){
    dificultad=d;
}

void config::c_reloj(int r){
    reloj=r;
}

void config::c_repeticion(int r2){
    repeticion=r2;
}

void config::c_elemento(int e){
    elemento=e;
}

//---------------------------------------------------
int config::g_dificultad() const{
    return dificultad;
}

int config::g_reloj() const{
    return reloj;
}

int config::g_repeticion() const{
    return repeticion;
}

int config::g_elemento() const{
    return elemento;
}
