cmake_minimum_required(VERSION 2.8.4)
project(telegram)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(Boost_USE_MULTITHREADED ON)
set(SOURCE_FILES main.cpp Users.cpp Users.h)
add_executable(telegram ${SOURCE_FILES})
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system iostreams unit_test_framework REQUIRED)
include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
target_link_libraries(telegram /usr/local/lib/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})



