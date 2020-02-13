#pragma once

#include "Widget.hpp"

class Textbox : public Widget {
	protected:
		Rectangle m_Box;
		Text	  m_Text;

	public:
		Textbox(const sf::Vector2f& _size);
		Textbox(const sf::Vector2f& _size, const std::string& _text);

		void SetText(const std::string& _text);
		void SetFontSize(unsigned int _fontSize);
		void SetBgColor(uint8_t r, uint8_t g, uint8_t b);
		void SetBgColor(const sf::Color& _color);

		void HandleEvents(const sf::RenderWindow& _window, sf::Event& _event) override;
		void Render(sf::RenderTarget& _renderer)							  override;
		void SetPosition(const sf::Vector2f& _pos)							  override;
		sf::Vector2f GetSize() const										  override;
};