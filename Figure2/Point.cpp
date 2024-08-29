#include <malloc.h>
#include "Figure2.h"

#ifdef DEBUG
#	include <stdio.h>
#endif


namespace Canvas
{
	namespace Figure2
	{
		unsigned char Point::cnt = 0;


		Point::Point(float x, float y)
			:X(x), Y(y), Color{ Black }
		{
			this->index = Point::cnt;
			this->Show = 1;
			Points[Point::cnt] = this;
			Point::cnt++;
		}



		Point::Point(float x, float y, float r, float g, float b, float a)
			:X(x), Y(y), Color{ r,g,b,a }
		{
			this->index = Point::cnt;
			this->Show = 1;
			Points[Point::cnt] = this;
			Point::cnt++;
		}



		void Point::Swap(Point& p, Point& q)
		{
			// Change the information stored in Points array
			Points[p.index] = &q;
			Points[q.index] = &p;
			// Swap the index
			unsigned char temp = p.index;
			p.index = q.index;
			q.index = temp;
		}



		Point::~Point()
		{
			Point::cnt--;
			Points[this->index] = Points[Point::cnt];
			Points[Point::cnt]->index = this->index;
		}
	}
}