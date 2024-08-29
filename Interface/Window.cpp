#include <glfw3.h>
#include <stdio.h>

#include "Window.h"
#include "Canvas.h"
#include "Event.h"


Window::Window(
	const unsigned int len,
	const unsigned int wid,
	const char* name,
	GLFWkeyfun eventFunc_1,
	GLFWmousebuttonfun eventFunc_2,
	GLFWscrollfun eventFunc_3,
	GLFWcursorposfun eventFunc_4
)
{
	// Create the window and store it's id in Handle
	this->Handle = glfwCreateWindow(len, wid, name, 0, 0);
	// Terminate if creation fails
	if (!this->Handle) {
		printf("Window %s creation failed!\n", name);
		glfwTerminate();
	}
	// Set basic attributes of the window
	this->Length = len;
	this->Width = wid;
#ifdef DEBUG
	this->Name = name;
#endif
	// Set events of the window
	glfwSetKeyCallback(this->Handle, eventFunc_1);
	glfwSetMouseButtonCallback(this->Handle, eventFunc_2);
	glfwSetScrollCallback(this->Handle, eventFunc_3);
	glfwSetCursorPosCallback(this->Handle, eventFunc_4);
}



Window::~Window()
{
	// Destroy the window
	glfwDestroyWindow(this->Handle);
#ifdef DEBUG
	printf("Window \"%s\" has been destroyed.\n", this->Name);
#endif
}