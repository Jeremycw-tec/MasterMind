#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo {
private:
    int h;
    int m;
    int s;
public:
    Tiempo();
    Tiempo(int);
    ~Tiempo();
    void ch(int);//cambiar horas
    void cm(int);//cambiar minutos
    void cs(int);//cambiar segundos

    int mh()const;//mostrar horas
    int mm()const;//mostrar minutos
    int ms()const;//mostrar segundos
    int tiempotot();
    void temporarizador();

};

#endif // TIEMPO_H
