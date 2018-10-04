#include <QtCore>
#include <QString>

#include <QCameraInfo>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "converter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    mCamera = new QCamera(cameras[1], this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->videoLabel->setLayout(mLayout);
    mCameraImageCapture->setCaptureDestination(
                QCameraImageCapture::CaptureToFile);
    QImageEncoderSettings imageEncoderSettings;
    imageEncoderSettings.setCodec("image/jpeg");
    imageEncoderSettings.setResolution(700, 700);
    mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
    mCamera->setCaptureMode(QCamera::CaptureStillImage);
    mCamera->start();

    QFile cascade(":/xml/face");
    cascade.open(QIODevice::ReadOnly);
    QFile savedFile("face.xml");
    savedFile.open(QIODevice::WriteOnly);
    QTextStream out(&savedFile);
    out << cascade.readAll();
    cascade.close();
    savedFile.close();

    imageProc = new ImageProcessor();
    if (!imageProc->load("face.xml"))
        ui->startPushButton->setText("no face cascade");
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()), this, SLOT(updateFrame()));
    tmrTimer->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateFrame()
{
    QString filename = "123.jpg";
    mCameraImageCapture->capture(filename);
    QImage src("/sdcard/DCIM/123.jpg");

    QPixmap qpixProcessed = Converter::cvMatToQPixmap(imageProc->process(Converter::QImageToCvMat(src)));
    int w = ui->label->width();
    int h = ui->label->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->label->setPixmap(qpixProcessed.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_startPushButton_clicked()
{
    if (tmrTimer->isActive())
    {
        tmrTimer->stop();
        ui->startPushButton->setText("Resume");
    }
    else {
        tmrTimer->start(20);
        ui->startPushButton->setText("Pause");
    }
}
