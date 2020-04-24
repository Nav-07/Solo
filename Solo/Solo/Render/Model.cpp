#include "Model.hpp"

Model::Model(std::vector<float> vertices) {
    this->mVertices = vertices;
    unsigned int mVBO;
    
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
}
void Model::OnRender() {
    glBindVertexArray(mVAO);
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size()/3);
    glBindVertexArray(0);
}
Model::~Model() {
    glDeleteVertexArrays(1, &mVAO);
}
