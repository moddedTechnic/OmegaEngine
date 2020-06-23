#pragma once

#include "Omega/Layer.h"

#include "imgui.h"

namespace Omega {

	class OpenGLLayer : public Layer {
	public:
		OpenGLLayer()
			: Layer("OpenGL Info") {}

		virtual void OnAttach() override {
			OM_CORE_INFO("OpenGL Info:");
			OM_CORE_INFO("  ~ Vendor:   {0}", glGetString(GL_VENDOR));
			OM_CORE_INFO("  ~ Renderer: {0}", glGetString(GL_RENDERER));
			OM_CORE_INFO("  ~ Version:  {0}", glGetString(GL_VERSION));
		}

		virtual void OnImGuiRender() override {
			ImGui::Begin("OpenGL Info");
			ImGui::Text("Vendor: %s", glGetString(GL_VENDOR));
			ImGui::Text("Renderer: %s", glGetString(GL_RENDERER));
			ImGui::Text("Version: %s", glGetString(GL_VERSION));
			ImGui::End();
		}
	};

}
