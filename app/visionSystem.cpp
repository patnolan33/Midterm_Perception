/**
 * @file visionSystem.cpp
 * @brief VisionSystem Class implementation
 * @details Implementation of the VisionSystem class to determine suggested actions based on images and depth measurements
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <visionSystem.hpp>

#include <string>
#include <memory>

/**
 * @brief VisionSystem constructor
 * @param maxDetectionDistance Maximum detection distance of the onboard lasers
 * @param vehicleCrossSection Vehicle forward cross section to determine if it can fit into any empty spaces found
 */
VisionSystem::VisionSystem(double maxDetectionDistance,
        double vehicleCrossSection) :
        camera(std::make_shared<Camera>()), leftLaser(
                std::make_shared < LaserRangeFinder
                        > (maxDetectionDistance + 0.1)), rightLaser(
                std::make_shared < LaserRangeFinder
                        > (maxDetectionDistance + 0.2)), vehicleCrossSection(
                vehicleCrossSection) {
}

/**
 * @brief Determine the control action based on images and depth measurements
 * @return string denoting the suggested action (i.e. turn right/left 45 degrees, continue straight, no action)
 */
std::string VisionSystem::determineControlAction() {
    // Take image with camera:
    if (camera->takeImage()) {
        // Grab a reading from both left and right lasers:
        leftLaser->takeDistanceReading();
        double leftReading = leftLaser->getDistance();
        rightLaser->takeDistanceReading();
        double rightReading = rightLaser->getDistance();

        // Check if we can fit within the space if both lasers read "infinite"
        // Decide which way to turn if one/both readings are finite
        if (leftReading > leftLaser->getMaxDetectionDistance()
                && rightReading > rightLaser->getMaxDetectionDistance()) {
            // Check if we can fit:
            if (vehicleCrossSection < camera->getObjectArea()) {
                // We can fit, lets drive straight:
                suggestedAction = "continue straight";
            } else {
                // We can't fit, just pick a direction to turn:
                suggestedAction = "turn right 45 degrees";
            }
        } else {
            // Check which way to turn
            if (leftReading == rightReading) {
                // We are looking straight at an obstacle
                // Just pick a direction to turn:
                suggestedAction = "turn right 45 degrees";
            } else if (leftReading < rightReading) {
                // We are close to an object on our left side, turn right:
                suggestedAction = "turn right 45 degrees";
            } else {
                // We are close to an object on our right side, turn left:
                suggestedAction = "turn left 45 degrees";
            }
        }
    } else {
        suggestedAction = "no action";
    }

    return suggestedAction;
}

/**
 * @brief Get the current suggested action
 * @return string denoting the suggested action (i.e. turn right/left 45 degrees, continue straight, no action)
 */
std::string VisionSystem::getSuggestedAction() {
    return suggestedAction;
}

/**
 * @brief Get the vehicle cross section
 * @return vehicle forward cross section
 */
double VisionSystem::getVehicleCrossSection() {
    return vehicleCrossSection;
}
