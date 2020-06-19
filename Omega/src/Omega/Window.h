#pragma once

#include "ompch.h"

#include "Omega/Core.h"
#include "Omega/Events/Event.h"

namespace Omega {

	struct WindowProps {
		string Title;
		unsigned int Width, Height;

		WindowProps(const string& title = "Omega Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	// Interface representing a desktop system base Window
	class OMEGA_API Window {
	public:
		using EventCallbackFn = function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}
