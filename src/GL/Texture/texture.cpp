#include "texture.h"
#include <stb_image.h>

void GL::texture::bind_vbo()
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_VERTEX_ARRAY, vbo);
}
void GL::texture::bind_texture()
{
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
}
void GL::texture::load_images(const char * path)
{
	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,width,height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE,NULL,nullptr);
	glBufferData(GL_VERTEX_ARRAY, points.size() * sizeof(float), points.data(),GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
}
void GL::texture::parametr_texture()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
}
void GL::texture::texture_init(std::vector<GLfloat>points)
{
	this->points = points;
	bind_vbo();
	bind_texture();
	parametr_texture();
	load_images("C:/Users/darkl/Desktop/Engine/Opengl/src/GL/Texture/textures/Без названия.jpg");
}