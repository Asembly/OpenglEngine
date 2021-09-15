#pragma once
#include<gl.h>
#include<GLFW/glfw3.h>
#include<Engine/packet.h>
#define HEIGHT 600
#define WIDTH  600
#define TITLE "application"

class engine
{
private:
	GL::buffer buffer;
	GL::shader shader;
	GL::input device;
	GL::texture tex;

	GLFWwindow* window;
	GLFWmonitor* monitor;
	GLFWcursor* cursor;

	void loop_window();
	void context_window();
	void init_glew();
	void init_glfw();
	void objects();
public:
	void init_window();
};
