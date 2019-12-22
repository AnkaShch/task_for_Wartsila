cmake_minimum_required(VERSION 3.15)
project(task)

set(CMAKE_CXX_STANDARD 17)

find_library(PTHREAD_LIBRARY pthread)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY -DBOOST_SYSTEM_NO_DEPRECATED)

add_executable(task main.cpp src/Request.h src/Stopper.cpp src/Stopper.h src/Worker.cpp src/Worker.h src/Request.cpp)

target_link_libraries(task ${PTHREAD_LIBRARY})
