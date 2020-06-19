#include "ompch.h"
#include "Application.h"

#include "Omega/Log.h"

#include <glad/glad.h>

#include "Input.h"

namespace Omega {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		OM_CORE_ASSERT(!s_Instance, "Aplication already exists");
		s_Instance = this;

		m_Window = unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(OM_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(OM_BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(.5, .5, .5, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}
