cmake_minimum_required(VERSION 3.28)

add_library(inverted_index_lib ${SOURCE_DIR}/inverted_index.cpp)

add_executable(test_search_engine test_inverted_index.cpp)

target_link_libraries(test_search_engine PRIVATE gtest_main inverted_index_lib)

target_include_directories(inverted_index_lib PRIVATE ${INCLUDE_DIR})
target_include_directories(test_search_engine PRIVATE ${INCLUDE_DIR})

include(GoogleTest)
gtest_discover_tests(test_search_engine)