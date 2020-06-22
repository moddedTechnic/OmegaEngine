#pragma once

#include "Core.h"

#include "Window.h"
#include "Omega/LayerStack.h"
#include "Omega/Events/Event.h"
#include "Omega/Events/ApplicationEvent.h"

#include "Omega/ImGui/ImGuiLayer.h"

namespace Omega {
	
	class OMEGA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();

}
