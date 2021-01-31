project(engine CXX)

file(GLOB ENGINE_SOURCES "src/*.cpp")
add_library(engine STATIC ${ENGINE_SOURCES})

target_link_libraries(engine PRIVATE
    Corrade::Main
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::MeshTools
    Magnum::SceneGraph
    Magnum::Shaders
    Magnum::Trade)
add_dependencies(engine
    Magnum::AnyImageImporter
    Magnum::AnySceneImporter
    Magnum::ObjImporter
    MagnumPlugins::StbImageImporter
    MagnumPlugins::TinyGltfImporter)
target_include_directories(engine PUBLIC "include")