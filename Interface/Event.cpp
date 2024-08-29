#include <glfw3.h>

#ifdef DEBUG
#	include <stdio.h>
#endif

#include "Canvas.h"
#include "..\Interface\Window.h"
#include "..\Figure2\Point.h"
#include "Event.h"


namespace Event
{
	bool Start = 0;



	void KeyPress(MainWindow)(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		using namespace Canvas;
		if (action == GLFW_PRESS) {
			switch (key) {
			case GLFW_KEY_LEFT:  offsetX -= 0.01f; break;
			case GLFW_KEY_RIGHT:  offsetX += 0.01f; break;
			case GLFW_KEY_UP:  offsetY += 0.01f; break;
			case GLFW_KEY_DOWN:  offsetY -= 0.01f; break;
			case GLFW_KEY_EQUAL:  mult += 0x01; break;
			case GLFW_KEY_MINUS:  mult -= mult <= 0x01 ? 0x00 : 0x01; break;

			case GLFW_KEY_S: Start = 1;
			}
		}
	}



	void MouseClick(MainWindow)(GLFWwindow* window, int button, int action, int mods)
	{
		using namespace Canvas;
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (action == GLFW_PRESS)  Press = 1;
			else  Press = 0;
		}
		if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			if (action == GLFW_PRESS) {
				//printf("(%f, %f)\n", (xpos - 450) / 450, (-ypos + 450) / 450);
				float x = (xpos - 450) / 450 - OffsetX, y = (-ypos + 450) / 450 - OffsetY;
				new Figure2::Point(x, y);
			}
		}
	}



	void Scroll(MainWindow)(GLFWwindow* window, double xoffset, double yoffset)
	{
		using namespace Canvas;
		if (yoffset < 0)  mult -= mult <= 0x01 ? 0x00 : 0x01;
		else if (yoffset > 0)  mult += 0x01;
	}



	void CursorMove(MainWindow)(GLFWwindow* window, double xpos, double ypos)
	{
		using namespace Canvas;
		if (Press) {
			if (xPos > xpos)  offsetX -= 0.01f;
			else if (xPos < xpos)  offsetX += 0.01f;
			if (yPos > ypos)  offsetY += 0.01f;
			else if (yPos < ypos)  offsetY -= 0.01f;
		}
		xPos = xpos, yPos = ypos;
	}
}