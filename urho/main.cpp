#include <Urho3D/Engine/Application.h>

// Чтобы везде не писать Urho3D::ИмяТипа.
using namespace Urho3D;

// Главный класс игры.
class Game : public Application
{
    // Макрос добавляет в класс информацию о текущем и базовом типе.
    URHO3D_OBJECT(Game, Application);

public:
    // Конструктор класса.
    Game(Context* context) : Application(context)
    {
    }
};

// Указываем движку главный класс игры.
URHO3D_DEFINE_APPLICATION_MAIN(Game)