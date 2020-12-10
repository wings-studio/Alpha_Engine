#include "BaseEntity.h"

using namespace std;

class BaseModelEntity : public BaseEntity
{
public:
	char* model;
	FUNC_GETPROPS;
};

AlphaProperties BaseModelEntity::GetProps()
{
	AlphaProperties props;
	props.Add("model", STR(model));
	return props;
}