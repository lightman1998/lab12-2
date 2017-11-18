cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/poljkee2010/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "c85118ae943500d5fce2afb24cee4253eb3296ae"
)

project(main)
hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)
hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(main PRIVATE CURL::libcurl OpenSSL::SSL OpenSSL::Crypto)

install(TARGETS main RUNTIME DESTINATION bin)
