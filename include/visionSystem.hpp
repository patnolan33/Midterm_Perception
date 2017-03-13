
#include <iostream>
#include <string>
#include <memory>

#include <camera.hpp>
#include <laserRangeFinder.hpp>


class VisionSystem {
public:

	VisionSystem(double maxDetectionDistance);

	std::string determineControlAction();

	std::string getSuggestedAction();


private:
	Camera camera;

	std::shared_ptr<LaserRangeFinder> leftLaser;

	std::shared_ptr<LaserRangeFinder> rightLaser;

	std::string suggestedAction;
};
