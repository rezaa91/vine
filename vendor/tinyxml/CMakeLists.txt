cmake_minimum_required(VERSION 3.17)

add_library(
    tinyxml STATIC
    tinystr.cpp
    tinyxml.cpp
    tinyxmlerror.cpp
    tinyxmlparser.cpp
)
