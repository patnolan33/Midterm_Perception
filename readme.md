# Perception Module for ACME Robotics (ENPM 808X Midterm)
[![Build Status](https://travis-ci.org/patnolan33/Midterm_Perception.svg?branch=master)](https://travis-ci.org/patnolan33/Midterm_Perception)
[![Coverage Status](https://coveralls.io/repos/github/patnolan33/Midterm_Perception/badge.svg?branch=master)](https://coveralls.io/github/patnolan33/Midterm_Perception?branch=master)
---

## Overview

The purpose of this repository is an implementation of the Perception Module for ACME robotics (ENPM 808X Midterm Project). Specifically, this software implements an object detection suite for the ACME robot's vision system. At a high level, the object detector works by taking an image, processing the image, and comparing against two single-point laser range finders to determine a suggested control action (i.e. "turn right/left 45 degrees", "continue straight", or "no action"). This implementation assumes that the action is only a suggestion, and the user has full control over every motion. This was done because there is little to no information regarding the specifics of other modules that would interface with the Perception module. However, it is assumed that this robot will not be fully autonomous at this stage and that the user has full control over a "Go/No-go" command. In this implementation, this is implemented as a simple "Continue? (yes/no)" input request after every suggested action.

The main features of this module include an image processing and decision engine. In short, the image processing, coupled with sensor measurements from two single-point laser range finders, allows for a simple state-machine type decision process. The image processing determines the boundary of either the object or open space that we are looking at. Then, we compare with the readings from each laser to determine if we are looking at open space or at an obstacle. If both laser readings are very large, we can assume that we are looking at open space. At this point, we can compare to our vehicle size (we only care about the cross section from the front) to the area occupied by the open space to determine if we can fit. If so, we can continue straight. If not, we must turn away and keep navigating. On the other hand, if one or both of our lasers produce a reading that is sufficiently small, we know that we are in danger of colliding with an obstacle. In this case, we need to determine which laser is providing the closer measurement and then turn away from that direction to avoid an obstacle. 

#### Results

Using the included test image "blackBorder.jpg" we are able to determine the boundary of the black border (in green) and determine control actions based on the size of the vehicle and noisy laser range finder readings. The fixation point for this implementation is the center of the image for simplicity (denoted by the red dot). In our tests and demo, we assume that this object is roughly 5 meters away (accounting for noise). We also assume that our vehicle is too big to fit through the space denoted by the white space in the image, and therefore must turn away. 

![boundary example](./results/boundaryExample.jpg?raw=true "Boundary Example")

## License

[MIT License](./LICENSE)

## SIP Process
The SIP Process followed is detailed in a spreadsheet at the following link:
[SIP Process](https://docs.google.com/spreadsheets/d/13Md_3JxLImuFK3fchP6q6-Ba7_WplzxLPu2Yvax6Z-Q/edit?usp=sharing)

## Installation

#### Prerequisites
This software has only been tested on Ubuntu 14.04 LTS. Other OSs are not tested and are not guaranteed to work. The only other prerequisite that this project has is OpenCV. This project has been tested with OpenCV version 2.4, but should also work with any subsequent versions. However, note that Travis CI support will not function with OpenCV versions greater than 2.4. 

If you do not have OpenCV installed, the installation instructions for Linux can be found on the OpenCV website [here](http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html#linux-installation) and downloads can be foud [here](http://opencv.org/downloads.html).

** NOTE: For the Virtual Machine provided for this class, OpenCV 2.4.8 should already be included, so this step can likely be skipped.

#### Clone project
- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/patnolan33/Midterm_Perception.git
```
## Build and Run Project

- Build project using cmake
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
- Run demo
  - The demo will output a suggested action, then ask the user to input a "yes" or "no" response (i.e. "y" or "n") to whether they wish to continue or stop the robot. Note that the robot is not actually moving in this demo, but the perception module will continue to output suggested actions until the user "stops" the robot. 
```
$ ./app/perception
```
- Run test
```
$ ./test/cpp-test
```

## Doxygen Documentation

If any changes are made to the source code, please document them and re-run the Doxygen documentation generation. To do so, simply change into the `docs/` directory and run:

```
$ cd docs/
$ doxygen Doxyfile
```

If Doxygen is not installed, install using

`sudo apt-get install doxygen`
