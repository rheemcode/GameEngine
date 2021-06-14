#pragma once

#include "Core/Layer.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Electro/Events/ApplicationEvent.h"
#include "Electro/Events/MouseEvent.h"


namespace Electro
{
	class ELECTRO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

		template<typename T>
		bool MouseEventCallback(T& e) { static_assert(false); }

		template<>
		bool MouseEventCallback<MouseButtonPressedEvent>(MouseButtonPressedEvent& e);
		template<>
		bool MouseEventCallback<MouseButtonReleasedEvent>(MouseButtonReleasedEvent& e);
		template<>
		bool MouseEventCallback<MouseMovedEvent>(MouseMovedEvent& e);
		template<>
		bool MouseEventCallback<MouseScrolledEvent>(MouseScrolledEvent& e);

		bool WindowResizeCallback(WindowResizeEvent& e);

	private:
		float m_Time = 0.f;
	};

}