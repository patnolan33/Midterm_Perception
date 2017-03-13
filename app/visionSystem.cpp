#include <visionSystem.hpp>

VisionSystem::VisionSystem(double maxDetectionDistance) {
	leftLaser = std::make_shared < LaserRangeFinder > (maxDetectionDistance);
	rightLaser = std::make_shared < LaserRangeFinder > (maxDetectionDistance);
}

std::string VisionSystem::determineControlAction() {
	return "turn right";
}

std::string VisionSystem::getSuggestedAction() {
	return "turn right";
}
