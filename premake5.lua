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
group ""

include "TRDEngine"
include "Game"