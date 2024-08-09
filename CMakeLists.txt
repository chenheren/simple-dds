cmake_minimum_required(VERSION 3.8)
project(simple_dds)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
add_library(simple_dds SHARED ${SRCS} )
target_include_directories(simple_dds INTERFACE $<INSTALL_INTERFACE:include>)
target_link_libraries(simple_dds PUBLIC pthread)

OPTION(BUILD_EXAMPLES "enable examples" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

OPTION(BUILD_UNITTEST "enable unit tests" ON)
if(BUILD_UNITTEST)
    add_subdirectory(unit_test)
endif()

OPTION(BUILD_TOOLS "enable build tools" ON)
if(BUILD_TOOLS)
    add_subdirectory(tools)
endif()

