#include "Display.hpp"

Display::Display(std::string title, unsigned int width, unsigned int height, bool resizable) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);
    
    mWidth = width;
    mHeight = height;
    mTitle = title;
    mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
    if (mWindow == nullptr)
        throw "Display: Unable to Initialise GLFW3";
    glfwMakeContextCurrent(mWindow);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        throw "Display: Unable to Create the OpenGL Context";
}
bool Display::shouldWindowClose() {
    return glfwWindowShouldClose(mWindow);
}
void Display::clearScreen(float r, float g, float b, float a) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r, g, b, a);
}
void Display::pollEvents() {
    glfwSwapBuffers(mWindow);
    glfwPollEvents();
}
Display::~Display() {
    glfwDestroyWindow(mWindow);
}
void Display::quit() {
    glfwSetWindowShouldClose(mWindow, GLFW_TRUE);
    glfwTerminate();
}
