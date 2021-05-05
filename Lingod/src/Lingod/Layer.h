#pragma once
#include "Lingod/Events/Event.h"

namespace Lingod {

	class LG_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}
		virtual void 	 OnImGiuRender()  {};
		const std::string& GetName() const { return m_DebugName; }
	protected:
	std::string m_DebugName;
    };
}

















