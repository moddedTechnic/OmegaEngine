#include "ompch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Omega {
	Application::Application() {}

	Application::~Application() {}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategory::EventCategoryApplication)) {
			OM_TRACE(e);
		}
		if (e.IsInCategory(EventCategory::EventCategoryInput)) {
			OM_TRACE(e);
		}

		while (true);
	}
}
