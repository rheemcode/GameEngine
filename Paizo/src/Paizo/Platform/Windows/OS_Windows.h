#pragma once
#include "Core/OS/OS.h"

namespace Paizo
{
	class Application;
	class OS_Windows : public OS
	{
		HINSTANCE hInstance;
		HWND m_mainWindow = nullptr;
		Application* mainApp;
	public:
		virtual void Init() override;
		virtual void Run() override;
		virtual const char* GetName() override { return "OS Windows"; }
		virtual Date GetDate();
		OS_Windows(HINSTANCE p_hInstance);
		~OS_Windows();
	};
}
