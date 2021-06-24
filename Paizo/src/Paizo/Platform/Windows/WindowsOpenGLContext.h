#pragma once
#include "Drivers/OpenGL/OpenGLContext.h"

namespace Paizo
{
	class WindowsOpenGLContext : public OpenGLContext
	{
	public:
		
		virtual void CreateContext(void* windowHandle) override;
		virtual void Init() override;
		virtual void SwapBuffers() override;
	
	private:
		void* m_WindowHandle;
	};
}


