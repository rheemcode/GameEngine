#include "elpch.h"
#include "Application.h"
#include "Log.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core/Layer.h"

namespace Electro
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		EL_CORE_ASSERT(!s_Instance, "Application already exists");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_ImGuiLayer = new ImGuiLayer();
		m_Window->SetEventCallbackFn(BIND_EVENT_FN(OnEvent));
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Run()
	{

		while (m_Running)
		{
			
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
			
			for (auto layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->Begin();

			for (auto layer : m_LayerStack)
				layer->OnImGuiRender();

			m_ImGuiLayer->End();
			m_Window->SwapBuffers();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		auto fn = std::bind(&Application::OnWindowClose, this, std::placeholders::_1);
		
		dispatcher.Dispatch<WindowCloseEvent>(fn);
		
		EL_CORE_TRACE("{0}", e);

	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		EL_CORE_TRACE("Window Closed");
		return true;
	}
}

