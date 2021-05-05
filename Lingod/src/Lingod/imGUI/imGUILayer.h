#pragma once

#include "Lingod/Core.h"
#include "Lingod/Layer.h"
#include "Lingod/Events/MouseEvent.h"
#include "Lingod/Events/KeyEvent.h"
#include "Lingod/Events/ApplicationEvent.h"
namespace Lingod
{

	class LG_API ImGUILayer : public Layer
	{
	public:
		ImGUILayer();
		~ImGUILayer() = default;

		void OnAttach()  override ;
		void OnDetach() override ;
		virtual void OnImGiuRender() override;
		void Begin();
		void end();		
	private:
		float m_Time = 0.0f;
	};
}