
#include"SimpleLadder.h"
#include<fstream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);


GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

int main(void)
{
	float ladderWidht, ladderHight;
	float hightStep, footDepth;
	std::cout
		<< "*****************************************\n"
		<< "*********** All input must be ***********\n"
		<< "*********** in centimeters! *************\n"
		<< "*****************************************\n\n";

	std::cout << "Insert ladder widht: ";
	std::cin >> ladderWidht;
	
	std::cout << "Insert ladder hight: ";
	std::cin >> ladderHight;
	
	std::cout << "Insert step hight: ";
	std::cin >> hightStep;
	
	std::cout << "Insert foot depth: ";
	std::cin >> footDepth;
	
	Ladder * stairs = new SimpleLadder(ladderWidht, footDepth, hightStep, ladderHight);
	
	std::cout
		<< "Sucsessful created ladder:\n"
		<< "Ladder widht: " << stairs->widthLadder() << std::endl
		<< "Ladder hight: " << stairs->hightLadder() << std::endl
		<< "Step hight: " << stairs->hightStep() << std::endl
		<< "Foot depth: " << stairs->footDepth() << std::endl
		<< "Ladder type: " << stairs->type() << std::endl
		<< "Steps number: " << stairs->numberOfSteps() << std::endl;

	std::string fileName = "SimpleLadder.txt";
	stairs->save(fileName, 0.0f, 0.0f, 0.0f);



	GLFWwindow *window;

	// Initialize the library
	if (!glfwInit())
	{
		delete stairs;
		return -1;
	}

	// Create a windowed mode window
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ladder", NULL, NULL);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);


	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
	GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;

	
	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// Render OpenGL here

		glPushMatrix();
		glTranslatef(halfScreenWidth, halfScreenHeight, -500);
		glRotatef(rotationX, 1, 0, 0);
		glRotatef(rotationY, 0, 1, 0);
		glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

		stairs->draw(halfScreenWidth, halfScreenHeight, -500);
		
		glPopMatrix();


		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	delete stairs;

	return 0;
}


void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	const GLfloat rotationSpeed = 10;

	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			rotationX -= rotationSpeed;
			break;
		case GLFW_KEY_DOWN:
			rotationX += rotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationY += rotationSpeed;
			break;
		case GLFW_KEY_LEFT:
			rotationY -= rotationSpeed;
			break;
		}
	}
}
