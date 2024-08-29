#pragma once
#include "Point.h"
#include "Line.h"

#define White 1.0f, 1.0f, 1.0f, 1.0f
#define Red 1.0f, 0.0f, 0.0f, 1.0f
#define Green 0.0f, 1.0f, 0.0f, 1.0f
#define Blue 0.0f, 0.0f, 1.0f, 1.0f
#define Gray 0.5f, 0.5f, 0.5f, 1.0f
#define Black 0.0f, 0.0f, 0.0f, 1.0f


namespace Canvas
{
	namespace Figure2
	{
		// Maximum number of each figure2 that exists
		const unsigned short _MAX = 0x0200;
		extern Point* Points[_MAX];
		extern Line* Lines[_MAX];
		// GL objects' id of all figure2s
		extern unsigned int vao, vbo, ebo;
		// Create GL objects for all figure2s
		void Begin();
		// Update the inforation and draw out all figure2s
		void UpdateDraw(unsigned int shaderProgramId);
		// Delete GL objects for all figure2s
		void End();
	}
}