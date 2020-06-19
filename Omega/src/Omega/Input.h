#pragma once

#include "Omega/Core.h"
#include "Omega/Maths/Vector2.h"

namespace Omega {

	class OMEGA_API Input {
	protected:
		using Vector = Maths::Vector2<float>;

	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static Vector GetMousePos() { return s_Instance->GetMousePosImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual Vector GetMousePosImpl() = 0;

	private:
		static Input* s_Instance;
	};

}
