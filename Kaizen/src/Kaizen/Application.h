#pragma once

#include "Core.h"
#include "Kaizen/LayerStack.h"
#include "Window.h"
#include "Kaizen/Events/ApplicationEvent.h"

namespace Kaizen {
	class KAIZEN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	// To be defined in client
	Application* CreateApplication();
}


