set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    cameraTest.cpp
    objectDetectionTest.cpp
    laserRangeFinderTest.cpp
    visionSystemTest.cpp
    ../app/camera.cpp
    ../app/objectDetection.cpp
    ../app/laserRangeFinder.cpp
    ../app/visionSystem.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include)
find_package( OpenCV REQUIRED COMPONENTS core imgproc highgui )
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})