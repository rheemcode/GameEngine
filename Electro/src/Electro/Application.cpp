#include "elpch.h"
#include "Application.h"
#include "Log.h"
#include "Electro/Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Electro
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)




	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallbackFn(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		EL_CORE_TRACE("{0}", e);
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		EL_CORE_TRACE("Window Closed");
		return true;
	}
}

