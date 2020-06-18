#pragma once

namespace Omega::Maths {

	template<typename T>
	class OMEGA_API Vector2 {
	public:
		Vector2(T x, T y)
			: m_X(x), m_Y(y) {}

		~Vector2() {}

		inline T GetX() const { return m_X; }
		inline T GetY() const { return m_Y; }

	private:
		T m_X, m_Y;
	};

}
