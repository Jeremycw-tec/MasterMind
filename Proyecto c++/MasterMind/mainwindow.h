
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tiempo.h"
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
    void on_boton1_clicked();

    void on_boton2_clicked();

    void on_boton3_clicked();

    void on_boton4_clicked();

    void on_iniciar_clicked();

    void on_jugada_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
