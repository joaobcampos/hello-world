#include "Cobject.h"

Cobject::Cobject(glm::mat4 proj, glm::mat4 vw, glm::mat4 mdl,
			   	GLuint vb, GLuint cb,
				GLfloat g_v_buffer_data[], int v_buffer_size,
				GLfloat g_c_buffer_data[], int c_buffer_size
			   ) : vertexbuffer(0) , colorbuffer(0) {
	Projection = proj;
	View = vw;
	Model = mdl;
		// Intrinsic information of the object (position and color)
	
		
	g_vertex_buffer_data = new GLfloat(v_buffer_size);
	g_color_buffer_data = new GLfloat(c_buffer_size);
	
	for(int h = 0; h < v_buffer_size; ++h){
		g_vertex_buffer_data[h] = g_v_buffer_data[h];
	}
	
	for(int h = 0; h < v_buffer_size; ++h){
		g_color_buffer_data[h] = g_c_buffer_data[h];
	}
	
	vertex_buffer_size = v_buffer_size;
	color_buffer_size = c_buffer_size;
}

Cobject::~Cobject(){
	delete [] g_vertex_buffer_data;
	delete [] g_color_buffer_data;
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
		
void Cobject::bind_buffer(GLuint &buf, GLfloat data_buffer[]){
	glGenBuffers(1, &buf);
	glBindBuffer(GL_ARRAY_BUFFER, buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data_buffer), data_buffer, GL_STATIC_DRAW);
}

void Cobject::bind_vertex_buffer(GLfloat data_buffer[]){
	bind_buffer(vertexbuffer, data_buffer);
}
		
void Cobject::bind_color_buffer(GLfloat data_buffer[]){
	bind_buffer(colorbuffer, data_buffer);
}

glm::mat4 Cobject::get_mvp(){
	return Projection * View * Model;
}

GLuint Cobject::get_vertexbuffer(){
	return vertexbuffer;
}

GLuint Cobject::get_colorbuffer(){
	return colorbuffer;
}

void Cobject::enable_vertex_buffer(){
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void Cobject::enable_color_buffer(){
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void Cobject::disable_vertex_buffer(){
	glDisableVertexAttribArray(0);
}

void Cobject::disable_color_buffer(){
	glDisableVertexAttribArray(1);
}

void Cobject::draw(int n){
	glDrawArrays(GL_TRIANGLES, 0, n*3); 
}
