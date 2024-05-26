cmake_minimum_required(VERSION 3.0)
project(http-server-client)

#set(TARGET_NAME "http-server")
set(TARGET_NAME "http-server-client")
set(TARGET_NAME2 "http-server")
set(TARGET_NAME3 "http-client")
set(TARGET_NAME4 "http-client-test")

find_package(GTest REQUIRED)

set(LIBHV_INCLUDE ${PROJECT_BINARY_DIR}/contrib/libhv/include/hv)

add_subdirectory(${PROJECT_SOURCE_DIR}/contrib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wempty-body -Wredundant-move -O2")

# file(GLOB_RECURSE SOURCES
#   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h )

file(GLOB_RECURSE SOURCES_CLIENT
${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/*.hpp
${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPClient/Routers.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPClient/clientmain.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPClient/HTTPServer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPClient/HTTPServer.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPClient/Routers.hpp
  )

  file(GLOB_RECURSE SOURCES_SERVER
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPServer/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPServer/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPServer/*.h )

set(SOURCE_DIR_HEADER "")
execute_process(
    COMMAND find src -type d
    OUTPUT_VARIABLE SOURCE_DIR_HEADER
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    string(REPLACE "\n" ";" SOURCE_DIR_HEADER ${SOURCE_DIR_HEADER})
    
include_directories(${SOURCE_DIR_HEADER})
include_directories(${LIBHV_INCLUDE})
    
# add_executable(${TARGET_NAME} ${SOURCES})
# target_link_libraries(${TARGET_NAME} hv_static)

add_executable(${TARGET_NAME2} ${SOURCES_SERVER})
target_link_libraries(${TARGET_NAME2} hv_static)


add_executable(${TARGET_NAME3} ${SOURCES_CLIENT})
target_link_libraries(${TARGET_NAME3} hv_static GTest::GTest)

add_executable(${TARGET_NAME4} ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPClient/clientmain_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/Utility.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/Utility/Utility.hpp
)
target_link_libraries(${TARGET_NAME4} hv_static GTest::GTest)

add_test(NAME ${TARGET_NAME4} COMMAND ${TARGET_NAME4})

enable_testing()