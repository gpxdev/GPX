//
//  main.cpp
//  GPX
//
//  Created by George Coomber on 2015-10-04.
//  Copyright © 2015 George Coomber. All rights reserved.
//

#include <iostream>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <Config.h>
#include <Log/Log.h>

using namespace gp;

void render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, -0.5f);
	
	glEnd();
}

void initialize()
{
}

int main(int argc, const char * argv[])
{
	GLFWwindow* win;
	if (!glfwInit())
		return -1;
	
	Log log;
	
	Log::write("test");
	Log::write("line 2");
	
	win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Open GL Base Proj", nullptr, nullptr);
	if (!win)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	if (glewInit())
		return -1;
	
	glfwMakeContextCurrent(win);
	
	while (!glfwWindowShouldClose(win))
	{
		render();
		
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	
	glfwTerminate();
	exit(EXIT_SUCCESS);
	
	return 0;
}
