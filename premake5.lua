workspace "Omega"
	architecture "x64"
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

output_dir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

project "Omega"
	location "Omega"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/bin/" .. output_dir .. "/%{prj.name}")
	objdir ("bin/int/" .. output_dir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"OM_PLATFORM_WINDOWS",
			"OM_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/bin/" .. output_dir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines { "OM_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "OM_RELEASE" }
		optimize "On"

	filter "configurations:Dist"
		defines { "OM_DIST" }
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/bin/" .. output_dir .. "/%{prj.name}")
	objdir ("bin/int/" .. output_dir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Omega/vendor/spdlog/include",
		"Omega/src"
	}

	links {
		"Omega"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"OM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "OM_DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "OM_RELEASE" }
		optimize "On"

	filter "configurations:Dist"
		defines { "OM_DIST" }
		optimize "On"
