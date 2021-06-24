#pragma once

#include "Core/Layer.h"
#include "Paizo/Events/ApplicationEvent.h"
#include "Paizo/Events/MouseEvent.h"


namespace Paizo
{
	class PAIZO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void Begin();
		void End();
		void OnImGuiRender() override;
		void OnEvent(Event& event) override;
	private:
		float m_Time = 0.f;
		bool m_BlockEvents = false;
	};

}