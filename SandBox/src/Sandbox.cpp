#include <Kaizen.h>


class ExampleLayer : public Kaizen::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}
	void OnUpdate() override
	{

	}
	void OnEvent(Kaizen::Event& event) override
	{

	}
};


class Sandbox : public Kaizen::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Kaizen::ImGuiLayer());
	}

	~Sandbox() 
	{

	}
};

Kaizen::Application* Kaizen::CreateApplication()
{
	return new Sandbox();
}

