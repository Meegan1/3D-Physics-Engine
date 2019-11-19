cmake_minimum_required(VERSION 3.15)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)



add_executable(Assignment_2 main.cpp RenderWindow.cpp RenderWindow.h)

target_link_libraries(Assignment_2 Qt5::Widgets)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(Assignment_2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )