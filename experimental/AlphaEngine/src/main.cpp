#include <iostream>
#include "Input.h"

void minus(float a, float b)
{
	std::cout << a - b << std::endl;
}
void plus(float a, float b)
{
	std::cout << a + b << std::endl;
}
void multiply(float a, float b)
{
	std::cout << a * b << std::endl;
}

int main()
{
	Vector2 v;
	std::cin >> v.x >> v.y;
	Event<float, float> e;
	e.addHandler(Action<float, float>(plus));
	e.addHandler(Action<float, float>(minus));
	e.addHandler(Action<float, float>(multiply));
	e.exec(v.x, v.y);
}
