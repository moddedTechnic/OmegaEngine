#pragma once

#ifdef OM_PLATFORM_WINDOWS

extern Omega::Application* Omega::CreateApplication();

int main(int arg, char** argv) {
	auto app = Omega::CreateApplication();
	app->Run();
	delete app;
}

#endif // OM_PLATFORM_WINDOWS

