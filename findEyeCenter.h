#ifndef EYE_CENTER_H
#define EYE_CENTER_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "constants.h"


cv::Point findEyeCenter(cv::Mat face, cv::Rect eye);

#endif
