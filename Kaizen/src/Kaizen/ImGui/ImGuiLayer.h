#pragma once

#include "Kaizen/Layer.h"
#include "Kaizen/Events/KeyEvent.h"
#include "Kaizen/Events/MouseEvent.h"
#include "Kaizen/Events/ApplicationEvent.h"

namespace Kaizen
{
	class KAIZEN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
		void OnAttach();
		void OnDetach();

	private:

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		float m_Time = 0;
	};

}

