cmake_minimum_required(VERSION 2.8.3)

MESSAGE("BUILDING LIBRARIES IN:")
MESSAGE(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/boilerplate/types/Sensor
)

file(GLOB Sensor
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/boilerplate/types/Sensor/Sensor.cpp
)

