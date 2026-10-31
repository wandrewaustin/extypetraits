cmake_minimum_required(VERSION 3.8)

project(extypetraits VERSION 1 LANGUAGES CXX)
add_library(extypetraits INTERFACE)

target_include_directories(extypetraits INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(extypetraits INTERFACE cxx_std_11)
