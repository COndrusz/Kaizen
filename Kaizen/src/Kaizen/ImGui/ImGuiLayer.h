#pragma once

#include "Kaizen/Layer.h"

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
		float m_Time = 0;
	};

}

