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
#include "../Common/ImageList.h"
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
    void setImageList(std::shared_ptr<ImageList> imageList);
    ~MainWindow();
    void setOpenFileCommand(std::shared_ptr<OpenFileCommand> openFileCommand);

private slots:
    void on_inputImage_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ImageList> imageList;
    QGraphicsView* graphView;
    QPushButton* inputImageButton;
    QGraphicsScene *scene;

    std::shared_ptr<OpenFileCommand> openFileCommand;
};

#endif // MAINWINDOW_H
