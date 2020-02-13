#pragma once

#include <SFML/Graphics.hpp>

class Widget {
	protected:
		class Rectangle : public sf::RectangleShape {
			public:
				Rectangle(const sf::Vector2f& _size);

				bool IsRolledOn(const sf::RenderWindow& _window) const;
				bool IsClickedOn(const sf::RenderWindow& _window, sf::Event& _ev);
		};

		class Text : public sf::Text {
			public:
				Text();

				void SetFontSize(unsigned int _fontSize);
				void UpdateText();
		};

	public:
		virtual void HandleEvents(const sf::RenderWindow& _window, sf::Event& _event) = 0;
		virtual void Render(sf::RenderTarget& _renderer)							  = 0;
		virtual void SetPosition(const sf::Vector2f& _pos)							  = 0;
		virtual sf::Vector2f GetSize() const										  = 0;
};