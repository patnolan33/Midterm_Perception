/**
 * @file objectDetection.cpp
 * @brief ObjectDetection Class implementation
 * @details Implementation of the ObjectDetection class to determine the boundary of any imaged object
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <objectDetection.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief ObjectDetection constructor
 */
ObjectDetection::ObjectDetection() :
        objectArea(0) {
    fixationPoint.x = 0;
    fixationPoint.y = 0;
}

/**
 * @brief Get the vector of pixel locations of the detected boundary
 * @return vector of pixel locations
 */
std::vector<cv::Point> ObjectDetection::getBoundaryPixels() {
    return boundaryPixels;
}

/**
 * @brief Get the area of the detected object
 * @return object area
 */
double ObjectDetection::getObjectArea() {
    return objectArea;
}

/**
 * @brief Detect the object boundary assuming a fixation point at the center of the image given by filename
 * @param filename Image filename to read in and process
 * @param displayImage True if you wish to display the processed image
 * @return success or failure (true or false)
 */
bool ObjectDetection::detectObjectBoundary(const std::string &filename,
        bool displayImage) {
    // Define image processing constants:
    int threshold = 100;

    cv::Mat srcImg = cv::imread(filename);
    cv::Mat srcImgGray;
    cv::cvtColor(srcImg, srcImgGray, CV_RGB2GRAY);
    cv::blur(srcImgGray, srcImgGray, cv::Size(3, 3));

    cv::Mat cannyImg;
    std::vector < std::vector<cv::Point> > contours;
    std::vector < cv::Vec4i > hierarchy;

    // Detect edges using a Canny edge detector:
    cv::Canny(srcImgGray, cannyImg, threshold, threshold * 2, 3);
    // Find all contours:
    cv::findContours(cannyImg, contours, hierarchy, CV_RETR_TREE,
            CV_CHAIN_APPROX_SIMPLE);

    // Determine the middle of the image as the fixation point:
    fixationPoint.x = srcImg.size().width / 2;
    fixationPoint.y = srcImg.size().height / 2;

    // Determine which contour the fixation point is contained in:
    for (auto &contour : contours) {
        double isContained = cv::pointPolygonTest(contour,
                cv::Point2f(static_cast<float>(fixationPoint.x),
                        static_cast<float>(fixationPoint.y)),
                false);
        if (isContained > 0) {
            boundaryPixels = contour;
            break;
        }
    }

    if (boundaryPixels.size() > 0) {
        // Set object area:
        objectArea = cv::contourArea(boundaryPixels);

        // If desired, show the image and the contour that was found:
        if (displayImage) {
            drawBoundary(boundaryPixels, srcImg);
        }

        return true;
    } else {
        return false;
    }
}

/**
 * @brief Draw/Plot the image and process boundary
 * @param boundary Vector of pixel locations denoting the boundary
 * @param srcImg Image to display
 */
void ObjectDetection::drawBoundary(std::vector<cv::Point> boundary,
        cv::Mat srcImg) {
    cv::RNG rng(12345);
    const cv::Point *pts = (const cv::Point*) cv::Mat(boundary).data;
    int npts = cv::Mat(boundary).rows;
    cv::polylines(srcImg, &pts, &npts, 1, true, cv::Scalar(0, 255, 0), 3, CV_AA,
            0);
    circle(srcImg, fixationPoint, 1, CV_RGB(255, 0, 0), 3);
    namedWindow("Contours", cv::WINDOW_AUTOSIZE);
    imshow("Boundary", srcImg);

    // Wait for close or press 0 to close
    cv::waitKey(0);
}
