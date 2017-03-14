/**
 * @file main.cpp
 * @brief Program main
 * @details This file is used to implement the VisionSystem class and determine suggested actions until a user terminates vehicle motion.
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <visionSystem.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <memory>
#include <string>



int main() {
    std::shared_ptr<VisionSystem> visionSystem = std::make_shared < VisionSystem
            > (10, 0);

    std::string userInput = "";
    while (userInput != "n" && userInput != "N") {
        std::cout << std::endl << "Suggested action: "
                << visionSystem->determineControlAction() << std::endl;

        std::cout << "Would you like the robot to continue? (y/n)" << std::endl;
        std::cin >> userInput;
    }

    std::cout << "User terminated motion. Stopping robot." << std::endl;

    return 0;
}
