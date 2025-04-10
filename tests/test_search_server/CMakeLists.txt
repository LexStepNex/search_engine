cmake_minimum_required(VERSION 3.28)

add_library(search_server_lib ${SOURCE_DIR}/search_server.cpp
        ${SOURCE_DIR}/inverted_index.cpp
        ${SOURCE_DIR}/functions_for_search_server.cpp)

add_executable(test_search_server test_search_server.cpp)

target_link_libraries(test_search_server PRIVATE gtest_main search_server_lib)

target_include_directories(search_server_lib PRIVATE ${INCLUDE_DIR})
target_include_directories(test_search_server PRIVATE ${INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(test_search_server)
