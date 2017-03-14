/**
* @file main.cpp
* @brief Unit tests
* @details This file is used to run all unit tests for the Perception module
* @author Patrick Nolan (patnolan33)
* @copyright MIT License.
*/

#include <gtest/gtest.h>

int main( int argc , char** argv )
{
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
