#include <map>
#include <vector>
#include <fstream>

#define STR(val) AlphaString(val)
#define INT(val) AlphaInteger(val)

using namespace std;

class BaseAlphaObject
{
public:

	void Serialize(ofstream* stream);
	void Deserialize(ifstream* stream);
	void* GetValue();
};

class AlphaProperties
{
private:
	map<char*, BaseAlphaObject> props;

public:
	AlphaProperties();

	void Add(char* name, BaseAlphaObject value);
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

class AlphaString : public BaseAlphaObject
{
public:
	AlphaString();
	AlphaString(char* val);
	char* GetValue();
};

class AlphaInteger : public BaseAlphaObject
{
public:
	AlphaInteger();
	AlphaInteger(int val);
	int GetValue();
};