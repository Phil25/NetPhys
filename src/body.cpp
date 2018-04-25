#include "../include/body.h"

unsigned int body::next_id = 0;
std::map<unsigned int, body*> body::bodies;

body::body(vec2d pos, float mass, float radius):
	id(++next_id),
	pos(pos),
	mass(mass),
	radius(radius)
{}

body::~body(){
	bodies.erase(this->id);
}

// static
std::map<unsigned int, body*>::iterator body::begin(){
	return body::bodies.begin();
}

// static
std::map<unsigned int, body*>::iterator body::end(){
	return body::bodies.end();
}

// static
body* body::spawn(float mass, float radius){
	vec2d pos = vec2d{0, 0};
	return spawn(pos, mass, radius);
}

// static
body* body::spawn(const vec2d& pos, float mass, float radius){
	body* new_body = new body(pos, mass, radius);
	std::pair<unsigned int, body*> entry(new_body->id, new_body);
	bodies.insert(entry);
	return new_body;
}

void body::kill(){
	bodies.erase(this->id);
	delete this;
}

void body::add_pos(const vec2d& pos){
	this->pos += pos;
}

void body::add_vel(const vec2d& vel){
	this->vel += vel;
}

vec2d body::get_pos(){
	return this->pos;
}
