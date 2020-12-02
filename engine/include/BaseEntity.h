#include <string>
#include <map>
#include <vector>

using namespace std;

class BaseEntity
{
public:
	BaseEntity();

	void OnCreate();
	void OnDestroy();

	void Create(actiondata ad);
	void Destroy(actiondata ad);

	static Entity CreateEntity();

	Field name;
	event onCreate, onDestroy;
	action create, destroy;
};

struct actiondata
{
	BaseEntity* activator;
};

using action = void(actiondata);

struct event
{
public:
	void(*event_script) ();
	vector<action*> actions;
	BaseEntity* activator;

	event(BaseEntity* e, void(*func) ())
	{
		activator = e;
		event_script = func;
		actions = vector<action*>();
	}

	void exec()
	{
		for (int i = 0; i < actions.size(); i++)
		{
			actions[i](actiondata { activator = this->activator });
		}
	}

	void link(action* a)
	{
		actions.push_back(a);
	}
};

class Field
{
public:
	void* value;
	FieldType type;
	char* fullName, description;

	Field();
	Field(void* val);
	Field(FieldType t);
	Field(void* val, FieldType t);
};

enum FieldType
{
	BOOLEAN,
	INT,
	FLOAT,
	VECTOR3,
	QUATERNION,
	TEXTURE,
	MATERIAL,
	MODEL,
	COLOR,
	SOUND,
	SCRIPT,
	ENTITY,
	STRING,
	CHOOSE
};

class Entity
{
public:
	const char* name;
	BaseEntity* entity;
	map<char*, Field*> fields;
	map<char*, event*> events;
	map<char*, action*> actions;
};

