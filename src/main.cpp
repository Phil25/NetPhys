#include <iostream>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define BACKGROUND_COLOR 0.85f, 0.85f, 0.85f, 1.0f

GLFWwindow* window = nullptr;

static void glfw_error(int err, const char* desc);
static void on_key(GLFWwindow*, int key, int scancode, int action, int mods);

bool gl_init(){

	glfwSetErrorCallback(glfw_error);
	if(!glfwInit())
		return false;

	window = glfwCreateWindow(640, 640, "Test", NULL, NULL);
	if(!window){
		glfwTerminate();
		return false;
	}

	glfwSetKeyCallback(window, on_key);
	glfwMakeContextCurrent(window);
	glClearColor(BACKGROUND_COLOR);

	return true;
}

int main(){

	if(!gl_init())
		return 1;

	int width, height;
	while(!glfwWindowShouldClose(window)){

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glOrtho(0, width, 0, height, 0, 1);

		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();



		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

static void glfw_error(int err, const char* desc){
	std::cerr << "Error " << err << ": " << desc << std::endl;
}

static void on_key(GLFWwindow* w, int key, int scancode, int action, int mods){
	(void)scancode;
	(void)mods;
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(w, GLFW_TRUE);
}
