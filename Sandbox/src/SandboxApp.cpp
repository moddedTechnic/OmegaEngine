#include <Omega.h>

class Sandbox : public Omega::Application {
public:
	Sandbox();
	~Sandbox();
};

Sandbox::Sandbox() {}

Sandbox::~Sandbox() {}

Omega::Application* Omega::CreateApplication() {
	return new Sandbox();
}
