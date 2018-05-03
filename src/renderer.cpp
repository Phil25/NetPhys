#include "../include/renderer.h"
#include "../include/body.h"
#include <GL/gl.h>
#include <math.h>

renderer& renderer::get_instance(){
	static renderer instance;
	return instance;
}

void renderer::update() const{
	auto end = body::end();
	for(auto it = body::begin(); it != end; it++)
		render_body(it->second);
}

vec2d get_circle_pos(const vec2d& o, float r, float ang){
	return vec2d{o.x +r *cos(ang), o.y +r *sin(ang)};
}

void renderer::render_body(body* b) const{
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

void renderer::draw(const vec2d& p1, const vec2d& p2) const{
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
}
