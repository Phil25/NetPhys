#include <GLFW/glfw3.h>
#include "body.h"


#ifndef RENDERER_H
#define RENDERER_H


#define BACKGROUND_COLOR 0.25f, 0.25f, 0.25f, 1.0f

namespace renderer{
	const float pi = 3.1415926535f;
	const float tau = 6.28318530718f;
	const float step = tau/24;

	extern int width, height;
	extern GLFWwindow* window;

	namespace geo{
		void draw(const vec2d& p1, const vec2d& p2);
		vec2d get_circle_pos(const vec2d& o, float r, float ang);
		void render_body(body*);
	}

	GLFWwindow* init();
	void resize();
	void clear();
	void update();

}


#endif
