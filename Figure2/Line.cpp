#include "Figure2.h"


namespace Canvas
{
	namespace Figure2
	{
		unsigned char Line::cnt = 0;


		Line::Line(Point& p, Point& q)
			: Start(p), End(q), Color{ Black }
		{
			this->index = Line::cnt;
			this->Show = 1;
			Lines[Line::cnt] = this;
			cnt++;
		}



		Line::Line(Point& p, Point& q, float r, float g, float b, float a)
			: Start(p), End(q), Color{ r,g,b,a }
		{
			this->index = Line::cnt;
			this->Show = 1;
			Lines[Line::cnt] = this;
			Line::cnt++;
		}



		void Line::Swap(Line& r, Line& s)
		{
			// Change the information stored in Lines array
			Lines[r.index] = &s;
			Lines[s.index] = &r;
			// Swap the index
			unsigned char temp = r.index;
			r.index = s.index;
			s.index = temp;
		}



		Line::~Line()
		{
			Line::cnt--;
			Lines[this->index] = Lines[Line::cnt];
			Lines[Line::cnt]->index = this->index;
		}
	}
}