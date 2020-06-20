#pragma once

#include "Omega/Layer.h"
#include "Omega/Events.h"

namespace Omega {

	class OMEGA_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
		void OnImGuiRender() override;

	private:
		float m_Time = 0.f;
	};

}
