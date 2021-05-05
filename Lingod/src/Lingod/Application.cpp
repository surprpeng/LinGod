#include "lgpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Lingod/log.h"
#include "Lingod/LayerStack.h"
#include "Lingod/Core.h"
#include  <glad/glad.h>
namespace Lingod{


	Application* Application::s_Instance = nullptr;
	Application::Application()
	{

		LG_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::onEvent));
		m_ImGuiLayer = new ImGUILayer();
		PushOverLayer(m_ImGuiLayer);
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
			dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*(--it))->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}
	void Application::PushLayer(Layer* Layer)
	{
		m_LayerStack.PushLayer(Layer);
		Layer->OnAttach();
	}
	void Application::PushOverLayer(Layer* Layer)
	{
		m_LayerStack.PushOverlay(Layer);
		Layer->OnAttach();
	}



	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		while (m_Running)
		{
			glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGiuRender();
			m_ImGuiLayer->end();
			m_Window->OnUpdate();
		};
	}
}