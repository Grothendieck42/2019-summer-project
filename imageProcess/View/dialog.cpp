#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(const QString &name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->setWindowTitle("调整" + name);
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
