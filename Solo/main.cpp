#include "Solo.hpp"

class Example : public Solo_EntryPoint {
protected:
    void OnInit() override {}
    void OnHandleEvents() override {}
    void OnUpdate() override {}
    void OnRender() override {}
    void OnDestroy() override {}
};
int main() {
    Example example;
    example.constructWindow("Window", 1280, 720);
    example.start();
}
