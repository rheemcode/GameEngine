#pragma once

#ifdef PAIZO_PLATFORM_WINDOWS

#ifndef UNICODE
#define UNICODE
#endif 

#include "Platform/Windows/WindowsMain.h"
extern Paizo::Application* Paizo::CreateApplication();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	return _main(hInstance, hPrevInstance, pCmdLine, nCmdShow);
}

#else
int main(int argc, char** argv)
{
	Paizo::Log::Init();
	PAIZO_CORE_WARN("Initialized Paizo Core");
	EL_WARN("Hello from App");
	auto app = Paizo::CreateApplication();
	app->Run();
	delete app;
}
#endif
