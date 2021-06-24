#include "pzpch.h"
#include "OS_Windows.h"
#include "Paizo/Core/Application.h"

namespace Paizo
{
	void OS_Windows::Init()
	{
		Log::Init();
		mainApp = Paizo::CreateApplication();
		PAIZO_ASSERT(!mainApp, "Couldn't create an Application");
	}

	void OS_Windows::Run()
	{
		mainApp->Run();
	}

	Date OS_Windows::GetDate()
	{
		return Date();
	}

	OS_Windows::OS_Windows(HINSTANCE p_hInstance)
	{
		hInstance = p_hInstance;
		m_mainWindow = nullptr;
		PAIZO_ASSERT(!s_Instance, "OS already exits");
		s_Instance = this;
	}

	OS_Windows::~OS_Windows()
	{
		delete mainApp;
	}
}
