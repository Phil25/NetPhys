#include "../include/renderer.h"

renderer& renderer::get_instance(){
	static renderer instance;
	return instance;
}
