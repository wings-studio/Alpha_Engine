cmake_minimum_required(VERSION 3.10)

project(AlphaSample)

set(SOURCES "src/Main.cpp")

add_executable(AlphaSample ${SOURCES})

target_include_directories(AlphaSample 
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(AlphaSample PUBLIC "lib/AlphaEngine")