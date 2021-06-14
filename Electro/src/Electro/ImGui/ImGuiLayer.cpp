#include "elpch.h"
#include "ImGuiLayer.h"
#include "GLFW/glfw3.h"
#include "Core/Application.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Electro/Events/Event.h"
#include "Platform/Windows/WindowsWindow.h"
#include "Core/OS/Input.h"

namespace Electro
{

#define BIND_EVENT_FN(x) std::bind(&ImGuiLayer::x, this, std::placeholders::_1)
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") {}

	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::OnUpdate()
	{
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        auto& win  = static_cast<WindowsWindow&>(app.GetWindow());

        int display_w, display_h;
        glfwGetFramebufferSize(static_cast<GLFWwindow*>(win.GetNativeWindow()), &display_w, &display_h);

        io.DisplayFramebufferScale = ImVec2(app.GetWindow().GetWidth() / display_w, app.GetWindow().GetHeight() / display_h);
        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Begin("Click");
        if (ImGui::Button("Click"))
            EL_CORE_TRACE("Clicked");
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::StyleColorsDark();
        // Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
        io.KeyMap[ImGuiKey_Tab] = Key::TAB,
        io.KeyMap[ImGuiKey_LeftArrow] = Key::LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = Key::RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = Key::UP;
        io.KeyMap[ImGuiKey_DownArrow] = Key::DOWN;
        io.KeyMap[ImGuiKey_PageUp] = Key::PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = Key::PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = Key::HOME;
        io.KeyMap[ImGuiKey_End] = Key::END;
        io.KeyMap[ImGuiKey_Insert] = Key::INSERT;
        io.KeyMap[ImGuiKey_Delete] = Key::KDELETE;
        io.KeyMap[ImGuiKey_Backspace] = Key::BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = Key::SPACE;
        io.KeyMap[ImGuiKey_Enter] = Key::ENTER;
        io.KeyMap[ImGuiKey_Escape] = Key::ESCAPE;
        io.KeyMap[ImGuiKey_KeyPadEnter] = Key::KP_ENTER;
        io.KeyMap[ImGuiKey_A] = Key::A;
        io.KeyMap[ImGuiKey_C] = Key::C;
        io.KeyMap[ImGuiKey_V] = Key::V;
        io.KeyMap[ImGuiKey_X] = Key::X;
        io.KeyMap[ImGuiKey_Y] = Key::Y;
        io.KeyMap[ImGuiKey_Z] = Key::Z;

        ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnEvent(Event& event)
	{
        switch (event.GetEventType())
        {
            case (EventType::MouseButtonPressed):
            {
                MouseButtonPressedEvent& mouseEvent = static_cast<MouseButtonPressedEvent&>(event);
                EventDispatcher dispatcher(event);
                dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(MouseEventCallback<MouseButtonPressedEvent>));
                break;
            }
            case (EventType::MouseButtonReleased):
            {
                MouseButtonPressedEvent& mouseEvent = static_cast<MouseButtonPressedEvent&>(event);
                EventDispatcher dispatcher(event);
                dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(MouseEventCallback<MouseButtonReleasedEvent>));
                break;
            }
            case(EventType::MouseMoved):
            {
                MouseMovedEvent& mouseEvent = static_cast<MouseMovedEvent&>(event);
                EventDispatcher dispatcher(event);
                dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(MouseEventCallback<MouseMovedEvent>)); 
                break;
            }
            case(EventType::MouseScrolled):
            {
                MouseScrolledEvent& mouseEvent = static_cast<MouseScrolledEvent&>(event);
                EventDispatcher dispatcher(event);
                dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(MouseEventCallback<MouseScrolledEvent>));
            }
        }
	}

    bool ImGuiLayer::WindowResizeCallback(WindowResizeEvent& e)
    {
        return false;
    }

    template<>
    bool ImGuiLayer::MouseEventCallback(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());
        EL_CORE_TRACE(Input::GetMouseX());
        EL_CORE_TRACE("Handled Mouse Move");
        return true;
    }

    template<>
    bool ImGuiLayer::MouseEventCallback(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;
        EL_CORE_TRACE("Handled Mouse Pressed");
        return false;
    }

    template<>
    bool ImGuiLayer::MouseEventCallback(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;
        EL_CORE_TRACE("Handled Mouse Released");
        return false;
    }

    template<>
    bool ImGuiLayer::MouseEventCallback(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheelH += e.GetXOffset();
        io.MouseWheel += e.GetYOffset();
        return false;
    }
}