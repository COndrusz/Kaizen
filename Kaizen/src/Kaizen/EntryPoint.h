#pragma once

#ifdef KZ_PLATFORM_WINDOWS

extern Kaizen::Application* Kaizen::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Kaizen");
	auto app = Kaizen::CreateApplication();
	app->Run();
	delete app;
}


#endif