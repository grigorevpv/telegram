cmake_minimum_required(VERSION 2.8.4)
project(telegram)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(Boost_USE_MULTITHREADED ON)
set(SOURCE_FILES main.cpp)

include_directories (${PROJECT_SOURCE_DIR}/lib/)
set(HEADER lib/Users.h lib/config.h lib/Cards.h lib/bcm2835.h lib/reader.h lib/config.h lib/rc522.h lib/rfid.h)
set(SOURCE_LIB lib/Users.cpp lib/Cards.cpp lib/config.c lib/reader.c lib/config.c lib/rc522.c lib/rfid.c)
add_executable(telegram ${SOURCE_FILES})
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system iostreams unit_test_framework REQUIRED)
include_directories( ./lib /usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
target_link_libraries(telegram ${SOURCE_LIB} /usr/local/lib/libTgBot.a /usr/local/lib/libbcm2835.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CMAKE_DL_LIBS} ${HEADER})




















#set(SOURCE_FILES main.cpp lib/Users.cpp lib/Users.h lib/Cards.cpp lib/config.h lib/Cards.h lib/bcm2835.h lib/reader.h lib/reader.c lib/config.h lib/rc522.h lib/rfid.h lib/data.txt lib/RC522.conf)

#file(GLOB SOURCES "./*.cpp ./*.c")
#set(HEADER ./lib/Users.h ./lib/config.h ./lib/Cards.h ./lib/bcm2835.h ./lib/reader.h ./lib/config.h ./lib/rc522.h ./lib/rfid.h)
#set(SOURCE_LIB ./lib/Users.cpp ./lib/Cards.cpp ./lib/config.c ./lib/reader.c ./lib/config.c ./lib/rc522.c ./lib/rfid.c)
#set(HEADER lib/Users.h lib/config.h lib/Cards.h lib/bcm2835.h lib/reader.h lib/config.h lib/rc522.h lib/rfid.h)
#set(SOURCE_LIB lib/Users.cpp lib/Cards.cpp lib/config.c lib/reader.c lib/config.c lib/rc522.c lib/rfid.c)
#configure_file (
#        "${PROJECT_SOURCE_DIR}/lib/Users.h.in"
#        "${PROJECT_BINARY_DIR}/lib/Users.h"
#        "${PROJECT_SOURCE_DIR}/lib/config.h.in"
#        "${PROJECT_BINARY_DIR}/lib/config.h"
#        "${PROJECT_SOURCE_DIR}/lib/Cards.h.in"
#        "${PROJECT_BINARY_DIR}/lib/Cards.h"
#        "${PROJECT_SOURCE_DIR}/lib/bcm2835.h.in"
#        "${PROJECT_BINARY_DIR}/lib/bcm2835.h"
#        "${PROJECT_SOURCE_DIR}/lib/reader.h.in"
#        "${PROJECT_BINARY_DIR}/lib/reader.h"
#        "${PROJECT_SOURCE_DIR}/lib/config.h.in"
#        "${PROJECT_BINARY_DIR}/lib/config.h"
#        "${PROJECT_SOURCE_DIR}/lib/rc522.h.in"
#        "${PROJECT_BINARY_DIR}/lib/rc522.h"
#        "${PROJECT_SOURCE_DIR}/lib/rfid.h.in"
#        "${PROJECT_BINARY_DIR}/lib/rfid.h"
#)
#include_directories("${PROJECT_BINARY_DIR}")