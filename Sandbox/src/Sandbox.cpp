#include <Lingod.h>
#include "imGUI/imgui.h"
class ExampleLayer : public Lingod::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	virtual void OnImGiuRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello Word!!");
		ImGui::End();
	}

	void OnUpdate() override
	{
		if (Lingod::Input::IsKeyPressed(Lingod::Key::Tab)) {
			LG_TRACE("Tab Key is pressed(poll)!");
		}
	}

	void OnEvent(Lingod::Event& event) override
	{
		if (event.GetEventType() == Lingod::EventType::KeyPressed) {
			Lingod::KeyPressedEvent& e = (Lingod::KeyPressedEvent&)event;
			if(e.GetKeyCode() == Lingod::Key::Tab)
				LG_TRACE("Tab Key is pressed(event)!");

			LG_TRACE("{0}", (char)e.GetKeyCode());

		}
	}
};

class Sandbox : public Lingod::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
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



