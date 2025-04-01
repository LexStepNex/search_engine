cmake_minimum_required(VERSION 3.28)

add_executable(search_engine search_engine.cpp
        ConverterJSON.cpp
        ${MY_INCLUDE_DIR}/ConverterJSON.h
        ${MY_INCLUDE_DIR}/initial_tests.h
        ${MY_INCLUDE_DIR}/file_exception.h
        ${MY_INCLUDE_DIR}/general_functions.h
        ${MY_INCLUDE_DIR}/functions_for_work_with_files.h
        general_functions.cpp
        general_functions.cpp)