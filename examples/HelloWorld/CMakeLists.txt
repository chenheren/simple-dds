cmake_minimum_required(VERSION 3.8)
project(HelloWorld)

add_executable(publisher HelloPublisher.cpp)
target_link_libraries(publisher simple_dds)

add_executable(subscriber HelloSubscriber.cpp)
target_link_libraries(subscriber simple_dds)