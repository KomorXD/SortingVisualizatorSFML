#pragma once

#include "BaseState.hpp"
#include "../GUI/Textbox.hpp"
#include "../Utilities/Sort.hpp"

#include <vector>

enum class STATE {
	PREP,
	SORTING,
	END
};

class SortingState : public BaseState {
	private:
		std::vector<Bar> m_Bars;
		STATE			 m_State;

		Textbox m_BubbleText;
		Textbox m_QuickText;
		Textbox m_InsertionText;

		void ShuffleBars();

	public:
		SortingState(App& _app);
		~SortingState() = default;

		void HandleEvents(sf::Event& _ev)		 override;
		void HandleInput(float _dTime)			 override;
		void Update(float _dTime)				 override;
		void Render(sf::RenderTarget& _renderer) override;
};