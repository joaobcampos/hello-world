// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Cscreen.h"
using namespace glm;


int main(){
	GLFWwindow * window = NULL;
	Cscreen * ptr_screen;
	double red = 0.0f; 
	double green = 0.0f; 
	double blue = 0.4f; 
	double alpha = 0.0f;
	double size_x = 1024; 
	double size_y = 768; 
	std::string title = "playgrond";
	window = ptr_screen->initialize(red, green, blue, alpha, size_x, size_y, title);
	if (window == NULL){
		std::cout << "Something wrong happened." << std::endl;
	}
	
	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
		} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );
	return 0;
}