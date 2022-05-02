cmake_minimum_required(VERSION 3.16)

project(filter2D)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV 4)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV >= 4 not found")
endif()

# message(${OpenCV_LIBS})

add_library(${PROJECT_NAME} SHARED
            ${CMAKE_CURRENT_SOURCE_DIR}/filter2D/Filter2D.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/filter2D/Filter2D.h)

target_link_libraries(${PROJECT_NAME}
    opencv_core)

add_executable(blur blur.cpp)
target_link_libraries(blur PUBLIC
    ${PROJECT_NAME}
    opencv_imgcodecs
    opencv_highgui
    )
