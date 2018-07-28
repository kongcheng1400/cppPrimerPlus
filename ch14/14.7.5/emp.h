#include <iostream>
#include <string>

class Abstr_emp
{
	private:
		std::string fname;
		std::string lname;
		std::string job;
	
	protected:
		void displayEmployee() const;
		void setEmployee();


	public:
		Abstr_emp();
		Abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
		virtual void showAll() const;
		virtual void setAll();
		friend std::ostream & operator<<(std::ostream &os,
				const Abstr_emp & e);
		virtual ~Abstr_emp() = 0;


};

class Employee : public Abstr_emp
{
	public:
		Employee();
		Employee(const std::string & fn, const std::string & ln,
				const std::string &j);
		virtual void showAll() const;
		virtual void setAll();
		virtual ~Employee() {};
};


class Manager : virtual public Abstr_emp
{
	private:
		int inChargeOf_m;
	protected:
		int inChargeOf() const { return inChargeOf_m;} 
		int & inChargeOf() { return inChargeOf_m;}
		void displayManager() const;
		void setManager();
	public:
		Manager();
		Manager(const std::string & fn, const std::string & ln,
				const std::string & j, int ico = 0);
		Manager(const Abstr_emp & e, int ico);
		Manager(const Manager & m);
		virtual void showAll() const;
		virtual void setAll();
		virtual ~Manager() {};

};

class Fink : virtual public Abstr_emp
{
	private:
		std::string reportsTo_m;
	protected:
		const std::string reportsTo() const { return reportsTo_m;}
		std::string & reportsTo() {return reportsTo_m;}
		void displayFink() const;
		void setFink();

	public:
		Fink();
		Fink(const std::string & fn, const std::string & ln,
				const std::string &j, const std::string & rpo);
		Fink(const Abstr_emp & e, const std::string & rpo);
		Fink(const Fink & e);
		virtual void showAll() const;
		virtual void setAll();
		virtual ~Fink() {};
};

class HighFink: public Manager, public Fink
{
	public:
		HighFink();
		HighFink(const std::string & fn, const std::string & ln,
				 const std::string & j, const std::string & rpo,
				 int ico);
		HighFink(const Abstr_emp & e, const std::string & rpo, int ico);
		HighFink(const Fink & f, int ico);
		HighFink(const Manager & m, const std::string & rpo);
		HighFink(const HighFink & h);

		virtual void showAll() const;
		virtual void setAll();

		virtual ~HighFink() {};


};












































