#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class BadHMean : public std::logic_error
{
	private:
		double v1;
		double v2;
		std::string funcName;
	public:
		BadHMean(double a = 0, double b = 0, const std::string & exTyp = "BadHMean",
				const std::string & fn = "ABC") : std::logic_error(exTyp), v1(a), v2(b), funcName(fn) {};

		std::string msg() { return funcName + " invalid paramter: " + to_string(v1) + " and " + to_string(v2);}
		virtual ~BadHMean() throw() {}
};



class BadGMean : public std::logic_error
{
	private:
		double v1;
		double v2;
		std::string funcName;
	public:
		BadGMean(double a = 0, double b = 0, const string & exType = "BadGmean",
				const std::string & fn = "CDE") : v1(a), v2(b), std::logic_error(exType), funcName(fn) {}

		std::string msg() { return funcName + " invalid paramter: " + to_string(v1) + " and " + to_string(v2);}
		virtual ~BadGMean() throw() {}

};


