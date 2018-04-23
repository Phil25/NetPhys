#include <map>
#include "vec2d.h"

#ifndef BODY_H
#define BODY_H


class body{

static std::map<unsigned int, body*> bodies;
static unsigned int next_id;

unsigned int id;
vec2d pos;

public:
	float mass;
	float radius;
	vec2d vel;

private:
	body(vec2d pos, float mass, float radius);

public:
	~body();
	body(body const&) = delete;
	void operator=(body const&) = delete;

	static body* spawn(float mass, float radius);
	static body* spawn(const vec2d& pos, float mass, float radius);
	void kill();

	void add_pos(vec2d&);
	void add_vel(vec2d&);

	vec2d get_pos();

};


#endif
