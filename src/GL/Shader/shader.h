#pragma once
#include<GL/Shader/packet.h>

namespace GL
{
class shader
{
	private:
		GLuint program;
		GLuint sh;
		Math math = {};
		camera cam = {};
		std::vector<GLuint>mShader;
		void log();
	public:
	void uniform(GLFWwindow * window, GLFWmonitor* monitor, GLFWcursor* cursor);
	void load_shader(GLenum target,const char * path);
	void create_program();
};
}