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
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"OM_PLATFORM_WINDOWS",
			"OM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines { "OM_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "OM_RELEASE" }
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines { "OM_DIST" }
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Omega/vendor/spdlog/include",
		"Omega/src",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"Omega"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"OM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "OM_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "OM_RELEASE" }
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines { "OM_DIST" }
		runtime "Release"
		optimize "On"
