workspace "GameEngine"
	architecture("x64")


	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}
						
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Electro/vendor/GLFW/include"

include "Electro/vendor/GLFW"

project "Electro"
	
	location "Electro"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "elpch.h"
	pchsource "Electro/src/elpch.cpp"

	files
	{
		"%{prj.name}/src/**h",
		"%{prj.name}/src/**cpp",

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}


	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"

		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines
		{
			"EL_PLATFORM_WINDOWS",
			"EL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		

	filter "configurations:Release"
		defines "EL_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		buildoptions "/MD"
		optimize "On"
	

project "Sandbox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**h",
		"%{prj.name}/src/**cpp",

	}

	includedirs
	{
		"Electro/vendor/spdlog/include",
		"Electro/src"
	}

	links
	{
		"Electro"
	}

	filter "system:windows"

		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EL_PLATFORM_WINDOWS"
		}

	

	filter "configurations:Debug"
		defines "EL_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		

	filter "configurations:Release"
		defines "EL_RELEASE"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		buildoptions "/MDd"
		optimize "On"