#pragma once

#include "Core.h"

namespace Kaizen {
	class KAIZEN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};


	// To be defined in client
	Application* CreateApplication();
}


