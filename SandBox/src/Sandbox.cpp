#include <Kaizen.h>

class Sandbox : public Kaizen::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Kaizen::Application* Kaizen::CreateApplication()
{
	return new Sandbox();
}

