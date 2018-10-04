#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include "findEyeCenter.h"

using namespace cv;

class ImageProcessor
{
public:
    bool load(const String& faceCascade);
    Mat process(Mat);
private:
    void findEyes(Mat frame_gray, Rect face);
    //Mat frame;
    Mat debugImage;
    CascadeClassifier face_cascade;
    //colors in bgr format
    const Scalar red = Scalar(0, 0, 255);
    const Scalar blue = Scalar(255, 0, 0);
};

#endif // IMAGEPROCESSOR_H
