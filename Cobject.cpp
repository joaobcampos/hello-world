#include "Cobject.h"

Cobject::Cobject(GLuint programID, std::string shaders) : binder(programID), shaders(shaders){};
Cobject::~Cobject(){};
	
		
	private:
		glm::mat4 Projection; //_triangle = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		// Camera matrix
		glm::mat4 View; //_triangle       = glm::lookAt(
								glm::vec3(5,0,0), // Camera is at (4,3,-3), in World Space
								glm::vec3(0,0,0), // and looks at the origin
								glm::vec3(0,0,-1)  // Head is up (set to 0,-1,0 to look upside-down)
						   );
		// Model matrix : an identity matrix (model will be at the origin)
		glm::mat4 Model;//      = glm::mat4(1.0f);//  + glm::mat4(glm::vec4(0.0f, 0.0f, 1.0f, 0.0f); glm::vec4(1.0f, 0.0f, 1.0f, 0.0f); glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
		GLfloat * g_vertex_buffer;
	 	GLfloat * g_color_buffer
}
