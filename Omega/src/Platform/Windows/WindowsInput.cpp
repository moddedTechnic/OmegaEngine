#include "ompch.h"
#include "WindowsInput.h"

#include "Omega/Application.h"
#include <GLFW/glfw3.h>

namespace Omega {

	Input* Input::s_Instance = new WindowsInput();

#define GET_WINDOW auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow())

	bool WindowsInput::IsKeyPressedImpl(int keycode) {
		GET_WINDOW;
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) {
		GET_WINDOW;
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl() {
		return GetMousePosImpl().GetX();
	}

	float WindowsInput::GetMouseYImpl() {
		return GetMousePosImpl().GetY();
	}

	WindowsInput::Vector WindowsInput::GetMousePosImpl() {
		GET_WINDOW;
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return WindowsInput::Vector((float) xpos, (float) ypos);
	}

}
