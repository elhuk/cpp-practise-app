# Get the problem name from the current directory
get_filename_component(problem ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required (VERSION 3.14)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

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

#add_subdirectory(external/gtest)

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

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)