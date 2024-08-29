#pragma once

#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int


namespace Canvas
{
	extern unsigned char mult;
	extern float OffsetX, OffsetY;
	extern float offsetX, offsetY;
	extern bool Press;
	extern double xPos, yPos;

	class Canvas
	{
	public:
		Canvas(ushort x, ushort y, ushort w, ushort h, float r, float g, float b, float a);
		~Canvas();

		void Draw();
	private:
		ushort xpos, ypos;
		ushort width, height;
		float color[4];
	};
}