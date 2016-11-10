#ifndef COBJECT_H
#define COBJECT_H


#include <GL/glew.h>
#include <glm/glm.hpp>

class Cobject{
	public:
		Cobject(glm::mat4 proj, glm::mat4 vw, glm::mat4 mdl,
				GLfloat g_v_buffer_data[], 
				GLfloat g_c_buffer_data[] 
			   );
		~Cobject();
	
		void set_projection(const glm::mat4 &proj);
	
		void set_view(const glm::mat4 &vw);
	
		void set_model(const glm::mat4 &mdl);
		
		
		
		glm::mat4 get_mvp();
		void enable_buffers();
		void disable_buffers();
		void delete_buffers();
		void draw(int n);
		
	private:
		// Representation of the outside perspective
		glm::mat4 Projection;
		glm::mat4 View;
		glm::mat4 Model;
		// Intrinsic information of the object (position and color)
		GLuint * buffer;
		
		void bind_buffer(GLuint &buf, GLfloat data_buffer[], int size);
};

#endif
