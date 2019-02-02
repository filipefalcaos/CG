cmake_minimum_required(VERSION 3.10)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_1 src/bresenham.cpp src/bresenham.h src/main.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(project_1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
