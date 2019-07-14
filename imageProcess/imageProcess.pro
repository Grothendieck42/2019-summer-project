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

SOURCES += \
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
        ViewModel/Command/SaveFileCommand.cpp \
        ViewModel/Command/ToBinaryCommand.cpp \
        ViewModel/Command/ToGrayCommand.cpp \
        main.cpp \
        View/mainwindow.cpp \
        App/app.cpp \
        ViewModel/ViewModel.cpp \
        Model/Model.cpp \
        Common/Command.cpp \
        ViewModel/Command/OpenFileCommand.cpp \
        ViewModel/Command/LightContrastCommand.cpp \
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
    ViewModel/Command/BilaterBlurCommand.cpp

HEADERS += \
        View/mainwindow.h \
        App/app.h \
        Common/myImage.h \
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
        ViewModel/Command/ToBibaryCommand.h \
        ViewModel/Command/ToGrayCommand.h \
        ViewModel/ViewModel.h \
        Model/Model.h \
        Common/Command.h \
        ViewModel/Command/OpenFileCommand.h \
        ViewModel/Command/LightContrastCommand.h \
        ViewModel/Command/AverBlurCommand.h \
        Utility/utility.h \
        Common/ImageList.h \
        Common/Notification.h \
        View/Notification/UpdateNotification.h \
        ViewModel/Notification/UpdateDataNotification.h \
    View/lightconstractdialog.h \
        Common/Common.h \
    ViewModel/Notification/UpdateTmpNotification.h \
    ViewModel/Command/TmpLightContrastCommand.h \
    ViewModel/Command/MidBlurCommand.h \
    ViewModel/Command/GaussBlurCommand.h \
    ViewModel/Command/BilaterBlurCommand.h
FORMS += \
       View/mainwindow.ui \
    View/lightconstractdialog.ui

INCLUDEPATH +=E:\opencv\build\include
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_core410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_highgui410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_imgcodecs410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_imgproc410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_features2d410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_calib3d410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_dnn410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_ml410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_photo410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_stitching410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_videoio410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_flann410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_objdetect410.dll.a
LIBS +=E:\opencv\minGW_build\install\x86\mingw\lib\libopencv_video410.dll.a
