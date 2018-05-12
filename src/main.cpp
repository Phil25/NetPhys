#include <iostream>
#include <string.h>
#include <GL/glew.h>

#include "../include/cmd.h"
#include "../include/input.h"
#include "../include/renderer.h"
#include "../include/phys.h"
#include "../include/body.h"

#define SEC_PER_UPDATE 0.01

static void glfw_error(int err, const char* desc);

int main(int, char**){

	GLFWwindow* window = renderer::init();
	if(window == NULL)
		return 1;

	double prev = glfwGetTime();
	double lag = 0.0;

	input::init(window);

	while(!glfwWindowShouldClose(window)){

		double curr = glfwGetTime();
		float dt = curr -prev;
		prev = curr;
		lag += dt;

		glfwPollEvents();

		renderer::resize();
		phys::resize(0, 0, renderer::height, renderer::width);
		renderer::clear();

		while(lag >= SEC_PER_UPDATE){
			phys::update(dt);
			lag -= SEC_PER_UPDATE;
		}

		renderer::update();

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

static void glfw_error(int err, const char* desc){
	std::cerr << "Error " << err << ": " << desc << std::endl;
}
