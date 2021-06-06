#include <Electro.h>

class SandBox : public Electro::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}

};

Electro::Application* Electro::CreateApplication()
{
	return new SandBox();
}