#include "buffer.h"
#include<iostream>

GL::buffer::~buffer()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}
void GL::buffer::bind_vao()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}
void GL::buffer::bind_vbo()
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}
void GL::buffer::data_buffer(std::vector<float>mPoints)
{
	this->mPoints = mPoints;
	bind_vao();
	bind_vbo();
	glBufferData(GL_ARRAY_BUFFER, mPoints.size() * sizeof(float), mPoints.data(), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(mBuffer.size(), 3, GL_FLOAT,GL_FALSE, 3 * sizeof(float),(void*)0);
	mBuffer.push_back(vbo);
	loger();
}
void GL::buffer::loger()
{
	std::cout << "vbo:" << mBuffer.size() << std::endl;
	std::cout << (mPoints.size() * sizeof(float)) * 8 << "(bit)" << std::endl;
}

void GL::buffer::indexing(std::vector<GLint>mIndex)
{
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndex.size() * sizeof(float), mIndex.data(), GL_DYNAMIC_DRAW);
}
void GL::buffer::import_texture()
{
	tex.texture_init(mPoints);
}
void GL::buffer::render(GLenum target,int count)
{
	for (int index = 0; index < mBuffer.size(); index++)
	{
		glEnableVertexAttribArray(index);
	}
	glDrawElements(target,count,GL_UNSIGNED_INT,0);
	for (int index = 0; index < mBuffer.size(); index++)
	{
		glDisableVertexAttribArray(index);
	}
}