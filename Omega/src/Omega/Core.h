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


#ifdef OM_ENABLE_ASSERTS
	#define OM_ASSERT(x, ...) { if(!(x)) { OM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak; } }
	#define OM_CORE_ASSERT(x, ...) { if(!(x)) { OM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak; } }

#else
	#define OM_ASSERT
	#define OM_CORE_ASSERT

#endif


#define BIT(x) (1 << (x))

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
