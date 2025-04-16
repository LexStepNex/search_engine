cmake_minimum_required(VERSION 3.28)

file(COPY ${CMAKE_SOURCE_DIR}/config.json DESTINATION ${CMAKE_BINARY_DIR}/tests)

add_library(search_server_lib ${SOURCE_DIR}/search_server.cpp
        ${SOURCE_DIR}/converter_json.cpp
        ${SOURCE_DIR}/general_functions.cpp
        ${SOURCE_DIR}/functions_for_converter_json.cpp
        ${SOURCE_DIR}/functions_for_work_with_files.cpp
        ${SOURCE_DIR}/inverted_index.cpp
        ${SOURCE_DIR}/functions_for_search_server.cpp)

add_executable(test_search_server test_search_server.cpp)

target_link_libraries(test_search_server PRIVATE gtest_main search_server_lib nlohmann_json::nlohmann_json)
target_link_libraries(search_server_lib PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(search_server_lib PRIVATE ${INCLUDE_DIR})
target_include_directories(test_search_server PRIVATE ${INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(test_search_server)