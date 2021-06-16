#include "elpch.h"
#include "Drivers/OpenGL/OpenGLContext.h"
#include "Core.h"

namespace Electro
{
	OpenGLContext* OpenGLContext::s_Instance = nullptr;

	OpenGLContext::OpenGLContext()
	{
		EL_CORE_ASSERT(!s_Instance, "OpenGLContext already exists");
		s_Instance = this;
	}

	OpenGLContext::~OpenGLContext()
	{
		s_Instance = nullptr;
	}
}