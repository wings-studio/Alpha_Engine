# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Alpha Engine")

include(MethaneApplications.cmake)
include(MethaneShaders.cmake)

set(TARGET AlphaEngine)
set(SOURCES
    main.cpp
)

add_methane_application(${TARGET}
    "${SOURCES}"
    "${RESOURCES_DIR}"
    "install directory"
    "Name"
    "Description"
    "Copyright"
    "${METHANE_VERSION_SHORT}"
    "${METHANE_VERSION_BUILD}"
)
