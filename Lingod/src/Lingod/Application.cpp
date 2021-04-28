#include "lgpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "log.h"
namespace Lingod{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	class A {
	public:
		A(int a, int b) : a(a),b(b) {};
	private:
		int a;
		int b;
	};
	void Application::run()
	{
		WindowResizeEvent e(1600, 10);
		A a(1, 2);
		LG_CORE_TRACE(a);
		std::string i = "sda";
		LG_CORE_TRACE(i);
		while (true);
	}
}