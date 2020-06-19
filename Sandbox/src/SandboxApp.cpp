#include <Omega.h>

class ExampleLayer : public Omega::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		if (Omega::Input::IsKeyPressed(OM_KEY_TAB))
			OM_INFO("Tab key pressed");
	}

	void OnEvent(Omega::Event& event) override {}
};


class Sandbox : public Omega::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Omega::ImGuiLayer());
	}

	~Sandbox() {}
};


Omega::Application* Omega::CreateApplication() {
	return new Sandbox();
}
