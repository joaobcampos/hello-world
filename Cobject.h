#ifndef COBJECT_H
#define COBJECT_H


#include <GL/glew.h>
#include <glm/glm.hpp>

class Cobject{
	public:
		Cobject(glm::mat4 proj, glm::mat4 vw, glm::mat4 mdl,
			   	GLuint vb, GLuint cb,
				GLfloat g_v_buffer_data[], int v_buffer_size,
				GLfloat g_c_buffer_data[], int c_buffer_size
			   );
		~Cobject();
	
		void set_projection(const glm::mat4 &proj);
	
		void set_view(const glm::mat4 &vw);
	
		void set_model(const glm::mat4 &mdl);
		
		GLuint get_vertexbuffer();
		GLuint get_colorbuffer();
		void bind_vertex_buffer(GLfloat data_buffer[]);
		void bind_color_buffer(GLfloat data_buffer[]);
		glm::mat4 get_mvp();
		void enable_vertex_buffer();
		void enable_color_buffer();
		void disable_vertex_buffer();
		void disable_color_buffer();
		void draw(int n);
		
	private:
		// Representation of the outside perspective
		glm::mat4 Projection;
		glm::mat4 View;
		glm::mat4 Model;
		// Intrinsic information of the object (position and color)
		GLuint vertexbuffer;
	 	GLuint colorbuffer;
		
		GLfloat * g_vertex_buffer_data;
		GLfloat * g_color_buffer_data;
	
		int vertex_buffer_size;
		int color_buffer_size;
		
		void bind_buffer(GLuint &buf, GLfloat data_buffer[]);
};

#endif
