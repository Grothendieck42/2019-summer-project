#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QFileDialog>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>
#include "../Common/myImage.h"
#include "../Command/OpenFileCommand.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update();
    void setImage(std::shared_ptr<Image> image);
    ~MainWindow();
    void setOpenFileCommand(std::shared_ptr<OpenFileCommand> openFileCommand);

private slots:

    void on_actionopen_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Image> image;
    QGraphicsView* graphView;
    QPushButton* inputImageButton;
    QGraphicsScene *scene;

    std::shared_ptr<OpenFileCommand> openFileCommand;
};

#endif // MAINWINDOW_H
