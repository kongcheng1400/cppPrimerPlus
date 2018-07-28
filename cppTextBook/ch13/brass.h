#ifndef BRASS_H_
#define BRASS_H_

#include <string>

class Brass
{
	private:
		std::string fullName_m;
		long acctNum_m;
		double balance_m;
	public:
		Brass(const std::string & s = "Nullbody", long an = -1,
					double bal = 0.0);
		void deposit(double amt);
		virtual void withdraw(double amt);
		double balance() const;
		virtual void viewAcct() const;
		virtual ~Brass(){};

};


class BrassPlus : public Brass
{
	private:
		double maxLoan_m;
		double rate_m;
		double owesBank_m;

	public:
		BrassPlus(const std::string & s = "Nullbody", long an = -1,
					double bal = 0.0, double ml = 500, double r = 0.11125);

		BrassPlus(const Brass & ba, double ml = 550, double r = 0.11125);
		virtual void viewAcct() const;
		virtual void withdraw(double amt);
		void resetMax(double m) {maxLoan_m = m;}
		void resetRate(double r) {rate_m = r;}
		void resetOwes() {owesBank_m = 0;}


};



#endif
