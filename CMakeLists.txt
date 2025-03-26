cmake_minimum_required(VERSION 3.28)
project(search_engine)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(nlohmann_json)

add_subdirectory(Source)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(search_engine PUBLIC include)