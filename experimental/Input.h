#include <iostream>
#include <vector>

template<typename T>
class Action
{
public:
	Action()
	{
	}
	Action(void(*func)(T))
	{
		setFunc(func);
	}
	~Action()
	{
	}
	
	void setFunc(void(*func)(T))
	{
		action = func;
	}
	void exec(T param)
	{
		(*action)(param);
	}
private:
	void(*action)(T);	
};

template<typename T>
class Event
{
public:
	Event()
	{
	}
	~Event()
	{
	}
	
	void addHandler(Action<T> handler)
	{
		handlers.push_back(handler);
	}
	void exec(T param)
	{
		for (int i = 0; i < handlers.size(); i++)
		{
			handlers[i].exec(param);
		}
	}
private:
	std::vector<Action<T> > handlers;
};

class Input
{
public:
	//static 	
};
