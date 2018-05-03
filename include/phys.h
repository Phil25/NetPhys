#include "body.h"

#ifndef PHYS_H
#define PHYS_H

#define BOTTOM phys::edges[0]
#define LEFT phys::edges[1]
#define TOP phys::edges[2]
#define RIGHT phys::edges[3]

class phys{

public:
	// screen edges
	// 0 - bottom, 1 - left, 2 - top, 3 - right
	static float edges[4];

private:
	phys(){}

public:
	static phys& get_instance();

	phys(phys const&) = delete;
	void operator=(phys const&) = delete;

	void update(float) const;

private:
	void update_body(float, body*) const;
	void collision(body*, bool) const;
	void collision(body*, body*) const;
	void update_position(float, body*) const;

};

#endif
