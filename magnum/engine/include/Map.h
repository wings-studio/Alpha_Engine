#include "Renderer.h"
#include <string>

class Map
{
public:
	Map();
	~Map();

	void load(std::string filename);
	void run();
private:
	Renderer renderer;
};