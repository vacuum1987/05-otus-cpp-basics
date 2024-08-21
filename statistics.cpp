#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double eval() const override {
		return m_max;
	}

	const char * name() const override {
		return "max";
	}

private:
	double m_max;
};


class Mean : public IStatistics {
public:
	Mean()  {
		m_mean = 0;
		sum_tmp = 0;
		arg_count = 0;
	}

	void update(double next) override {
		arg_count++;
		sum_tmp += next;
		m_mean = sum_tmp / arg_count;
	}

	double eval() const override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";
	}

	
private:
	double sum_tmp;
	double m_mean;
	int arg_count;
};



class Std : public IStatistics {
public:
	Std()  {
		std::vector<double> values = {0};
		m_std = 0;
		m_mean = 0;
		sum_tmp = 0;
		arg_count = 0;
	}

	void update(double next) override {
		arg_count++;
		sum_tmp += next;
		m_mean = sum_tmp / arg_count;
		values.push_back(next);
		
	}

	double eval() const override {
		int vector_size = static_cast<int>(values.size());
		double D = 0;
		for (int i=0 ; i <vector_size;++i) {
			D += (values[i] - m_mean)*(values[i] - m_mean);
		};
		double m_std = sqrt (D / (vector_size - 1));
		return m_std;
	}

	const char * name() const override {
		return "std";
	}



private:
	std::vector<double> values;
	double m_std;
	double sum_tmp;
	double m_mean;
	int arg_count;
};


class Pct : public IStatistics {
public:
	Pct(int percentile)  {
		std::vector<double> values = {0};
		p_percentile = percentile;
		

	}

	void update(double next) override {
		
		
		values.push_back(next);
		
	}

	double eval() const override {
		int vector_size = static_cast<int>(values.size());
		int n = vector_size * p_percentile / 100; 			// получаем номер элемента массива в виде int с округлением в меньшую сторону из-за неявного преобразования
		//std::cout << "n" << " = " << n << std::endl;
		std::vector<double> test_data = values;
		std::sort(test_data.begin(), test_data.end());
		double m_pct = test_data[n];
		//std::cout << "pct" << p_percentile << " = " << m_pct << std::endl;
		return m_pct;
	}

	const char * name() const override {
		std::string pct_name_str = {"pct"};
		pct_name_str +=  std::to_string (p_percentile);
		//char const * pct_name_char = pct_name_str.c_str();
		std::cout <<  pct_name_str;
		//std::cout << "char" << " = " << pct_name_char << std::endl;
		
		//std::cout << "char*" << " = " << *pct_name_char << std::endl;
		return "";
	}



private:
	std::vector<double> values;
	int p_percentile;
	double m_pct;
	
};



int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};
	statistics[4] = new Pct(90);
	statistics[5] = new Pct(95);

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