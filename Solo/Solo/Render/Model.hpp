#pragma once
#include <GL/glew.h>
#include <vector>

class Model {
private:
    std::vector<float> mVertices;
    unsigned int mVAO;
public:
    Model(std::vector<float> vertices);
    void OnRender();
    ~Model();
};
