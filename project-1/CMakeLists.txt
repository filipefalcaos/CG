cmake_minimum_required(VERSION 3.10)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_1 src/bresenham/bresenham_line.cpp src/bresenham/bresenham_line.h src/main.cpp src/equations/line_equation.cpp src/equations/line_equation.h src/utils/utils.cpp src/utils/utils.h src/bresenham/bresenham_circle.cpp src/bresenham/bresenham_circle.h src/equations/circle_equation.cpp src/equations/circle_equation.h src/draw/ice_hockey_rink.cpp src/draw/ice_hockey_rink.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(project_1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
