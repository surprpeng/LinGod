#pragma once

#ifdef LG_PLAYFORM_WINDOWS
	extern Lingod::Application* Lingod::CreateApplication();

	int main()
	{
		auto app = Lingod::CreateApplication();
		app->run();
		delete app;
	}

#endif