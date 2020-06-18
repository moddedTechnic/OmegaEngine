#pragma once

#include "Core.h"

#include "Window.h"
#include "Omega/LayerStack.h"
#include "Events/Event.h"
#include "Omega/Events/ApplicationEvent.h"

namespace Omega {
	
	class OMEGA_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();

}
