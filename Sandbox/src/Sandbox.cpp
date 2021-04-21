#include <Lingod.h>

class Sandbox : public Lingod::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
private:

};

Lingod::Application* Lingod::CreateApplication()
{
	return new Sandbox();
}
