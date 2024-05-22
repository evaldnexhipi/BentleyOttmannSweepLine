cmake_minimum_required(VERSION 3.10)
project(BentleyOttmannSweepLine)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(BentleyOttmannSweepLine
    src/main.cpp
    src/Event.cpp
    src/SweepLineAlgorithm.cpp
)
