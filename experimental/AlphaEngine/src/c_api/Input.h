#include <ae_math.h>

void ae_onKeyPressed(void(func*)(unsigned int, const char*));
void ae_onKeyReleased(void(func*)(unsigned int, const char*));
void ae_onMousePressed(void(func*)(unsigned int, Vector2));
void ae_onMouseReleased(void(func*)(unsigned int, Vector2));

#ifdef __cplusplus
#include <Input.h>
extern "C"
{
	void ae_onKeyPressed(void(func*)(unsigned int, const char*))
	{
		Input::onKeyPressed.addHandler(func);	
	}
	void ae_onKeyReleased(void(func*)(unsigned int, const char*))
	{
		Input::onKeyReleased.addHandler(func);	
	}
	void ae_onMousePressed(void(func*)(unsigned int, Vector2))
	{
		Input::onMousePressed.addHandler(func);
	}
	void ae_onMouseReleased(void(func*)(unsigned int, Vector2))
	{
		Input::onMouseReleased.addHandler(func);
	}
}
#endif
