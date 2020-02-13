#include "Sort.hpp"

Sort::Sort() { }

Sort& Sort::Get() {
	static Sort instance;

	return instance;
}

void Sort::BubbleSort(std::vector<Bar>* bars, App* app) {
	int interval = 0;

	for (unsigned i = 0; i < bars->size() - 1; i++) {
		for (unsigned j = 0; j < bars->size() - i - 1; j++) {
			if (bars->at(j).value > bars->at(j + 1).value) {
				sf::Vector2f tempPos = bars->at(j).body.getPosition();

				bars->at(j).body.setPosition(bars->at(j + 1).body.getPosition());
				bars->at(j + 1).body.setPosition(tempPos);

				std::swap(bars->at(j).value, bars->at(j + 1).value);

				bars->at(j).body.setFillColor(sf::Color::Red);
				bars->at(j + 1).body.setFillColor(sf::Color::Red);

				if (interval > 200) {
					app->RunGameLoopIteration();
					interval = 0;
				}

				interval++;
			}
		}
	}
}

void Sort::QuickSort(std::vector<Bar>* bars, int left, int right, App* app) {
	int min = (left + right) / 2;
	int i = left;
	int j = right;
	unsigned pivot = bars->at(min).value;

	while (left < j || i < right) {
		while (bars->at(i).value < pivot)
			i++;

		while (bars->at(j).value > pivot)
			j--;

		app->RunGameLoopIteration();

		if (i <= j) {
			sf::Vector2f tempPos = bars->at(i).body.getPosition();

			bars->at(i).body.setPosition(bars->at(j).body.getPosition());
			bars->at(j).body.setPosition(tempPos);

			std::swap(bars->at(i).value, bars->at(j).value);

			bars->at(i).body.setFillColor(sf::Color::Red);
			bars->at(j).body.setFillColor(sf::Color::Red);

			i++;
			j--;
		}
		else {
			if (left < j)
				QuickSort(bars, left, j, app);
			if (i < right)
				QuickSort(bars, i, right, app);

			return;
		}
	}
}

void Sort::InsertionSort(std::vector<Bar>* bars, App* app) {
	int j, key;

	for (unsigned i = 1; i < bars->size(); i++) {
		key = bars->at(i).value;
		j = i - 1;

		while (j >= 0 && bars->at(j).value > key) {
			sf::Vector2f tempPos = bars->at(j).body.getPosition();

			bars->at(j).body.setPosition(bars->at(j + 1).body.getPosition());
			bars->at(j + 1).body.setPosition(tempPos);

			std::swap(bars->at(j + 1).value, bars->at(j).value);

			bars->at(j).body.setFillColor(sf::Color::Red);
			bars->at(j + 1).body.setFillColor(sf::Color::Red);

			j--;
		}

		app->RunGameLoopIteration();

		bars->at(j + 1).value = key;
	}
}
