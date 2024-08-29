#pragma once

#include <glfw3.h>
#include "..\Figure2\Point.h"

#define KeyPress(X) X##KeyPress
#define MouseClick(X) X##MouseClick
#define Scroll(X) X##Scroll
#define CursorMove(X) X##CursorMove



namespace Event
{
	extern bool Start;


	void KeyPress(MainWindow)(GLFWwindow* window, int key, int scancode, int action, int mods);


	void MouseClick(MainWindow)(GLFWwindow* window, int button, int action, int mods);


	void Scroll(MainWindow)(GLFWwindow* window, double xoffset, double yoffset);


	void CursorMove(MainWindow)(GLFWwindow* window, double xpos, double ypos);
}