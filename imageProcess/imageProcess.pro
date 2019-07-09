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
        main.cpp \
        View/mainwindow.cpp \
        App/app.cpp \
        ViewModel/ViewModel.cpp \
        Model/Model.cpp \
        Command/Command.cpp \
        Command/OpenFileCommand.cpp \
        Parameter/FileParameter.cpp \
        Parameter/Parameter.cpp \
        Common/myImage.cpp \
        Utility/utility.cpp

HEADERS += \
        View/mainwindow.h \
        App/app.h \
        Common/myImage.h \
        ViewModel/ViewModel.h \
        Model/Model.h \
        App/app.h \
        Common/myImage.h \
        ViewModel/ViewModel.h \
        Model/Model.h \
        Command/Command.h \
        Command/OpenFileCommand.h \
        Parameter/FileParameter.h \
        Parameter/Parameter.h \
        Utility/utility.h
FORMS += \
       View/mainwindow.ui

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
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
