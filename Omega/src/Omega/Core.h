#pragma once

#ifdef OM_PLATFORM_WINDOWS
	#ifdef OM_BUILD_DLL
		#define OMEGA_API __declspec(dllexport)
	#else
		#define OMEGA_API __declspec(dllimport)
	#endif // OM_BUILD_DLL

#else
	#error Hazel only supports Windows

#endif // OM_PLATFORM_WINDOWS


#define BIT(x) (1 << x)

//Standard Library
#include <string>
using std::string;

#include <functional>

#include <sstream>
using std::stringstream;
