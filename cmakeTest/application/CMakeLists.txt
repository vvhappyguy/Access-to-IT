# ----------------------
# PROJECT INFORMATION
# ----------------------

cmake_minimum_required(VERSION 3.10)

project(demo-app)

include(GNUInstallDirs)

# -------------------------
# COMPILER CONFIGURATION
# -------------------------

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")

# ----------------------------------
# EXECUTABLE BUILD INFORMATION
# ----------------------------------

add_executable(app app.cpp)

target_link_libraries(app PRIVATE test)
