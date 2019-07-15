#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QString>
#include <QSlider>
#include <QSpinBox>
#include "../Common/Command.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(const QString &title, const QString &name, int min = 1, int max = 100, QWidget *parent = nullptr);
    ~Dialog();
    void setCommand(std::shared_ptr<Command> command);
    void setTmpCommand(std::shared_ptr<Command> tmpCommand);
    void setDisplayNowCommand(std::shared_ptr<Command> displayNowCommand);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
    QLabel *label;
    QSlider *slider;
    QSpinBox *board;
    std::shared_ptr<Command> command;
    std::shared_ptr<Command> tmpCommand;
    std::shared_ptr<Command> displayNowCommand;
};

#endif // DIALOG_H
