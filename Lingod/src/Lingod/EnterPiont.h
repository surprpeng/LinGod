#pragma once

#ifdef LG_PLAYFORM_WINDOWS
	//extern Lingod::Application* Lingod::CreateApplication();

	int main()
	{
		Lingod::log::init();
		LG_CORE_WARN("initozation");
		LG_INFO("hello !");
		auto app = Lingod::CreateApplication();
		app->run();
		delete app;
	}

#endif