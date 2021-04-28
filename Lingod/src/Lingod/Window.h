#pragma once
#pragma once

#include "lgpch.h"

#include "Core.h"
#include "Lingod/Events/Event.h"

namespace Lingod
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// Constructor
		WindowProps(std::string title = "LinGodEngine Editor",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{}
	};

	// Interface representing a desktop system based Window
	class LG_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		//virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};


}