
#include <iostream>
#include <string>
#include <memory>

#include <camera.hpp>
#include <laserRangeFinder.hpp>


class VisionSystem {
public:

	VisionSystem(double maxDetectionDistance, double vehicleCrossSection);

	std::string determineControlAction();

	std::string getSuggestedAction();

	double getVehicleCrossSection();


private:
	std::shared_ptr<Camera> camera;

	std::shared_ptr<LaserRangeFinder> leftLaser;

	std::shared_ptr<LaserRangeFinder> rightLaser;

	std::string suggestedAction;

	double vehicleCrossSection;
};
