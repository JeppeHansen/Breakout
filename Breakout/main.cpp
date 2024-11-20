#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game.h"


const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char* argv[]) {

	glfwInit();

	glfwWindowHint(GLFW_RESIZABLE, false);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	Breakout.Init();

    while (!glfwWindowShouldClose(window))
    {
        
    }
	glfwTerminate();
	return 0;
}