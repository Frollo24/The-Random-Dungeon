project "TRDEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/int/" .. outputdir .. "/%{prj.name}")

	pchheader "TRDPCH.h"
	pchsource "src/TRDPCH.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	defines
	{
		"GLFW_INCLUDE_NONE"
	}

	filter "configurations:Debug"
		defines "TRD_DEBUG"
		runtime "Debug"
		optimize "Off"
		symbols "On"

	filter "configurations:Release"
		defines "TRD_RELEASE"
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines "TRD_DIST"
		runtime "Release"
		optimize "On"
		symbols "Off"