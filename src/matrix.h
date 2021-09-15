#pragma once
#include<gl.h>
#include<glm.hpp>
#include<gtx/transform.hpp>
#include<gtc/matrix_transform.hpp>
#include<type_ptr.hpp>
//#include<vec3.hpp>

class Math
{
private:
	GLfloat matrix[4][4];
public:
	Math()
	{
		matrix[0][0] = 0.0f;
		matrix[1][0] = 0.0f;
		matrix[2][0] = 0.0f;
		matrix[3][0] = 0.0f;

		matrix[0][1] = 0.0f;
		matrix[1][1] = 0.0f;
		matrix[2][1] = 0.0f;
		matrix[3][1] = 0.0f;

		matrix[0][2] = 0.0f;
		matrix[1][2] = 0.0f;
		matrix[2][2] = 0.0f;
		matrix[3][2] = 0.0f;

		matrix[0][3] = 0.0f;
		matrix[1][3] = 0.0f;
		matrix[2][3] = 0.0f;
		matrix[3][3] = 0.0f;
	}
	void translate(GLuint program)
	{
		matrix[0][0] = 1.0f;
		matrix[1][1] = 1.0f;
		matrix[2][2] = 1.0f;
		matrix[3][3] = 1.0f;

		matrix[0][3] = 0.0f;
		matrix[1][3] = 0.0f;
		matrix[2][3] = 0.0f;

		GLuint location = glGetUniformLocation(program, "translate");
		glUniformMatrix4fv(location, 1, GL_FALSE,&matrix[0][0]);
	}
	void scale(GLuint program)
	{
		matrix[0][0] = 0.5f;
		matrix[1][1] = 0.5f;
		matrix[2][2] = 0.0f;

		matrix[3][3] = 1.0f;

		GLuint location = glGetUniformLocation(program, "scale");
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
	}
	GLfloat pos = 0.0f;
	void rotate(GLuint program)
	{
		pos+=0.01;
		matrix[0][0] = 1.0f;

		matrix[1][1] = cos(pos);

		matrix[2][1] = sin(pos);

		matrix[1][2] = -sin(pos);

		matrix[2][2] = cos(pos);
		//matrix[1][1] = 1.0f;
		//matrix[2][2] = 1.0f;
		matrix[3][3] = 1.0f;

		GLuint location = glGetUniformLocation(program, "rotate");
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
	}
};
