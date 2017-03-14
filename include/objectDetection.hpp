/**
 * @file objectDetection.hpp
 * @brief ObjectDetection Class implementation
 * @details Definition of the ObjectDetection class to determine the boundary of any imaged object
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <cv.h>

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief ObjectDetection class handles determining object boundary and area
 */
class ObjectDetection {
 public:
    /**
     * @brief ObjectDetection constructor
     */
    ObjectDetection();

    /**
     * @brief Get the vector of pixel locations of the detected boundary
     * @return vector of pixel locations
     */
    std::vector<cv::Point> getBoundaryPixels();

    /**
     * @brief Get the area of the detected object
     * @return object area
     */
    double getObjectArea();

    /**
     * @brief Detect the object boundary assuming a fixation point at the center of the image given by filename
     * @param filename Image filename to read in and process
     * @param displayImage True if you wish to display the processed image
     * @return success or failure (true or false)
     */
    bool detectObjectBoundary(const std::string &filename, bool displayImage);

 private:
    /**
     * @brief Draw/Plot the image and process boundary
     * @param boundary Vector of pixel locations denoting the boundary
     * @param srcImg Image to display
     */
    void drawBoundary(std::vector<cv::Point> boundary, cv::Mat srcImg);

    /**
     * @brief Container for the vector of X/Y pairs denoting the object boundary
     */
    std::vector<cv::Point> boundaryPixels;

    /**
     * @brief Container for the detected object area
     */
    double objectArea;

    /**
     * @brief Fixation point (this implementation assumes the center of the image)
     */
    cv::Point fixationPoint;
};
