cmake_minimum_required(VERSION 3.0)
project( Calibration )
find_package( OpenCV REQUIRED )
include_directories( 
    ${OpenCV_INCLUDE_DIRS}
     )
add_executable(Calibration 
               calib.cpp )
target_link_libraries( Calibration ${OpenCV_LIBS} )
