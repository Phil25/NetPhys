#include <GLFW/glfw3.h>
#include <map>

#include "cmd.h"

#ifndef INPUT_H
#define INPUT_H


namespace input{

	typedef std::map<int, cmd::root*> cmd_map;
	typedef std::pair<int, cmd::root*> cmd_pair;

	namespace{
		cmd_map cmds;
	}

	void init(GLFWwindow*);
	void process(GLFWwindow* w, int key, int scancode, int action, int mods);

};


#endif
