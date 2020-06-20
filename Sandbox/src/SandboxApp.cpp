#include <Omega.h>

#include "imgui/imgui.h"

class ExampleLayer : public Omega::Layer {
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {
		if (Omega::Input::IsKeyPressed(OM_KEY_TAB))
			OM_INFO("Tab key pressed");
	}

	virtual void OnImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello world");
		ImGui::End();
		ImGui::End();
	}

	void OnEvent(Omega::Event& event) override {}
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
