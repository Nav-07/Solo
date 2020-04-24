#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

class Shader {
private:
    unsigned int mShader, mVertex, mFragment;
    unsigned int CreateShader(std::string ShaderType, std::string File);
public:
    Shader(std::string Vertex, std::string Fragment);
    void UseShader();
    ~Shader();
};
