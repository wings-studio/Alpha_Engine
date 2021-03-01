#include <iostream>
#include "Input.h"

void print(int a)
{
	std::cout << a << std::endl;
}
void square(int a)
{
	std::cout << a * a << std::endl;
}

int main()
{
	Event<int> e;
	e.addHandler(Action<int>(print));
	e.addHandler(Action<int>(square));
	e.exec(3);
}
