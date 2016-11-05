#ifndef CSCREEN_H
#define CSCREEN_H

#include <string>

class GLFWwindow;
class Cscreen{
	public:
		Cscreen();
		~Cscreen();

		Cscreen * get_screen();
		GLFWwindow *  initialize(double red, double green, double blue, double alpha, double size_x, double size_y, std::string title);
	
	private:
		Cscreen * screen_ptr;
};
#endif