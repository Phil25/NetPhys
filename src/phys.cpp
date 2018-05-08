#include "../include/phys.h"

namespace phys{
	float edges[4];
}

void phys::engine::collision(body* b, bool horizontal){
	b->vel.x -= b->vel.x *2 *(horizontal ? 1 : 0);
	b->vel.y -= b->vel.y *2 *(horizontal ? 0 : 1);
}

void phys::engine::collision(body* a, body* b){
	vec2d delta = a->pos -b->pos;
	float dist = delta.length();
	delta *= ((a->radius +b->radius) -dist) /dist;

	delta.normalize();
	float vel = (a->vel -b->vel).dot(delta);

	// bodies moving away from each other already
	if(vel > 0.0f) return;

	float inv_mass = 1/a->mass + 1/b->mass;
	float dampening = a->dampening *b->dampening;

	float mag = (-(1.0f +dampening) *vel) /inv_mass;
	vec2d impulse = delta *mag;

	a->vel += impulse /a->mass;
	b->vel -= impulse /b->mass;
}

void phys::engine::update_position(float dt, body* b){
	const vec2d pos_dt = {b->vel.x *dt, b->vel.y *dt};
	b->add_pos(pos_dt);
}

void phys::engine::update_body(float dt, body* b){

	// other body collision
	for(auto it = body::begin(); it != body::end(); it++)
		if(it->second != b)
			if(b->colliding(it->second))
				collision(b, it->second);

	// screen bottom/top collision
	if(b->pos.y < b->radius || b->pos.y > TOP -b->radius)
		collision(b, false);

	// screen left/right collision
	if(b->pos.x < b->radius || b->pos.x > RIGHT -b->radius)
		collision(b, true);

	update_position(dt, b);
}

void phys::resize(float bottom, float left, float top, float right){
	BOTTOM = bottom;
	LEFT = left;
	TOP = top;
	RIGHT = right;
}

void phys::update(float dt){
	auto end = body::end();
	for(auto it = body::begin(); it != end; it++)
		engine::update_body(dt, it->second);
}
