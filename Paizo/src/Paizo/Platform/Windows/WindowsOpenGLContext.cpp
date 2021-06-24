#include "pzpch.h"
#include "WindowsOpenGLContext.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Paizo
{
	static bool s_GLFWInitialized = false;
	void WindowsOpenGLContext::Init(GLFWwindow* p_Window)
	{
		m_WindowHandle = p_Window;
		glfwMakeContextCurrent(m_WindowHandle);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PAIZO_CORE_ASSERT(success, "Failed to initialize Glad");
	}

	void WindowsOpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers((m_WindowHandle));
	}
	int WindowsOpenGLContext::GetWindowWidth() const
	{
		return 0;
	}
	int WindowsOpenGLContext::GetWindowHeight() const
	{
		return 0;
	}
}
