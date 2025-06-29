cmake_minimum_required(VERSION 3.10)
project(FaceDetection)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(camera_test camera_test.cpp)
target_link_libraries(camera_test ${OpenCV_LIBS})

add_executable(face_detection face_detection.cpp)
target_link_libraries(face_detection ${OpenCV_LIBS})

file(COPY "/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml" 
     DESTINATION ${CMAKE_BINARY_DIR})
