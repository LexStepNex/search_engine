cmake_minimum_required(VERSION 3.28)

add_executable(search_engine search_engine.cpp
        ConverterJSON.cpp
        ${MY_INCLUDE_DIR}/ConverterJSON.h
        ${MY_INCLUDE_DIR}/initial_tests.h
        ${MY_INCLUDE_DIR}/file_exception.h
        ${MY_INCLUDE_DIR}/functions.h)