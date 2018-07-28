#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double>
{
	private:
		typedef std::valarray<double> ArrayDb;

		//private method
		std::ostream & arr_out(std::ostream & os) const;

	public:
		Student() : std::string("Null student"), ArrayDb() {}
		explicit Student(const std::string & s) : std::string(s), ArrayDb() {}
		explicit Student(int n) : std::string("Null student"), ArrayDb(n) {}
		Student(const std::string & s, int n) : std::string(s), ArrayDb(n) {}
		Student(const std::string & s, const ArrayDb & a): std::string(s), ArrayDb(a) {}
		Student(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {};
	   ~Student() {};

		double average() const;
		const std::string & name() const;
		double & operator[](int i);
		double operator[](int i) const;		

		//friends
		friend std::istream & operator>>(std::istream & is, Student & stu);
		friend std::istream & getline(std::istream & is, Student & stu);

		friend std::ostream & operator<<(std::ostream & os, const Student & stu);


};







#endif
