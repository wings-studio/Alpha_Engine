#include <string>
#include <map>
#include <vector>

using namespace std;

#define EVENT(name, funcname) event name = event(this, funcname)
#define FIELD(name, type) Field f_##name = Field(&name, FieldType::type)
#define ACTION(name, funcname) action name = funcname

class BaseEntity;

struct actiondata
{
	BaseEntity* activator;
};

typedef void (BaseEntity::* action)(actiondata);

struct event
{
public:
	void(BaseEntity::*event_script)();
	vector<action> actions;
	BaseEntity* activator;

	event(BaseEntity* e, void(BaseEntity::*func)())
	{
		activator = e;
		event_script = func;
		actions = vector<action>();
	}

	void exec();

	void link(action a);
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

class BaseEntity
{
public:
	BaseEntity();

	void OnCreate();
	void OnDestroy();

	void Create(actiondata ad);
	void Destroy(actiondata ad);

	char* name;
	FIELD(name, STRING);
	EVENT(onCreate, &BaseEntity::OnCreate);
	EVENT(onDestroy, &BaseEntity::OnDestroy);
	ACTION(create, &BaseEntity::Create);
	ACTION(destroy, &BaseEntity::Destroy);
};

class Entity
{
public:
	const char* name;
	BaseEntity* entity;
	map<char*, Field*> fields;
	map<char*, event*> events;
	map<char*, action> actions;

	void CallAction(char* name);
};

