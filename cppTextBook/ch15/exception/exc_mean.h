#include <iostream>

class BadHMean
{
	private:
		double v1;
		double v2;

	public:
		BadHMean(double a = 0, double b = 0) : v1(a), v2(b) {}
		void msg();

};

inline void BadHMean::msg()
{
	std::cout << "hman(" << v1 << "," << v2 << "):"
			  << "invalid arguments: a = -b\n";
}

class BadGMean
{
	public:
		double v1;
		double v2;
		BadGMean(double a = 0, double b = 0) : v1(a), v2(b) {}

		const char * msg();
};

inline const char * BadGMean::msg()
{
	return "gmean() arguments should be > = 0\n";
}
