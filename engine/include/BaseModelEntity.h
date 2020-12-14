#include "BaseEntity.h"

using namespace std;

class BaseModelEntity : public BaseEntity
{
public:
	char* model;
	FUNC_GETPROPS;
};

class ModelEntity : public BaseModelEntity
{
public:

	int fadeDistance;
	FUNC_GETPROPS;
};