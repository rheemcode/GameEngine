#pragma once

namespace Paizo
{
	typedef unsigned char uint8_t;
	typedef uint8_t MouseButton;

	namespace Mouse
	{
		enum : MouseButton
		{
			BUTTON_1 = 0,
			BUTTON_2 = 1,
			BUTTON_3 = 2,
			BUTTON_4 = 3,
			BUTTON_5 = 4,
			BUTTON_6 = 5,
			BUTTON_7 = 6,
			BUTTON_8 = 7,
			LEFT     = BUTTON_1,
			MIDDLE   = BUTTON_2,
			RIGHT    = BUTTON_3,
			LAST     = BUTTON_8

		};
	}
}