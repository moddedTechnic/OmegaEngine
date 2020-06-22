workspace "Omega"
	architecture "x64"
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Omega/vendor/GLFW/include"
IncludeDir["Glad"] = "Omega/vendor/Glad/include"
IncludeDir["ImGui"] = "Omega/vendor/imgui"
IncludeDir["glm"] = "Omega/vendor/glm"

group "Dependencies"
	include "Omega/vendor/GLFW"
	include "Omega/vendor/Glad"
	include "Omega/vendor/imgui"

group ""

project "Omega"
	location "Omega"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "ompch.h"
	pchsource "Omega/src/ompch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"OM_PLATFORM_WINDOWS",
			"OM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines { "OM_DEBUG" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines { "OM_RELEASE" }
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines { "OM_DIST" }
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Omega/vendor/spdlog/include",
		"Omega/src",
		"Omega/vendor",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"Omega"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"OM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "OM_DEBUG" }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines { "OM_RELEASE" }
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines { "OM_DIST" }
		runtime "Release"
		optimize "on"
