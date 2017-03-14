#include <iostream>
#include <visionSystem.hpp>
#include <memory>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	std::shared_ptr<VisionSystem> visionSystem = std::make_shared<VisionSystem>(10, 0);

	std::cout << "Suggested action: " << visionSystem->determineControlAction() << std::endl;

    return 0;
}
