#include "Player.h"
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/GL/GL.h>

using namespace Magnum;

class AlphaGame : Platform::Application
{
public:
	explicit AlphaGame(const Arguments& arguments);

    int main();
private:
    void drawEvent() override;
    void viewportEvent(ViewportEvent& event) override;
    void keyPressEvent(KeyEvent& event) override;
    void mousePressEvent(MouseEvent& event) override;
    void mouseReleaseEvent(MouseEvent& event) override;
    void mouseMoveEvent(MouseMoveEvent& event) override;
    void mouseScrollEvent(MouseScrollEvent& event) override;

    Player player;
};

AlphaGame::AlphaGame(const Arguments& arguments) : Platform::Application{ arguments, NoCreate }
{
	//pass
}

void AlphaGame::drawEvent()
{
    player.draw();
}

void AlphaGame::viewportEvent(ViewportEvent& event)
{
}

void AlphaGame::keyPressEvent(KeyEvent& event)
{
}

void AlphaGame::mousePressEvent(MouseEvent& event)
{
}

void AlphaGame::mouseReleaseEvent(MouseEvent& event)
{
}

void AlphaGame::mouseMoveEvent(MouseMoveEvent& event)
{
}

void AlphaGame::mouseScrollEvent(MouseScrollEvent& event)
{
}

int AlphaGame::main()
{
    return exec();
}

int main(int argc, char** argv)
{
    AlphaGame game({argc, argv});
    return game.main();
}