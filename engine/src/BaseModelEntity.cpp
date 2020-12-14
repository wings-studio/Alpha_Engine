#include "BaseModelEntity.h"

using namespace std;

AlphaProperties BaseModelEntity::GetProps()
{
	AlphaProperties props;
	props.Add("model", STR(model));
	return props;
}

AlphaProperties ModelEntity::GetProps()
{
	AlphaProperties ap = BaseModelEntity::GetProps();
	ap.Add("fade_distance", INT(fadeDistance));
	return ap;
}

DEFINE_ENTITY(model, ModelEntity);