#include "SortingState.hpp"
#include "../App.hpp"
#include "../Utilities/Random.hpp"

Bar::Bar(const sf::Vector2f& _size, unsigned _value)
	: body(_size), value(_value) { }

void SortingState::ShuffleBars() {
	for (unsigned i = 0; i < m_Bars.size(); i++) {
		sf::Vector2f tempPos = m_Bars[i].body.getPosition();
		unsigned tempValue = m_Bars[i].value;
		unsigned randIndex = Random::Get().IntInRange(0, m_Bars.size() - 1);

		m_Bars[i].body.setPosition(m_Bars[randIndex].body.getPosition());
		m_Bars[randIndex].body.setPosition(tempPos);

		m_Bars[i].value = m_Bars[randIndex].value;
		m_Bars[randIndex].value = tempValue;
	}
}

SortingState::SortingState(App& _app)
	: BaseState(_app), m_State(STATE::PREP), m_BubbleText({ 1.0f, 1.0f }, "1 - Bubble Sort"), m_QuickText({ 1.0f, 1.0f }, "2 - Quick Sort")
	, m_InsertionText({ 1.0f, 1.0f }, "3 - Insertion Sort") {

	sf::Vector2f windowSize = static_cast<sf::Vector2f>(m_p_App->GetWindow().getSize());

	m_Bars.reserve(static_cast<unsigned>(windowSize.x));

	float scalar = 0.5f;
	
	for (unsigned i = 0; i < m_Bars.capacity(); i++)
		m_Bars.emplace_back(sf::Vector2f(windowSize.x / m_Bars.capacity(), (i + 1) * scalar), i);

	for (unsigned i = 0; i < m_Bars.size(); i++) {
		m_Bars[i].body.setOrigin(0.0f, m_Bars[i].body.getSize().y);
		m_Bars[i].body.setPosition(i * windowSize.x / m_Bars.size(), windowSize.y);
	}

	ShuffleBars();

	m_BubbleText.SetPosition({ windowSize.x / 8.0f, windowSize.y / 12.0f });
	m_BubbleText.SetBgColor(sf::Color::Black);

	m_QuickText.SetPosition({ windowSize.x / 8.0f, windowSize.y / 7.0f });
	m_QuickText.SetBgColor(sf::Color::Black);

	m_InsertionText.SetPosition({ windowSize.x / 8.0f, windowSize.y / 5.0f });
	m_InsertionText.SetBgColor(sf::Color::Black);
}

void SortingState::HandleEvents(sf::Event& _ev) {
	if (_ev.type == sf::Event::KeyPressed) {
		switch (_ev.key.code) {
			case sf::Keyboard::Escape:
				if (m_State != STATE::SORTING)
					m_p_App->CloseWindow();
				
				break;

			default:
				break;
		}
	}
}

void SortingState::HandleInput(float _dTime) {
	if (m_State != STATE::SORTING) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			ShuffleBars();
			m_State = STATE::SORTING;
			Sort::Get().BubbleSort(&m_Bars, m_p_App);
			m_State = STATE::END;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			ShuffleBars();
			m_State = STATE::SORTING;
			Sort::Get().QuickSort(&m_Bars, 0, m_Bars.size() - 1, m_p_App);
			m_State = STATE::END;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			ShuffleBars();
			m_State = STATE::SORTING;
			Sort::Get().InsertionSort(&m_Bars, m_p_App);
			m_State = STATE::END;
		}
	}
}

void SortingState::Update(float _dTime) {
	for (auto& bar : m_Bars) {
		const sf::Color& barColor = bar.body.getFillColor();

		if (barColor.b < 200)
			bar.body.setFillColor(sf::Color(255, barColor.g + 127, barColor.b + 127));
	}
}

void SortingState::Render(sf::RenderTarget& _renderer) {
	for (auto& bar : m_Bars)
		_renderer.draw(bar.body);

	if (m_State != STATE::SORTING) {
		m_BubbleText.Render(_renderer);
		m_QuickText.Render(_renderer);
		m_InsertionText.Render(_renderer);
	}
}