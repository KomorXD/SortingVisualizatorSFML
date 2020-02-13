#pragma once

#include "../App.hpp"

#include <SFML/Graphics.hpp>

struct Bar {
	sf::RectangleShape body;
	unsigned		   value;

	Bar(const sf::Vector2f& _size, unsigned _value);
};

class Sort {
	private:
		Sort();

	public:
		static Sort& Get();

		void BubbleSort(std::vector<Bar>* bars, App* app);
		void QuickSort(std::vector<Bar>* bars, int left, int right, App* app);
		void InsertionSort(std::vector<Bar>* bars, App* app);
};