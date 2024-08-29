#include <glew.h>
#include <glfw3.h>
#include <malloc.h>
#ifdef DEBUG
#	include <stdio.h>
#endif
#include <thread>

#include "Shader.h"
#include "..\Interface\Canvas.h"
#include "CoordSys.h"
#include "..\Interface\Event.h"
#include "..\Interface\Window.h"
#include "..\Figure2\Figure2.h"


unsigned char Canvas::mult = 0x01;
float Canvas::offsetX = 0.0f, Canvas::offsetY = 0.0f;
float Canvas::OffsetX = 0.0f, Canvas::OffsetY = 0.0f;
bool Canvas::Press = 0;
double Canvas::xPos, Canvas::yPos;

unsigned int JarvisMarch(Canvas::Figure2::Point* p, unsigned int n);


void Test()
{
	using namespace Canvas::Figure2;
	unsigned int n;
	Point* p[100];
	scanf_s("%d", &n);
	for (unsigned int i = 0; i < n; i++) {
		float x, y;
		scanf_s("%f %f", &x, &y);
		p[i] = new Point(x / 20, y / 20, Gray);
	}
	JarvisMarch(p[0], n);
}



int main()
{
	// Initialize GLFW
	if (!glfwInit()) {
#ifdef DEBUG
		printf("GLFW initialization failed!\n");
		return -1;
	}
	else  printf("GLFW initialization succeeded!\n");
#else
		return -1;
}
#endif
	// Create windows
	Window MainWindow(
		1600, 900,
		"Geometry Visual Debugger",
		Event::KeyPress(MainWindow),
		Event::MouseClick(MainWindow),
		Event::Scroll(MainWindow),
		Event::CursorMove(MainWindow)
	);
	/* Make the window's context current */
	glfwMakeContextCurrent(MainWindow.Handle);
	// Initialize GLEW
	// WARNING: Should be after glMakeContextCurrent()!!!
	if (glewInit() != GLEW_OK) {
#ifdef DEBUG
		printf("GLEW initialization failed!\n");
		return -1;
	}
	else  printf("GLEW initialization succeeded!\n");
#else
		return -1;
	}
#endif
	// Specifies the canvas area
	glViewport(500, 100, 800, 800);

	// Define shader sources
	const char* vsSrc =
		"#version 330 core\n"
		"layout (location = 0)  in vec4 aPos;\n"
		"layout (location = 1)  in vec4 aColor;\n"
		"layout (location = 2)  in vec4 bColor;\n"
		"out vec4 pColor;\n"
		"out vec4 lColor;\n"
		"void main() {\n"
		"	gl_Position = aPos;\n"
		"	pColor = aColor;\n"
		"	lColor = bColor;\n"
		"}";
	const char* fsSrc =
		"#version 330 core\n"
		"in vec4 pColor;\n"
		"in vec4 lColor;\n"
		"out vec4 pointColor;\n"
		"out vec4 lineColor;\n"
		"void main() {\n"
		"   pointColor = pColor;\n"
		"	lineColor = lColor;\n"
		"}";



	unsigned int vsId = Shader::Compile(GL_VERTEX_SHADER, vsSrc);
	unsigned int fsId = Shader::Compile(GL_FRAGMENT_SHADER, fsSrc);
	unsigned int spId = Shader::Link(vsId, fsId);


	Canvas::CoordSys::Load();
	Canvas::Figure2::Begin();

	glEnable(GL_PROGRAM_POINT_SIZE_EXT);
	glPointSize(5);


	std::thread Algorithm(Test);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(MainWindow.Handle))
	{
		/* Render here */
		glClearColor(White);
		glClear(GL_COLOR_BUFFER_BIT);


		//Canvas::CoordSys::UpdateDraw(Canvas::CoordSys::CARTESIAN_2, spId);
		Canvas::Figure2::UpdateDraw(spId);


		/* Swap front and back buffers */
		glfwSwapBuffers(MainWindow.Handle);

		/* Poll for and process events */
		glfwPollEvents();
		Canvas::OffsetX = Canvas::offsetX * Canvas::mult;
		Canvas::OffsetY = Canvas::offsetY * Canvas::mult;
	}

	Algorithm.join();

	printf("Done.\n");


	Canvas::Figure2::End();
	Canvas::CoordSys::Unload();
	glfwTerminate();

	return 0;
}