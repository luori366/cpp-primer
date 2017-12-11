cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME cpp-primer)
project(${PROJECT_NAME})

#######################
##  Google test      ##
#######################
find_package(Threads REQUIRED)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-Wall -Wno-deprecated -pthread -DENABLE_NLS=0)

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/external)
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(include ${GTEST_INCLUDE_DIRS})

enable_testing()

set(PROJECT_TEST_NAME ${PROJECT_NAME}-test)

file(GLOB TEST_SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*/*.cpp
    ${PROJECT_SOURCE_DIR}/test/*.cpp
    )
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)

if(NOT WIN32 OR MINGW)
    target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )
else()
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
endif()

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

#######################
##    test cases 　　###
#######################
# add_test(test_function_template_overload ${PROJECT_TEST_NAME})