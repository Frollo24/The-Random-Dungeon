project "Game"
	kind "ConsoleApp"
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
		"%{wks.location}/TRDEngine/src",
		"%{wks.location}/TRDEngine/vendor/glm",
	}

	links
	{
		"TRDEngine"
	}

	postbuildcommands
	{
		("{COPYDIR} \"%{prj.location}assets\" \"../bin/" .. outputdir .. "/Game/assets" .. "/\"")
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
		kind "WindowedApp"
		defines "TRD_DIST"
		runtime "Release"
		optimize "On"
		symbols "Off"