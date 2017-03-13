
#include <iostream>
#include <vector>
#include <tuple>

#include <cv.h>


class ObjectDetection {
public:

	ObjectDetection();

	std::vector<std::tuple<double, double> > getBoundaryPixels();

	bool detectObjectBoundary(cv::Mat image);


private:
	std::vector<std::tuple<double, double> > boundaryPixels;

};
