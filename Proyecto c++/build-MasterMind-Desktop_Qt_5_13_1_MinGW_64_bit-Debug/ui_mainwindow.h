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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *boton1;
    QPushButton *boton2;
    QPushButton *boton3;
    QPushButton *boton4;
    QPushButton *el1;
    QPushButton *el2;
    QPushButton *el3;
    QPushButton *el4;
    QPushButton *el5;
    QPushButton *el6;
    QPushButton *jugada;
    QPushButton *iniciar;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *ver1;
    QPushButton *ver2;
    QPushButton *ver3;
    QPushButton *ver4;
    QPushButton *boton3_2;
    QPushButton *boton4_2;
    QPushButton *ver1_2;
    QPushButton *boton2_2;
    QPushButton *ver3_2;
    QPushButton *ver2_2;
    QPushButton *ver4_2;
    QPushButton *boton1_2;
    QPushButton *boton3_3;
    QPushButton *boton4_3;
    QPushButton *ver1_3;
    QPushButton *boton2_3;
    QPushButton *ver3_3;
    QPushButton *ver2_3;
    QPushButton *ver4_3;
    QPushButton *boton1_3;
    QPushButton *boton3_4;
    QPushButton *boton4_4;
    QPushButton *ver1_4;
    QPushButton *boton2_4;
    QPushButton *ver3_4;
    QPushButton *ver2_4;
    QPushButton *ver4_4;
    QPushButton *boton1_4;
    QPushButton *boton3_5;
    QPushButton *boton4_5;
    QPushButton *ver1_5;
    QPushButton *boton2_5;
    QPushButton *ver3_5;
    QPushButton *ver2_5;
    QPushButton *ver4_5;
    QPushButton *boton1_5;
    QPushButton *boton3_6;
    QPushButton *boton4_6;
    QPushButton *ver1_6;
    QPushButton *boton2_6;
    QPushButton *ver3_6;
    QPushButton *ver2_6;
    QPushButton *ver4_6;
    QPushButton *boton1_6;
    QPushButton *boton3_7;
    QPushButton *boton4_7;
    QPushButton *ver1_7;
    QPushButton *boton2_7;
    QPushButton *ver3_7;
    QPushButton *ver2_7;
    QPushButton *ver4_7;
    QPushButton *boton1_7;
    QPushButton *boton3_8;
    QPushButton *boton4_8;
    QPushButton *ver1_8;
    QPushButton *boton2_8;
    QPushButton *ver3_8;
    QPushButton *ver2_8;
    QPushButton *ver4_8;
    QPushButton *boton1_8;
    QPushButton *boton3_1;
    QPushButton *boton4_1;
    QPushButton *ver1_1;
    QPushButton *boton2_1;
    QPushButton *ver3_1;
    QPushButton *ver2_1;
    QPushButton *ver4_1;
    QPushButton *boton1_1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(653, 718);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        boton1 = new QPushButton(centralwidget);
        boton1->setObjectName(QString::fromUtf8("boton1"));
        boton1->setEnabled(false);
        boton1->setGeometry(QRect(110, 510, 40, 40));
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Elementos/Colores/gris.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        boton1->setIcon(icon);
        boton1->setIconSize(QSize(40, 40));
        boton1->setFlat(false);
        boton2 = new QPushButton(centralwidget);
        boton2->setObjectName(QString::fromUtf8("boton2"));
        boton2->setEnabled(false);
        boton2->setGeometry(QRect(180, 510, 40, 40));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/gris.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        boton2->setIcon(icon1);
        boton2->setIconSize(QSize(40, 40));
        boton3 = new QPushButton(centralwidget);
        boton3->setObjectName(QString::fromUtf8("boton3"));
        boton3->setEnabled(false);
        boton3->setGeometry(QRect(250, 510, 40, 40));
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
        boton4 = new QPushButton(centralwidget);
        boton4->setObjectName(QString::fromUtf8("boton4"));
        boton4->setEnabled(false);
        boton4->setGeometry(QRect(320, 510, 40, 40));
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
        el1 = new QPushButton(centralwidget);
        el1->setObjectName(QString::fromUtf8("el1"));
        el1->setGeometry(QRect(570, 60, 40, 40));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rojo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        el1->setIcon(icon2);
        el1->setIconSize(QSize(40, 40));
        el2 = new QPushButton(centralwidget);
        el2->setObjectName(QString::fromUtf8("el2"));
        el2->setGeometry(QRect(570, 130, 40, 40));
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/azul.png"), QSize(), QIcon::Normal, QIcon::Off);
        el2->setIcon(icon3);
        el2->setIconSize(QSize(40, 40));
        el3 = new QPushButton(centralwidget);
        el3->setObjectName(QString::fromUtf8("el3"));
        el3->setGeometry(QRect(570, 200, 40, 40));
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/amarillo.png"), QSize(), QIcon::Normal, QIcon::Off);
        el3->setIcon(icon4);
        el3->setIconSize(QSize(40, 40));
        el4 = new QPushButton(centralwidget);
        el4->setObjectName(QString::fromUtf8("el4"));
        el4->setGeometry(QRect(570, 270, 40, 40));
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/naranja.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        el4->setIcon(icon5);
        el4->setIconSize(QSize(40, 40));
        el5 = new QPushButton(centralwidget);
        el5->setObjectName(QString::fromUtf8("el5"));
        el5->setGeometry(QRect(570, 340, 40, 40));
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/verde.png"), QSize(), QIcon::Normal, QIcon::Off);
        el5->setIcon(icon6);
        el5->setIconSize(QSize(40, 40));
        el6 = new QPushButton(centralwidget);
        el6->setObjectName(QString::fromUtf8("el6"));
        el6->setGeometry(QRect(570, 410, 40, 40));
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/morado.png"), QSize(), QIcon::Normal, QIcon::Off);
        el6->setIcon(icon7);
        el6->setIconSize(QSize(40, 40));
        jugada = new QPushButton(centralwidget);
        jugada->setObjectName(QString::fromUtf8("jugada"));
        jugada->setEnabled(false);
        jugada->setGeometry(QRect(30, 580, 91, 31));
        iniciar = new QPushButton(centralwidget);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));
        iniciar->setEnabled(true);
        iniciar->setGeometry(QRect(140, 580, 71, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 580, 91, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 580, 91, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 620, 81, 31));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(450, 580, 81, 31));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(550, 580, 71, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 630, 47, 13));
        ver1 = new QPushButton(centralwidget);
        ver1->setObjectName(QString::fromUtf8("ver1"));
        ver1->setEnabled(true);
        ver1->setGeometry(QRect(380, 510, 16, 16));
        ver1->setIcon(icon1);
        ver2 = new QPushButton(centralwidget);
        ver2->setObjectName(QString::fromUtf8("ver2"));
        ver2->setGeometry(QRect(380, 530, 16, 16));
        ver2->setIcon(icon1);
        ver3 = new QPushButton(centralwidget);
        ver3->setObjectName(QString::fromUtf8("ver3"));
        ver3->setGeometry(QRect(400, 510, 16, 16));
        ver3->setIcon(icon1);
        ver4 = new QPushButton(centralwidget);
        ver4->setObjectName(QString::fromUtf8("ver4"));
        ver4->setGeometry(QRect(400, 530, 16, 16));
        ver4->setIcon(icon1);
        boton3_2 = new QPushButton(centralwidget);
        boton3_2->setObjectName(QString::fromUtf8("boton3_2"));
        boton3_2->setEnabled(true);
        boton3_2->setGeometry(QRect(250, 460, 40, 40));
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
        boton3_2->setIcon(icon1);
        boton3_2->setIconSize(QSize(40, 40));
        boton4_2 = new QPushButton(centralwidget);
        boton4_2->setObjectName(QString::fromUtf8("boton4_2"));
        boton4_2->setEnabled(true);
        boton4_2->setGeometry(QRect(320, 460, 40, 40));
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
        boton4_2->setIcon(icon1);
        boton4_2->setIconSize(QSize(40, 40));
        ver1_2 = new QPushButton(centralwidget);
        ver1_2->setObjectName(QString::fromUtf8("ver1_2"));
        ver1_2->setEnabled(true);
        ver1_2->setGeometry(QRect(380, 460, 16, 16));
        ver1_2->setIcon(icon1);
        boton2_2 = new QPushButton(centralwidget);
        boton2_2->setObjectName(QString::fromUtf8("boton2_2"));
        boton2_2->setEnabled(true);
        boton2_2->setGeometry(QRect(180, 460, 40, 40));
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
        boton2_2->setIcon(icon1);
        boton2_2->setIconSize(QSize(40, 40));
        ver3_2 = new QPushButton(centralwidget);
        ver3_2->setObjectName(QString::fromUtf8("ver3_2"));
        ver3_2->setGeometry(QRect(400, 460, 16, 16));
        ver3_2->setIcon(icon1);
        ver2_2 = new QPushButton(centralwidget);
        ver2_2->setObjectName(QString::fromUtf8("ver2_2"));
        ver2_2->setGeometry(QRect(380, 480, 16, 16));
        ver2_2->setIcon(icon1);
        ver4_2 = new QPushButton(centralwidget);
        ver4_2->setObjectName(QString::fromUtf8("ver4_2"));
        ver4_2->setGeometry(QRect(400, 480, 16, 16));
        ver4_2->setIcon(icon1);
        boton1_2 = new QPushButton(centralwidget);
        boton1_2->setObjectName(QString::fromUtf8("boton1_2"));
        boton1_2->setEnabled(true);
        boton1_2->setGeometry(QRect(110, 460, 40, 40));
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
        boton1_2->setIcon(icon);
        boton1_2->setIconSize(QSize(40, 40));
        boton1_2->setFlat(false);
        boton3_3 = new QPushButton(centralwidget);
        boton3_3->setObjectName(QString::fromUtf8("boton3_3"));
        boton3_3->setEnabled(true);
        boton3_3->setGeometry(QRect(250, 410, 40, 40));
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
        boton3_3->setIcon(icon1);
        boton3_3->setIconSize(QSize(40, 40));
        boton4_3 = new QPushButton(centralwidget);
        boton4_3->setObjectName(QString::fromUtf8("boton4_3"));
        boton4_3->setEnabled(true);
        boton4_3->setGeometry(QRect(320, 410, 40, 40));
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
        boton4_3->setIcon(icon1);
        boton4_3->setIconSize(QSize(40, 40));
        ver1_3 = new QPushButton(centralwidget);
        ver1_3->setObjectName(QString::fromUtf8("ver1_3"));
        ver1_3->setEnabled(true);
        ver1_3->setGeometry(QRect(380, 410, 16, 16));
        ver1_3->setIcon(icon1);
        boton2_3 = new QPushButton(centralwidget);
        boton2_3->setObjectName(QString::fromUtf8("boton2_3"));
        boton2_3->setEnabled(true);
        boton2_3->setGeometry(QRect(180, 410, 40, 40));
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
        boton2_3->setIcon(icon1);
        boton2_3->setIconSize(QSize(40, 40));
        ver3_3 = new QPushButton(centralwidget);
        ver3_3->setObjectName(QString::fromUtf8("ver3_3"));
        ver3_3->setGeometry(QRect(400, 410, 16, 16));
        ver3_3->setIcon(icon1);
        ver2_3 = new QPushButton(centralwidget);
        ver2_3->setObjectName(QString::fromUtf8("ver2_3"));
        ver2_3->setGeometry(QRect(380, 430, 16, 16));
        ver2_3->setIcon(icon1);
        ver4_3 = new QPushButton(centralwidget);
        ver4_3->setObjectName(QString::fromUtf8("ver4_3"));
        ver4_3->setGeometry(QRect(400, 430, 16, 16));
        ver4_3->setIcon(icon1);
        boton1_3 = new QPushButton(centralwidget);
        boton1_3->setObjectName(QString::fromUtf8("boton1_3"));
        boton1_3->setEnabled(true);
        boton1_3->setGeometry(QRect(110, 410, 40, 40));
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
        boton1_3->setIcon(icon);
        boton1_3->setIconSize(QSize(40, 40));
        boton1_3->setFlat(false);
        boton3_4 = new QPushButton(centralwidget);
        boton3_4->setObjectName(QString::fromUtf8("boton3_4"));
        boton3_4->setEnabled(true);
        boton3_4->setGeometry(QRect(250, 360, 40, 40));
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
        boton3_4->setIcon(icon1);
        boton3_4->setIconSize(QSize(40, 40));
        boton4_4 = new QPushButton(centralwidget);
        boton4_4->setObjectName(QString::fromUtf8("boton4_4"));
        boton4_4->setEnabled(true);
        boton4_4->setGeometry(QRect(320, 360, 40, 40));
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
        boton4_4->setIcon(icon1);
        boton4_4->setIconSize(QSize(40, 40));
        ver1_4 = new QPushButton(centralwidget);
        ver1_4->setObjectName(QString::fromUtf8("ver1_4"));
        ver1_4->setEnabled(true);
        ver1_4->setGeometry(QRect(380, 360, 16, 16));
        ver1_4->setIcon(icon1);
        boton2_4 = new QPushButton(centralwidget);
        boton2_4->setObjectName(QString::fromUtf8("boton2_4"));
        boton2_4->setEnabled(true);
        boton2_4->setGeometry(QRect(180, 360, 40, 40));
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
        boton2_4->setIcon(icon1);
        boton2_4->setIconSize(QSize(40, 40));
        ver3_4 = new QPushButton(centralwidget);
        ver3_4->setObjectName(QString::fromUtf8("ver3_4"));
        ver3_4->setGeometry(QRect(400, 360, 16, 16));
        ver3_4->setIcon(icon1);
        ver2_4 = new QPushButton(centralwidget);
        ver2_4->setObjectName(QString::fromUtf8("ver2_4"));
        ver2_4->setGeometry(QRect(380, 380, 16, 16));
        ver2_4->setIcon(icon1);
        ver4_4 = new QPushButton(centralwidget);
        ver4_4->setObjectName(QString::fromUtf8("ver4_4"));
        ver4_4->setGeometry(QRect(400, 380, 16, 16));
        ver4_4->setIcon(icon1);
        boton1_4 = new QPushButton(centralwidget);
        boton1_4->setObjectName(QString::fromUtf8("boton1_4"));
        boton1_4->setEnabled(true);
        boton1_4->setGeometry(QRect(110, 360, 40, 40));
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
        boton1_4->setIcon(icon);
        boton1_4->setIconSize(QSize(40, 40));
        boton1_4->setFlat(false);
        boton3_5 = new QPushButton(centralwidget);
        boton3_5->setObjectName(QString::fromUtf8("boton3_5"));
        boton3_5->setEnabled(true);
        boton3_5->setGeometry(QRect(250, 310, 40, 40));
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
        boton3_5->setIcon(icon1);
        boton3_5->setIconSize(QSize(40, 40));
        boton4_5 = new QPushButton(centralwidget);
        boton4_5->setObjectName(QString::fromUtf8("boton4_5"));
        boton4_5->setEnabled(true);
        boton4_5->setGeometry(QRect(320, 310, 40, 40));
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
        boton4_5->setIcon(icon1);
        boton4_5->setIconSize(QSize(40, 40));
        ver1_5 = new QPushButton(centralwidget);
        ver1_5->setObjectName(QString::fromUtf8("ver1_5"));
        ver1_5->setEnabled(true);
        ver1_5->setGeometry(QRect(380, 310, 16, 16));
        ver1_5->setIcon(icon1);
        boton2_5 = new QPushButton(centralwidget);
        boton2_5->setObjectName(QString::fromUtf8("boton2_5"));
        boton2_5->setEnabled(true);
        boton2_5->setGeometry(QRect(180, 310, 40, 40));
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
        boton2_5->setIcon(icon1);
        boton2_5->setIconSize(QSize(40, 40));
        ver3_5 = new QPushButton(centralwidget);
        ver3_5->setObjectName(QString::fromUtf8("ver3_5"));
        ver3_5->setGeometry(QRect(400, 310, 16, 16));
        ver3_5->setIcon(icon1);
        ver2_5 = new QPushButton(centralwidget);
        ver2_5->setObjectName(QString::fromUtf8("ver2_5"));
        ver2_5->setGeometry(QRect(380, 330, 16, 16));
        ver2_5->setIcon(icon1);
        ver4_5 = new QPushButton(centralwidget);
        ver4_5->setObjectName(QString::fromUtf8("ver4_5"));
        ver4_5->setGeometry(QRect(400, 330, 16, 16));
        ver4_5->setIcon(icon1);
        boton1_5 = new QPushButton(centralwidget);
        boton1_5->setObjectName(QString::fromUtf8("boton1_5"));
        boton1_5->setEnabled(true);
        boton1_5->setGeometry(QRect(110, 310, 40, 40));
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
        boton1_5->setIcon(icon);
        boton1_5->setIconSize(QSize(40, 40));
        boton1_5->setFlat(false);
        boton3_6 = new QPushButton(centralwidget);
        boton3_6->setObjectName(QString::fromUtf8("boton3_6"));
        boton3_6->setEnabled(true);
        boton3_6->setGeometry(QRect(250, 260, 40, 40));
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
        boton3_6->setIcon(icon1);
        boton3_6->setIconSize(QSize(40, 40));
        boton4_6 = new QPushButton(centralwidget);
        boton4_6->setObjectName(QString::fromUtf8("boton4_6"));
        boton4_6->setEnabled(true);
        boton4_6->setGeometry(QRect(320, 260, 40, 40));
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
        boton4_6->setIcon(icon1);
        boton4_6->setIconSize(QSize(40, 40));
        ver1_6 = new QPushButton(centralwidget);
        ver1_6->setObjectName(QString::fromUtf8("ver1_6"));
        ver1_6->setEnabled(true);
        ver1_6->setGeometry(QRect(380, 260, 16, 16));
        ver1_6->setIcon(icon1);
        boton2_6 = new QPushButton(centralwidget);
        boton2_6->setObjectName(QString::fromUtf8("boton2_6"));
        boton2_6->setEnabled(true);
        boton2_6->setGeometry(QRect(180, 260, 40, 40));
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
        boton2_6->setIcon(icon1);
        boton2_6->setIconSize(QSize(40, 40));
        ver3_6 = new QPushButton(centralwidget);
        ver3_6->setObjectName(QString::fromUtf8("ver3_6"));
        ver3_6->setGeometry(QRect(400, 260, 16, 16));
        ver3_6->setIcon(icon1);
        ver2_6 = new QPushButton(centralwidget);
        ver2_6->setObjectName(QString::fromUtf8("ver2_6"));
        ver2_6->setGeometry(QRect(380, 280, 16, 16));
        ver2_6->setIcon(icon1);
        ver4_6 = new QPushButton(centralwidget);
        ver4_6->setObjectName(QString::fromUtf8("ver4_6"));
        ver4_6->setGeometry(QRect(400, 280, 16, 16));
        ver4_6->setIcon(icon1);
        boton1_6 = new QPushButton(centralwidget);
        boton1_6->setObjectName(QString::fromUtf8("boton1_6"));
        boton1_6->setEnabled(true);
        boton1_6->setGeometry(QRect(110, 260, 40, 40));
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
        boton1_6->setIcon(icon);
        boton1_6->setIconSize(QSize(40, 40));
        boton1_6->setFlat(false);
        boton3_7 = new QPushButton(centralwidget);
        boton3_7->setObjectName(QString::fromUtf8("boton3_7"));
        boton3_7->setEnabled(true);
        boton3_7->setGeometry(QRect(250, 210, 40, 40));
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
        boton3_7->setIcon(icon1);
        boton3_7->setIconSize(QSize(40, 40));
        boton4_7 = new QPushButton(centralwidget);
        boton4_7->setObjectName(QString::fromUtf8("boton4_7"));
        boton4_7->setEnabled(true);
        boton4_7->setGeometry(QRect(320, 210, 40, 40));
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
        boton4_7->setIcon(icon1);
        boton4_7->setIconSize(QSize(40, 40));
        ver1_7 = new QPushButton(centralwidget);
        ver1_7->setObjectName(QString::fromUtf8("ver1_7"));
        ver1_7->setEnabled(true);
        ver1_7->setGeometry(QRect(380, 210, 16, 16));
        ver1_7->setIcon(icon1);
        boton2_7 = new QPushButton(centralwidget);
        boton2_7->setObjectName(QString::fromUtf8("boton2_7"));
        boton2_7->setEnabled(true);
        boton2_7->setGeometry(QRect(180, 210, 40, 40));
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
        boton2_7->setIcon(icon1);
        boton2_7->setIconSize(QSize(40, 40));
        ver3_7 = new QPushButton(centralwidget);
        ver3_7->setObjectName(QString::fromUtf8("ver3_7"));
        ver3_7->setGeometry(QRect(400, 210, 16, 16));
        ver3_7->setIcon(icon1);
        ver2_7 = new QPushButton(centralwidget);
        ver2_7->setObjectName(QString::fromUtf8("ver2_7"));
        ver2_7->setGeometry(QRect(380, 230, 16, 16));
        ver2_7->setIcon(icon1);
        ver4_7 = new QPushButton(centralwidget);
        ver4_7->setObjectName(QString::fromUtf8("ver4_7"));
        ver4_7->setGeometry(QRect(400, 230, 16, 16));
        ver4_7->setIcon(icon1);
        boton1_7 = new QPushButton(centralwidget);
        boton1_7->setObjectName(QString::fromUtf8("boton1_7"));
        boton1_7->setEnabled(true);
        boton1_7->setGeometry(QRect(110, 210, 40, 40));
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
        boton1_7->setIcon(icon);
        boton1_7->setIconSize(QSize(40, 40));
        boton1_7->setFlat(false);
        boton3_8 = new QPushButton(centralwidget);
        boton3_8->setObjectName(QString::fromUtf8("boton3_8"));
        boton3_8->setEnabled(true);
        boton3_8->setGeometry(QRect(250, 160, 40, 40));
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
        boton3_8->setIcon(icon1);
        boton3_8->setIconSize(QSize(40, 40));
        boton4_8 = new QPushButton(centralwidget);
        boton4_8->setObjectName(QString::fromUtf8("boton4_8"));
        boton4_8->setEnabled(true);
        boton4_8->setGeometry(QRect(320, 160, 40, 40));
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
        boton4_8->setIcon(icon1);
        boton4_8->setIconSize(QSize(40, 40));
        ver1_8 = new QPushButton(centralwidget);
        ver1_8->setObjectName(QString::fromUtf8("ver1_8"));
        ver1_8->setEnabled(true);
        ver1_8->setGeometry(QRect(380, 160, 16, 16));
        ver1_8->setIcon(icon1);
        boton2_8 = new QPushButton(centralwidget);
        boton2_8->setObjectName(QString::fromUtf8("boton2_8"));
        boton2_8->setEnabled(true);
        boton2_8->setGeometry(QRect(180, 160, 40, 40));
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
        boton2_8->setIcon(icon1);
        boton2_8->setIconSize(QSize(40, 40));
        ver3_8 = new QPushButton(centralwidget);
        ver3_8->setObjectName(QString::fromUtf8("ver3_8"));
        ver3_8->setGeometry(QRect(400, 160, 16, 16));
        ver3_8->setIcon(icon1);
        ver2_8 = new QPushButton(centralwidget);
        ver2_8->setObjectName(QString::fromUtf8("ver2_8"));
        ver2_8->setGeometry(QRect(380, 180, 16, 16));
        ver2_8->setIcon(icon1);
        ver4_8 = new QPushButton(centralwidget);
        ver4_8->setObjectName(QString::fromUtf8("ver4_8"));
        ver4_8->setGeometry(QRect(400, 180, 16, 16));
        ver4_8->setIcon(icon1);
        boton1_8 = new QPushButton(centralwidget);
        boton1_8->setObjectName(QString::fromUtf8("boton1_8"));
        boton1_8->setEnabled(true);
        boton1_8->setGeometry(QRect(110, 160, 40, 40));
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
        boton1_8->setIcon(icon);
        boton1_8->setIconSize(QSize(40, 40));
        boton1_8->setFlat(false);
        boton3_1 = new QPushButton(centralwidget);
        boton3_1->setObjectName(QString::fromUtf8("boton3_1"));
        boton3_1->setEnabled(true);
        boton3_1->setGeometry(QRect(250, 510, 40, 40));
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
        boton3_1->setIcon(icon1);
        boton3_1->setIconSize(QSize(40, 40));
        boton4_1 = new QPushButton(centralwidget);
        boton4_1->setObjectName(QString::fromUtf8("boton4_1"));
        boton4_1->setEnabled(true);
        boton4_1->setGeometry(QRect(320, 510, 40, 40));
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
        boton4_1->setIcon(icon1);
        boton4_1->setIconSize(QSize(40, 40));
        ver1_1 = new QPushButton(centralwidget);
        ver1_1->setObjectName(QString::fromUtf8("ver1_1"));
        ver1_1->setEnabled(true);
        ver1_1->setGeometry(QRect(380, 510, 16, 16));
        ver1_1->setIcon(icon1);
        boton2_1 = new QPushButton(centralwidget);
        boton2_1->setObjectName(QString::fromUtf8("boton2_1"));
        boton2_1->setEnabled(true);
        boton2_1->setGeometry(QRect(180, 510, 40, 40));
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
        boton2_1->setIcon(icon1);
        boton2_1->setIconSize(QSize(40, 40));
        ver3_1 = new QPushButton(centralwidget);
        ver3_1->setObjectName(QString::fromUtf8("ver3_1"));
        ver3_1->setGeometry(QRect(400, 510, 16, 16));
        ver3_1->setIcon(icon1);
        ver2_1 = new QPushButton(centralwidget);
        ver2_1->setObjectName(QString::fromUtf8("ver2_1"));
        ver2_1->setGeometry(QRect(380, 530, 16, 16));
        ver2_1->setIcon(icon1);
        ver4_1 = new QPushButton(centralwidget);
        ver4_1->setObjectName(QString::fromUtf8("ver4_1"));
        ver4_1->setGeometry(QRect(400, 530, 16, 16));
        ver4_1->setIcon(icon1);
        boton1_1 = new QPushButton(centralwidget);
        boton1_1->setObjectName(QString::fromUtf8("boton1_1"));
        boton1_1->setEnabled(true);
        boton1_1->setGeometry(QRect(110, 510, 40, 40));
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
        boton1_1->setIcon(icon);
        boton1_1->setIconSize(QSize(40, 40));
        boton1_1->setFlat(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 653, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boton1->setText(QString());
        boton2->setText(QString());
        boton3->setText(QString());
        boton4->setText(QString());
        el1->setText(QString());
        el2->setText(QString());
        el3->setText(QString());
        el4->setText(QString());
        el5->setText(QString());
        el6->setText(QString());
        jugada->setText(QCoreApplication::translate("MainWindow", "Hacer jugada", nullptr));
        iniciar->setText(QCoreApplication::translate("MainWindow", "Iniciar juego", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Terminar Juego", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Deshacer Movida", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Cargar Juego", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Guardar Juego", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Jugador:", nullptr));
        ver1->setText(QString());
        ver2->setText(QString());
        ver3->setText(QString());
        ver4->setText(QString());
        boton3_2->setText(QString());
        boton4_2->setText(QString());
        ver1_2->setText(QString());
        boton2_2->setText(QString());
        ver3_2->setText(QString());
        ver2_2->setText(QString());
        ver4_2->setText(QString());
        boton1_2->setText(QString());
        boton3_3->setText(QString());
        boton4_3->setText(QString());
        ver1_3->setText(QString());
        boton2_3->setText(QString());
        ver3_3->setText(QString());
        ver2_3->setText(QString());
        ver4_3->setText(QString());
        boton1_3->setText(QString());
        boton3_4->setText(QString());
        boton4_4->setText(QString());
        ver1_4->setText(QString());
        boton2_4->setText(QString());
        ver3_4->setText(QString());
        ver2_4->setText(QString());
        ver4_4->setText(QString());
        boton1_4->setText(QString());
        boton3_5->setText(QString());
        boton4_5->setText(QString());
        ver1_5->setText(QString());
        boton2_5->setText(QString());
        ver3_5->setText(QString());
        ver2_5->setText(QString());
        ver4_5->setText(QString());
        boton1_5->setText(QString());
        boton3_6->setText(QString());
        boton4_6->setText(QString());
        ver1_6->setText(QString());
        boton2_6->setText(QString());
        ver3_6->setText(QString());
        ver2_6->setText(QString());
        ver4_6->setText(QString());
        boton1_6->setText(QString());
        boton3_7->setText(QString());
        boton4_7->setText(QString());
        ver1_7->setText(QString());
        boton2_7->setText(QString());
        ver3_7->setText(QString());
        ver2_7->setText(QString());
        ver4_7->setText(QString());
        boton1_7->setText(QString());
        boton3_8->setText(QString());
        boton4_8->setText(QString());
        ver1_8->setText(QString());
        boton2_8->setText(QString());
        ver3_8->setText(QString());
        ver2_8->setText(QString());
        ver4_8->setText(QString());
        boton1_8->setText(QString());
        boton3_1->setText(QString());
        boton4_1->setText(QString());
        ver1_1->setText(QString());
        boton2_1->setText(QString());
        ver3_1->setText(QString());
        ver2_1->setText(QString());
        ver4_1->setText(QString());
        boton1_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
