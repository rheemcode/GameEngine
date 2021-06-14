#include "elpch.h"
#include "Core/OS/Input.h"
#include "Core/Application.h"
#include "WindowsInput.h"
#include <GLFW/glfw3.h>

namespace Electro
{

	Input* Input::s_Instance = new WindowsInput();

	bool Electro::WindowsInput::IsKeyPressedImpl(KeyCode keyCode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		if (glfwGetKey(window, keyCode))
			return true;

		return false;
	}

	bool Electro::WindowsInput::IsMouseButtonPressedImpl(MouseButton button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		if (glfwGetMouseButton(window, button))
			return true;

		return false;
	}

	std::pair<float, float> Electro::WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double mouseX, mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		return { mouseX, mouseY };
	}

	float Electro::WindowsInput::GetMouseXImpl()
	{
		auto [mouseX, mouseY] = GetMousePositionImpl();
		return mouseX;
	}

	float Electro::WindowsInput::GetMouseYImpl()
	{
		auto [mouseX, mouseY] = GetMousePositionImpl();
		return mouseY;
	}
}