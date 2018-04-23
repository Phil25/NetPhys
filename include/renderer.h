

#ifndef RENDERER_H
#define RENDERER_H


class renderer{

private:
	renderer(){}

public:
	static renderer& get_instance();

	renderer(renderer const&) = delete;
	void operator=(renderer const&) = delete;



};


#endif
