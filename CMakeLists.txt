cmake_minimum_required(VERSION 2.8.12)

if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(netzwerk)

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  if(NOT CYGWIN)
    set(CMAKE_CXX_EXTENSIONS OFF)
  endif()
endif()

set(NETZWERK_VERSION 0.1)

# Set source directory
set(SOURCE_DIR "src/netzwerk")

# Tell CMake that headers are also in SOURCE_DIR
include_directories(${SOURCE_DIR})

# List source files
set(SOURCES "${SOURCE_DIR}/ops.cc")

# PyBind11
add_subdirectory(lib/pybind11)

pybind11_add_module(netzwerk ${SOURCES} "${SOURCE_DIR}/bindings.cc")

# Testing
enable_testing()

set(TEST_NAME "${PROJECT_NAME}_test")

set(TEST_DIR "tests")

#set(TEST_SOURCES
#    "${TEST_DIR}/test_main.cpp"
#    "${TEST_DIR}/test_math.cpp")

# Generate a test executable
#include_directories(lib/catch2)
#add_executable(${TEST_NAME} ${TEST_SOURCES} ${SOURCES})

set(TEST_SOURCES
    "${TEST_DIR}/tests_main.cc"
    "${TEST_DIR}/ops_test.cc")

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(lib/googletest EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
#else()
#  include_directories(${gtest_SOURCE_DIR})
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${TEST_NAME} ${TEST_SOURCES} ${SOURCES})
target_link_libraries(${TEST_NAME} gtest gtest_main)
add_test(NAME test1 COMMAND ${TEST_NAME})

