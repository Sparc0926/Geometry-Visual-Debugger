#pragma once


namespace Canvas
{
	namespace Figure2
	{
		class Point
		{
		public:
			// Load data of this point into the vbo and vao
			Point(float x, float y);
			Point(float x, float y, float r, float g, float b, float a);
			~Point();

			// Attribute of this point
			float X, Y, Color[4];
			// Whether to draw this point
			bool Show;

			static void Swap(Point& p, Point& q);

			// Getter functions
			static unsigned char Cnt() { return Point::cnt; }
			unsigned char Index() const { return this->index; }
		private:
			// Number of currently existing points
			static unsigned char cnt;
			// Index of the current point in vbo
			unsigned char index;
		};
	}
}