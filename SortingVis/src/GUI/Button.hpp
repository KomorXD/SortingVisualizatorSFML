#pragma once

#include "Textbox.hpp"

#include <functional>

class Button : public Textbox {
	protected:
		std::function<void(void)> m_Func;

	public:
		Button(const sf::Vector2f& _size);
		Button(const sf::Vector2f& _size, const std::string& _text);

		void SetFunction(std::function<void(void)> _f);

		void HandleEvents(const sf::RenderWindow& _window, sf::Event& _ev) override;
};