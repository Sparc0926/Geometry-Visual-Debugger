#include <glew.h>
#include "Canvas.h"

namespace Canvas
{
	Canvas::Canvas(ushort x, ushort y, ushort w, ushort h, float r, float g, float b, float a)
		:xpos(x), ypos(y), width(w), height(h), color{ r,g,b,a }
	{
		glViewport(x, y, w, h);
		glClearColor(r, g, b, a);
	}



	Canvas::~Canvas()
	{
	}
}