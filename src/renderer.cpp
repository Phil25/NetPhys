#include "../include/renderer.h"

namespace renderer{
	int width, height;
	GLFWwindow* window;
}

void renderer::geo::draw(const vec2d& p1, const vec2d& p2){
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
}

vec2d renderer::geo::get_circle_pos(const vec2d& o, float r, float ang){
	return vec2d{o.x +r *cos(ang), o.y +r *sin(ang)};
}

void renderer::geo::render_body(body* b){
	glBegin(GL_POLYGON);
	float ang = 0.0f;
	vec2d last = get_circle_pos(b->pos, b->radius, ang);
	for(ang = step; ang < tau; ang += step){
		vec2d p = get_circle_pos(b->pos, b->radius, ang);
		draw(last, p);
		last = p;
	}

	glEnd();
}

GLFWwindow* renderer::init(){
	if(!glfwInit())
		return NULL;

	window = glfwCreateWindow(640, 640, "Test", NULL, NULL);
	if(!window){
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);
	glClearColor(BACKGROUND_COLOR);

	return window;
}

void renderer::resize(){
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glOrtho(0, width, 0, height, 0, 1);
}

void renderer::clear(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void renderer::update(){
	auto end = body::end();
	for(auto it = body::begin(); it != end; it++)
		geo::render_body(it->second);
}
