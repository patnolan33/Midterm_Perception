/**
* @file visionSystem.gpp
* @brief VisionSystem Class implementation
* @details Definition of the VisionSystem class to determine suggested actions based on images and depth measurements
* @author Patrick Nolan (patnolan33)
* @copyright MIT License.
*/


#include <camera.hpp>
#include <laserRangeFinder.hpp>

#include <iostream>
#include <string>
#include <memory>


/**
 * @brief VisionSystem class determines suggested vehicle actions based on images and depth measurements
 */
class VisionSystem {
 public:
	/**
	 * @brief VisionSystem constructor
	 * @param maxDetectionDistance Maximum detection distance of the onboard lasers
	 * @param vehicleCrossSection Vehicle forward cross section to determine if it can fit into any empty spaces found
	 */
    VisionSystem(double maxDetectionDistance, double vehicleCrossSection);

	/**
	 * @brief Determine the control action based on images and depth measurements
	 * @return string denoting the suggested action (i.e. turn right/left 45 degrees, continue straight, no action)
	 */
    std::string determineControlAction();

	/**
	 * @brief Get the current suggested action
	 * @return string denoting the suggested action (i.e. turn right/left 45 degrees, continue straight, no action)
	 */
    std::string getSuggestedAction();

	/**
	 * @brief Get the vehicle cross section
	 * @return vehicle forward cross section
	 */
    double getVehicleCrossSection();


 private:
	/**
	 * @brief Instantiation of the onboard Camera
	 */
    std::shared_ptr<Camera> camera;

	/**
	 * @brief Instantiation of the left LaserRangeFinder
	 */
    std::shared_ptr<LaserRangeFinder> leftLaser;

	/**
	 * @brief Instantiation of the right LaserRangeFinder
	 */
    std::shared_ptr<LaserRangeFinder> rightLaser;

	/**
	 * @brief Container for the current suggested control action
	 */
    std::string suggestedAction;

	/**
	 * @brief container for the vehicle cross sectoin
	 */
    double vehicleCrossSection;
};
