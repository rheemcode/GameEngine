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
IncludeDir["Glad"] = "Electro/vendor/Glad/include"
IncludeDir["ImGui"] = "Electro/vendor/imgui"

include "Electro/vendor/GLFW"
include "Electro/vendor/Glad"
include "Electro/vendor/imgui"

project "Electro"
	
	location "Electro"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
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
		"%{prj.name}/src/Electro",
		"%{prj.name}/src/Electro/Core",
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
			"EL_PLATFORM_WINDOWS",
			"EL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		runtime "Debug"
		symbols "On"
		

	filter "configurations:Release"
		defines "EL_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
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
		"Electro/vendor/spdlog/include",
		"Electro/vendor/imgui",
		"Electro/src",
		"Electro/src/Electro"
	}

	links
	{
		"Electro"
	}

	filter "system:windows"

		systemversion "latest"

		defines
		{
			"EL_PLATFORM_WINDOWS"
		}

	

	filter "configurations:Debug"
		defines "EL_DEBUG"
		symbols "On"
		

	filter "configurations:Release"
		defines "EL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EL_DIST"
		buildoptions "/MDd"
		optimize "On"