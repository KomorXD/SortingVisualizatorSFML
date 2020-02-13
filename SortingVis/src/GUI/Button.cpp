#include "Button.hpp"

Button::Button(const sf::Vector2f& _size)
	: Textbox(_size) { }

Button::Button(const sf::Vector2f& _size, const std::string& _text)
	: Textbox(_size, _text) { }

void Button::SetFunction(std::function<void(void)> _f) {
	m_Func = _f;
}

void Button::HandleEvents(const sf::RenderWindow& _window, sf::Event& _ev) {
	if (m_Box.IsRolledOn(_window)) {
		m_Box.setFillColor(sf::Color(46, 46, 46));

		if (m_Box.IsClickedOn(_window, _ev))
			m_Func();
	}
	else
		m_Box.setFillColor(sf::Color(33, 33, 33));
}
