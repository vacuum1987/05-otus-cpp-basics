#pragma once
#include <vector>
#include "IStatistics.hpp"

class Std : public IStatistics {
public:
	Std();
	void update(double next) override;
	double eval() const override;
    const char * name() const override;
private:
	std::vector<double> values;
	double m_std;
	double sum_tmp;
	double m_mean;
	int arg_count;
};