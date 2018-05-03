#include <math.h>
#include <ostream>

#ifndef VEC2D_H
#define VEC2D_H


struct vec2d{
	float x, y;

	vec2d operator+(const vec2d& other) const{
		return vec2d{x +other.x, y +other.y};
	}

	vec2d operator-(const vec2d& other) const{
		return vec2d{x -other.x, y -other.y};
	}

	vec2d operator*(const float val) const{
		return vec2d{x *val, y *val};
	}

	vec2d operator/(const float val) const{
		return vec2d{x /val, y /val};
	}

	void operator+=(const vec2d& other){
		x += other.x;
		y += other.y;
	}

	void operator-=(const vec2d& other){
		x -= other.x;
		y -= other.y;
	}

	void operator*=(const float val){
		x *= val;
		y *= val;
	}

	inline void invert(){
		x = -x;
		y = -y;
	}

	inline float length(bool squared=false) const{
		float lensqr = x*x + y*y;
		return squared ? lensqr : std::sqrt(lensqr);
	}

	inline void normalize(){
		float len = length();
		x /= len;
		y /= len;
	}

	inline float dot(const vec2d& other) const{
		return x*other.x + y*other.y;
	}

	inline float distance(const vec2d& other, bool squared=false) const{
		float dx = other.x -x;
		float dy = other.y -y;
		float distsqr = dx*dx + dy*dy;
		return squared ? distsqr : std::sqrt(distsqr);
	}

	friend inline std::ostream& operator<<(std::ostream& os, const vec2d& v){
		return os << '(' << v.x << ", " << v.y << ')';
	}
};


#endif
