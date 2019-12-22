cmake_minimum_required(VERSION 3.15)
project(task)

set(CMAKE_CXX_STANDARD 17)

find_library(PTHREAD_LIBRARY pthread)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY -DBOOST_SYSTEM_NO_DEPRECATED)

add_executable(task main.cpp Request.h Stopper.cpp Stopper.h Worker.cpp Worker.h Request.cpp)

target_link_libraries(task ${PTHREAD_LIBRARY})
