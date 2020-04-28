#pragma once
#include <GL/glew.h>
#include <vector>

class Model {
private:
    std::vector<float> mVertices;
    std::vector<unsigned int> mIndices;
    unsigned int mVAO;
public:
    Model(std::vector<float> vertices, std::vector<unsigned int> indices);
    void OnRender();
    ~Model();
};
