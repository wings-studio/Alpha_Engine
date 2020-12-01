#include <string>

using namespace std;

class BaseEntity
{
public:
	BaseEntity();

	~BaseEntity();

	void OnCreate();

	void OnDestroy();

	void Create();

	void Destroy();

	string name;
};

