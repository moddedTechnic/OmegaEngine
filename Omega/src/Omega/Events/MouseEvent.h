#pragma once

#include "Event.h"

#include "Omega/Maths/Vector2.h"

namespace Omega {
	using Maths::Vector2;

	class OMEGA_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_Pos(x, y) {}

		MouseMovedEvent(double x, double y)
			: m_Pos((float) x, (float) y) {}

		inline Vector2<float> GetPos() const { return m_Pos; }
		inline float GetX() const { return m_Pos.GetX(); }
		inline float GetY() const { return m_Pos.GetY(); }

		string ToString() const override {
			stringstream ss;
			ss << "MouseMovedEvent: " << GetX() << ", " << GetY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		Vector2<float> m_Pos;
	};

	class OMEGA_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOff, float yOff)
			: m_Offset(xOff, yOff) {}

		MouseScrolledEvent(double xOff, double yOff)
			: m_Offset((float) xOff, (float) yOff) {}

		inline Vector2<float> GetOffset() const { return m_Offset; }
		inline float GetXOffset() const { return m_Offset.GetX(); }
		inline float GetYOffset() const { return m_Offset.GetY(); }

		string ToString() const override {
			stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		Vector2<float> m_Offset;
	};

	class OMEGA_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class OMEGA_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		string ToString() const override {
			stringstream ss;
			ss << "MouseButtonPressed: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class OMEGA_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		string ToString() const override {
			stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};

}
