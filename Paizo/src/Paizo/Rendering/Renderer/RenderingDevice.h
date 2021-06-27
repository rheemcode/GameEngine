#pragma once


class RenderingDevice
{
	static RenderingDevice* s_Instance;
public:
	enum RenderDeviceType
	{
		UNKNOWN,
		OPENGL,
		VULKAN,
		DIRECTX
	};
	
	enum ShaderLanguage
	{
		GLSL,
		HLSL
	};

	RenderingDevice* Get();
	void Create(RenderDeviceType p_rendererType);
	virtual void DrawList() = 0;

};