#pragma once

#include "Point.h"


namespace Canvas
{
	namespace Figure2
	{
		class Line
		{
		public:
			Line(Point& p, Point& q);
			Line(Point& p, Point& q, float r, float g, float b, float a);
			~Line();

			// Attribute of this line
			Point& Start, & End;
			float Color[4];
			// Whether to draw this line
			bool Show;

			static void Swap(Line& r, Line& s);

			// Getter functions
			static unsigned char Cnt() { return Line::cnt; }
			unsigned char Index() const { return this->index; }
		private:
			// Number of currently existing lines
			static unsigned char cnt;
			// Index of the current line in ebo
			unsigned char index;
		};
	}
}