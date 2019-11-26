#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>//reproducir mp3

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void funcionActivacionTimer();

private slots:
    void on_boton1_clicked();

    void on_boton2_clicked();

    void on_boton3_clicked();

    void on_boton4_clicked();

    void on_jugada_clicked();

    void on_iniciar_clicked();

    void on_deshacer_clicked();

    void on_terminar_clicked();

    void on_nombre_returnPressed();

    void on_cargar_clicked();

    void on_guardar_clicked();
    
    void on_prueba_clicked();

    void on_ayuda_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *reproductor;//reproducir aplausos

};
#endif // MAINWINDOW_H
