#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QFileDialog>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QPixmap>
#include <QGraphicsScene>
#include <memory>
#include "lightconstractdialog.h"
#include "../Common/myImage.h"
#include "../Common/ImageList.h"
#include "../Common/Command.h"
#include "Notification/UpdateNotification.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update();
    void error(const QString &content);
    void setQImage(std::shared_ptr<QImage> qImage);
    ~MainWindow();
    void setDisplayNowCommand(std::shared_ptr<Command> displayNowCommand);
    void setOpenFileCommand(std::shared_ptr<Command> openFileCommand);
    void setSaveFileCommand(std::shared_ptr<Command> saveFileCommand);
    void setAverBlurCommand(std::shared_ptr<Command> averBlurCommand);
    void setMidBlurCommand(std::shared_ptr<Command> midBlurCommand);
    void setGaussBlurCommand(std::shared_ptr<Command> gaussBlurCommand);
    void setBilaterBlurCommand(std::shared_ptr<Command> bilaterBlurCommand);
    void setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand);
    void setTmpLightContrastCommand(std::shared_ptr<Command> tmpLightContrastCommand);
    void setToGrayCommand(std::shared_ptr<Command> toGrayCommand);
    void setToBinaryCommand(std::shared_ptr<Command> toBinaryCommand);
    void setDetectEdgeCommand(std::shared_ptr<Command> detectEdgeCommand);
    void setGrayEqualizeHistCommand(std::shared_ptr<Command> grayEqualizeHistCommand);
    void setColorEqualizeHistCommand(std::shared_ptr<Command> colorEqualizeHistCommand);
    void setLaplaceCommand(std::shared_ptr<Command> laplaceCommand);
    void setLogEnhanceCommand(std::shared_ptr<Command> logEnhanceCommand);
    void setGammaCorrectCommand(std::shared_ptr<Command> gammaCorrectCommand);
    void setAddGaussNoiseCommand(std::shared_ptr<Command> addGaussNoiseCommand);
    void setAddSaltNoiseCommand(std::shared_ptr<Command> addSaltNoiseCommand);
    void setImageSegmentationCommand(std::shared_ptr<Command> imageSegmentationCommand);
    void setImageEnlargeCommand(std::shared_ptr<Command> imageEnlargeCommand);
    void setImageReductCommand(std::shared_ptr<Command> imageReductCommand);
    void setImageGuidedCommand(std::shared_ptr<Command> imageGuidedCommand);
    void setImageDefogCommand(std::shared_ptr<Command> imageDefogCommand);
    void setTrainModelCommand(std::shared_ptr<Command> trainModelCommand);
    void setDetectFacesCommand(std::shared_ptr<Command> detectFacesCommand);
    void setAnnotateFacesCommand(std::shared_ptr<Command> annotateFacesCommand);
    void setBeautifyFacesCommand(std::shared_ptr<Command> beautifyFacesCommand);
    void setGenerateHeadshotsCommand(std::shared_ptr<Command> generateHeadshotsCommand);
    void setUndoCommand(std::shared_ptr<Command> undoCommand);
    std::shared_ptr<Notification> getNotification();
private slots:

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionToGray_triggered();

    void on_actionToBinary_triggered();

    void on_actionlight_triggered();

    void on_actionjizhilvbo_triggered();

    void on_actionzhongzhillvbo_triggered();

    void on_actiongaosilvbo_triggered();

    void on_actionshuangbianlvbo_triggered();

    void on_actionDetectEdge_triggered();

    void on_actionGrayEqualizeHist_triggered();

    void on_actionColorEqualizeHist_triggered();

    void on_actionLaplace_triggered();

    void on_actionLogEnhance_triggered();

    void on_actionGamma_triggered();

    void on_actionGaussNoise_triggered();

    void on_actionSalt_triggered();

    void on_actionImageSegmentation_triggered();

    void on_actionEnlarge_triggered();

    void on_actionReduct_triggered();

    void on_actionGuidedFilter_triggered();

    void on_actionDefog_triggered();

    void on_actionTrainEigenModel_triggered();

    void on_actionDetectFaces_triggered();

    void on_actionAnnotateFaces_triggered();

    void on_actionBeautifyFaces_triggered();

    void on_actionGenerateHeadshots_triggered();

    void on_actionchexiao_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QImage> qImage;
    QGraphicsView* graphView;
    QGraphicsScene *scene;
    QMenu *tool_item;
    QMenu *adjust_item;
    QMenu *enlarge_item;
    QAction *actionDetectFaces;
    QAction *actionAnnotateFaces;
    QAction *actionBeautifyFaces;
    QAction *actionGenerateHeadshots;
    LightConstractDialog lightDialog;

    std::shared_ptr<UpdateNotification> updateNotification;
    std::shared_ptr<Command> openFileCommand;
    std::shared_ptr<Command> saveFileCommand;
    std::shared_ptr<Command> toGrayCommand;
    std::shared_ptr<Command> toBinaryCommand;
    std::shared_ptr<Command> averBlurCommand;
    std::shared_ptr<Command> midBlurCommand;
    std::shared_ptr<Command> gaussBlurCommand;
    std::shared_ptr<Command> bilaterBlurCommand;
    std::shared_ptr<Command> detectEdgeCommand;
    std::shared_ptr<Command> grayEqualizeHistCommand;
    std::shared_ptr<Command> colorEqualizeHistCommand;
    std::shared_ptr<Command> laplaceCommand;
    std::shared_ptr<Command> logEnhanceCommand;
    std::shared_ptr<Command> gammaCorrectCommand;
    std::shared_ptr<Command> addGaussNoiseCommand;
    std::shared_ptr<Command> addSaltNoiseCommand;
    std::shared_ptr<Command> imageSegmentationCommand;
    std::shared_ptr<Command> imageEnlargeCommand;
    std::shared_ptr<Command> imageReductCommand;
    std::shared_ptr<Command> imageGuidedCommand;
    std::shared_ptr<Command> imageDefogCommand;
    std::shared_ptr<Command> trainEigenModelCommand;
    std::shared_ptr<Command> detectFacesCommand;
    std::shared_ptr<Command> annotateFacesCommand;
    std::shared_ptr<Command> beautifyFacesCommand;
    std::shared_ptr<Command> generateHeadshotsCommand;
    std::shared_ptr<Command> undoCommand;
};


