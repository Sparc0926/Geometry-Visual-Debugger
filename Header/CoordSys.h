#pragma once

#include "..\Interface\Canvas.h"

#define MAX 2



namespace Canvas
{
	namespace CoordSys
	{
		typedef enum : unsigned char {
			CARTESIAN_2 = 0x00,
			POLOR_2 = 0x01
		} Type;
		extern unsigned int vboCoordSys[MAX], vaoCoordSys[MAX], eboCoordSys[MAX];
		/// <summary>
		/// The vertex data of each coordinate system
		/// </summary>
		extern float vdCartesian2[20];
		extern unsigned char edCartesian2[12];
		/// <summary>
		/// Whether to show the selected coordinate system
		/// </summary>
		extern bool Show[MAX];

		void Load();
		void UpdateDraw(Type coordSysType, unsigned int shaderProgramId);
		void Unload();
	}
}