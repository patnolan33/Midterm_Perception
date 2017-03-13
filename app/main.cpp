#include <iostream>
#include <objectDetection.hpp>
#include <memory>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	std::shared_ptr<ObjectDetection> detector = std::make_shared<ObjectDetection>();

	detector->detectObjectBoundary("../blackBorder.jpg", true);

    return 0;
}
