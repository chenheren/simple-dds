cmake_minimum_required(VERSION 3.8)
project(HelloWorld)

add_executable(talker HelloPublisher.cpp)
target_link_libraries(talker simple_dds)

add_executable(listener HelloSubscriber.cpp)
target_link_libraries(listener simple_dds)