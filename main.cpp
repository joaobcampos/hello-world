// Include standard headers
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Cscreen.h"
#include "Cobject.h"
#include "shader.h"
using namespace glm;

void scale_vertex(GLfloat * g_vertex_buffer_data, int size, double scale){
	for(int h = 0; h < size; ++h){
		g_vertex_buffer_data[h] = scale * g_vertex_buffer_data[h];
	}
}

void shake_randomly_plane_xy(GLfloat * g_vertex_buffer_data, int size, double var_x, double var_y){
	for(int h = 0; h < size; h = h + 3){
		if (g_vertex_buffer_data[h] + var_x < 2){
			g_vertex_buffer_data[h] = g_vertex_buffer_data[h] + var_x;
		}
		if (g_vertex_buffer_data[h + 1] + var_y < 2){
			g_vertex_buffer_data[h + 1] = g_vertex_buffer_data[h + 1] + var_y;
		}
	}
}

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
	GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader" );
	
	GLfloat g_vertex_buffer_data[] = { 
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f
	};
	std::cout << "Debugging point 1." << std::endl;
	// One color for each vertex. They were generated randomly.
	GLfloat g_color_buffer_data[] = { 
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};
	std::cout << "Debugging point 2." << std::endl;
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	Cobject cube(glm::perspective(90.0f, 4.0f / 3.0f, 0.1f, 100.0f) , glm::lookAt(glm::vec3(5,0,0), glm::vec3(0,0,0), glm::vec3(0,0,-1) ), glm::mat4(1.0f),
			g_vertex_buffer_data, g_color_buffer_data, 108); 			
	
	std::cout << "Debugging point 3." << std::endl;
	glm::mat4 MVP   = cube.get_mvp();
	
	std::cout << "***************************************" << std::endl;
	std::cout << "Perspective matrix" << std::endl;
	for(int g = 0; g < 4; ++g){
		for(int h = 0; h < 4; ++h){
			std::cout << MVP[g][h] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "***************************************" << std::endl;
	std::cout << "Debugging point 7." << std::endl;
	std::random_device rd;
  	std::mt19937 rng(rd());
  	std::uniform_int_distribution<int> uni(-100,100);
	scale_vertex(g_vertex_buffer_data, 108, 0.5);
	cube.bind_new_vertex_buffer(g_vertex_buffer_data, 108);
	do{
		double var_x = uni(rng)/100;
		double var_y = uni(rng)/100;
		shake_randomly_plane_xy(g_vertex_buffer_data, 108, var_x, var_y);
		
		cube.bind_new_vertex_buffer(g_vertex_buffer_data, 108);
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		
		for(int h = 0; h < 108; ++h){
			std::cout << g_vertex_buffer_data[h] << " ";
			if ( (h + 1) % 3 == 0){
				std::cout << std::endl;
			}
		}
		
		
		
		cube.enable_buffers();
		GLuint * buf = cube.get_buffer();
		cube.draw(12);
		cube.disable_buffers();
		glfwSwapBuffers(window);
		glfwPollEvents();
		} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );
	return 0;
}
