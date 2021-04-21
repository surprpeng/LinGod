#pragma once

#include "Core.h"
namespace Lingod {
	class LG_API Application
	{
	public:
		Application();
		virtual ~Application();


		void run();
	private:
	};

	// to be define in client
	Application* CreateApplication();
}

