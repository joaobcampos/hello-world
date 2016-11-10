#include "Cobject.h"
#include <cstdlib>
#include <iostream>

Cobject::Cobject(glm::mat4 proj, glm::mat4 vw, glm::mat4 mdl,
				GLfloat g_v_buffer_data[], 
				GLfloat g_c_buffer_data[] 
			   ){

	Projection = proj;
	View = vw;
	Model = mdl;
	
	buffer = new GLuint(2);

	glGenBuffers(2, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_v_buffer_data), g_v_buffer_data, GL_STATIC_DRAW);

	GLuint colorbuffer;
	
	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_c_buffer_data), g_c_buffer_data, GL_STATIC_DRAW);
}

Cobject::~Cobject(){
	glDeleteBuffers(2, buffer);
}

void Cobject::set_projection(const glm::mat4 &proj){
	Projection = proj;
}
	
void Cobject::set_view(const glm::mat4 &vw){
	View = vw;
}
	
void Cobject::set_model(const glm::mat4 &mdl){
	Model = mdl;
}	
		

glm::mat4 Cobject::get_mvp(){
	return Projection * View * Model;
}


void Cobject::enable_buffers(){
	if (buffer != NULL){
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	}
}

void Cobject::disable_buffers(){
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Cobject::delete_buffers(){
	glDeleteBuffers(2, buffer);
}

void Cobject::draw(int n){
	glDrawArrays(GL_TRIANGLES, 0, n*3); 
}
