#pragma once


#ifdef EL_PLATFORM_WINDOWS

extern Electro::Application* Electro::CreateApplication();

int main(int argc, char** argv)
{
	Electro::Log::Init();
	EL_CORE_WARN("Initialized Electro Core");
	EL_WARN("Hello from App");
	auto app = Electro::CreateApplication();
	app->Run();
	delete app;
}

int WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	return 0;
}

#endif