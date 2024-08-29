#pragma once

#include <glfw3.h>
#include "Event.h"




class Window
{
public:
	// Create a window named "name" of size "length"*"width" and set its events
	Window(
		const unsigned int len,
		const unsigned int wid,
		const char* name,
		GLFWkeyfun eventFunc_1,
		GLFWmousebuttonfun eventFunc_2,
		GLFWscrollfun eventFunc_3,
		GLFWcursorposfun eventFunc_4
	);
	~Window();

	GLFWwindow* Handle;
private:
	unsigned int Length, Width;
#ifdef DEBUG
	const char* Name;
#endif
};