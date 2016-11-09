#ifndef COBJECT_H
#define COBJECT_H

class GLfloat;

class Cobject{
	public:
		Cobject(GLuint vb, GLuint cb, const glm::mat4 &proj, const glm::mat4 &vw_, const glm::mat4 &mdl) : vertexbuffer(vb), colorbuffer(cb), Projection(proj), View(vw), Model(mdl){};
		~Cobject();
	
		void set_projection(const glm::mat4 &proj){
			Projection = proj;
		}
	
		void set_view(const glm::mat4 &vw_){
			View = vw;
		}
	
		void set_model(const glm::mat4 &mdl){
			Model = &mdl;
		}	
		
		GLuint get_vertexbuffer();
		GLuint get_colorbuffer();
		void bind_vertex_buffer(GLfloat data_buffer[]);
		void bind_vertex_buffer(GLfloat data_buffer[]);
		glm::mat4 get_mvp();
		
	private:
		// Representation of the outside perspective
		glm::mat4 Projection;
		glm::mat4 View;
		glm::mat4 Model;
		// Intrinsic information of the object (position and color)
		GLuint vertexbuffer;
	 	GLuint colorbuffer;
		void bind_buffer(GLuint &buf, GLfloat data_buffer[]);
}

#endif;
