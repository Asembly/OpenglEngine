#include<Engine/engine.h>

void engine::init_glfw()
{
	glfwInit();
}
void engine::init_glew()
{
	glewInit();
	glewExperimental = GL_TRUE;
} 
void engine::context_window()
{
	glfwMakeContextCurrent(window);
	init_glew();
	objects();
}
void engine::loop_window()
{
	while(!glfwWindowShouldClose(window))
	{
		shader.uniform(window,monitor,cursor);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		buffer.render(GL_QUADS,6);
		glClearColor(0,0.2,0.2,1.0f);
		glfwSwapBuffers(window);
	}
}
void engine::init_window()
{
	init_glfw();
	window = glfwCreateWindow(WIDTH,HEIGHT,TITLE,NULL,NULL);
	context_window();
	loop_window();
}
void engine::objects()
{
	buffer.data_buffer({ 0.5f,0.5f,0.0f,
						0.5f,-0.5f,0.0f,
						-0.5f,-0.5f,0.0f,
						-0.5f,0.5f,0.0f});
	tex.texture_init({ 0.0f, 0.0f,
				       1.0f, 0.0f,
				       1.0f, 1.0f,
				       0.0f, 1.0f });
	buffer.indexing({0,1,2,3});
	shader.load_shader(GL_VERTEX_SHADER, "C:/Users/darkl/Desktop/Engine/Opengl/src/GL/Shader/shader/shader.vertical");
	shader.load_shader(GL_FRAGMENT_SHADER, "C:/Users/darkl/Desktop/Engine/Opengl/src/GL/Shader/shader/shader.fragment");
	shader.create_program();
}