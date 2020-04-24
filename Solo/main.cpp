#include "Solo.hpp"

class Example : public Solo_EntryPoint {
private:
    Model* model;
    Shader* shader;
protected:
    void OnInit() override {
        shader = new Shader("res/Vertex.txt", "res/Fragment.txt");
        model = new Model({0.0f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f});
    }
    void OnHandleEvents() override {}
    void OnUpdate() override {}
    void OnRender() override {
        shader->UseShader();
        model->OnRender();
    }
    void OnDestroy() override {
        delete model;
        delete shader;
    }
};
int main() {
    Example example;
    example.constructWindow("Window", 1280, 720);
    example.start();
}
