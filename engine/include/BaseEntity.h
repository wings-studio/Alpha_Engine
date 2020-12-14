#include <string>
#include <map>
#include <vector>
#include "AlphaObject.h"

using namespace std;

#define EVENT(name, funcname) event name = event(this, funcname)
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

class BaseEntity
{
public:
	BaseEntity();

	void OnCreate();
	void OnDestroy();

	void Create(actiondata ad);
	void Destroy(actiondata ad);

	virtual AlphaProperties GetProps();

	char* name;
	EVENT(onCreate, &BaseEntity::OnCreate);
	EVENT(onDestroy, &BaseEntity::OnDestroy);
	ACTION(create, &BaseEntity::Create);
	ACTION(destroy, &BaseEntity::Destroy);
};

class AlphaEntity : public AlphaObject
{
public:
	AlphaEntity()
	{
		entity = NULL;
	}
	AlphaEntity(BaseEntity e)
	{
		entity = &e;
	}

	void InstallEntity(char* name)
	{
		if (entity != NULL)
			AlphaEntity::InstallTemplate(name, entity->GetProps());
	}

	void PrintTemplate(char* tname)
	{
		GetTemplate(tname).PrintInfo();
	}

	BaseEntity* entity;
};

template <class T>
class EntityFactory
{
public:
	EntityFactory(char* pClassName)
	{
		AlphaEntity ae(dynamic_cast<BaseEntity&>(T()));
		ae.InstallEntity(pClassName);
	}
};

#define DEFINE_ENTITY(mapClassName,DLLClassName) \
	static EntityFactory<DLLClassName> mapClassName( #mapClassName )
#define FUNC_GETPROPS AlphaProperties GetProps()

