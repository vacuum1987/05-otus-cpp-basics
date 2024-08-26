#pragma once
#include "IStatistics.hpp"

class Mean : public IStatistics {
public:
	Mean();
	void update(double next) override;
	double eval() const override;
    const char * name() const override;
private:
	double sum_tmp;
	double m_mean;
	int arg_count;
};