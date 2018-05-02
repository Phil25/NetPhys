#include "../include/phys.h"

float abs(float val){
	return val < 0 ? -val : val;
}

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

	b->vel.y -= g *b->mass;
	if(b->pos.y < b->radius){
		b->vel.y *= -b->dampening;
		b->pos.y = b->radius;
	}

	update_position(dt, b);
}

void phys::update_position(float dt, body* b) const{
	const vec2d pos_dt = {b->vel.x *dt, b->vel.y *dt};
	b->add_pos(pos_dt);
}
