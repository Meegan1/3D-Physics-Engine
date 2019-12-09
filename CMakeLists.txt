cmake_minimum_required(VERSION 3.15)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLM REQUIRED)

SET(Engine_HDRS ${QtTest_HDRS} Rendering/Engine.h Rendering/ObjectDialog.h)

QT5_WRAP_CPP(Engine_HDRS_MOC ${Engine_HDRS})

add_executable(Assignment_2 main.cpp Rendering/Engine.cpp ${Engine_HDRS_MOC} Objects/Ball.cpp Objects/Ball.h Rendering/Camera.cpp Rendering/Camera.h Physics/PhysicsEngine.cpp Physics/PhysicsEngine.h Objects/RigidBody.h Objects/Plane.cpp Objects/Plane.h Objects/Object.h Rendering/ObjectDialog.cpp)

target_link_libraries(Assignment_2 Qt5::Widgets)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} )
target_link_libraries(Assignment_2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )