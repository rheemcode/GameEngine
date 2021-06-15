#pragma once
#include "Core/OS/Input.h"

namespace Electro
{

	class WindowsInput : public Input
	{
	protected:
		bool IsKeyPressedImpl(KeyCode keyCode) override;
		bool IsMouseButtonPressedImpl(MouseButton button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}

