#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

class AcctABC
{
	private:
		std::string fullName_m;
		long acctNum_m;
		double balance_m;

	protected:
		struct Formatting
		{
			std::ios_base::fmtflags flag_m;
			std::streamsize pr_m;
		};

		long acctNum() const {return acctNum_m;};
		const std::string & fullName() const {return fullName_m;}
		Formatting setFormat() const;
		void restore(Formatting & f) const;

	public:
		AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
		void deposit(double amt);
		virtual void withdraw(double amt) = 0;
		double balance() const {return balance_m;};
		virtual void viewAcct() const = 0;
		virtual ~AcctABC() {}
};


class Brass : public AcctABC
{
	public:
		Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0): AcctABC(s, an, bal) {};
		virtual void withdraw(double amt);
		virtual void viewAcct() const;
		virtual ~Brass(){}	


};

class BrassPlus : public AcctABC
{
	private:
		double maxLoan_m;
		double rate_m;
		double owesBank_m;

	public:
		BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1);
		BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
		virtual void viewAcct() const;
		virtual void withdraw(double amt);
		void resetMax(double m) {maxLoan_m = m;}
		void resetRate(double r) {rate_m = r;}
		void resetOwes() {owesBank_m = 0;}



};





#endif
