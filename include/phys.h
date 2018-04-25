#include "body.h"

#ifndef PHYS_H
#define PHYS_H


class phys{

	const float g = 9.81;

private:
	phys(){}

	void update_body(float, body*) const;
	void update_position(float, body*) const;

public:
	static phys& get_instance();

	phys(phys const&) = delete;
	void operator=(phys const&) = delete;

	void update(float) const;

};


#endif
