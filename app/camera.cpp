/**
 * @file camera.cpp
 * @brief Camera Class implementation
 * @details Implementation of the Camera class to take an image and detect any objects within the image.
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <camera.hpp>

#include <iostream>
#include <vector>
#include <memory>

/**
 * @brief Camera constructor
 */
Camera::Camera() :
        boundaryDetection(std::make_shared<ObjectDetection>()) {
}

/**
 * @brief Take an image and perform object detection processing
 * @return success or failure (true or false)
 */
bool Camera::takeImage() {
    // Capture image from webcam:
    videoCapture = cv::VideoCapture(0);

    // Get the image frame:
    cv::Mat img;
    videoCapture >> img;

    if (img.empty()) {
        std::cout
                << "Something went wrong. Using blackBorder.jpg..."
                << std::endl;
        currentImage = "../blackBorder.jpg";

        boundaryDetection->detectObjectBoundary(currentImage, false);
    } else {
        cv::imwrite("webcamImage.jpg", img);
        currentImage = "webcamImage.jpg";

        boundaryDetection->detectObjectBoundary(currentImage, false);
    }

    // Only return true if our boundary has been found
    if (getBoundary().size() > 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Get the current detected boundary
 * @return vector of pixel locations denoting the object boundary
 */
std::vector<cv::Point> Camera::getBoundary() {
    return boundaryDetection->getBoundaryPixels();
}

/**
 * @brief Get the current detected object area
 * @return object area
 */
double Camera::getObjectArea() {
    return boundaryDetection->getObjectArea();
}
