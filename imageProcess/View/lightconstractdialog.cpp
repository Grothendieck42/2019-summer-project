#include "lightconstractdialog.h"
#include "ui_lightconstractdialog.h"
#include "../Common/Common.h"
#include <QDebug>

LightConstractDialog::LightConstractDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightConstractDialog)
{
    ui->setupUi(this);
    lightBoard = this->findChild<QSpinBox*>("lightBoard");
    contrastBoard = this->findChild<QSpinBox*>("contrastBoard");
    lightSlider = this->findChild<QSlider*>("lightSlide");
    contrastSlider = this->findChild<QSlider*>("contrastSlide");
}

LightConstractDialog::~LightConstractDialog()
{
    delete ui;
}

void LightConstractDialog::on_buttonBox_accepted()
{
    lightContrastCommand->setParameter(lightContrast{.light = lightBoard->value(), .contrast = contrastBoard->value()});
    lightContrastCommand->exec();
}

void LightConstractDialog::on_buttonBox_rejected()
{
}

void LightConstractDialog::on_contrastBoard_valueChanged(int arg1)
{
    contrastSlider->setValue(arg1);
}

void LightConstractDialog::on_lightBoard_valueChanged(int arg1)
{
    lightSlider->setValue(arg1);
}

void LightConstractDialog::on_contrastSlide_valueChanged(int value)
{
    contrastBoard->setValue(value);
}

void LightConstractDialog::on_lightSlide_valueChanged(int value)
{
    lightBoard->setValue(value);
}

void LightConstractDialog::setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand)
{
    this->lightContrastCommand = lightContrastCommand;
}

