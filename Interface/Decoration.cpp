#include <glew.h>
#include "Decoration.h"

#define POSITION 0
#define COLOR 1


namespace Decoration
{
	uint vao, vbo, ebo;
	float vd[] = {
		0
	};
	uchar ed[];



	void Begin()
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

		glBufferData(GL_ARRAY_BUFFER, 512 * 24, (void*)0, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 512, (void*)0, GL_STATIC_DRAW);

		glVertexAttribPointer(POSITION, 2, GL_FLOAT, GL_FALSE, 24, (void*)0);
		glVertexAttribPointer(COLOR, 4, GL_FLOAT, GL_FALSE, 24, (void*)8);

		glEnableVertexAttribArray(POSITION);
		glEnableVertexAttribArray(COLOR);
	}



	void Draw()
	{

	}



	void End()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
	}
}