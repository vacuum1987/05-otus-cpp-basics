#include "IStatistics.hpp"
#include "Mean.hpp"

	Mean::Mean()  {
		m_mean = 0;
		sum_tmp = 0;
		arg_count = 0;
	};

	void Mean::update(double next)  {
		arg_count++;
		sum_tmp += next;
		m_mean = sum_tmp / arg_count;
	};

	double Mean::eval() const  {
		return m_mean;
	};

	const char * Mean::name() const  {
		return "mean";
	};