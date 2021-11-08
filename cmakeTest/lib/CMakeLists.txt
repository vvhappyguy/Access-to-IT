# ----------------------
# PROJECT INFORMATION
# ----------------------

cmake_minimum_required(VERSION 3.12)

project(
  test
  VERSION 0.2.0
  LANGUAGES CXX)

include(GNUInstallDirs)

# ---------------
# DEPENDENCIES
# ---------------

find_package(sdbus-c++ REQUIRED)

# -----------------------------
# SOURCE FILES CONFIGURATION
# -----------------------------
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(PRIVATE_HDR_SRCS
    ${INCLUDE_DIR}/round.hpp
)

set(PRIVATE_SRC_SRCS
    ${SOURCE_DIR}/round.cpp
)

set(CPP_SRCS
    ${SOURCE_DIR}/utility.cpp
)

set(HDR_SRCS
    ${INCLUDE_DIR}/utility.hpp
)

set(PUBLIC_HDR_SRCS
    ${INCLUDE_DIR}/check.hpp
)

set(PUBLIC_SRC_SRCS
    ${SOURCE_DIR}/check.cpp
)

# Sources for building temporary library
set(TESTCPP_LIB_SRCS  ${PRIVATE_HDR_SRCS} ${PRIVATE_SRC_SRCS})

# Sources for building public library
set(TEST_SRCS ${PUBLIC_HDR_SRCS} ${PUBLIC_SRC_SRCS}  ${CPP_SRCS} ${HDR_SRCS})

# Headers for installing
set(TEST_INSTALL_HDRS ${PUBLIC_HDR_SRCS} ${HDR_SRCS})

# -------------------------
# COMPILER CONFIGURATION
# -------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -Wall -Wpedantic")

# -------------------------------------
# TEMPORARY LIBRARY BUILD INFORMATION
# -------------------------------------

add_library(test-library ${TESTCPP_LIB_SRCS})
target_include_directories(
  test-library PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
              $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
target_link_libraries(test-library PUBLIC SDBusCpp::sdbus-c++)

# ----------------------------------
# PUBLIC LIBRARY BUILD INFORMATION
# ----------------------------------

add_library(test SHARED ${TEST_SRCS})
target_include_directories(
  test PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
              $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

target_link_libraries(test PRIVATE test-library)

# ---------------
# INSTALLATION
# ---------------

install(TARGETS test LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${TEST_INSTALL_HDRS}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/test)
