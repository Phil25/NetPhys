
#ifndef VEC2D_H
#define VEC2D_H


struct vec2d{
	float x, y;

	vec2d operator+(vec2d& other){
		return vec2d{x +other.x, y +other.y};
	}

	void operator+=(vec2d& other){
		x += other.x;
		y += other.y;
	}
};


#endif
