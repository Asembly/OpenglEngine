#include "shader.h"

void GL::shader::create_program()
{
	program = glCreateProgram();
	for (int i = 0; i < mShader.size(); i++)
	{
		glAttachShader(program,mShader[i]);
	}
	glLinkProgram(program);
	log();
	glUseProgram(program);
}
void GL::shader::load_shader(GLenum target,const char*path)
{
	std::fstream file;
	const GLchar* source;

	file.open(path);
	std::string st = { std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>() };
	source = st.c_str();

	sh = glCreateShader(target);
	glShaderSource(sh,1,&source,nullptr);
	glCompileShader(sh);

	mShader.push_back(sh);
}
void GL::shader::log()
{
	std::ofstream ofstr("Q:/VisualStudio/source/Engine/Opengl/src/GL/Shader/loger.txt",std::ios::trunc);
	GLint status;
	GLchar infolog[512];

	glGetShaderiv(sh, GL_COMPILE_STATUS,&status);
	if (!status)
	{
		glGetShaderInfoLog(sh, 512, NULL, infolog);
		ofstr<<"ERROR" << std::endl;
	}
	else
	{
		ofstr<<"info: shader was compiled"<<std::endl;
	}
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		ofstr << "info: program not was to linked" << std::endl;
	}
	else
	{
		ofstr << "info: program linked" << std::endl;
	}
	glGetProgramiv(program, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE)
	{
		ofstr<< "Shader not compiled\n";
	}
	else
	{
		ofstr << "Shader compiled\n";
	}
}
void GL::shader::uniform(GLFWwindow *window,GLFWmonitor * monitor,GLFWcursor * cursor)
{
	//cam.transform_matrix(window,program, monitor, cursor);
	math.translate(program);
	math.scale(program);
	math.rotate(program);
}