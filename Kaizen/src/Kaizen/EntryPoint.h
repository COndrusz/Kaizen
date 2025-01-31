#pragma once

#ifdef KZ_PLATFORM_WINDOWS

extern Kaizen::Application* Kaizen::CreateApplication();

int main(int argc, char** argv) 
{
	Kaizen::Log::Init();
	KZ_CORE_WARN("Initialise Log");
	int a = 5;
	KZ_INFO("Hi! Var={0}", a);
	auto app = Kaizen::CreateApplication();
	app->Run();
	delete app;
}


#endif