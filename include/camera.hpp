/**
* @file camera.hpp
* @brief Camera Class implementation
* @details Definition of the Camera class to take an image and detect any objects within the image.
* @author Patrick Nolan (patnolan33)
* @copyright MIT License.
*/

#include <objectDetection.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <memory>

/**
 * @brief Camera class handles taking an image and performing image processing to determine any object boundary and area
 */
class Camera {
 public:
	/**
	 * @brief Camera constructor
	 */
    Camera();

	/**
	 * @brief Take an image and perform object detection processing
	 * @return success or failure (true or false)
	 */
    bool takeImage();

	/**
	 * @brief Get the current detected boundary
	 * @return vector of pixel locations denoting the object boundary
	 */
    std::vector<cv::Point> getBoundary();

	/**
	 * @brief Get the current detected object area
	 * @return object area
	 */
    double getObjectArea();

 private:
	/**
	 * @brief Container for any connected webcam
	 */
    cv::VideoCapture videoCapture;

	/**
	 * @brief Container for the image filename that will be processed
	 */
    std::string currentImage;

	/**
	 * @brief Instantiation of the ObjectDetection algorithm
	 */
    std::shared_ptr<ObjectDetection> boundaryDetection;
};
