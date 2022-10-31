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
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
		"vendor/stb_image/stb_image.h",
		"vendor/stb_image/stb_image.cpp",
		"vendor/tiny_obj_loader/tiny_obj_loader.h",
		"vendor/tiny_obj_loader/tiny_obj_loader.cpp"
	}

	includedirs
	{
		"src",
		"vendor/stb_image",
		"vendor/tiny_obj_loader",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
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