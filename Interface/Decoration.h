#pragma once

#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int

namespace Decoration
{
	extern uint vao, vbo, ebo;
	extern float vd[];
	extern uchar ed[];

	void Begin();
	void Draw();
	void End();
}