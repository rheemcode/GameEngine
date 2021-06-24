#pragma once

#ifdef EL_PLATFORM_WINDOWS

#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
extern Paizo::Application* Paizo::CreateApplication();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Paizo::Log::Init();
	EL_CORE_WARN("Initialized Paizo Core");
	EL_WARN("Hello from App");
	auto app = Paizo::CreateApplication();
	app->Run();
	delete app;
}


int main(int argc, char** argv)
{
	Paizo::Log::Init();
	EL_CORE_WARN("Initialized Paizo Core");
	EL_WARN("Hello from App");
	auto app = Paizo::CreateApplication();
	app->Run();
	delete app;
}



#endif