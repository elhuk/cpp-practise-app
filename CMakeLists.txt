# Get the problem name from the current directory
get_filename_component(problem ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required (VERSION 3.5)

# Name the project after the problem
project(${problem} VERSION 1.0
                   DESCRIPTION "Project for learning c++"
                   LANGUAGES CXX)

# Add all cpp and h files
file(GLOB SRC_FILES
    "*.h"
    "*.cpp"
)

# Enable C++11 features on gcc/clang
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

add_executable(${problem} ${SRC_FILES})

add_subdirectory(external/gtest)

#target_include_directories(${PROJECT_NAME} 
#    PUBLIC external/gtest/googletest/include
#)

#target_link_directories(${PROJECT_NAME}
#    PRIVATE external/gtest/googletest/src
#)
#
#target_link_libraries(${PROJECT_NAME}
#    gtest
#)