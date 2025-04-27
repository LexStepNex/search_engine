cmake_minimum_required(VERSION 3.28)
project("search_engine" VERSION 0.01)

set(CMAKE_CXX_STANDARD 20)

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})
file(COPY config.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY requests.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY answers.json DESTINATION ${CMAKE_BINARY_DIR})

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_subdirectory(tests)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(search_engine PUBLIC include)