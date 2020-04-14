#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Display/Display.hpp"

#include "Solo/Solo_EntryPoint.hpp"

void runGame(Solo_EntryPoint* entrypoint) {
    float deltaTime, currentFrame, lastFrame;
    deltaTime = currentFrame = lastFrame = 0.0f;
    
    entrypoint->Init();
    while (!entrypoint->mShouldClose) {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        entrypoint->HandleEvents();
        entrypoint->Update(deltaTime);
        entrypoint->Render();
    }
    delete entrypoint;
}
