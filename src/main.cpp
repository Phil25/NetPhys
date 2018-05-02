#include <iostream>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/cmd.h"
#include "../include/input.h"
#include "../include/renderer.h"
#include "../include/phys.h"
#include "../include/body.h"

#define BACKGROUND_COLOR 0.25f, 0.25f, 0.25f, 1.0f
#define SEC_PER_UPDATE 0.01

GLFWwindow* window = nullptr;

static void glfw_error(int err, const char* desc);

bool gl_init(){

	glfwSetErrorCallback(glfw_error);
	if(!glfwInit())
		return false;

	window = glfwCreateWindow(640, 640, "Test", NULL, NULL);
	if(!window){
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	glClearColor(BACKGROUND_COLOR);

	return true;
}

void adjust_window(int& width, int& height){
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glOrtho(0, width, 0, height, 0, 1);
}

void clear_context(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

int main(){

	if(!gl_init())
		return 1;

	input::init(window);
	renderer& r = renderer::get_instance();
	phys& p = phys::get_instance();

	int width, height;
	double prev = glfwGetTime();
	double lag = 0.0;
	
	while(!glfwWindowShouldClose(window)){

		double curr = glfwGetTime();
		float dt = curr -prev;
		prev = curr;
		lag += dt;

		glfwPollEvents();

		adjust_window(width, height);
		clear_context();

		while(lag >= SEC_PER_UPDATE){
			p.update(dt);
			lag -= SEC_PER_UPDATE;
		}

		r.update();

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

static void glfw_error(int err, const char* desc){
	std::cerr << "Error " << err << ": " << desc << std::endl;
}
