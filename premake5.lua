workspace "Paizo Engine"
	architecture("x64")


	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}
						
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Paizo/vendor/GLFW/include"
IncludeDir["Glad"] = "Paizo/vendor/Glad/include"
IncludeDir["ImGui"] = "Paizo/vendor/imgui"

include "Paizo/vendor/GLFW"
include "Paizo/vendor/Glad"
include "Paizo/vendor/imgui"

project "Paizo"
	
	location "Paizo"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "pzpch.h"
	pchsource "Paizo/src/pzpch.cpp"

	files
	{
		"%{prj.name}/src/**h",
		"%{prj.name}/src/**cpp",

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/src/Paizo",
		"%{prj.name}/src/Paizo/Core",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	}


	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"

		systemversion "latest"


		defines
		{
			"PAIZO_PLATFORM_WINDOWS",
			"PAIZO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "PAIZO_DEBUG"
		runtime "Debug"
		symbols "On"
		

	filter "configurations:Release"
		defines "PAIZO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PAIZO_DIST"
		runtime "Release"
		optimize "On"
	

project "Sandbox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**h",
		"%{prj.name}/src/**cpp",

	}

	includedirs
	{
		"Paizo/vendor/spdlog/include",
		"Paizo/vendor/imgui",
		"Paizo/src",
		"Paizo/src/Paizo"
	}

	links
	{
		"Electro"
	}

	filter "system:windows"

		systemversion "latest"

		defines
		{
			"PAIZO_PLATFORM_WINDOWS"
		}

	

	filter "configurations:Debug"
		defines "PAIZO_DEBUG"
		symbols "On"
		

	filter "configurations:Release"
		defines "PAIZO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PAIZO_DIST"
		optimize "On"