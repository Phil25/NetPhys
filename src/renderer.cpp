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

	const int quality = 30;
	const float step = pi2/quality;
	float ang = 0.0f;
	vec2d pos = b->get_pos();
	float r = b->radius;
	vec2d last = get_circle_pos(pos, r, ang);

	for(int i = 0; i <= quality; i++){
		vec2d p = get_circle_pos(pos, r, ang);
		glVertex2f(last.x, last.y);
		glVertex2f(p.x, p.y);
		last = p;
		ang += step;
	}

	glEnd();
}
