#pragma once

#ifdef OM_PLATFORM_WINDOWS

extern Omega::Application* Omega::CreateApplication();

int main(int arg, char** argv) {
	Omega::Log::Init();
	OM_CORE_INFO("Initialised Log");
	OM_INFO("Initialised Log");

	auto app = Omega::CreateApplication();
	app->Run();
	delete app;
}

#endif // OM_PLATFORM_WINDOWS

