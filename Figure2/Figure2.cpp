#include <glew.h>
#include <malloc.h>
#include "..\Interface\Canvas.h"
#include "Figure2.h"

#define point 0
#define line 1

#define POINT_POSITION 0
#define POINT_COLOR 1
#define LINE_COLOR 2


namespace Canvas
{
	namespace Figure2
	{
		Point* Points[_MAX];
		Line* Lines[_MAX];
		unsigned int vao, vbo, ebo;

		void Begin()
		{
			// Generate objects
			glGenVertexArrays(1, &vao);
			glGenBuffers(1, &vbo);
			glGenBuffers(1, &ebo);
			// Bind objects
			glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
			// initialize data to vbo and vao
			glBufferData(GL_ARRAY_BUFFER, _MAX * 40, (void*)0, GL_DYNAMIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, _MAX * 40, (void*)0, GL_DYNAMIC_DRAW);
			// Set up the layout
			glVertexAttribPointer(POINT_POSITION, 2, GL_FLOAT, GL_FALSE, 40, (void*)0);
			glVertexAttribPointer(POINT_COLOR, 4, GL_FLOAT, GL_FALSE, 40, (void*)8);
			glVertexAttribPointer(LINE_COLOR, 4, GL_FLOAT, GL_FALSE, 40, (void*)24);

			glEnableVertexAttribArray(POINT_POSITION);
			glEnableVertexAttribArray(POINT_COLOR);
			glEnableVertexAttribArray(LINE_COLOR);
		}





		static void draw(unsigned char figure, unsigned char index)
		{
			switch (figure) {
			case point:
			{
				Point* P = Points[index];
				if (P->Show) {
					float position[2] = {
						(P->X + offsetX) * mult,
						(P->Y + offsetY) * mult
					};
					glBufferSubData(GL_ARRAY_BUFFER, index * 40, 8, position);
					glBufferSubData(GL_ARRAY_BUFFER, index * 40 + 8, 16, P->Color);
					glBufferSubData(GL_ARRAY_BUFFER, index * 40 + 24, 16, 0);
					glDrawArrays(GL_POINTS, index, 1);
				}
				break;
			}
			case line:
			{
				Line* L = Lines[index];
				if (L->Show) {
					unsigned char ed[2] = {
						L->Start.Index(),
						L->End.Index()
					};
					glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, index << 1, 2, ed);
					glBufferSubData(GL_ARRAY_BUFFER, ed[0] * 40 + 24, 16, L->Color);
					glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, (void*)(index << 1));
				}
				break;
			}
			}
		}





		void UpdateDraw(unsigned int shaderProgramId)
		{
			glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
			glUseProgram(shaderProgramId);
			// Draw all figure2s
			if (Point::Cnt() < Line::Cnt()) {
				for (unsigned short i = 0; i < Point::Cnt(); i++) {
					draw(point, i);
					draw(line, i);
				}
				for (unsigned short i = Point::Cnt(); i < Line::Cnt(); i++)  draw(line, i);
			}
			else {
				for (unsigned short i = 0; i < Line::Cnt(); i++) {
					draw(point, i);
					draw(line, i);
				}
				for (unsigned short i = Line::Cnt(); i < Point::Cnt(); i++)  draw(point, i);
			}
		}





		void End()
		{
			//glClearBufferData(GL_ARRAY_BUFFER, vbo, )
			for (unsigned short i = 0; i < _MAX; i++) {
				delete(Points[i]);
				delete(Lines[i]);
			}
			// Delete objects
			glDeleteVertexArrays(1, &vao);
			glDeleteBuffers(1, &vbo);
			glDeleteBuffers(1, &ebo);
		}
	}
}