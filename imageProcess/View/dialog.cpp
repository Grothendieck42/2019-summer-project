#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(const QString &title, const QString &name, int min ,int max, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->setWindowTitle(title);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    ui->setupUi(this);
    label = this->findChild<QLabel*>("label");
    slider = this->findChild<QSlider*>("horizontalSlider");
    board = this->findChild<QSpinBox*>("spinBox");
    label->setText(name);
    slider->setMinimum(min);
    slider->setMaximum(max);
    board->setMinimum(min);
    board->setMaximum(max);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::setCommand(std::shared_ptr<Command> command)
{

}

void Dialog::setTmpCommand(std::shared_ptr<Command> tmpCommand)
{

}

void Dialog::on_buttonBox_accepted()
{

}

void Dialog::on_buttonBox_rejected()
{
    displayNowCommand->exec();
}

void Dialog::on_horizontalSlider_valueChanged(int value)
{
    board->setValue(value);
}

void Dialog::on_spinBox_valueChanged(int arg1)
{
    slider->setValue(arg1);
}
