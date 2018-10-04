#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QBoxLayout>
#include <QImage>
#include <QTimer>
#include "imageprocessor.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startPushButton_clicked();
public slots:
    void updateFrame();
private:
    Ui::MainWindow *ui;

    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QBoxLayout *mLayout;
    QTimer* tmrTimer;
    ImageProcessor* imageProc;
};

#endif // MAINWINDOW_H
