workspace "Kaizen"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Kaizen/vendor/GLFW/include"

include "Kaizen/vendor/GLFW"

project "Kaizen"
	location "Kaizen"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "kzpch.h"
	pchsource "Kaizen/src/kzpch.cpp"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
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
		"opengl32.lib",
		"dwmapi.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"KZ_PLATFORM_WINDOWS",
			"KZ_BUILD_DLL"
		}
		buildoptions { "/utf-8" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "KZ_DEBUG"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Release"
		defines "KZ_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "KZ_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kaizen/vendor/spdlog/include",
		"Kaizen/src"
	}

	links
	{
		"Kaizen"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"KZ_PLATFORM_WINDOWS"
		}

		 buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "KZ_DEBUG"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Release"
		defines "KZ_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "KZ_DIST"
		buildoptions "/MD"
		optimize "On"