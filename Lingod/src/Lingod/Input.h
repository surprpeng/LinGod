#pragma once
#include "lgpch.h"
#include "Core.h"

namespace Lingod
{
	class LG_API Input
	{
	public:
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual bool IsKeyPressedImpl(int KeyCode) = 0;
		virtual bool IsMousePressedImpl(int button) = 0;
		
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMousePressed(int button) { return s_Instance->IsMousePressedImpl(button); }
	private:
		static Input* s_Instance;
	};


}