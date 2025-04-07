cmake_minimum_required(VERSION 3.28)

add_executable(search_engine search_engine.cpp
        converter_json.cpp
        ${INCLUDE_DIR}/converter_json.h
        ${INCLUDE_DIR}/initial_tests.h
        ${INCLUDE_DIR}/file_exception.h
        ${INCLUDE_DIR}/general_functions.h
        ${INCLUDE_DIR}/functions_for_work_with_files.h
        general_functions.cpp
        ${INCLUDE_DIR}/functions_for_converter_json.h
        functions_for_converter_json.cpp
        ${INCLUDE_DIR}/inverted_index.h
        inverted_index.cpp)