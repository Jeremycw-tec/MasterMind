/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *boton3_1;
    QPushButton *boton2_6;
    QLabel *minutos;
    QPushButton *boton4_1;
    QPushButton *ver4_8;
    QLabel *horas;
    QPushButton *boton2_2;
    QPushButton *boton2_8;
    QPushButton *cargar;
    QPushButton *boton3_2;
    QPushButton *ver1_4;
    QLabel *jug1;
    QPushButton *jugada;
    QPushButton *el4;
    QPushButton *boton1_1;
    QLabel *njugadas;
    QPushButton *ver4_6;
    QPushButton *ver1_8;
    QLabel *lnombre;
    QPushButton *boton1_5;
    QPushButton *el2;
    QPushButton *el6;
    QPushButton *boton1_7;
    QPushButton *ver2_2;
    QPushButton *boton3;
    QPushButton *boton2_5;
    QPushButton *boton1_8;
    QPushButton *ver1_1;
    QPushButton *terminar;
    QPushButton *boton4_6;
    QPushButton *ver1_2;
    QPushButton *ver2_5;
    QLabel *jug7;
    QPushButton *boton1_4;
    QPushButton *boton3_6;
    QPushButton *boton1;
    QPushButton *ver2_4;
    QPushButton *ayuda;
    QPushButton *ver2_6;
    QPushButton *ver4_7;
    QPushButton *ver4_1;
    QLabel *jug2;
    QPushButton *deshacer;
    QPushButton *boton4;
    QPushButton *ver4_2;
    QPushButton *boton3_8;
    QPushButton *ver3_3;
    QPushButton *boton4_7;
    QPushButton *ver4;
    QPushButton *ver4_4;
    QLabel *jug4;
    QLabel *jug6;
    QPushButton *ver3;
    QPushButton *ver3_4;
    QLabel *jug5;
    QPushButton *ver3_7;
    QPushButton *ver2_1;
    QPushButton *boton2_1;
    QPushButton *boton2_7;
    QPushButton *boton4_2;
    QPushButton *ver3_6;
    QPushButton *ver4_3;
    QPushButton *ver2_7;
    QPushButton *ver4_5;
    QPushButton *ver1_5;
    QPushButton *boton4_4;
    QPushButton *boton3_5;
    QPushButton *iniciar;
    QPushButton *ver1;
    QPushButton *ver1_7;
    QPushButton *boton4_8;
    QPushButton *ver2_3;
    QPushButton *boton2;
    QPushButton *ver1_3;
    QPushButton *guardar;
    QLabel *segundos;
    QPushButton *boton2_3;
    QPushButton *ver1_6;
    QPushButton *ver3_5;
    QLabel *jug3;
    QLineEdit *nombre;
    QPushButton *boton3_4;
    QPushButton *boton4_3;
    QPushButton *boton1_3;
    QPushButton *ver2_8;
    QPushButton *boton3_7;
    QPushButton *ver3_8;
    QPushButton *boton1_6;
    QPushButton *ver3_1;
    QPushButton *boton2_4;
    QLabel *jug8;
    QPushButton *boton3_3;
    QPushButton *boton1_2;
    QPushButton *boton4_5;
    QPushButton *el3;
    QPushButton *ver3_2;
    QPushButton *el5;
    QPushButton *ver2;
    QLabel *orden;
    QPushButton *el1;
    QLCDNumber *hor;
    QLCDNumber *min;
    QLCDNumber *seg;
    QPushButton *winlose;
    QPushButton *prueba;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(631, 639);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        boton3_1 = new QPushButton(centralwidget);
        boton3_1->setObjectName(QString::fromUtf8("boton3_1"));
        boton3_1->setEnabled(true);
        boton3_1->setGeometry(QRect(240, 410, 40, 40));
        boton3_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_1->setIconSize(QSize(40, 40));
        boton2_6 = new QPushButton(centralwidget);
        boton2_6->setObjectName(QString::fromUtf8("boton2_6"));
        boton2_6->setEnabled(true);
        boton2_6->setGeometry(QRect(170, 160, 40, 40));
        boton2_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/gris.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        boton2_6->setIcon(icon);
        boton2_6->setIconSize(QSize(40, 40));
        minutos = new QLabel(centralwidget);
        minutos->setObjectName(QString::fromUtf8("minutos"));
        minutos->setGeometry(QRect(130, 520, 47, 13));
        boton4_1 = new QPushButton(centralwidget);
        boton4_1->setObjectName(QString::fromUtf8("boton4_1"));
        boton4_1->setEnabled(true);
        boton4_1->setGeometry(QRect(310, 410, 40, 40));
        boton4_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_1->setIconSize(QSize(40, 40));
        ver4_8 = new QPushButton(centralwidget);
        ver4_8->setObjectName(QString::fromUtf8("ver4_8"));
        ver4_8->setGeometry(QRect(390, 80, 16, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/gris.png"), QSize(), QIcon::Normal, QIcon::Off);
        ver4_8->setIcon(icon1);
        horas = new QLabel(centralwidget);
        horas->setObjectName(QString::fromUtf8("horas"));
        horas->setGeometry(QRect(20, 520, 47, 13));
        boton2_2 = new QPushButton(centralwidget);
        boton2_2->setObjectName(QString::fromUtf8("boton2_2"));
        boton2_2->setEnabled(true);
        boton2_2->setGeometry(QRect(170, 360, 40, 40));
        boton2_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_2->setIcon(icon);
        boton2_2->setIconSize(QSize(40, 40));
        boton2_8 = new QPushButton(centralwidget);
        boton2_8->setObjectName(QString::fromUtf8("boton2_8"));
        boton2_8->setEnabled(true);
        boton2_8->setGeometry(QRect(170, 60, 40, 40));
        boton2_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_8->setIcon(icon);
        boton2_8->setIconSize(QSize(40, 40));
        cargar = new QPushButton(centralwidget);
        cargar->setObjectName(QString::fromUtf8("cargar"));
        cargar->setGeometry(QRect(440, 430, 81, 31));
        boton3_2 = new QPushButton(centralwidget);
        boton3_2->setObjectName(QString::fromUtf8("boton3_2"));
        boton3_2->setEnabled(true);
        boton3_2->setGeometry(QRect(240, 360, 40, 40));
        boton3_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_2->setIcon(icon);
        boton3_2->setIconSize(QSize(40, 40));
        ver1_4 = new QPushButton(centralwidget);
        ver1_4->setObjectName(QString::fromUtf8("ver1_4"));
        ver1_4->setEnabled(true);
        ver1_4->setGeometry(QRect(370, 260, 16, 16));
        ver1_4->setIcon(icon1);
        jug1 = new QLabel(centralwidget);
        jug1->setObjectName(QString::fromUtf8("jug1"));
        jug1->setEnabled(true);
        jug1->setGeometry(QRect(70, 420, 16, 16));
        jugada = new QPushButton(centralwidget);
        jugada->setObjectName(QString::fromUtf8("jugada"));
        jugada->setEnabled(false);
        jugada->setGeometry(QRect(20, 480, 91, 31));
        el4 = new QPushButton(centralwidget);
        el4->setObjectName(QString::fromUtf8("el4"));
        el4->setGeometry(QRect(560, 280, 40, 40));
        el4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        el4->setIconSize(QSize(40, 40));
        boton1_1 = new QPushButton(centralwidget);
        boton1_1->setObjectName(QString::fromUtf8("boton1_1"));
        boton1_1->setEnabled(true);
        boton1_1->setGeometry(QRect(100, 410, 40, 40));
        QPalette palette;
        QBrush brush(QColor(176, 176, 176, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QRadialGradient gradient(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(255, 255, 255, 255));
        gradient.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QRadialGradient gradient1(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(255, 255, 255, 255));
        gradient1.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QRadialGradient gradient2(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(255, 255, 255, 255));
        gradient2.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QRadialGradient gradient3(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(255, 255, 255, 255));
        gradient3.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush5(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QRadialGradient gradient4(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(255, 255, 255, 255));
        gradient4.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush6(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        QRadialGradient gradient5(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(255, 255, 255, 255));
        gradient5.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush7(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QRadialGradient gradient6(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(255, 255, 255, 255));
        gradient6.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush8(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QRadialGradient gradient7(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(255, 255, 255, 255));
        gradient7.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush9(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        QRadialGradient gradient8(0.3, -0.4, 1.35, 0.3, -0.4);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(255, 255, 255, 255));
        gradient8.setColorAt(1, QColor(136, 136, 136, 255));
        QBrush brush10(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        QBrush brush11(QColor(176, 176, 176, 128));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        boton1_1->setPalette(palette);
        boton1_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_1->setIconSize(QSize(40, 40));
        boton1_1->setFlat(false);
        njugadas = new QLabel(centralwidget);
        njugadas->setObjectName(QString::fromUtf8("njugadas"));
        njugadas->setGeometry(QRect(30, 440, 61, 20));
        ver4_6 = new QPushButton(centralwidget);
        ver4_6->setObjectName(QString::fromUtf8("ver4_6"));
        ver4_6->setGeometry(QRect(390, 180, 16, 16));
        ver4_6->setIcon(icon1);
        ver1_8 = new QPushButton(centralwidget);
        ver1_8->setObjectName(QString::fromUtf8("ver1_8"));
        ver1_8->setEnabled(true);
        ver1_8->setGeometry(QRect(370, 60, 16, 16));
        ver1_8->setIcon(icon1);
        lnombre = new QLabel(centralwidget);
        lnombre->setObjectName(QString::fromUtf8("lnombre"));
        lnombre->setGeometry(QRect(360, 520, 47, 16));
        boton1_5 = new QPushButton(centralwidget);
        boton1_5->setObjectName(QString::fromUtf8("boton1_5"));
        boton1_5->setEnabled(true);
        boton1_5->setGeometry(QRect(100, 210, 40, 40));
        boton1_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_5->setIconSize(QSize(40, 40));
        boton1_5->setFlat(false);
        el2 = new QPushButton(centralwidget);
        el2->setObjectName(QString::fromUtf8("el2"));
        el2->setGeometry(QRect(560, 140, 40, 40));
        el2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        el2->setIconSize(QSize(40, 40));
        el6 = new QPushButton(centralwidget);
        el6->setObjectName(QString::fromUtf8("el6"));
        el6->setGeometry(QRect(560, 420, 40, 40));
        el6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        el6->setIconSize(QSize(40, 40));
        boton1_7 = new QPushButton(centralwidget);
        boton1_7->setObjectName(QString::fromUtf8("boton1_7"));
        boton1_7->setEnabled(true);
        boton1_7->setGeometry(QRect(100, 110, 40, 40));
        boton1_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_7->setIconSize(QSize(40, 40));
        boton1_7->setFlat(false);
        ver2_2 = new QPushButton(centralwidget);
        ver2_2->setObjectName(QString::fromUtf8("ver2_2"));
        ver2_2->setGeometry(QRect(370, 380, 16, 16));
        ver2_2->setIcon(icon1);
        boton3 = new QPushButton(centralwidget);
        boton3->setObjectName(QString::fromUtf8("boton3"));
        boton3->setEnabled(false);
        boton3->setGeometry(QRect(240, 410, 40, 40));
        boton3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3->setIcon(icon1);
        boton3->setIconSize(QSize(40, 40));
        boton2_5 = new QPushButton(centralwidget);
        boton2_5->setObjectName(QString::fromUtf8("boton2_5"));
        boton2_5->setEnabled(true);
        boton2_5->setGeometry(QRect(170, 210, 40, 40));
        boton2_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_5->setIcon(icon);
        boton2_5->setIconSize(QSize(40, 40));
        boton1_8 = new QPushButton(centralwidget);
        boton1_8->setObjectName(QString::fromUtf8("boton1_8"));
        boton1_8->setEnabled(true);
        boton1_8->setGeometry(QRect(100, 60, 40, 40));
        boton1_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_8->setIconSize(QSize(40, 40));
        boton1_8->setFlat(false);
        ver1_1 = new QPushButton(centralwidget);
        ver1_1->setObjectName(QString::fromUtf8("ver1_1"));
        ver1_1->setEnabled(true);
        ver1_1->setGeometry(QRect(370, 410, 16, 16));
        ver1_1->setIcon(icon1);
        terminar = new QPushButton(centralwidget);
        terminar->setObjectName(QString::fromUtf8("terminar"));
        terminar->setEnabled(true);
        terminar->setGeometry(QRect(220, 480, 91, 31));
        boton4_6 = new QPushButton(centralwidget);
        boton4_6->setObjectName(QString::fromUtf8("boton4_6"));
        boton4_6->setEnabled(true);
        boton4_6->setGeometry(QRect(310, 160, 40, 40));
        boton4_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_6->setIcon(icon);
        boton4_6->setIconSize(QSize(40, 40));
        ver1_2 = new QPushButton(centralwidget);
        ver1_2->setObjectName(QString::fromUtf8("ver1_2"));
        ver1_2->setEnabled(true);
        ver1_2->setGeometry(QRect(370, 360, 16, 16));
        ver1_2->setIcon(icon1);
        ver2_5 = new QPushButton(centralwidget);
        ver2_5->setObjectName(QString::fromUtf8("ver2_5"));
        ver2_5->setGeometry(QRect(370, 230, 16, 16));
        ver2_5->setIcon(icon1);
        jug7 = new QLabel(centralwidget);
        jug7->setObjectName(QString::fromUtf8("jug7"));
        jug7->setGeometry(QRect(70, 120, 16, 16));
        boton1_4 = new QPushButton(centralwidget);
        boton1_4->setObjectName(QString::fromUtf8("boton1_4"));
        boton1_4->setEnabled(true);
        boton1_4->setGeometry(QRect(100, 260, 40, 40));
        boton1_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_4->setIconSize(QSize(40, 40));
        boton1_4->setFlat(false);
        boton3_6 = new QPushButton(centralwidget);
        boton3_6->setObjectName(QString::fromUtf8("boton3_6"));
        boton3_6->setEnabled(true);
        boton3_6->setGeometry(QRect(240, 160, 40, 40));
        boton3_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_6->setIcon(icon);
        boton3_6->setIconSize(QSize(40, 40));
        boton1 = new QPushButton(centralwidget);
        boton1->setObjectName(QString::fromUtf8("boton1"));
        boton1->setEnabled(false);
        boton1->setGeometry(QRect(100, 410, 40, 40));
        boton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1->setIcon(icon1);
        boton1->setIconSize(QSize(40, 40));
        boton1->setFlat(false);
        ver2_4 = new QPushButton(centralwidget);
        ver2_4->setObjectName(QString::fromUtf8("ver2_4"));
        ver2_4->setGeometry(QRect(370, 280, 16, 16));
        ver2_4->setIcon(icon1);
        ayuda = new QPushButton(centralwidget);
        ayuda->setObjectName(QString::fromUtf8("ayuda"));
        ayuda->setGeometry(QRect(540, 480, 71, 31));
        ver2_6 = new QPushButton(centralwidget);
        ver2_6->setObjectName(QString::fromUtf8("ver2_6"));
        ver2_6->setGeometry(QRect(370, 180, 16, 16));
        ver2_6->setIcon(icon1);
        ver4_7 = new QPushButton(centralwidget);
        ver4_7->setObjectName(QString::fromUtf8("ver4_7"));
        ver4_7->setGeometry(QRect(390, 130, 16, 16));
        ver4_7->setIcon(icon1);
        ver4_1 = new QPushButton(centralwidget);
        ver4_1->setObjectName(QString::fromUtf8("ver4_1"));
        ver4_1->setGeometry(QRect(390, 430, 16, 16));
        ver4_1->setIcon(icon1);
        ver4_1->setIconSize(QSize(16, 16));
        jug2 = new QLabel(centralwidget);
        jug2->setObjectName(QString::fromUtf8("jug2"));
        jug2->setGeometry(QRect(70, 370, 16, 16));
        deshacer = new QPushButton(centralwidget);
        deshacer->setObjectName(QString::fromUtf8("deshacer"));
        deshacer->setGeometry(QRect(330, 480, 91, 31));
        boton4 = new QPushButton(centralwidget);
        boton4->setObjectName(QString::fromUtf8("boton4"));
        boton4->setEnabled(false);
        boton4->setGeometry(QRect(310, 410, 40, 40));
        boton4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4->setIcon(icon1);
        boton4->setIconSize(QSize(40, 40));
        ver4_2 = new QPushButton(centralwidget);
        ver4_2->setObjectName(QString::fromUtf8("ver4_2"));
        ver4_2->setGeometry(QRect(390, 380, 16, 16));
        ver4_2->setIcon(icon1);
        boton3_8 = new QPushButton(centralwidget);
        boton3_8->setObjectName(QString::fromUtf8("boton3_8"));
        boton3_8->setEnabled(true);
        boton3_8->setGeometry(QRect(240, 60, 40, 40));
        boton3_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_8->setIcon(icon);
        boton3_8->setIconSize(QSize(40, 40));
        ver3_3 = new QPushButton(centralwidget);
        ver3_3->setObjectName(QString::fromUtf8("ver3_3"));
        ver3_3->setGeometry(QRect(390, 310, 16, 16));
        ver3_3->setIcon(icon1);
        boton4_7 = new QPushButton(centralwidget);
        boton4_7->setObjectName(QString::fromUtf8("boton4_7"));
        boton4_7->setEnabled(true);
        boton4_7->setGeometry(QRect(310, 110, 40, 40));
        boton4_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_7->setIcon(icon);
        boton4_7->setIconSize(QSize(40, 40));
        ver4 = new QPushButton(centralwidget);
        ver4->setObjectName(QString::fromUtf8("ver4"));
        ver4->setGeometry(QRect(390, 430, 16, 16));
        ver4->setIcon(icon1);
        ver4_4 = new QPushButton(centralwidget);
        ver4_4->setObjectName(QString::fromUtf8("ver4_4"));
        ver4_4->setGeometry(QRect(390, 280, 16, 16));
        ver4_4->setIcon(icon1);
        jug4 = new QLabel(centralwidget);
        jug4->setObjectName(QString::fromUtf8("jug4"));
        jug4->setGeometry(QRect(70, 270, 16, 16));
        jug6 = new QLabel(centralwidget);
        jug6->setObjectName(QString::fromUtf8("jug6"));
        jug6->setGeometry(QRect(70, 170, 16, 16));
        ver3 = new QPushButton(centralwidget);
        ver3->setObjectName(QString::fromUtf8("ver3"));
        ver3->setGeometry(QRect(390, 410, 16, 16));
        ver3->setIcon(icon1);
        ver3_4 = new QPushButton(centralwidget);
        ver3_4->setObjectName(QString::fromUtf8("ver3_4"));
        ver3_4->setGeometry(QRect(390, 260, 16, 16));
        ver3_4->setIcon(icon1);
        jug5 = new QLabel(centralwidget);
        jug5->setObjectName(QString::fromUtf8("jug5"));
        jug5->setGeometry(QRect(70, 220, 16, 16));
        ver3_7 = new QPushButton(centralwidget);
        ver3_7->setObjectName(QString::fromUtf8("ver3_7"));
        ver3_7->setGeometry(QRect(390, 110, 16, 16));
        ver3_7->setIcon(icon1);
        ver2_1 = new QPushButton(centralwidget);
        ver2_1->setObjectName(QString::fromUtf8("ver2_1"));
        ver2_1->setGeometry(QRect(370, 430, 16, 16));
        ver2_1->setIcon(icon1);
        boton2_1 = new QPushButton(centralwidget);
        boton2_1->setObjectName(QString::fromUtf8("boton2_1"));
        boton2_1->setEnabled(true);
        boton2_1->setGeometry(QRect(170, 410, 40, 40));
        boton2_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_1->setIconSize(QSize(40, 40));
        boton2_7 = new QPushButton(centralwidget);
        boton2_7->setObjectName(QString::fromUtf8("boton2_7"));
        boton2_7->setEnabled(true);
        boton2_7->setGeometry(QRect(170, 110, 40, 40));
        boton2_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_7->setIcon(icon);
        boton2_7->setIconSize(QSize(40, 40));
        boton4_2 = new QPushButton(centralwidget);
        boton4_2->setObjectName(QString::fromUtf8("boton4_2"));
        boton4_2->setEnabled(true);
        boton4_2->setGeometry(QRect(310, 360, 40, 40));
        boton4_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_2->setIcon(icon);
        boton4_2->setIconSize(QSize(40, 40));
        ver3_6 = new QPushButton(centralwidget);
        ver3_6->setObjectName(QString::fromUtf8("ver3_6"));
        ver3_6->setGeometry(QRect(390, 160, 16, 16));
        ver3_6->setIcon(icon1);
        ver4_3 = new QPushButton(centralwidget);
        ver4_3->setObjectName(QString::fromUtf8("ver4_3"));
        ver4_3->setGeometry(QRect(390, 330, 16, 16));
        ver4_3->setIcon(icon1);
        ver2_7 = new QPushButton(centralwidget);
        ver2_7->setObjectName(QString::fromUtf8("ver2_7"));
        ver2_7->setGeometry(QRect(370, 130, 16, 16));
        ver2_7->setIcon(icon1);
        ver4_5 = new QPushButton(centralwidget);
        ver4_5->setObjectName(QString::fromUtf8("ver4_5"));
        ver4_5->setGeometry(QRect(390, 230, 16, 16));
        ver4_5->setIcon(icon1);
        ver1_5 = new QPushButton(centralwidget);
        ver1_5->setObjectName(QString::fromUtf8("ver1_5"));
        ver1_5->setEnabled(true);
        ver1_5->setGeometry(QRect(370, 210, 16, 16));
        ver1_5->setIcon(icon1);
        boton4_4 = new QPushButton(centralwidget);
        boton4_4->setObjectName(QString::fromUtf8("boton4_4"));
        boton4_4->setEnabled(true);
        boton4_4->setGeometry(QRect(310, 260, 40, 40));
        boton4_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_4->setIcon(icon);
        boton4_4->setIconSize(QSize(40, 40));
        boton3_5 = new QPushButton(centralwidget);
        boton3_5->setObjectName(QString::fromUtf8("boton3_5"));
        boton3_5->setEnabled(true);
        boton3_5->setGeometry(QRect(240, 210, 40, 40));
        boton3_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_5->setIcon(icon);
        boton3_5->setIconSize(QSize(40, 40));
        iniciar = new QPushButton(centralwidget);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));
        iniciar->setEnabled(false);
        iniciar->setGeometry(QRect(130, 480, 71, 31));
        ver1 = new QPushButton(centralwidget);
        ver1->setObjectName(QString::fromUtf8("ver1"));
        ver1->setEnabled(true);
        ver1->setGeometry(QRect(370, 410, 16, 16));
        ver1->setIcon(icon1);
        ver1_7 = new QPushButton(centralwidget);
        ver1_7->setObjectName(QString::fromUtf8("ver1_7"));
        ver1_7->setEnabled(true);
        ver1_7->setGeometry(QRect(370, 110, 16, 16));
        ver1_7->setIcon(icon1);
        boton4_8 = new QPushButton(centralwidget);
        boton4_8->setObjectName(QString::fromUtf8("boton4_8"));
        boton4_8->setEnabled(true);
        boton4_8->setGeometry(QRect(310, 60, 40, 40));
        boton4_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_8->setIcon(icon);
        boton4_8->setIconSize(QSize(40, 40));
        ver2_3 = new QPushButton(centralwidget);
        ver2_3->setObjectName(QString::fromUtf8("ver2_3"));
        ver2_3->setGeometry(QRect(370, 330, 16, 16));
        ver2_3->setIcon(icon1);
        boton2 = new QPushButton(centralwidget);
        boton2->setObjectName(QString::fromUtf8("boton2"));
        boton2->setEnabled(false);
        boton2->setGeometry(QRect(170, 410, 40, 40));
        boton2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2->setIcon(icon1);
        boton2->setIconSize(QSize(40, 40));
        ver1_3 = new QPushButton(centralwidget);
        ver1_3->setObjectName(QString::fromUtf8("ver1_3"));
        ver1_3->setEnabled(true);
        ver1_3->setGeometry(QRect(370, 310, 16, 16));
        ver1_3->setIcon(icon1);
        guardar = new QPushButton(centralwidget);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setEnabled(false);
        guardar->setGeometry(QRect(440, 480, 81, 31));
        segundos = new QLabel(centralwidget);
        segundos->setObjectName(QString::fromUtf8("segundos"));
        segundos->setGeometry(QRect(240, 520, 61, 16));
        boton2_3 = new QPushButton(centralwidget);
        boton2_3->setObjectName(QString::fromUtf8("boton2_3"));
        boton2_3->setEnabled(true);
        boton2_3->setGeometry(QRect(170, 310, 40, 40));
        boton2_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_3->setIcon(icon);
        boton2_3->setIconSize(QSize(40, 40));
        ver1_6 = new QPushButton(centralwidget);
        ver1_6->setObjectName(QString::fromUtf8("ver1_6"));
        ver1_6->setEnabled(true);
        ver1_6->setGeometry(QRect(370, 160, 16, 16));
        ver1_6->setIcon(icon1);
        ver3_5 = new QPushButton(centralwidget);
        ver3_5->setObjectName(QString::fromUtf8("ver3_5"));
        ver3_5->setGeometry(QRect(390, 210, 16, 16));
        ver3_5->setIcon(icon1);
        jug3 = new QLabel(centralwidget);
        jug3->setObjectName(QString::fromUtf8("jug3"));
        jug3->setGeometry(QRect(70, 320, 16, 16));
        nombre = new QLineEdit(centralwidget);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setGeometry(QRect(360, 540, 171, 20));
        boton3_4 = new QPushButton(centralwidget);
        boton3_4->setObjectName(QString::fromUtf8("boton3_4"));
        boton3_4->setEnabled(true);
        boton3_4->setGeometry(QRect(240, 260, 40, 40));
        boton3_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_4->setIcon(icon);
        boton3_4->setIconSize(QSize(40, 40));
        boton4_3 = new QPushButton(centralwidget);
        boton4_3->setObjectName(QString::fromUtf8("boton4_3"));
        boton4_3->setEnabled(true);
        boton4_3->setGeometry(QRect(310, 310, 40, 40));
        boton4_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_3->setIcon(icon);
        boton4_3->setIconSize(QSize(40, 40));
        boton1_3 = new QPushButton(centralwidget);
        boton1_3->setObjectName(QString::fromUtf8("boton1_3"));
        boton1_3->setEnabled(true);
        boton1_3->setGeometry(QRect(100, 310, 40, 40));
        boton1_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_3->setIconSize(QSize(40, 40));
        boton1_3->setFlat(false);
        ver2_8 = new QPushButton(centralwidget);
        ver2_8->setObjectName(QString::fromUtf8("ver2_8"));
        ver2_8->setGeometry(QRect(370, 80, 16, 16));
        ver2_8->setIcon(icon1);
        boton3_7 = new QPushButton(centralwidget);
        boton3_7->setObjectName(QString::fromUtf8("boton3_7"));
        boton3_7->setEnabled(true);
        boton3_7->setGeometry(QRect(240, 110, 40, 40));
        boton3_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_7->setIcon(icon);
        boton3_7->setIconSize(QSize(40, 40));
        ver3_8 = new QPushButton(centralwidget);
        ver3_8->setObjectName(QString::fromUtf8("ver3_8"));
        ver3_8->setGeometry(QRect(390, 60, 16, 16));
        ver3_8->setIcon(icon1);
        boton1_6 = new QPushButton(centralwidget);
        boton1_6->setObjectName(QString::fromUtf8("boton1_6"));
        boton1_6->setEnabled(true);
        boton1_6->setGeometry(QRect(100, 160, 40, 40));
        boton1_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_6->setIconSize(QSize(40, 40));
        boton1_6->setFlat(false);
        ver3_1 = new QPushButton(centralwidget);
        ver3_1->setObjectName(QString::fromUtf8("ver3_1"));
        ver3_1->setGeometry(QRect(390, 410, 16, 16));
        ver3_1->setIcon(icon1);
        boton2_4 = new QPushButton(centralwidget);
        boton2_4->setObjectName(QString::fromUtf8("boton2_4"));
        boton2_4->setEnabled(true);
        boton2_4->setGeometry(QRect(170, 260, 40, 40));
        boton2_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton2_4->setIcon(icon);
        boton2_4->setIconSize(QSize(40, 40));
        jug8 = new QLabel(centralwidget);
        jug8->setObjectName(QString::fromUtf8("jug8"));
        jug8->setGeometry(QRect(70, 70, 16, 16));
        boton3_3 = new QPushButton(centralwidget);
        boton3_3->setObjectName(QString::fromUtf8("boton3_3"));
        boton3_3->setEnabled(true);
        boton3_3->setGeometry(QRect(240, 310, 40, 40));
        boton3_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton3_3->setIcon(icon);
        boton3_3->setIconSize(QSize(40, 40));
        boton1_2 = new QPushButton(centralwidget);
        boton1_2->setObjectName(QString::fromUtf8("boton1_2"));
        boton1_2->setEnabled(true);
        boton1_2->setGeometry(QRect(100, 360, 40, 40));
        boton1_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color:#b0b0b0;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style:outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton1_2->setIconSize(QSize(40, 40));
        boton1_2->setFlat(false);
        boton4_5 = new QPushButton(centralwidget);
        boton4_5->setObjectName(QString::fromUtf8("boton4_5"));
        boton4_5->setEnabled(true);
        boton4_5->setGeometry(QRect(310, 210, 40, 40));
        boton4_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        boton4_5->setIcon(icon);
        boton4_5->setIconSize(QSize(40, 40));
        el3 = new QPushButton(centralwidget);
        el3->setObjectName(QString::fromUtf8("el3"));
        el3->setGeometry(QRect(560, 210, 40, 40));
        el3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        el3->setIconSize(QSize(40, 40));
        ver3_2 = new QPushButton(centralwidget);
        ver3_2->setObjectName(QString::fromUtf8("ver3_2"));
        ver3_2->setGeometry(QRect(390, 360, 16, 16));
        ver3_2->setIcon(icon1);
        el5 = new QPushButton(centralwidget);
        el5->setObjectName(QString::fromUtf8("el5"));
        el5->setGeometry(QRect(560, 350, 40, 40));
        el5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        el5->setIconSize(QSize(40, 40));
        ver2 = new QPushButton(centralwidget);
        ver2->setObjectName(QString::fromUtf8("ver2"));
        ver2->setGeometry(QRect(370, 430, 16, 16));
        ver2->setIcon(icon1);
        orden = new QLabel(centralwidget);
        orden->setObjectName(QString::fromUtf8("orden"));
        orden->setGeometry(QRect(560, 40, 47, 13));
        el1 = new QPushButton(centralwidget);
        el1->setObjectName(QString::fromUtf8("el1"));
        el1->setGeometry(QRect(560, 70, 40, 40));
        el1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 20px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }"));
        el1->setIconSize(QSize(40, 40));
        hor = new QLCDNumber(centralwidget);
        hor->setObjectName(QString::fromUtf8("hor"));
        hor->setGeometry(QRect(20, 540, 111, 51));
        min = new QLCDNumber(centralwidget);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(130, 540, 111, 51));
        seg = new QLCDNumber(centralwidget);
        seg->setObjectName(QString::fromUtf8("seg"));
        seg->setGeometry(QRect(240, 540, 111, 51));
        winlose = new QPushButton(centralwidget);
        winlose->setObjectName(QString::fromUtf8("winlose"));
        winlose->setGeometry(QRect(80, 0, 301, 51));
        winlose->setIconSize(QSize(300, 70));
        prueba = new QPushButton(centralwidget);
        prueba->setObjectName(QString::fromUtf8("prueba"));
        prueba->setEnabled(false);
        prueba->setGeometry(QRect(440, 380, 81, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boton3_1->setText(QString());
        boton2_6->setText(QString());
        minutos->setText(QCoreApplication::translate("MainWindow", "Minutos:", nullptr));
        boton4_1->setText(QString());
        ver4_8->setText(QString());
        horas->setText(QCoreApplication::translate("MainWindow", "Horas:", nullptr));
        boton2_2->setText(QString());
        boton2_8->setText(QString());
        cargar->setText(QCoreApplication::translate("MainWindow", "Cargar Juego", nullptr));
        boton3_2->setText(QString());
        ver1_4->setText(QString());
        jug1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        jugada->setText(QCoreApplication::translate("MainWindow", "Hacer jugada", nullptr));
        el4->setText(QString());
        boton1_1->setText(QString());
        njugadas->setText(QCoreApplication::translate("MainWindow", "N\302\260 Jugadas", nullptr));
        ver4_6->setText(QString());
        ver1_8->setText(QString());
        lnombre->setText(QCoreApplication::translate("MainWindow", "Jugador:", nullptr));
        boton1_5->setText(QString());
        el2->setText(QString());
        el6->setText(QString());
        boton1_7->setText(QString());
        ver2_2->setText(QString());
        boton3->setText(QString());
        boton2_5->setText(QString());
        boton1_8->setText(QString());
        ver1_1->setText(QString());
        terminar->setText(QCoreApplication::translate("MainWindow", "Terminar Juego", nullptr));
        boton4_6->setText(QString());
        ver1_2->setText(QString());
        ver2_5->setText(QString());
        jug7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        boton1_4->setText(QString());
        boton3_6->setText(QString());
        boton1->setText(QString());
        ver2_4->setText(QString());
        ayuda->setText(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
        ver2_6->setText(QString());
        ver4_7->setText(QString());
        ver4_1->setText(QString());
        jug2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        deshacer->setText(QCoreApplication::translate("MainWindow", "Deshacer Movida", nullptr));
        boton4->setText(QString());
        ver4_2->setText(QString());
        boton3_8->setText(QString());
        ver3_3->setText(QString());
        boton4_7->setText(QString());
        ver4->setText(QString());
        ver4_4->setText(QString());
        jug4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        jug6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        ver3->setText(QString());
        ver3_4->setText(QString());
        jug5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        ver3_7->setText(QString());
        ver2_1->setText(QString());
        boton2_1->setText(QString());
        boton2_7->setText(QString());
        boton4_2->setText(QString());
        ver3_6->setText(QString());
        ver4_3->setText(QString());
        ver2_7->setText(QString());
        ver4_5->setText(QString());
        ver1_5->setText(QString());
        boton4_4->setText(QString());
        boton3_5->setText(QString());
        iniciar->setText(QCoreApplication::translate("MainWindow", "Iniciar juego", nullptr));
        ver1->setText(QString());
        ver1_7->setText(QString());
        boton4_8->setText(QString());
        ver2_3->setText(QString());
        boton2->setText(QString());
        ver1_3->setText(QString());
        guardar->setText(QCoreApplication::translate("MainWindow", "Guardar Juego", nullptr));
        segundos->setText(QCoreApplication::translate("MainWindow", "Segundos:", nullptr));
        boton2_3->setText(QString());
        ver1_6->setText(QString());
        ver3_5->setText(QString());
        jug3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        nombre->setText(QString());
        boton3_4->setText(QString());
        boton4_3->setText(QString());
        boton1_3->setText(QString());
        ver2_8->setText(QString());
        boton3_7->setText(QString());
        ver3_8->setText(QString());
        boton1_6->setText(QString());
        ver3_1->setText(QString());
        boton2_4->setText(QString());
        jug8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        boton3_3->setText(QString());
        boton1_2->setText(QString());
        boton4_5->setText(QString());
        el3->setText(QString());
        ver3_2->setText(QString());
        el5->setText(QString());
        ver2->setText(QString());
        orden->setText(QCoreApplication::translate("MainWindow", "Orden", nullptr));
        el1->setText(QString());
        winlose->setText(QString());
        prueba->setText(QCoreApplication::translate("MainWindow", "Continuar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
