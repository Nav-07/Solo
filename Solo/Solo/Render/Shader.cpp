#include "Shader.hpp"

unsigned int Shader::CreateShader(std::string ShaderType, std::string File) {
    int success; GLchar infolog[1024];
    unsigned int ShaderID = glCreateShader(ShaderType == "VERTEX" ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    std::fstream ShaderFile(File);
    std::string Code;
    if (!ShaderFile.is_open())
        throw "Shader File Doesn't Exist";
    else {
        std::stringstream sstr; sstr << ShaderFile.rdbuf();
        Code = sstr.str();
        ShaderFile.close();
    }
    const char* CodePointer = Code.c_str();
    glShaderSource(ShaderID, 1, &CodePointer, nullptr);
    glCompileShader(ShaderID);
    glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(ShaderID, 1024, nullptr, infolog);
        std::cout << ShaderType << ": " << infolog << std::endl;
    }
    return ShaderID;
}
Shader::Shader(std::string Vertex, std::string Fragment) {
    mVertex = CreateShader("VERTEX", Vertex);
    mFragment = CreateShader("FRAGMENT", Fragment);
    mShader = glCreateProgram();
    glAttachShader(mShader, mVertex);
    glAttachShader(mShader, mFragment);
    glLinkProgram(mShader);
    int success; char infolog[1024];
    glGetProgramiv(mShader, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(mShader, 1024, nullptr, infolog);
        std::cout << "Program: " << infolog << std::endl;
    }
    glDetachShader(mShader, mVertex);
    glDetachShader(mShader, mFragment);
    glDeleteShader(mVertex);
    glDeleteShader(mFragment);
}
void Shader::UseShader() {
    glUseProgram(mShader);
}
Shader::~Shader() {
    glDeleteProgram(mShader);
}
