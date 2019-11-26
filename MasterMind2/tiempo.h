#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo {
private:
    int h;
    int m;
    int s;
public:
    Tiempo();//constructor por defecto
    Tiempo(int,int,int);//recibe horas, minutos y segundos
    ~Tiempo();
    void ctiempo(int);//cambia todo el tiempo
    void ch(int);//cambiar horas
    void cm(int);//cambiar minutos
    void cs(int);//cambiar segundos

    int mh()const;//mostrar horas
    int mm()const;//mostrar minutos
    int ms()const;//mostrar segundos
    int tiempotot();
    void cronometro();//-1 segundo
    void temporarizador();//+1 segundo

};

#endif // TIEMPO_H
