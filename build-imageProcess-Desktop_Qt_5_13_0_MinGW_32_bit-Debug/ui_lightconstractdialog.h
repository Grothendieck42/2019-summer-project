/********************************************************************************
** Form generated from reading UI file 'lightconstractdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTCONSTRACTDIALOG_H
#define UI_LIGHTCONSTRACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_LightConstractDialog
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *contrastSlide;
    QSlider *lightSlide;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *contrastBoard;
    QSpinBox *lightBoard;

    void setupUi(QDialog *LightConstractDialog)
    {
        if (LightConstractDialog->objectName().isEmpty())
            LightConstractDialog->setObjectName(QString::fromUtf8("LightConstractDialog"));
        LightConstractDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(LightConstractDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 30, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        contrastSlide = new QSlider(LightConstractDialog);
        contrastSlide->setObjectName(QString::fromUtf8("contrastSlide"));
        contrastSlide->setGeometry(QRect(30, 51, 161, 31));
        contrastSlide->setMinimum(1);
        contrastSlide->setMaximum(1000);
        contrastSlide->setValue(100);
        contrastSlide->setOrientation(Qt::Horizontal);
        lightSlide = new QSlider(LightConstractDialog);
        lightSlide->setObjectName(QString::fromUtf8("lightSlide"));
        lightSlide->setGeometry(QRect(30, 180, 160, 22));
        lightSlide->setMaximum(100);
        lightSlide->setOrientation(Qt::Horizontal);
        label = new QLabel(LightConstractDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 57, 16));
        label_2 = new QLabel(LightConstractDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 57, 16));
        contrastBoard = new QSpinBox(LightConstractDialog);
        contrastBoard->setObjectName(QString::fromUtf8("contrastBoard"));
        contrastBoard->setGeometry(QRect(210, 50, 51, 31));
        contrastBoard->setMinimum(1);
        contrastBoard->setMaximum(1000);
        contrastBoard->setValue(100);
        lightBoard = new QSpinBox(LightConstractDialog);
        lightBoard->setObjectName(QString::fromUtf8("lightBoard"));
        lightBoard->setGeometry(QRect(210, 180, 51, 31));
        lightBoard->setMaximum(100);

        retranslateUi(LightConstractDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LightConstractDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LightConstractDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LightConstractDialog);
    } // setupUi

    void retranslateUi(QDialog *LightConstractDialog)
    {
        LightConstractDialog->setWindowTitle(QCoreApplication::translate("LightConstractDialog", "\344\272\256\345\272\246\345\257\271\346\257\224\345\272\246\350\260\203\350\212\202", nullptr));
        label->setText(QCoreApplication::translate("LightConstractDialog", "\344\272\256\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("LightConstractDialog", "\345\257\271\346\257\224\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LightConstractDialog: public Ui_LightConstractDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTCONSTRACTDIALOG_H
