#include <map>
#include "vec2d.h"

#ifndef BODY_H
#define BODY_H


class body{

	static std::map<unsigned int, body*> bodies;
	static unsigned int next_id;

	unsigned int id;

public:
	vec2d pos;
	vec2d vel;

	float mass;
	float radius;
	float dampening = 0.75; // force dampening during collision

private:
	body(vec2d pos, float mass, float radius);

public:
	~body();
	body(body const&) = delete;
	void operator=(body const&) = delete;

	static std::map<unsigned int, body*>::iterator begin();
	static std::map<unsigned int, body*>::iterator end();

	static body* spawn(float mass, float radius);
	static body* spawn(const vec2d& pos, float mass, float radius);
	void kill();

	void add_pos(const vec2d&);
	void add_vel(const vec2d&);

	int get_id();

	bool colliding(body*);

};


#endif
