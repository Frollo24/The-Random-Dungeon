project "TRDEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src"
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