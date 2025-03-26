cmake_minimum_required(VERSION 3.28)

add_executable(search_engine main.cpp
        ConverterJSON.cpp
        ${MY_INCLUDE_DIR}/ConverterJSON.h)