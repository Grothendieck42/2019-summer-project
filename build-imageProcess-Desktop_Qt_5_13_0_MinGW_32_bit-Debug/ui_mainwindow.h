/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *action_bmp;
    QAction *action_png;
    QAction *action_jpg;
    QAction *actionToGray;
    QAction *actionToBinary;
    QAction *actionlight;
    QAction *actionDetectEdge;
    QAction *actionGrayEqualizeHist;
    QAction *actionColorEqualizeHist;
    QAction *actionLaplace;
    QAction *actionLogEnhance;
    QAction *actionGamma;
    QAction *actionGaussNoise;
    QAction *actionSalt;
    QAction *actionImageSegmentation;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *image1;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(940, 782);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        action_bmp = new QAction(MainWindow);
        action_bmp->setObjectName(QString::fromUtf8("action_bmp"));
        action_png = new QAction(MainWindow);
        action_png->setObjectName(QString::fromUtf8("action_png"));
        action_jpg = new QAction(MainWindow);
        action_jpg->setObjectName(QString::fromUtf8("action_jpg"));
        actionToGray = new QAction(MainWindow);
        actionToGray->setObjectName(QString::fromUtf8("actionToGray"));
        actionToBinary = new QAction(MainWindow);
        actionToBinary->setObjectName(QString::fromUtf8("actionToBinary"));
        actionlight = new QAction(MainWindow);
        actionlight->setObjectName(QString::fromUtf8("actionlight"));
        actionDetectEdge = new QAction(MainWindow);
        actionDetectEdge->setObjectName(QString::fromUtf8("actionDetectEdge"));
        actionGrayEqualizeHist = new QAction(MainWindow);
        actionGrayEqualizeHist->setObjectName(QString::fromUtf8("actionGrayEqualizeHist"));
        actionColorEqualizeHist = new QAction(MainWindow);
        actionColorEqualizeHist->setObjectName(QString::fromUtf8("actionColorEqualizeHist"));
        actionLaplace = new QAction(MainWindow);
        actionLaplace->setObjectName(QString::fromUtf8("actionLaplace"));
        actionLogEnhance = new QAction(MainWindow);
        actionLogEnhance->setObjectName(QString::fromUtf8("actionLogEnhance"));
        actionGamma = new QAction(MainWindow);
        actionGamma->setObjectName(QString::fromUtf8("actionGamma"));
        actionGaussNoise = new QAction(MainWindow);
        actionGaussNoise->setObjectName(QString::fromUtf8("actionGaussNoise"));
        actionSalt = new QAction(MainWindow);
        actionSalt->setObjectName(QString::fromUtf8("actionSalt"));
        actionImageSegmentation = new QAction(MainWindow);
        actionImageSegmentation->setObjectName(QString::fromUtf8("actionImageSegmentation"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        image1 = new QGraphicsView(centralWidget);
        image1->setObjectName(QString::fromUtf8("image1"));

        gridLayout->addWidget(image1, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 940, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menu_4);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(actionopen);
        menu->addAction(actionsave);
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(action_bmp);
        menu_2->addAction(action_png);
        menu_2->addAction(action_jpg);
        menu_3->addAction(actionToGray);
        menu_3->addAction(actionToBinary);
        menu_3->addAction(actionDetectEdge);
        menu_3->addAction(actionImageSegmentation);
        menu_4->addAction(actionlight);
        menu_4->addAction(actionGrayEqualizeHist);
        menu_4->addAction(actionColorEqualizeHist);
        menu_4->addAction(menu_5->menuAction());
        menu_4->addAction(actionGaussNoise);
        menu_4->addAction(actionSalt);
        menu_5->addAction(actionLaplace);
        menu_5->addAction(actionLogEnhance);
        menu_5->addAction(actionGamma);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actionsave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        action_bmp->setText(QCoreApplication::translate("MainWindow", ".bmp", nullptr));
        action_png->setText(QCoreApplication::translate("MainWindow", ".png", nullptr));
        action_jpg->setText(QCoreApplication::translate("MainWindow", ".jpeg", nullptr));
        actionToGray->setText(QCoreApplication::translate("MainWindow", "\350\275\254\345\214\226\344\270\272\347\201\260\345\272\246\345\233\276", nullptr));
        actionToBinary->setText(QCoreApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226", nullptr));
        actionlight->setText(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264\344\272\256\345\272\246/\345\257\271\346\257\224\345\272\246", nullptr));
        actionDetectEdge->setText(QCoreApplication::translate("MainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        actionGrayEqualizeHist->setText(QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", nullptr));
        actionColorEqualizeHist->setText(QCoreApplication::translate("MainWindow", "\345\275\251\350\211\262\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", nullptr));
        actionLaplace->setText(QCoreApplication::translate("MainWindow", "\346\213\211\346\231\256\346\213\211\346\226\257\345\233\276\345\203\217\351\224\220\345\214\226", nullptr));
        actionLogEnhance->setText(QCoreApplication::translate("MainWindow", "\345\257\271\346\225\260\345\217\230\346\215\242", nullptr));
        actionGamma->setText(QCoreApplication::translate("MainWindow", "\344\274\275\351\251\254\346\240\241\346\255\243", nullptr));
        actionGaussNoise->setText(QCoreApplication::translate("MainWindow", "\351\253\230\346\226\257\345\231\252\345\243\260", nullptr));
        actionSalt->setText(QCoreApplication::translate("MainWindow", "\346\244\222\347\233\220\345\231\252\345\243\260", nullptr));
        actionImageSegmentation->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\210\206\345\211\262", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\242\236\345\274\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
