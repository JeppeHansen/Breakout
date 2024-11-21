#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game.h"

#include <iostream>

// Adjust viewport if user resizes the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char* argv[]) {

	// initialize GLFW lib 
	glfwInit(); 

	glfwWindowHint(GLFW_RESIZABLE, false); // Window not resizeable
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Using OpenGL version 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Gives access to OpenGL features without backwards-compatible features.

	// Create window object
	// Holds windowing data and is required by most of GLFW's other function
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", nullptr, nullptr);

	if (window == NULL) {
		std::cout << "Failed to initialize GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// Initialize GLAD
	// GLAD manages function pointers for OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	


	// OpenGL config
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); // Specifies the actual window for renderings


	Breakout.Init();

	// Render loop
    while (!glfwWindowShouldClose(window))
    {
		processInput(window);
        
    }
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
