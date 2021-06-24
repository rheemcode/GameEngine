#pragma once
#include "Drivers./OpenGL/OpenGLContext.h"
#include "Core/OS/Window.h"


namespace Paizo
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width;  }
		inline unsigned int GetHeight() const override { return m_Data.Height;  }

		// Window Attributes
		inline  void SetEventCallbackFn(const EventCallbackFn& callback) override { m_Data.EventCallback = callback;  }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;
		virtual void SwapBuffers() override;
		virtual void* GetNativeWindow() const  override { return m_Window; }

	private:
		void Init(const WindowProps& props);
		void Shutdown();

	private:
		OpenGLContext* m_Context;
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};

}
