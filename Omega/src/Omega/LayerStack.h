#pragma once

#include "Omega/Core.h"
#include "Layer.h"

namespace Omega {

	class OMEGA_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* Overlay);
		bool PopLayer(Layer* layer);
		bool PopOverlay(Layer* overlay);

		using iterator = vector<Layer*>::iterator;

		iterator begin() { return m_Layers.begin(); }
		iterator end() { return m_Layers.end(); }

	private:
		vector<Layer*> m_Layers;
		iterator m_LayerInsert;
 	};

}
