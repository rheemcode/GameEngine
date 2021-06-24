#include <Paizo.h>
#include "imgui.h"

class ExampleLayer : public Paizo::Layer
{
public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override
	{
	//	EL_INFO("ExampleLayer: Update");
	}
	
	void OnImGuiRender() override
	{
		ImGui::Begin("ImGui");
		ImGui::Text("Hello Wordl");
		ImGui::End();
	}

	void OnEvent(Paizo::Event& e) override
	{
		//EL_TRACE("{0}", e);
	}
};

class SandBox : public Paizo::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}

};

Paizo::Application* Paizo::CreateApplication()
{
	return new SandBox();
}