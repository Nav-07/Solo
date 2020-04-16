#pragma once
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <string>

class Solo_EntryPoint {
private:
    GLFWwindow* mWindow;
    bool mIsOpen = false;
public:
    void constructWindow(std::string title, unsigned int width, unsigned int height);
    void start();
    ~Solo_EntryPoint();
protected:
    virtual void OnInit();
    virtual void OnHandleEvents();
    virtual void OnUpdate();
    virtual void OnRender();
    virtual void OnDestroy();
    
    void CloseWindow();
};
