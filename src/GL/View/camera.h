#pragma once
#include<gl.h>
#include<glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtx/transform.hpp>
#include<type_ptr.hpp>
#include<GL/Keyboard/key/input.h>

class camera
{
private:
	GLint location = {};
	GL::input device = {};
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.3f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -0.1f);
	glm::vec3 derection = glm::normalize(cameraPos - glm::vec3(0.0f, 0.0f, 0.0f));
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 rightPos = glm::normalize(up - derection);
	glm::vec3 directionCam;
	glm::mat4 look;
	glm::mat4 perspective; 
	glm::mat4 rotate;
public:
	void transform_matrix(GLFWwindow *window, GLuint program,GLFWmonitor* monitor, GLFWcursor *cursor);
	void translate_matrix(GLuint program, const char* name);
	void perspective_matrix(GLuint program, const char* name);
	void rotateCam(GLuint program,const char * name);
};

