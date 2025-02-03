#include "kzpch.h"
#include "Application.h"
#include "Kaizen/Log.h"
#include "Kaizen/Events/ApplicationEvent.h"


namespace Kaizen {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		KZ_TRACE(e);

		while (true);
	}
}