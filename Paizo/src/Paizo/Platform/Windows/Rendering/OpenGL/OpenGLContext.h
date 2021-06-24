#pragma once


namespace Paizo
{
	class OpenGLContext 
	{
		static OpenGLContext* s_Instance;
	public:
		static OpenGLContext* GetContext() { return s_Instance; };


		virtual void MakeCurrent() {};

		virtual void CreateContext(void * window = nullptr) = 0;
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		OpenGLContext();
		~OpenGLContext();

	};
}