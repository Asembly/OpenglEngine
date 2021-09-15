#include "input.h"
#include<iostream>

void GL::input::keyCallback(GLFWwindow* window, GLint key,GLint action)
{
	if (key < 0)
	{
	    std::printf("Error: This key not have on the keyboard...");
	}
	else
	{
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			position_cam += speed * glm::vec3(0.0f, 0.0f,1.0f);
		}
		else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			position_cam -= speed * glm::vec3(0.0f, 0.0f,1.0f);
		}
	}
}
void GL::input::mouseCallback(GLFWwindow* window, GLint key, GLint action,GLFWmonitor *monitor,GLFWcursor*cursor)
{
}
GLint GL::input::getStateEventsKeyboard(GLFWwindow* window,GLuint key)
{
	if (key < 0)
	{
		std::printf("Error: This key not have on the input device...");
	}
	else
	{
		state = glfwGetKey(window, key);
		return state;
	}
	return 0;
}
glm::vec3 GL::input::getPosCam()
{
	return position_cam;
}