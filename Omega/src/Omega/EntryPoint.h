#pragma once

#ifdef OM_PLATFORM_WINDOWS

extern Omega::Application* Omega::CreateApplication();

int main(int arg, char** argv) {
	Omega::Log::Init();
	OM_CORE_TRACE("Initialised Log");
	OM_TRACE("Initialised Log");

	auto app = Omega::CreateApplication();
	app->Run();
	delete app;
}

#endif // OM_PLATFORM_WINDOWS

