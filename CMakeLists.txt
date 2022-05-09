cmake_minimum_required(VERSION 3.1)
project(main VERSION 0.1.0 LANGUAGES CXX)

add_executable(main second.cpp)



target_compile_features(main PRIVATE cxx_std_17)
set (CMAKE_CXX_FLAGS "-pg")
