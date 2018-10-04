#include "imageprocessor.h"
#include <vector>

bool ImageProcessor::load(const String& faceCascade)
{
    return face_cascade.load(faceCascade);
}

void ImageProcessor::findEyes(Mat frame_gray, Rect face) {
    Mat faceROI = frame_gray(face);
    Mat debugFace = faceROI;

    //-- Find eye regions and draw them
    int eye_width = face.width * kEyePercentWidth / 100;
    int eye_height = face.width * kEyePercentHeight / 100;
    int eye_top = face.height * kEyePercentTop / 100;
    int eye_leftside = face.width * kEyePercentSide / 100;
    Rect leftEyeRegion(eye_leftside, eye_top, eye_width, eye_height);
    Rect rightEyeRegion(face.width - eye_width - eye_leftside, eye_top, eye_width, eye_height);

    //-- Find Eye Centers
    Point leftPupil = findEyeCenter(faceROI, leftEyeRegion); // Left Eye
    Point rightPupil = findEyeCenter(faceROI, rightEyeRegion); //Right Eye
    // get corner regions
    Rect leftRightCornerRegion(leftEyeRegion);
    leftRightCornerRegion.width -= leftPupil.x;
    leftRightCornerRegion.x += leftPupil.x + face.x;
    leftRightCornerRegion.height /= 2;
    leftRightCornerRegion.y += leftRightCornerRegion.height / 2 + face.y;

    Rect leftLeftCornerRegion(leftEyeRegion);
    leftLeftCornerRegion.x += face.x;
    leftLeftCornerRegion.y += face.y;
    rectangle(debugImage, leftLeftCornerRegion, red);
    leftLeftCornerRegion.height /= 2;
    leftLeftCornerRegion.width = leftPupil.x;
    leftLeftCornerRegion.y += leftLeftCornerRegion.height / 2;

    Rect rightLeftCornerRegion(rightEyeRegion);
    rightLeftCornerRegion.x += face.x;
    rightLeftCornerRegion.y += face.y;
    rectangle(debugImage, rightLeftCornerRegion, red);
    rightLeftCornerRegion.height /= 2;
    rightLeftCornerRegion.width = rightPupil.x;
    rightLeftCornerRegion.y += rightLeftCornerRegion.height / 2;

    Rect rightRightCornerRegion(rightEyeRegion);
    rightRightCornerRegion.width -= rightPupil.x;
    rightRightCornerRegion.x += rightPupil.x + face.x;
    rightRightCornerRegion.height /= 2;
    rightRightCornerRegion.y += rightRightCornerRegion.height / 2 + face.y;

    rectangle(debugImage, leftRightCornerRegion, blue);
    rectangle(debugImage, leftLeftCornerRegion, blue);
    rectangle(debugImage, rightLeftCornerRegion, blue);
    rectangle(debugImage, rightRightCornerRegion, blue);
    // change eye centers to face coordinates
    rightPupil.x += rightEyeRegion.x + face.x;
    rightPupil.y += rightEyeRegion.y + face.y;
    leftPupil.x += leftEyeRegion.x + face.x;
    leftPupil.y += leftEyeRegion.y + face.y;
    // draw eye centers
    circle(debugImage, rightPupil, 3, red);
    circle(debugImage, rightPupil, 4, red);
    circle(debugImage, leftPupil, 3, red);
    circle(debugImage, leftPupil, 4, red);
}


Mat ImageProcessor::process(Mat frame)
{
    flip(frame, frame, 1);
    frame.copyTo(debugImage);

    std::vector<Rect> faces;
    std::vector<Mat> bgrChannels(3);
    split(frame, bgrChannels);
    //using red part to get single-channel matrix
    Mat frame_gray = bgrChannels[2];
    //-- Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE | CV_HAAR_FIND_BIGGEST_OBJECT, Size(150, 150));

    for (unsigned int i = 0; i < faces.size(); i++)
    {
        rectangle(debugImage, faces[i], blue);
    }
    //-- Show what you got
    if (faces.size() > 0) {
        findEyes(frame_gray, faces[0]);
    }
    return debugImage;
}
