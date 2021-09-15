#include "camera.h"
#include<iostream>
void camera::transform_matrix(GLFWwindow * window,GLuint program,GLFWmonitor * monitor,GLFWcursor *cursor)
{
	device.keyCallback(window, 0, 0);
	device.mouseCallback(window, 0, 0, monitor, cursor);
	perspective_matrix(program, "perspective");
	translate_matrix(program,"translate");
	rotateCam(program, "rotateCam");
}
void camera::translate_matrix(GLuint program, const char* name)
{
	location = glGetUniformLocation(program, name);
	look = glm::lookAt(device.getPosCam(),cameraFront,up);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(look));
}
void camera::perspective_matrix(GLuint program, const char* name)
{
	location = glGetUniformLocation(program, name);
	perspective = glm::perspective(45.0f,1.0f,0.1f,100.0f);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(perspective));
}
void camera::rotateCam(GLuint program, const char* name)
{
	location = glGetUniformLocation(program, name);
	//rotate = glm::rotate(device.getAngel(), device.getRotateCam());
	//glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(rotate));
}