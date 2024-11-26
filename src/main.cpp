#include "engine.hpp"

class App {
public:
	App();

	~App() = default;
private:
};

class UI {
public:
	UI();

	~UI() = default;

	void show_scene_window();
private:
};

int main(int argc, char *argv[]) {
	Engine engine { Engine() };
	engine.init();
	engine.run();
	engine.shutdown();
    return 0;
}
