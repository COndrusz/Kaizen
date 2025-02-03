workspace "Kaizen"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
		symbols "On"

	filter "configurations:Release"
		defines "KZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KZ_DIST"
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
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"KZ_PLATFORM_WINDOWS"
		}

		 buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "KZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KZ_DIST"
		optimize "On"