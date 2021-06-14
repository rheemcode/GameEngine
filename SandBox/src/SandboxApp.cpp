#include <Electro.h>

class ExampleLayer : public Electro::Layer
{
public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override
	{
	//	EL_INFO("ExampleLayer: Update");
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
		PushOverLay(new Electro::ImGuiLayer());
	}

	~SandBox()
	{

	}

};

Electro::Application* Electro::CreateApplication()
{
	return new SandBox();
}