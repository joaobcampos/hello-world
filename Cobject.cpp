#include "Cobject.h"



void Cobject::set_projection(const glm::mat4 &proj){
	Projection = proj;
}
	
void Cobject::set_view(const glm::mat4 &vw_){
	View = vw;
}
	
void Cobject::set_model(const glm::mat4 &mdl){
	Model = &mdl;
}	
		
void Cobject::bind_buffer(GLuint &buf, GLfloat * data_buffer){
	glGenBuffers(1, &buf);
	glBindBuffer(GL_ARRAY_BUFFER, buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data_buffer), data_buffer, GL_STATIC_DRAW);
}

void Cobject::bind_vertex_buffer(GLfloat * data_buffer){
	bind_buffer(&vertexbuffer, GLfloat data_buffer);
}
		
void Cobject::bind_color_buffer(GLfloat * data_buffer){
	bind_buffer(&colorxbuffer, GLfloat data_buffer);
}

glm::mat4 Cobject::get_mvp(){
	return Projection * View_triangle * Model_triangle;
}

GLuint Cobject::get_vertexbuffer(){
	return vertexbuffer;
}

GLuint Cobject::get_colorbuffer(){
	return colorbuffer;
}
