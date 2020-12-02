#include "BaseEntity.h"
#include <typeinfo>

using namespace std;

BaseEntity::BaseEntity()
{
	name = Field(FieldType::STRING);
}

Field::Field()
{
	value = "";
	type = FieldType::STRING;
}

Field::Field(void* val)
{
	value = val;
	const char* tn = typeid(val).name();
	if (tn == "int" || tn == "short")
	{
		type = FieldType::INT;
	}
	else if (tn == "float")
	{
		type = FieldType::FLOAT;
	}
	// and other types TODO
}

Field::Field(FieldType t)
{

}

Field::Field(void* val, FieldType t)
{
	//pass
}