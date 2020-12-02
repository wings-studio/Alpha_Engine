cmake_minimum_required(VERSION 3.10)

project(AlphaEngine)

set(SOURCES "src/Game.cpp" "src/BaseEntity.cpp")

add_library(AlphaEngine ${SOURCES})

link_directories(AlphaEngine "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_include_directories(AlphaEngine 
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
