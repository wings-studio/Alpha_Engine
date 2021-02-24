#include <Corrade/Containers/Array.h>
#include <Corrade/Containers/Optional.h>
#include <Corrade/PluginManager/Manager.h>
#include <Corrade/Utility/Arguments.h>
#include <Corrade/Utility/DebugStl.h>
#include <Magnum/ImageView.h>
#include <Magnum/Mesh.h>
#include <Magnum/PixelFormat.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/GL/TextureFormat.h>
#include <Magnum/Math/Color.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/SceneGraph/Camera.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/Shaders/Phong.h>
#include <Magnum/Trade/AbstractImporter.h>
#include <Magnum/Trade/ImageData.h>
#include <Magnum/Trade/MeshData.h>
#include <Magnum/Trade/MeshObjectData3D.h>
#include <Magnum/Trade/PhongMaterialData.h>
#include <Magnum/Trade/SceneData.h>
#include <Magnum/Trade/TextureData.h>

using namespace Magnum;
using namespace Math::Literals;

typedef SceneGraph::Object<SceneGraph::MatrixTransformation3D> Object3D;
typedef SceneGraph::Scene<SceneGraph::MatrixTransformation3D> Scene3D;

class ColoredDrawable : public SceneGraph::Drawable3D {
public:
    explicit ColoredDrawable(Object3D& object, Shaders::Phong& shader, GL::Mesh& mesh, const Color4& color, SceneGraph::DrawableGroup3D& group) : SceneGraph::Drawable3D{ object, &group }, _shader(shader), _mesh(mesh), _color{ color } {}

private:
    void draw(const Matrix4& transformationMatrix, SceneGraph::Camera3D& camera) override;

    Shaders::Phong& _shader;
    GL::Mesh& _mesh;
    Color4 _color;
};

class TexturedDrawable : public SceneGraph::Drawable3D {
public:
    explicit TexturedDrawable(Object3D& object, Shaders::Phong& shader, GL::Mesh& mesh, GL::Texture2D& texture, SceneGraph::DrawableGroup3D& group) : SceneGraph::Drawable3D{ object, &group }, _shader(shader), _mesh(mesh), _texture(texture) {}

private:
    void draw(const Matrix4& transformationMatrix, SceneGraph::Camera3D& camera) override;

    Shaders::Phong& _shader;
    GL::Mesh& _mesh;
    GL::Texture2D& _texture;
};

class Renderer
{
public:
	Renderer();

    void addModel(std::string filePath);
    void addCube();

    void render();
private:

    Shaders::Phong _coloredShader,
        _texturedShader{ Shaders::Phong::Flag::DiffuseTexture };
    Containers::Array<Containers::Optional<GL::Mesh>> _meshes;
    Containers::Array<Containers::Optional<GL::Texture2D>> _textures;

    Scene3D _scene;
    Object3D _cameraObject;
    SceneGraph::Camera3D* _camera;
    SceneGraph::DrawableGroup3D drawables;
};