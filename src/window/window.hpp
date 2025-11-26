#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <stdexcept>

enum WindowMode
{
	FULLSCREEN,
	WINDOWED
};

class Window
{
public:
	GLFWwindow* glwindow;

	int width;
	int height;
	const char* title;
	bool vSynvEnabled;


	WindowMode mode = WindowMode::WINDOWED;


	Window();
	~Window();

	void init();

	bool isShouldClose() const;
	void setShouldClose() const;
	void swapBuffers();
private:

};