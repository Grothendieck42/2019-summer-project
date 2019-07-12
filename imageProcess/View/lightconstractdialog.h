#ifndef LIGHTCONSTRACTDIALOG_H
#define LIGHTCONSTRACTDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QSpinBox>
#include "../Common/Command.h"

namespace Ui {
class LightConstractDialog;
}

class LightConstractDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LightConstractDialog(QWidget *parent = nullptr);
    ~LightConstractDialog();
    void setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_contrastBoard_valueChanged(int arg1);

    void on_lightBoard_valueChanged(int arg1);

    void on_contrastSlide_valueChanged(int value);

    void on_lightSlide_valueChanged(int value);

private:
    Ui::LightConstractDialog *ui;
    QSpinBox* lightBoard;
    QSpinBox* contrastBoard;
    QSlider* lightSlider;
    QSlider* contrastSlider;
    std::shared_ptr<Command> lightContrastCommand;
    int old_light;
    int old_contrast;
};

#endif // LIGHTCONSTRACTDIALOG_H
