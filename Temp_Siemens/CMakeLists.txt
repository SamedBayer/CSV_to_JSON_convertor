cmake_minimum_required(VERSION 3.1)
project(JsonPATH VERSION 0.1.0 LANGUAGES CXX)
 

add_executable(JsonPATH JsonPATH.cpp)




target_include_directories(JsonPATH PUBLIC include)


target_compile_features(JsonPATH PRIVATE cxx_std_17)

set (CMAKE_CXX_FLAGS "-pg")