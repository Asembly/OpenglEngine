#pragma once
#include<gl.h>
#include<vector>

namespace GL
{
	class texture
	{
	private:
		GLuint vbo;
		GLuint tex;
		GLuint loc;
		std::vector<GLfloat>points;
		int width, height, nrChannels;

		void bind_vbo();
		void bind_texture();
		void parametr_texture();
		void load_images(const char* path);
	public:
		void texture_init(std::vector<GLfloat>points);
	};
}
