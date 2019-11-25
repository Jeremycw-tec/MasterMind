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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labh;
    QLabel *labm;
    QLabel *labs;
    QGroupBox *groupBox;
    QRadioButton *dificultadop1;
    QRadioButton *dificultadop2;
    QRadioButton *dificultadop3;
    QGroupBox *groupBox_2;
    QRadioButton *cpjuego;
    QRadioButton *rno;
    QRadioButton *rsi;
    QRadioButton *cpjugada;
    QGroupBox *groupBox_3;
    QRadioButton *repsi;
    QRadioButton *repno;
    QGroupBox *groupBox_4;
    QRadioButton *elementocolor;
    QRadioButton *elementoletra;
    QRadioButton *elementonumero;
    QRadioButton *elementodefinido;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QSpinBox *horas;
    QSpinBox *minutos;
    QSpinBox *segundos;
    QPushButton *guardar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(653, 406);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labh = new QLabel(centralwidget);
        labh->setObjectName(QString::fromUtf8("labh"));
        labh->setGeometry(QRect(20, 210, 47, 13));
        labm = new QLabel(centralwidget);
        labm->setObjectName(QString::fromUtf8("labm"));
        labm->setGeometry(QRect(60, 210, 47, 13));
        labs = new QLabel(centralwidget);
        labs->setObjectName(QString::fromUtf8("labs"));
        labs->setGeometry(QRect(110, 210, 47, 13));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 291, 91));
        dificultadop1 = new QRadioButton(groupBox);
        dificultadop1->setObjectName(QString::fromUtf8("dificultadop1"));
        dificultadop1->setGeometry(QRect(10, 20, 271, 17));
        dificultadop1->setChecked(true);
        dificultadop2 = new QRadioButton(groupBox);
        dificultadop2->setObjectName(QString::fromUtf8("dificultadop2"));
        dificultadop2->setGeometry(QRect(10, 40, 281, 17));
        dificultadop3 = new QRadioButton(groupBox);
        dificultadop3->setObjectName(QString::fromUtf8("dificultadop3"));
        dificultadop3->setGeometry(QRect(10, 60, 271, 17));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 151, 101));
        cpjuego = new QRadioButton(groupBox_2);
        cpjuego->setObjectName(QString::fromUtf8("cpjuego"));
        cpjuego->setGeometry(QRect(10, 80, 141, 17));
        rno = new QRadioButton(groupBox_2);
        rno->setObjectName(QString::fromUtf8("rno"));
        rno->setGeometry(QRect(10, 40, 41, 17));
        rsi = new QRadioButton(groupBox_2);
        rsi->setObjectName(QString::fromUtf8("rsi"));
        rsi->setGeometry(QRect(10, 20, 82, 17));
        rsi->setChecked(true);
        cpjugada = new QRadioButton(groupBox_2);
        cpjugada->setObjectName(QString::fromUtf8("cpjugada"));
        cpjugada->setGeometry(QRect(10, 60, 141, 17));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 260, 221, 61));
        repsi = new QRadioButton(groupBox_3);
        repsi->setObjectName(QString::fromUtf8("repsi"));
        repsi->setGeometry(QRect(10, 20, 41, 17));
        repsi->setChecked(true);
        repno = new QRadioButton(groupBox_3);
        repno->setObjectName(QString::fromUtf8("repno"));
        repno->setGeometry(QRect(10, 40, 41, 17));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(320, 10, 321, 351));
        elementocolor = new QRadioButton(groupBox_4);
        elementocolor->setObjectName(QString::fromUtf8("elementocolor"));
        elementocolor->setGeometry(QRect(40, 20, 51, 17));
        elementocolor->setChecked(true);
        elementoletra = new QRadioButton(groupBox_4);
        elementoletra->setObjectName(QString::fromUtf8("elementoletra"));
        elementoletra->setGeometry(QRect(120, 20, 51, 17));
        elementonumero = new QRadioButton(groupBox_4);
        elementonumero->setObjectName(QString::fromUtf8("elementonumero"));
        elementonumero->setGeometry(QRect(200, 20, 61, 17));
        elementodefinido = new QRadioButton(groupBox_4);
        elementodefinido->setObjectName(QString::fromUtf8("elementodefinido"));
        elementodefinido->setGeometry(QRect(280, 20, 71, 17));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 60, 40, 40));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8(":/rojo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 110, 40, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon1.addFile(QString::fromUtf8(":/azul.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(40, 40));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 160, 40, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon2.addFile(QString::fromUtf8(":/amarillo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(40, 40));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 210, 40, 40));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon3.addFile(QString::fromUtf8(":/naranja.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(40, 40));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 260, 40, 40));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon4.addFile(QString::fromUtf8(":/verde.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(40, 40));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(350, 310, 40, 40));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon5.addFile(QString::fromUtf8(":/morado.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(40, 40));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(430, 110, 40, 40));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon6.addFile(QString::fromUtf8(":/B.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(40, 40));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(430, 310, 40, 40));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon7.addFile(QString::fromUtf8(":/F.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon7);
        pushButton_8->setIconSize(QSize(40, 40));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(430, 60, 40, 40));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/A.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon8);
        pushButton_9->setIconSize(QSize(40, 40));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(430, 210, 40, 40));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/D.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon9);
        pushButton_10->setIconSize(QSize(40, 40));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(430, 160, 40, 40));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/C.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon10);
        pushButton_11->setIconSize(QSize(40, 40));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(430, 260, 40, 40));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/E.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon11);
        pushButton_12->setIconSize(QSize(40, 40));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(510, 110, 40, 40));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon12);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(510, 310, 40, 40));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon13);
        pushButton_14->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(510, 60, 40, 40));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon14);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(510, 210, 40, 40));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon15);
        pushButton_16->setIconSize(QSize(40, 40));
        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(510, 160, 40, 40));
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon16);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(510, 260, 40, 40));
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon17);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(590, 110, 40, 40));
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/k.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon18);
        pushButton_19->setIconSize(QSize(40, 40));
        pushButton_20 = new QPushButton(centralwidget);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(590, 310, 40, 40));
        pushButton_20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/t.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon19);
        pushButton_20->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(centralwidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(590, 60, 40, 40));
        pushButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/s.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon20);
        pushButton_21->setIconSize(QSize(40, 40));
        pushButton_22 = new QPushButton(centralwidget);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setGeometry(QRect(590, 210, 40, 40));
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/r.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon21);
        pushButton_22->setIconSize(QSize(40, 40));
        pushButton_23 = new QPushButton(centralwidget);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setGeometry(QRect(590, 160, 40, 40));
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/i.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_23->setIcon(icon22);
        pushButton_23->setIconSize(QSize(40, 40));
        pushButton_24 = new QPushButton(centralwidget);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setGeometry(QRect(590, 260, 40, 40));
        pushButton_24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/y.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_24->setIcon(icon23);
        pushButton_24->setIconSize(QSize(40, 40));
        horas = new QSpinBox(centralwidget);
        horas->setObjectName(QString::fromUtf8("horas"));
        horas->setGeometry(QRect(10, 230, 42, 22));
        minutos = new QSpinBox(centralwidget);
        minutos->setObjectName(QString::fromUtf8("minutos"));
        minutos->setGeometry(QRect(60, 230, 42, 22));
        segundos = new QSpinBox(centralwidget);
        segundos->setObjectName(QString::fromUtf8("segundos"));
        segundos->setGeometry(QRect(110, 230, 42, 22));
        guardar = new QPushButton(centralwidget);
        guardar->setObjectName(QString::fromUtf8("guardar"));
        guardar->setGeometry(QRect(10, 330, 75, 23));
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
        labh->setText(QCoreApplication::translate("MainWindow", "Horas", nullptr));
        labm->setText(QCoreApplication::translate("MainWindow", "Minutos", nullptr));
        labs->setText(QCoreApplication::translate("MainWindow", "Segundos", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Nivel de dificultad:", nullptr));
        dificultadop1->setText(QCoreApplication::translate("MainWindow", "F\303\241cil (8 jugadas, combinaci\303\263n de 4 elementos de 6)", nullptr));
        dificultadop2->setText(QCoreApplication::translate("MainWindow", "Medio (7 jugadas, combinaci\303\263n de 4 elementos de 6)", nullptr));
        dificultadop3->setText(QCoreApplication::translate("MainWindow", "Dif\303\255cil (6 jugadas, combinaci\303\263n de 4 elementos de 6)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Reloj:", nullptr));
        cpjuego->setText(QCoreApplication::translate("MainWindow", "Cronometro por juego", nullptr));
        rno->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        rsi->setText(QCoreApplication::translate("MainWindow", "Si", nullptr));
        cpjugada->setText(QCoreApplication::translate("MainWindow", "Cronometro por jugada", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Repeticion de elementos de la combinacion:", nullptr));
        repsi->setText(QCoreApplication::translate("MainWindow", "Si", nullptr));
        repno->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Panel de elementos para usar en la combinaci\303\263n:", nullptr));
        elementocolor->setText(QString());
        elementoletra->setText(QString());
        elementonumero->setText(QString());
        elementodefinido->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        pushButton_16->setText(QString());
        pushButton_17->setText(QString());
        pushButton_18->setText(QString());
        pushButton_19->setText(QString());
        pushButton_20->setText(QString());
        pushButton_21->setText(QString());
        pushButton_22->setText(QString());
        pushButton_23->setText(QString());
        pushButton_24->setText(QString());
        guardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
