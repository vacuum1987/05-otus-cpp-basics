#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "IStatistics.hpp"
#include "Pct.hpp"


	Pct::Pct(int percentile)  {
		std::vector<double> values = {0};
		p_percentile = percentile;
	};

	void Pct::update(double next) {
		values.push_back(next);
	};

	double Pct::eval() const  {
		int vector_size = static_cast<int>(values.size());
		int n = vector_size * p_percentile / 100; 			// получаем номер элемента массива в виде int с округлением в меньшую сторону из-за неявного преобразования
		//std::cout << "n" << " = " << n << std::endl;
		std::vector<double> test_data = values;
		std::sort(test_data.begin(), test_data.end());
		double m_pct = test_data[n];
		//std::cout << "pct" << p_percentile << " = " << m_pct << std::endl;
		return m_pct;
	};

	const char * Pct::name() const {
		std::string pct_name_str = {"pct"};
		pct_name_str +=  std::to_string (p_percentile);
		//char const * pct_name_char = pct_name_str.c_str();
		std::cout <<  pct_name_str;
		//std::cout << "char" << " = " << pct_name_char << std::endl;
		
		//std::cout << "char*" << " = " << *pct_name_char << std::endl;
		return "";
	};