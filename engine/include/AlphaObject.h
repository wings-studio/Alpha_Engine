#include <map>
#include <vector>
#include <fstream>

#define add(key, value) insert(make_pair(key, value));
#define STR(val) AlphaString(val)
#define INT(val) AlphaInteger(val)

using namespace std;

class BaseAlphaObject
{
public:

	void Serialize(ofstream* stream);
	void Deserialize(ifstream* stream);
};

typedef map<char*, BaseAlphaObject> AlphaProperties;

class AlphaObject : public BaseAlphaObject
{
public:
	void InstallProperties(char* name, AlphaProperties props)
	{
		properties.add(name, props);
	}

private:
	map<char*, AlphaProperties> properties;
};

class AlphaString : public BaseAlphaObject
{
public:
	AlphaString();
	AlphaString(char* val);
};

class AlphaInteger : public BaseAlphaObject
{
public:
	AlphaInteger();
	AlphaInteger(int val);
};