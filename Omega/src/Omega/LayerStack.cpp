#include "ompch.h"
#include "LayerStack.h"

namespace Omega {

	LayerStack::LayerStack() {
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer) {
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		m_Layers.emplace_back(overlay);
	}

	bool LayerStack::PopLayer(Layer* layer) {
		if (PopOverlay(layer)) {
			m_LayerInsert--;
			return true;
		}

		return false;
	}

	bool LayerStack::PopOverlay(Layer* overlay) {
		auto it = std::find(begin(), end(), overlay);
		if (it != end()) {
			m_Layers.erase(it);
			return true;
		}

		return false;
	}

}
