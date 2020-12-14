#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include "Util.h"

#pragma region Basic Alpha Types define directives 

#define STR(val) AlphaString(val)
#define INT(val) AlphaInteger(val)
#define FLOAT(val) AlphaFloat(val)
#define VEC3(val) AlphaVector3(val)

#pragma endregion

/// Define base alpha type
#define DEFINE_BAT(ClassName, TypeName) \
class Alpha##ClassName : public BaseAlphaObject \
{ \
public: \
	Alpha##ClassName(); \
	Alpha##ClassName(TypeName val); \
	TypeName GetValue(); \
 \
private: \
	TypeName value; \
}

using namespace std;

class BaseAlphaObject
{
public:

	void* GetValue();
};

class AlphaProperties
{
private:
	map<char*, BaseAlphaObject> props;

public:
	AlphaProperties();

	void Add(char* name, BaseAlphaObject value);
	void PrintInfo();
};

class AlphaObject : public BaseAlphaObject
{
public:
	AlphaObject();

	AlphaProperties* GetValue();

protected:
	/// <summary>
	/// Creates a new template with properties that will be assigned with this name
	/// </summary>
	void InstallTemplate(char* name, AlphaProperties props);
	AlphaProperties GetTemplate(char* name);

private:
	static map<char*, AlphaProperties> templates;
	AlphaProperties props;
};

DEFINE_BAT(String, char*);
DEFINE_BAT(Integer, int);
DEFINE_BAT(Float, float);
DEFINE_BAT(Vector3, Vector3);
DEFINE_BAT(Boolean, bool);