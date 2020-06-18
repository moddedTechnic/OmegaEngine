#include <Omega.h>

class ExampleLayer : public Omega::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		OM_INFO("ExampleLayer::Update");
	}

	void OnEvent(Omega::Event& event) override {
		OM_TRACE("{0}", event);
	}
};


class Sandbox : public Omega::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {}
};


Omega::Application* Omega::CreateApplication() {
	return new Sandbox();
}
