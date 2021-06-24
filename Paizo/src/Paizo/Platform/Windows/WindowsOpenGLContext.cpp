#include "elpch.h"
#include "WindowsOpenGLContext.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Paizo
{
	void WindowsOpenGLContext::Init()
	{
		glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_WindowHandle));
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EL_CORE_ASSERT(success, "Failed to initialize Glad");
	}

	void WindowsOpenGLContext::CreateContext(void* windowHandle)
	{
		m_WindowHandle = windowHandle;
	}

	void WindowsOpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(static_cast<GLFWwindow*>(m_WindowHandle));
	}
}
