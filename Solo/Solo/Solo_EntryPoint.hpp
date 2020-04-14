#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

/*
 This is an optional class, The Game or Application can run without this entry_point, though you have to do everything on your own.
*/
class Solo_EntryPoint {
private:
public:
    virtual void Init();
    virtual void HandleEvents();
    virtual void Update(float deltaTime);
    virtual void Render();
    virtual void Destroy();
    bool mShouldClose = false;
};
