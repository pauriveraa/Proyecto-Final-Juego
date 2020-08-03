/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *potencia;
    QSlider *angulo;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLCDNumber *lcdNumber_3;
    QLabel *label_4;
    QLabel *labelnombre;
    QLineEdit *lineEdit;
    QPushButton *REGISTRARVS;
    QPushButton *disparovs;
    QLineEdit *lineEdit_2JUGADOR1;
    QLineEdit *lineEdit_3JUGADOR2;
    QLabel *label_5JUGADOR1;
    QLabel *label_6JUGADOR2;
    QLCDNumber *contavs;
    QLCDNumber *lcdNumber_4puntaje1;
    QLCDNumber *contanivel;
    QLCDNumber *lcdNumber_5puntaj2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *reiniciar;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *mutear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(667, 424);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        potencia = new QSlider(centralWidget);
        potencia->setObjectName(QString::fromUtf8("potencia"));
        potencia->setGeometry(QRect(90, 290, 71, 22));
        potencia->setMaximum(100);
        potencia->setOrientation(Qt::Horizontal);
        angulo = new QSlider(centralWidget);
        angulo->setObjectName(QString::fromUtf8("angulo"));
        angulo->setGeometry(QRect(60, 220, 22, 61));
        angulo->setMinimum(0);
        angulo->setMaximum(90);
        angulo->setOrientation(Qt::Vertical);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 340, 61, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/shoot.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(71, 160));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(90, 0, 491, 281));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing|QGraphicsView::DontClipPainter|QGraphicsView::DontSavePainterState|QGraphicsView::IndirectPainting);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(310, 350, 64, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 170, 71, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/start.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(75, 160));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 250, 71, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/exit.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(75, 160));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(220, 350, 64, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 200, 71, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/signin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(75, 160));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 150, 71, 31));
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(75, 160));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 200, 71, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/1vs1.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setIconSize(QSize(75, 160));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 330, 71, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 330, 61, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(420, 330, 41, 16));
        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(400, 350, 64, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 330, 47, 13));
        labelnombre = new QLabel(centralWidget);
        labelnombre->setObjectName(QString::fromUtf8("labelnombre"));
        labelnombre->setGeometry(QRect(60, 350, 47, 13));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 170, 113, 20));
        REGISTRARVS = new QPushButton(centralWidget);
        REGISTRARVS->setObjectName(QString::fromUtf8("REGISTRARVS"));
        REGISTRARVS->setGeometry(QRect(300, 290, 71, 31));
        REGISTRARVS->setIcon(icon3);
        REGISTRARVS->setIconSize(QSize(75, 160));
        disparovs = new QPushButton(centralWidget);
        disparovs->setObjectName(QString::fromUtf8("disparovs"));
        disparovs->setGeometry(QRect(170, 290, 61, 31));
        disparovs->setIcon(icon);
        disparovs->setIconSize(QSize(71, 160));
        lineEdit_2JUGADOR1 = new QLineEdit(centralWidget);
        lineEdit_2JUGADOR1->setObjectName(QString::fromUtf8("lineEdit_2JUGADOR1"));
        lineEdit_2JUGADOR1->setGeometry(QRect(210, 170, 113, 20));
        lineEdit_3JUGADOR2 = new QLineEdit(centralWidget);
        lineEdit_3JUGADOR2->setObjectName(QString::fromUtf8("lineEdit_3JUGADOR2"));
        lineEdit_3JUGADOR2->setGeometry(QRect(350, 170, 113, 20));
        label_5JUGADOR1 = new QLabel(centralWidget);
        label_5JUGADOR1->setObjectName(QString::fromUtf8("label_5JUGADOR1"));
        label_5JUGADOR1->setGeometry(QRect(240, 150, 47, 13));
        label_6JUGADOR2 = new QLabel(centralWidget);
        label_6JUGADOR2->setObjectName(QString::fromUtf8("label_6JUGADOR2"));
        label_6JUGADOR2->setGeometry(QRect(390, 150, 47, 13));
        contavs = new QLCDNumber(centralWidget);
        contavs->setObjectName(QString::fromUtf8("contavs"));
        contavs->setGeometry(QRect(360, 310, 64, 23));
        lcdNumber_4puntaje1 = new QLCDNumber(centralWidget);
        lcdNumber_4puntaje1->setObjectName(QString::fromUtf8("lcdNumber_4puntaje1"));
        lcdNumber_4puntaje1->setGeometry(QRect(510, 310, 64, 23));
        contanivel = new QLCDNumber(centralWidget);
        contanivel->setObjectName(QString::fromUtf8("contanivel"));
        contanivel->setGeometry(QRect(360, 350, 64, 23));
        lcdNumber_5puntaj2 = new QLCDNumber(centralWidget);
        lcdNumber_5puntaj2->setObjectName(QString::fromUtf8("lcdNumber_5puntaj2"));
        lcdNumber_5puntaj2->setGeometry(QRect(510, 350, 64, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(450, 310, 51, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(450, 350, 51, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 300, 101, 41));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 260, 61, 61));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(480, 340, 71, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/save.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon5);
        pushButton_7->setIconSize(QSize(75, 160));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(570, 340, 71, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagenes/load.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setIconSize(QSize(75, 160));
        reiniciar = new QPushButton(centralWidget);
        reiniciar->setObjectName(QString::fromUtf8("reiniciar"));
        reiniciar->setGeometry(QRect(590, 10, 71, 23));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 350, 47, 13));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(-10, -30, 661, 411));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/Mesadetrabajo 4.png")));
        label_10->setScaledContents(true);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(430, 320, 181, 41));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(280, 290, 111, 81));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logoard.png")));
        label_14->setScaledContents(true);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 220, 31, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_12->setFont(font);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(110, 310, 41, 21));
        label_13->setFont(font);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(-40, -170, 671, 381));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/instrucciones.jpeg")));
        label_15->setScaledContents(true);
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(0, 340, 31, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imagenes/INSTRUCCIONES.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon7);
        pushButton_9->setIconSize(QSize(30, 28));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(620, 340, 31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/imagenes/atrasestese.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon8);
        pushButton_10->setIconSize(QSize(30, 28));
        mutear = new QPushButton(centralWidget);
        mutear->setObjectName(QString::fromUtf8("mutear"));
        mutear->setGeometry(QRect(0, 0, 31, 41));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/imagenes/mutear.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        mutear->setIcon(icon9);
        mutear->setIconSize(QSize(34, 60));
        MainWindow->setCentralWidget(centralWidget);
        label_10->raise();
        graphicsView->raise();
        potencia->raise();
        angulo->raise();
        pushButton->raise();
        lcdNumber->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        lcdNumber_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        lcdNumber_3->raise();
        label_4->raise();
        labelnombre->raise();
        lineEdit->raise();
        REGISTRARVS->raise();
        disparovs->raise();
        lineEdit_2JUGADOR1->raise();
        lineEdit_3JUGADOR2->raise();
        label_5JUGADOR1->raise();
        label_6JUGADOR2->raise();
        contavs->raise();
        lcdNumber_4puntaje1->raise();
        contanivel->raise();
        lcdNumber_5puntaj2->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        label_9->raise();
        label_11->raise();
        label_14->raise();
        label_15->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        mutear->raise();
        reiniciar->raise();
        label_13->raise();
        label_12->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 667, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<font color=white>DISPAROS", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<font color=white>PUNTAJE", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<font color=white>MUNDO", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<font color=white>USUARIO", nullptr));
        labelnombre->setText(QCoreApplication::translate("MainWindow", "<font color=white>TextLabel", nullptr));
        REGISTRARVS->setText(QString());
        disparovs->setText(QString());
        label_5JUGADOR1->setText(QCoreApplication::translate("MainWindow", "<font color=white>PLAYER 1", nullptr));
        label_6JUGADOR2->setText(QCoreApplication::translate("MainWindow", "<font color=white>PLAYER 2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<font color=white>PLAYER 1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<font color=white>PLAYER 2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<font color=white>DISPAROS", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<font color=white>PUNTAJES", nullptr));
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        reiniciar->setText(QCoreApplication::translate("MainWindow", "REINICIAR", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "NIVEL", nullptr));
        label_10->setText(QString());
        label_11->setText(QString());
        label_14->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_15->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        mutear->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
