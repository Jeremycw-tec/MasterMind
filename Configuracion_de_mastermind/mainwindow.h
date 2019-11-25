#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cpjugada_clicked();

    void on_cpjuego_clicked();

    void on_rsi_clicked();

    void on_rno_clicked();

    void on_dificultadop1_clicked();

    void on_dificultadop2_clicked();

    void on_dificultadop3_clicked();

    void on_horas_valueChanged(int arg1);

    void on_minutos_valueChanged(int arg1);

    void on_segundos_valueChanged(int arg1);

    void on_repsi_clicked();

    void on_repno_clicked();

    void on_elementocolor_clicked();

    void on_elementoletra_clicked();

    void on_elementonumero_clicked();

    void on_elementodefinido_clicked();


    void on_guardar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
