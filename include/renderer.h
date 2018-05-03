#include "body.h"


#ifndef RENDERER_H
#define RENDERER_H


class renderer{

	const float pi = 3.1415926535f;
	const float tau = 6.28318530718f;

	const float step = tau/24;

private:
	renderer(){}

public:
	static renderer& get_instance();

	renderer(renderer const&) = delete;
	void operator=(renderer const&) = delete;

	void update() const;
	void render_body(body*) const;

private:
	void draw(const vec2d&, const vec2d&) const;

};


#endif
