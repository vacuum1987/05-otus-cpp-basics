cmake_minimum_required(VERSION 3.5)

project(05.homework)

add_executable(statistics
    IStatistics.hpp
    Max.hpp
    Min.hpp
    Mean.hpp
    Pct.hpp
    Std.hpp
    statistics.cpp
    Max.cpp
    Min.cpp
    Mean.cpp
    Pct.cpp
    Std.cpp)
set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

