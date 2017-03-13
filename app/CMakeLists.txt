add_executable(
	perception 
	main.cpp 
	objectDetection.cpp 
	camera.cpp 
	laserRangeFinder.cpp 
	visionSystem.cpp
	)
	
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

find_package( OpenCV REQUIRED COMPONENTS core imgproc highgui )
target_link_libraries( perception ${OpenCV_LIBS} )
