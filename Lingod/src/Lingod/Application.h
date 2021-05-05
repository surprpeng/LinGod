#pragma once
#include "Core.h"
#include "Lingod/Window.h"
#include "Events/ApplicationEvent.h"
#include "Lingod/Events/Event.h"
#include "Lingod/LayerStack.h"
#include "Lingod/imGUI/imGUILayer.h"
namespace Lingod {
	class LG_API Application
	{
	public:
		Application();
		virtual ~Application();


		void run();
		void onEvent(Event& e);

		void PushLayer(Layer* Layer);
		void PushOverLayer(Layer* Layer);

		inline static Application& Get() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window; };
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		LayerStack m_LayerStack;

		std::unique_ptr<Window> m_Window;
		ImGUILayer* m_ImGuiLayer;
		bool m_Running = true;
	private:
		static Application* s_Instance;

	};

	// to be define in client
	Application* CreateApplication();
}

