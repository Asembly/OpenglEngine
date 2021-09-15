#pragma once
#include<gl.h>
#include<GLFW/glfw3.h>
#include<glm.hpp>

namespace GL
{
class input
{
	private:
		GLint state = {};
		int hats[18];
		GLFWjoystickfun callback;
		GLfloat speed = 0.6f;
		glm::vec3 position_cam = glm::vec3(0.0f,0.0f,-1.0f);
		glm::vec3 position_cam_up = glm::vec3(0.0f,0.0f,0.0f);
		glm::vec3 direction = glm::normalize(position_cam - glm::vec3(1.0f, 0.0f, 0.0f));
		glm::vec3 target = glm::normalize(direction - position_cam_up);

	public:
		void keyCallback(GLFWwindow* window, GLint key, GLint action);
		void mouseCallback(GLFWwindow* window, GLint key, GLint action, GLFWmonitor *monitor, GLFWcursor* cursor);
		void joystickCallback(GLFWwindow* window, GLint key, GLint action);
		GLint getStateEventsKeyboard(GLFWwindow* window, GLuint key);
		glm::vec3 getPosCam();
};
}
