#pragma once
#include <vector>
#include "IStatistics.hpp"

class Pct : public IStatistics {
public:
	Pct(int percentile);
	void update(double next) override;
	double eval() const override;
	const char * name() const override;

private:
	std::vector<double> values;
	int p_percentile;
	double m_pct;
};
