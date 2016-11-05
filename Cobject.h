#ifndef COBJECT_H
#define COBJECT_H

class Cobject{
	public:
		Cobject(GLuint programID, std::string shaders) : binder(programID), shaders(shaders){};
		~Cobject();
	
		
	private:
		// Representation of the outside perspective
		glm::mat4 Projection;
		glm::mat4 View;
		glm::mat4 Model;
		// Intrinsic information of the object (position and color)
		GLuint vertexbuffer;
	 	GLuint colorbuffer;
}

#endif;