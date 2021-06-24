#pragma once
#include "Core/Layer.h"
#include "Paizo/Events/Event.h"


namespace Paizo
{
	class PAIZO_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}


		inline const std::string& GetName() const { return m_DebugName;  }

	protected:
		std::string m_DebugName;
	};
}