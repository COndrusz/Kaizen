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
		KZ_INFO("ExampleLayer::Update");
	}
	void OnEvent(Kaizen::Event& event) override
	{
		KZ_TRACE("{0}", event.ToString());
	}
};


class Sandbox : public Kaizen::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

Kaizen::Application* Kaizen::CreateApplication()
{
	return new Sandbox();
}

