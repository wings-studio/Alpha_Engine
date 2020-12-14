cmake_minimum_required(VERSION 3.10)

project(AlphaEngine)

set(SOURCES "src/Game.cpp" "src/BaseEntity.cpp" "src/BaseModelEntity.cpp" "src/BaseLogicEntity.cpp" 
	"src/BaseFigureEntity.cpp" "src/Figure.cpp" "src/AlphaObject.cpp")

add_library(AlphaEngine ${SOURCES})

link_directories(AlphaEngine "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_include_directories(AlphaEngine 
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Help CMake to find the installed library on Windows or Mac OS X 
if(WIN32) 
  list(APPEND CMAKE_PREFIX_PATH "C:\\Program Files (x86)\\ReactPhysics3D") 
elseif(APPLE) 
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/ReactPhysics3D") 
endif() 
 
# Import the ReactPhysics3D library 
find_package(ReactPhysics3D REQUIRED) 

target_link_libraries(AlphaEngine ReactPhysics3D::ReactPhysics3D)
