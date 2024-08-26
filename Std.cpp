#include "IStatistics.hpp"
#include <vector>
#include "Std.hpp"

	Std::Std()  {
		std::vector<double> values = {0};
		m_std = 0;
		m_mean = 0;
		sum_tmp = 0;
		arg_count = 0;
	};

	void Std::update(double next) {
		arg_count++;
		sum_tmp += next;
		m_mean = sum_tmp / arg_count;
		values.push_back(next);
	};

	double Std::eval() const {
		int vector_size = static_cast<int>(values.size());
		double D = 0;
		for (int i=0 ; i <vector_size;++i) {
			D += (values[i] - m_mean)*(values[i] - m_mean);
		};
		double m_std = sqrt (D / (vector_size - 1));
		return m_std;
	};

	const char * Std::name() const {
		return "std";
	};