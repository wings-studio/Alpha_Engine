#include "BaseModelEntity.h"

using namespace std;

class ModelEntity : public BaseModelEntity
{
public:

	int fadeDistance;
	FUNC_GETPROPS;
};

AlphaProperties ModelEntity::GetProps()
{
	AlphaProperties ap = BaseModelEntity::GetProps();
	ap.Add("fade_distance", INT(fadeDistance));
	return ap;
}