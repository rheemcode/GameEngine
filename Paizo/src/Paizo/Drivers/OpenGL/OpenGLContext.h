#pragma once
#include <GLFW/glfw3.h>

namespace Paizo
{
	class OpenGLContext 
	{
		static OpenGLContext* s_Instance;
		bool isVsync = true;
	
	public:
		OpenGLContext();
		virtual ~OpenGLContext();

		static OpenGLContext* GetContext() { return s_Instance; };
		void SetUseVsync(bool p_useVync) { isVsync = p_useVync; };
		virtual void MakeCurrent() {};
		virtual void ReleaseCurrent() {};
		virtual void Init(GLFWwindow* p_WindowHandle) = 0;
		virtual void SwapBuffers() = 0;

		virtual int GetWindowWidth() const = 0;
		virtual int GetWindowHeight() const = 0;

	};
}