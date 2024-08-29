#include <glew.h>
#include <glfw3.h>
#include "..\Interface\Canvas.h"
#include "CoordSys.h"

#ifdef DEBUG
#	include "..\Debugger\Timer.h"
#endif


namespace Canvas
{
	namespace CoordSys
	{
		uint vaoCoordSys[MAX], vboCoordSys[MAX], eboCoordSys[MAX];
		float vdCartesian2[20] = {
			-1.00f, 0.00f,  // x-axis
			 1.00f, 0.00f,
			 0.00f,-1.00f,  // y-axis
			 0.00f, 1.00f,
			 1.00f, 0.00f,  // arrow of x-axis
			 0.98f, 0.02f,
			 0.98f,-0.02f,
			 0.00f, 1.00f,  // arrow of y-axis
			 0.02f, 0.98f,
			-0.02f, 0.98f
		};
		uchar edCartesian2[12] = {
			0, 1,  // x-axis
			2, 3,  // y-axis
			4, 5,  // top arrow of x-axis
			4, 6,  // bottom arrow of x-axis
			7, 8,  // right arrow of y-axis
			7, 9   // left arrow of y-axis 
		};
		bool Show[MAX] = { 0 };



		void Load()
		{
			// Generate vaos and vbos for all coordinate systems
			glGenVertexArrays(MAX, vaoCoordSys);
			glGenBuffers(MAX, vboCoordSys);
			glGenBuffers(MAX, eboCoordSys);

			// Set up the attribute of cartesian2 system
			glBindVertexArray(vaoCoordSys[0]);
			glBindBuffer(GL_ARRAY_BUFFER, vboCoordSys[0]);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboCoordSys[0]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vdCartesian2), vdCartesian2, GL_DYNAMIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edCartesian2), edCartesian2, GL_DYNAMIC_DRAW);

			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			// TODO: Set up the attrbute of polor2 system
		}



		void UpdateDraw(Type coordSysType, uint shaderProgramId)
		{
			// Update the position vertex data
			glBindVertexArray(vaoCoordSys[coordSysType]);
			glBindBuffer(GL_ARRAY_BUFFER, vboCoordSys[coordSysType]);
			glUseProgram(shaderProgramId);
			switch (coordSysType)
			case CARTESIAN_2: {
				float a[4] = { OffsetX + 0.02f, OffsetX - 0.02f, OffsetY + 0.02f, OffsetY - 0.02f };
				glBufferSubData(GL_ARRAY_BUFFER, sizeof(float), sizeof(float), &OffsetY);
				glBufferSubData(GL_ARRAY_BUFFER, 3 * sizeof(float), sizeof(float), &OffsetY);
				glBufferSubData(GL_ARRAY_BUFFER, 4 * sizeof(float), sizeof(float), &OffsetX);
				glBufferSubData(GL_ARRAY_BUFFER, 6 * sizeof(float), sizeof(float), &OffsetX);
				glBufferSubData(GL_ARRAY_BUFFER, 9 * sizeof(float), sizeof(float), &OffsetY);
				glBufferSubData(GL_ARRAY_BUFFER, 11 * sizeof(float), sizeof(float), a + 2);
				glBufferSubData(GL_ARRAY_BUFFER, 13 * sizeof(float), sizeof(float), a + 3);
				glBufferSubData(GL_ARRAY_BUFFER, 14 * sizeof(float), sizeof(float), &OffsetX);
				glBufferSubData(GL_ARRAY_BUFFER, 16 * sizeof(float), sizeof(float), a);
				glBufferSubData(GL_ARRAY_BUFFER, 18 * sizeof(float), sizeof(float), a + 1);
				break;
			}
			// Draw the coordinate system
			glDrawElements(GL_LINES, 12, GL_UNSIGNED_BYTE, 0);
			return;
		}



		void Unload()
		{
			// Delete vaos and vbos for all coordinate systems
			glDeleteVertexArrays(MAX, vaoCoordSys);
			glDeleteBuffers(MAX, vboCoordSys);
			glDeleteBuffers(MAX, eboCoordSys);
		}
	}
}