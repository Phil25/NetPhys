#include <GLFW/glfw3.h>
#include "body.h"

#ifndef CMD_H
#define CMD_H

namespace cmd{

class root{

public:
	virtual ~root(){}
	virtual void exec(GLFWwindow*) = 0;

};

// quits the application
class quit : public root{

public:
	virtual void exec(GLFWwindow* w){
		glfwSetWindowShouldClose(w, GLFW_TRUE);
	}
};

// spawns a ball
class spawn : public root{

public:
	virtual void exec(GLFWwindow*){
		body::spawn(vec2d{200, 500}, 1, 25);
	}
};

} // end of namespace


#endif
