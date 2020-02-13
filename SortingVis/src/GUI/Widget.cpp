#include "Widget.hpp"
#include "../ResourceManagers/ResourceHolder.hpp"

Widget::Rectangle::Rectangle(const sf::Vector2f& _size)
	: sf::RectangleShape(_size) { }

bool Widget::Rectangle::IsRolledOn(const sf::RenderWindow& _window) const {
	sf::Vector2i mousePos = sf::Mouse::getPosition(_window);

	return getGlobalBounds().contains(sf::Vector2f(mousePos));
}

bool Widget::Rectangle::IsClickedOn(const sf::RenderWindow& _window, sf::Event& _ev) {
	if (IsRolledOn(_window)) {
		if (_ev.type == sf::Event::MouseButtonPressed)
			return _ev.mouseButton.button == sf::Mouse::Left;
	}

	return false;
}

Widget::Text::Text() {
	setFillColor(sf::Color::White);
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(2.0f);
	setFont(ResourceHolder::Get().fonts.Get("OpenSans"));
}

void Widget::Text::SetFontSize(unsigned int _fontSize) {
	setCharacterSize(_fontSize);
}

void Widget::Text::UpdateText() {
	sf::FloatRect textRect = getLocalBounds();

	setOrigin(textRect.left + textRect.width / 2.0f,
			  textRect.top + textRect.height / 2.0f);
}
