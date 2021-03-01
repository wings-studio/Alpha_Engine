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

int main()
{
	Vector2 v;
	std::cin >> v.x >> v.y;
	Event<float, float> e; // THIS IS WORKS
	e.addHandler(Action<float, float>(plus)); // VARIADIC TEMPLATES IS WORKS
	e.addHandler(Action<float, float>(minus)); // AHAHAHAH
	e.exec(v.x, v.y); // YEEEEEEEEEEEEEEEEEEEEEEEEEEEAH
}
