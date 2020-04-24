#include "Solo_EntryPoint.hpp"

void Solo_EntryPoint::constructWindow(std::string title, unsigned int width, unsigned int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Change This to a Dynamic Value
    
    mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (mWindow == nullptr)
        throw "Solo_EntryPoint: Unable to Initialise GLFW3!";
    glfwMakeContextCurrent(mWindow);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        throw "Solo_EntryPoint: Unable to Open an OpenGL Context!";
    mIsOpen = true;
}
void Solo_EntryPoint::start() {
    this->OnInit();
    while (mIsOpen) {
        if (glfwWindowShouldClose(mWindow))
            mIsOpen = false;
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(.0f, .0f, .0f, 1.0f);
        
        this->OnHandleEvents();
        this->OnUpdate();
        this->OnRender();
        
        glfwPollEvents();
        glfwSwapBuffers(mWindow);
    }
    this->OnDestroy();
}
Solo_EntryPoint::~Solo_EntryPoint() {
    glfwDestroyWindow(mWindow);
}

void Solo_EntryPoint::OnInit() {}
void Solo_EntryPoint::OnHandleEvents() {}
void Solo_EntryPoint::OnUpdate() {}
void Solo_EntryPoint::OnRender() {}
void Solo_EntryPoint::OnDestroy() {}

void Solo_EntryPoint::CloseWindow() {
    mIsOpen = false;
}
