#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Display {
private:
    unsigned int mWidth, mHeight;
    std::string mTitle;
    GLFWwindow* mWindow;
public:
    Display(std::string title, unsigned int width, unsigned int height, bool resizable);
    bool shouldWindowClose();
    void clearScreen(float r, float g, float b, float a);
    void pollEvents();
    ~Display();
    
    void quit();
};
