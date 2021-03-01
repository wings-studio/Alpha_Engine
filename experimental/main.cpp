#include <iostream>
#include "Input.h"

void minus(int a, int b)
{
	std::cout << a - b << std::endl;
}
void plus(int a, int b)
{
	std::cout << a + b << std::endl;
}

int main()
{
	Event<int, int> e; // THIS IS WORKS
	e.addHandler(Action<int, int>(plus)); // VARIADIC TEMPLATES IS WORKS
	e.addHandler(Action<int, int>(minus)); // AHAHAHAH
	e.exec(3, 6); // YEEEEEEEEEEEEEEEEEEEEEEEEEEEAH
}
