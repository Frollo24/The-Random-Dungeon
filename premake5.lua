include "dependencies.lua"

workspace "TheRandomDungeon"
	architecture "x64"
	startproject "Game"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

group "Dependencies"
	include "TRDEngine/vendor/GLFW"
	include "TRDEngine/vendor/Glad"
group ""

include "TRDEngine"
include "Game"