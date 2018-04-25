#include "../include/phys.h"
#include <iostream>

phys& phys::get_instance(){
	static phys instance;
	return instance;
}

void phys::update(float dt) const{
	auto end = body::end();
	for(auto it = body::begin(); it != end; it++)
		update_body(dt, it->second);
}

void phys::update_body(float dt, body* b) const{

	const vec2d pos = b->get_pos();
	b->vel.y -= g *b->mass;
	if(pos.y < b->radius)
		b->vel.y *= -0.8;

	update_position(dt, b);
}

void phys::update_position(float dt, body* b) const{
	const vec2d pos_dt = {b->vel.x *dt, b->vel.y *dt};
	b->add_pos(pos_dt);
}
