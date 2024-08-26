#include <iostream>
//#include <limits>
//#include <vector>
//#include <cmath>
#include "IStatistics.hpp"
#include "Min.hpp"
#include "Max.hpp"
#include "Mean.hpp"
#include "Std.hpp"
#include "Pct.hpp"

int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count]= {new Min{}, new Max{}, new Mean{}, new Std{}, new Pct(90), new Pct(95) };
	
	//IStatistics *statistics[statistics_count];

	//statistics[0] = new Min{};
	// statistics[1] = new Max{};
	// statistics[2] = new Mean{};
	// statistics[3] = new Std{};
	// statistics[4] = new Pct(90);
	// statistics[5] = new Pct(95);

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
			//std::cout << "val" << " = " << val << std::endl;
			
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}