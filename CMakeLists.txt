cmake_minimum_required(VERSION 3.23)
project(Project5)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project5 main.cpp Core/boiler.cpp Core/boiler.h Game/game.cpp Game/game.h Core/vector3.cpp Core/vector3.h Core/matrix.cpp Core/matrix.h OpenGLCore/baseObjects.cpp OpenGLCore/baseObjects.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.3.8)

target_link_libraries(Project5 glfw)
if (NOT APPLE)
    target_link_libraries(Project5 -lGLU)
endif ()

find_package(OpenGL REQUIRED)

target_link_libraries(Project5 OpenGL::GL)
