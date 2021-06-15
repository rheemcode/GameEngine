#include <Electro.h>
#include "imgui.h"

class ExampleLayer : public Electro::Layer
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
		ImGui::Begin("Im");
		ImGui::Text("Hello Wordl");
		ImGui::End();
	}

	void OnEvent(Electro::Event& e) override
	{
		//EL_TRACE("{0}", e);
	}
};

class SandBox : public Electro::Application
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

Electro::Application* Electro::CreateApplication()
{
	return new SandBox();
}