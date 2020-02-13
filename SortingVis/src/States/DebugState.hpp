#pragma once

#include "BaseState.hpp"
#include "../GUI/Button.hpp"

class DebugState : public BaseState {
	private:
		Button			   m_Button;
		sf::RectangleShape m_Shape;
		sf::Text		   m_Text;

	public:
		DebugState(App& _app);
		~DebugState() = default;

		void HandleEvents(sf::Event& _ev)		 override;
		void HandleInput(float _dTime)			 override;
		void Update(float _dTime)				 override;
		void Render(sf::RenderTarget& _renderer) override;
};