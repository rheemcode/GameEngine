#include "pzpch.h"
#include "OpenGLContext.h"
#include "Core.h"

namespace Paizo
{
	OpenGLContext* OpenGLContext::s_Instance = nullptr;

	OpenGLContext::OpenGLContext()
	{
		PAIZO_CORE_ASSERT(!s_Instance, "OpenGLContext already exists");
		s_Instance = this;
	}

	OpenGLContext::~OpenGLContext()
	{
		s_Instance = nullptr;
	}
}