#pragma once
#include "Drivers/OpenGL/OpenGLContext.h"

namespace Paizo
{
	class WindowsOpenGLContext : public OpenGLContext
	{
	public:
		
		GLFWwindow* GetWindowHandle() { return m_WindowHandle; };
		virtual void Init(GLFWwindow* p_WindowHandle) override;
		virtual void SwapBuffers() override;
		virtual int GetWindowWidth() const override;
		virtual int GetWindowHeight() const override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}


