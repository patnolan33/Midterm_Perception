#include <visionSystem.hpp>

VisionSystem::VisionSystem(double maxDetectionDistance, double vehicleCrossSection)
: vehicleCrossSection(vehicleCrossSection) {
	camera = std::make_shared<Camera>();
	leftLaser = std::make_shared<LaserRangeFinder>(maxDetectionDistance + 0.1);
	rightLaser = std::make_shared<LaserRangeFinder>(maxDetectionDistance + 0.2);
}

std::string VisionSystem::determineControlAction() {
	// Take image with camera:
	if(camera->takeImage()) {
		// Grab the boundary pixels:
		std::vector<cv::Point> boundary = camera->getBoundary();

		// Grab a reading from both left and right lasers:
		leftLaser->takeDistanceReading();
		double leftReading = leftLaser->getDistance();
		rightLaser->takeDistanceReading();
		double rightReading = rightLaser->getDistance();

		// Check if we can fit within the space if both lasers read "infinite"
		// Decide which way to turn if one/both readings are finite
		if(leftReading > leftLaser->getMaxDetectionDistance() && rightReading > rightLaser->getMaxDetectionDistance()) {
			// Check if we can fit:
			if(vehicleCrossSection < camera->getObjectArea()) {
				// We can fit, lets drive straight:
				suggestedAction = "continue straight";
				std::cout << "Test 1" << std::endl;
				std::cout << "Cross Section: " << vehicleCrossSection << " / Object Area: " << camera->getObjectArea() << std::endl;
			}
			else {
				// We can't fit, just pick a direction to turn:
				suggestedAction = "turn right 45 degrees";
				std::cout << "Test 2" << std::endl;
			}
		}
		else {
			// Check which way to turn
			if(leftReading == rightReading) {
				// We are looking straight at an obstacle, just pick a direction to turn:
				suggestedAction = "turn right 45 degrees";
				std::cout << "Test 3" << std::endl;
			}
			else if (leftReading < rightReading) {
				// We are close to an object on our left side, turn right:
				suggestedAction = "turn right 45 degrees";
				std::cout << "Test 4" << std::endl;
			}
			else {
				// We are close to an object on our right side, turn left:
				suggestedAction = "turn left 45 degrees";
				std::cout << "Test 5" << std::endl;
			}
		}
	}
	else {
		suggestedAction = "no action";
		std::cout << "Test 6" << std::endl;
	}

	return suggestedAction;
}

std::string VisionSystem::getSuggestedAction() {
	return suggestedAction;
}

double VisionSystem::getVehicleCrossSection() {
	return vehicleCrossSection;
}
