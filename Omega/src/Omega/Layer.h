#pragma once

#include "Omega/Core.h"
#include "Omega/Events/Event.h"

namespace Omega {

	class OMEGA_API Layer {
	public:
		Layer(const string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const string& GetName() const { return m_DebugName; }

	protected:
		string m_DebugName;
	};

}
