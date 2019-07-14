#-------------------------------------------------
#
# Project created by QtCreator 2019-07-07T15:11:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imageProcess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

QMAKE_CXXFLAGS = $$QMAKE_CFLAGS -std=c++17

SOURCES += \
        main.cpp \
        View/mainwindow.cpp \
        App/app.cpp \
        ViewModel/ViewModel.cpp \
        Model/Model.cpp \
        Common/Command.cpp \
        ViewModel/Command/OpenFileCommand.cpp \
        ViewModel/Command/LightContrastCommand.cpp \
        ViewModel/Command/AddGaussNoiseCommand.cpp \
        ViewModel/Command/AddSaltNoiseCommand.cpp \
        ViewModel/Command/ColorEqualizeHistCommand.cpp \
        ViewModel/Command/DetectEdgeCommand.cpp \
        ViewModel/Command/GammaCorrectCommand.cpp \
        ViewModel/Command/GrayEqualizeHistCommand.cpp \
        ViewModel/Command/ImageEnlargeCommand.cpp \
        ViewModel/Command/ImageReductCommand.cpp \
        ViewModel/Command/ImageSegmentationCommand.cpp \
        ViewModel/Command/LaplaceCommand.cpp \
        ViewModel/Command/LogEnhanceCommand.cpp \
        ViewModel/Command/savefilecommand.cpp \
        ViewModel/Command/ToBinaryCommand.cpp \
        ViewModel/Command/tograycommand.cpp \
        ViewModel/Command/AverBlurCommand.cpp \
        Common/myImage.cpp \
        Utility/utility.cpp \
        Common/ImageList.cpp \
        Common/Notification.cpp \
        View/Notification/UpdateNotification.cpp \
        ViewModel/Notification/UpdateDataNotification.cpp \
        View/lightconstractdialog.cpp \
        ViewModel/Notification/UpdateTmpNotification.cpp \
        ViewModel/Command/TmpLightContrastCommand.cpp \
        ViewModel/Command/MidBlurCommand.cpp \
        ViewModel/Command/GaussBlurCommand.cpp \
        ViewModel/Command/BilaterBlurCommand.cpp \
        ViewModel/Command/DisplayNowCommand.cpp \
        ViewModel/Command/UndoCommand.cpp \
        ViewModel/Command/TrainEigenModelCommand.cpp \
    View/dialog.cpp


HEADERS += \
        View/mainwindow.h \
        App/app.h \
        ViewModel/ViewModel.h \
        Model/Model.h \
        Common/Command.h \
        ViewModel/Command/OpenFileCommand.h \
        ViewModel/Command/LightContrastCommand.h \
        ViewModel/Command/AddGaussNoiseCommand.h \
        ViewModel/Command/AddSaltNoiseCommand.h \
        ViewModel/Command/ColorEqualizeHistCommand.h \
        ViewModel/Command/DetectEdgeCommand.h \
        ViewModel/Command/GammaCorrectCommand.h \
        ViewModel/Command/GrayEqualizeHistCommand.h \
        ViewModel/Command/ImageEnlargeCommand.h \
        ViewModel/Command/ImageReductCommand.h \
        ViewModel/Command/ImageSegmentationCommand.h \
        ViewModel/Command/LaplaceCommand.h \
        ViewModel/Command/LogEnhanceCommand.h \
        ViewModel/Command/SaveFileCommand.h \
        ViewModel/Command/ToBinaryCommand.h \
        ViewModel/Command/ToGrayCommand.h \
        ViewModel/Command/AverBlurCommand.h \
        Common/myImage.h \
        Utility/utility.h \
        Common/ImageList.h \
        Common/Notification.h \
        View/Notification/UpdateNotification.h \
        ViewModel/Notification/UpdateDataNotification.h \
        ViewModel/Command/DisplayNowCommand.h \
        ViewModel/Command/UndoCommand.h \
        View/lightconstractdialog.h \
        ViewModel/Notification/UpdateTmpNotification.h \
        ViewModel/Command/TmpLightContrastCommand.h \
        ViewModel/Command/MidBlurCommand.h \
        ViewModel/Command/GaussBlurCommand.h \
        ViewModel/Command/BilaterBlurCommand.h \
        ViewModel/Command/DetectFacesCommand.h \
        ViewModel/Command/LoadEigenModeCommand.h \
        ViewModel/Command/TrainEigenModelCommand.h \
        ViewModel/Command/AnnotateFacesCommand.h \
        ViewModel/Command/BeautifyFacesCommand.h \
        Common/Common.h \
        ViewModel/Command/GenerateHeadshotsCommand.h \
    View/dialog.h

FORMS += \
       View/mainwindow.ui \
       View/lightconstractdialog.ui \
    View/dialog.ui

INCLUDEPATH += /usr/local/opt/opencv/include/opencv4
LIBS += -L/usr/local/opt/opencv/lib \
     -lopencv_core \
     -lopencv_face \
     -lopencv_dnn \
     -lopencv_ccalib \
     -lopencv_datasets \
     -lopencv_fuzzy \
     -lopencv_img_hash \
     -lopencv_ml \
     -lopencv_optflow \
     -lopencv_photo \
     -lopencv_plot \
     -lopencv_reg \
     -lopencv_saliency \
     -lopencv_shape \
     -lopencv_stitching \
     -lopencv_surface_matching \
     -lopencv_text \
     -lopencv_tracking \
     -lopencv_videoio \
     -lopencv_xfeatures2d \
     -lopencv_ximgproc \
     -lopencv_xobjdetect \
     -lopencv_xphoto \
     -lopencv_imgproc \
     -lopencv_features2d\
     -lopencv_highgui\
     -lopencv_imgcodecs\
     -lopencv_aruco \
     -lopencv_bgsegm \
     -lopencv_bioinspired \
     -lopencv_calib3d \
     -lopencv_dpm \
     -lopencv_flann \
     -lopencv_imgcodecs \
     -lopencv_imgproc \
     -lopencv_line_descriptor \
     -lopencv_objdetect \
     -lopencv_phase_unwrapping \
     -lopencv_rgbd \
     -lopencv_stereo \
     -lopencv_structured_light \
     -lopencv_superres \
     -lopencv_video \
     -lopencv_videostab \
     -v
