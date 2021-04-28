#pragma once
#include "Core.h"
#include "Lingod/Window.h"
namespace Lingod {
	class LG_API Application
	{
	public:
		Application();
		virtual ~Application();


		void run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// to be define in client
	Application* CreateApplication();
}

