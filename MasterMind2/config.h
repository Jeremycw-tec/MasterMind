#ifndef CONFIG_H
#define CONFIG_H


class config
{
private:
    int dificultad;
    int repeticion;
    int reloj;
    int elemento;
public:
    config();
    config(int,int,int,int);
    ~config();
    void c_config(int);//crea los valores con un numero de 4 digitos
    void c_dificultad(int);
    void c_repeticion(int);
    void c_reloj(int);
    void c_elemento(int);

    int g_dificultad()const;
    int g_repeticion()const;
    int g_reloj()const;
    int g_elemento()const;
    //c=change,g=get
};

#endif // CONFIG_H
