#include "../include/input.h"

using namespace input;

void input::init(GLFWwindow* window){
	glfwSetKeyCallback(window, input::process);

	cmds.insert(cmd_pair(GLFW_KEY_ESCAPE, new cmd::quit));
	cmds.insert(cmd_pair(GLFW_KEY_SPACE, new cmd::spawn));
}

void input::process(GLFWwindow* w, int key, int scancode, int action, int mods){
	(void)w;
	(void)scancode;
	(void)mods;
	if(action == GLFW_PRESS && cmds.count(key))
		cmds.at(key)->exec(w);
}
