cmake_minimum_required(VERSION 3.8)

add_executable(graphic Graphic.cpp)
target_link_libraries(graphic simple_dds)

add_executable(node Node.cpp)
target_link_libraries(node simple_dds)

add_executable(topic Topic.cpp)
target_link_libraries(graphic simple_dds)
