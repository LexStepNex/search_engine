cmake_minimum_required(VERSION 3.28)

add_executable(search_engine search_engine.cpp
        converter_json.cpp
        ${MY_INCLUDE_DIR}/converter_json.h
        ${MY_INCLUDE_DIR}/initial_tests.h
        ${MY_INCLUDE_DIR}/file_exception.h
        ${MY_INCLUDE_DIR}/general_functions.h
        ${MY_INCLUDE_DIR}/functions_for_work_with_files.h
        general_functions.cpp
        ${MY_INCLUDE_DIR}/functions_for_converter_json.h
        functions_for_converter_json.cpp)