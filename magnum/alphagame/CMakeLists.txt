set(EXE_SOURCES "src/main.cpp")
add_executable(alphagame ${EXE_SOURCES})
target_link_libraries(alphagame 
    base
    Corrade::Main
    Magnum::Application
    Magnum::GL)