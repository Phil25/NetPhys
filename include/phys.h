#include "body.h"

#ifndef PHYS_H
#define PHYS_H


#define BOTTOM phys::edges[0]
#define LEFT phys::edges[1]
#define TOP phys::edges[2]
#define RIGHT phys::edges[3]

namespace phys{
	extern float edges[4];

	namespace engine{
		void collision(body* b, bool horizontal);
		void collision(body* a, body* b);
		void update_position(float dt, body* b);
		void update_body(float dt, body* b);
	}

	void resize(float, float, float, float);
	void update(float);
}


#endif
