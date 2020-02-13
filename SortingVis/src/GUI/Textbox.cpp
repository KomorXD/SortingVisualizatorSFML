#include "Textbox.hpp"

Textbox::Textbox(const sf::Vector2f& _size)
	: m_Box(_size) {

	m_Box.setFillColor(sf::Color(33, 33, 33));
	m_Box.setOrigin(m_Box.getSize() / 2.0f);

	m_Text.UpdateText();
}

Textbox::Textbox(const sf::Vector2f& _size, const std::string& _text)
	: m_Box(_size) {

	m_Box.setFillColor(sf::Color(33, 33, 33));
	m_Box.setOrigin(m_Box.getSize() / 2.0f);

	m_Text.setString(_text);
	m_Text.UpdateText();
}

void Textbox::SetText(const std::string& _text) {
	m_Text.setString(_text);
	m_Text.UpdateText();
}

void Textbox::SetFontSize(unsigned int _fontSize) {
	m_Text.setCharacterSize(_fontSize);
	m_Text.UpdateText();
}

void Textbox::SetBgColor(uint8_t r, uint8_t g, uint8_t b) {
	m_Box.setFillColor(sf::Color(r, g, b));
}

void Textbox::SetBgColor(const sf::Color& _color) {
	m_Box.setFillColor(_color);
}

void Textbox::HandleEvents(const sf::RenderWindow& _window, sf::Event& _event) {
	;
}

void Textbox::Render(sf::RenderTarget& _renderer) {
	_renderer.draw(m_Box);
	_renderer.draw(m_Text);
}

void Textbox::SetPosition(const sf::Vector2f& _pos) {
	m_Box.setPosition(_pos);
	m_Text.setPosition(_pos);

	m_Text.UpdateText();
}

sf::Vector2f Textbox::GetSize() const {
	return m_Box.getSize();
}
