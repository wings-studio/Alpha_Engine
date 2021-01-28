#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Math/Matrix4.h>
#include <Magnum/MeshTools/Interleave.h>
#include <Magnum/MeshTools/CompressIndices.h>
#include <Magnum/MeshTools/Compile.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/Shaders/Phong.h>
#include <Magnum/Trade/MeshData.h>

using namespace Magnum;
using namespace Magnum::GL;
using namespace Math::Literals;

class MyApplication: public Platform::Application {
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
        void mousePressEvent(MouseEvent& event) override;
        void mouseReleaseEvent(MouseEvent& event) override;
        void mouseMoveEvent(MouseMoveEvent& event) override;

        Mesh _mesh;
        Shaders::Phong _shader;

        Matrix4 _transformation, _projection;
        Color3 _color;
};

MyApplication::MyApplication(const Arguments& arguments) : Platform::Application{ arguments,
    Configuration{}.setTitle("First Magnum Application") } {

    Renderer::enable(Renderer::Feature::DepthTest);
    Renderer::enable(Renderer::Feature::FaceCulling);

    //_mesh = MeshTools::compile(Primitives::cubeSolid());
    Trade::MeshData cube = Primitives::cubeSolid();

    Buffer vertices;
    vertices.setData(MeshTools::interleave(cube.positions3DAsArray(),
        cube.normalsAsArray()));

    std::pair<Containers::Array<char>, Magnum::MeshIndexType> compressed =
        MeshTools::compressIndices(cube.indicesAsArray());
    Buffer indices;
    indices.setData(compressed.first);

    _mesh.setPrimitive(cube.primitive())
        .setCount(cube.indexCount())
        .addVertexBuffer(std::move(vertices), 0, Shaders::Phong::Position{},
            Shaders::Phong::Normal{})
        .setIndexBuffer(std::move(indices), 0, compressed.second);
    _transformation =
        Matrix4::rotationX(30.0_degf) * Matrix4::rotationY(40.0_degf);
    _projection =
        Matrix4::perspectiveProjection(
            35.0_degf, Vector2{ windowSize() }.aspectRatio(), 0.01f, 100.0f) *
        Matrix4::translation(Vector3::zAxis(-10.0f));
    _color = Color3::fromHsv({ 35.0_degf, 1.0f, 1.0f });
}

void MyApplication::drawEvent() {
    GL::defaultFramebuffer.clear(
        GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

    _shader.setLightPositions({ {1.4f, 1.0f, 0.75f, 0.0f} })
        .setDiffuseColor(_color)
        .setAmbientColor(Color3::fromHsv({ _color.hue(), 1.0f, 0.3f }))
        .setTransformationMatrix(_transformation)
        .setNormalMatrix(_transformation.normalMatrix())
        .setProjectionMatrix(_projection)
        .draw(_mesh);

    swapBuffers();
}

void MyApplication::mousePressEvent(MouseEvent& event)
{
    if (event.button() != MouseEvent::Button::Left) return;

    event.setAccepted();
}

void MyApplication::mouseReleaseEvent(MouseEvent& event) {
    _color = Color3::fromHsv({ _color.hue() + 50.0_degf, 1.0f, 1.0f });

    event.setAccepted();
    redraw();
}

void MyApplication::mouseMoveEvent(MouseMoveEvent& event) {
    if (!(event.buttons() & MouseMoveEvent::Button::Left)) return;

    Vector2 delta = 3.0f * Vector2{ event.relativePosition() } / Vector2{ windowSize() };

    _transformation =
        Matrix4::rotationX(Rad{ delta.y() }) *
        _transformation *
        Matrix4::rotationY(Rad{ delta.x() });

    event.setAccepted();
    redraw();
}

MAGNUM_APPLICATION_MAIN(MyApplication)
