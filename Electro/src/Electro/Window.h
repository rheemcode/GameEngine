

#pragma once
#include "elpch.h"

#include "Electro/Core.h"
#include "Electro/Events/Event.h"


namespace Electro
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Electro Engine",
			unsigned int width = 1280,
			unsigned int height = 700)
			: Title(title), Width(width), Height(height)
		{

		}

	};

	// Implemented per Platform
	class ELECTRO_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallbackFn(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}

