
#ifndef VEC2D_H
#define VEC2D_H


struct vec2d{
	float x, y;

	vec2d operator+(const vec2d& other) const{
		return vec2d{x +other.x, y +other.y};
	}

	void operator+=(const vec2d& other){
		x += other.x;
		y += other.y;
	}

	void operator-(){
		x = -x;
		y = -y;
	}
};


#endif
