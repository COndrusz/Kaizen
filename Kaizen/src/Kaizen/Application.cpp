#include "kzpch.h"
#include "Application.h"
#include "Kaizen/Log.h"
#include "Kaizen/Events/ApplicationEvent.h"


namespace Kaizen {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{

		KZ_CORE_INFO("Hello");
		while (m_Running) 
		{
			m_Window->OnUpdate();
		}
	}
}