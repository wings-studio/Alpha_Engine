void on_key_pressed(void(func*)(int, const char*));
void on_key_released(void(func*)(int, const char*));

#ifdef __cplusplus
#include <Input.h>
extern "C"
{
	void on_key_pressed(void(func*)(int, const char*))
	{
		Input::onKeyPressed.addHandler(func);	
	}
	void on_key_released(void(func*)(int, const char*))
	{
		Input::onKeyReleased.addHandler(func);	
	}
}
#endif
