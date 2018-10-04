#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T17:06:56
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EyeDetect
TEMPLATE = app

win32 {
#    INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.10150.0\ucrt"
#    LIBS += "C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10150.0\ucrt\x86\ucrtd.lib"


    INCLUDEPATH += F:\opencv\build\include
    OPENCVLIBS = F:\opencv\build\lib\Debug
    LIBS += $$OPENCVLIBS/opencv_calib3d310d.lib \
    $$OPENCVLIBS/opencv_core310d.lib\
    $$OPENCVLIBS/opencv_features2d310d.lib\
    $$OPENCVLIBS/opencv_flann310d.lib\
    $$OPENCVLIBS/opencv_highgui310d.lib\
    $$OPENCVLIBS/opencv_imgcodecs310d.lib\
    $$OPENCVLIBS/opencv_imgproc310d.lib\
    $$OPENCVLIBS/opencv_ml310d.lib\
    $$OPENCVLIBS/opencv_objdetect310d.lib\
    $$OPENCVLIBS/opencv_photo310d.lib\
    $$OPENCVLIBS/opencv_shape310d.lib\
    $$OPENCVLIBS/opencv_stitching310d.lib\
    $$OPENCVLIBS/opencv_superres310d.lib\
    $$OPENCVLIBS/opencv_ts310d.lib\
    $$OPENCVLIBS/opencv_video310d.lib\
    $$OPENCVLIBS/opencv_videoio310d.lib\
    $$OPENCVLIBS/opencv_videostab310d.lib
}

android {
    INCLUDEPATH += $$_PRO_FILE_PWD_/sdk/native/jni/include
    OPENCV3RDPARTYLIBS = $$_PRO_FILE_PWD_/sdk/native/3rdparty/libs/armeabi-v7a
    OPENCVNATIVELIBS = $$_PRO_FILE_PWD_/sdk/native/libs/armeabi-v7a
    LIBS += $$OPENCV3RDPARTYLIBS/liblibtiff.a \
    $$OPENCV3RDPARTYLIBS/liblibjpeg.a \
    $$OPENCV3RDPARTYLIBS/liblibjasper.a \
    $$OPENCV3RDPARTYLIBS/liblibpng.a \
    $$OPENCV3RDPARTYLIBS/libtbb.a \
    $$OPENCV3RDPARTYLIBS/libIlmImf.a
    LIBS += $$OPENCVNATIVELIBS/libopencv_core.a \
    $$OPENCVNATIVELIBS/libopencv_flann.a \
    $$OPENCVNATIVELIBS/libopencv_imgproc.a \
    $$OPENCVNATIVELIBS/libopencv_highgui.a \
    $$OPENCVNATIVELIBS/libopencv_features2d.a \
    $$OPENCVNATIVELIBS/libopencv_calib3d.a \
    $$OPENCVNATIVELIBS/libopencv_ml.a \
    $$OPENCVNATIVELIBS/libopencv_objdetect.a \
    $$OPENCVNATIVELIBS/libopencv_photo.a \
    $$OPENCVNATIVELIBS/libopencv_stitching.a \
    $$OPENCVNATIVELIBS/libopencv_superres.a \
    $$OPENCVNATIVELIBS/libopencv_ts.a \
    $$OPENCVNATIVELIBS/libopencv_video.a \
    $$OPENCVNATIVELIBS/libopencv_videostab.a \
    $$OPENCVNATIVELIBS/libopencv_imgcodecs.a \
    $$OPENCVNATIVELIBS/libopencv_shape.a \
    $$OPENCVNATIVELIBS/libopencv_videoio.a \
    $$OPENCVNATIVELIBS/libopencv_java3.so

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
}
SOURCES += main.cpp\
        findEyeCenter.cpp\
        mainwindow.cpp \
    imageprocessor.cpp


HEADERS  += mainwindow.h \
    constants.h \
    findEyeCenter.h \
    imageprocessor.h \
    converter.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    xml.qrc

DISTFILES += \
    android-sources/AndroidManifest.xml \
    android-sources/gradle/wrapper/gradle-wrapper.jar \
    android-sources/gradlew \
    android-sources/res/values/libs.xml \
    android-sources/build.gradle \
    android-sources/gradle/wrapper/gradle-wrapper.properties \
    android-sources/gradlew.bat

QMAKE_CXXFLAGS += -std=gnu++14
