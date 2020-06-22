#include "ompch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Omega {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) {
		OM_CORE_ASSERT(windowHandle, "WindowHandle is null");
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(m_WindowHandle);
		OM_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize Glad");

		OM_CORE_INFO("OpenGL Info:");
		OM_CORE_INFO("  ~ Vendor:   {0}", glGetString(GL_VENDOR));
		OM_CORE_INFO("  ~ Renderer: {0}", glGetString(GL_RENDERER));
		OM_CORE_INFO("  ~ Version:  {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(m_WindowHandle);
	}

}
