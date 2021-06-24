#pragma once
#include "pzpch.h"
#include "OS_Windows.h"

int _main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Paizo::OS_Windows os(hInstance);
	os.Init();
	os.Run();
	return 0;
}

