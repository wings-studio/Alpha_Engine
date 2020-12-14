#include "AlphaObject.h"

using namespace std;

void AlphaObject::InstallTemplate(char* name, AlphaProperties props)
{
	templates.insert(make_pair(name, props));
}

AlphaProperties AlphaObject::GetTemplate(char* name)
{
	return templates[name];
}

void AlphaProperties::PrintInfo()
{
	auto p = props.begin();
	for (; p != props.end(); p++)
	{
		cout << p->first << ' ' << p->second.GetValue() << endl;
	}
}

ostream& operator << (ostream& os, BaseAlphaObject& obj)
{
	return os << obj.GetValue();
}

istream& operator >> (istream& in, AlphaString& obj)
{
	return in >> obj.GetValue();
}

istream& operator >> (istream& in, AlphaInteger& obj)
{
	return in >> obj.GetValue();
}