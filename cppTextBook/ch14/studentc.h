#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
	private:
		typedef std::valarray<double> ArrayDb;
		std::string name_m;
		ArrayDb scores_m;

		//private method
		std::ostream & arr_out(std::ostream & os) const;

	public:
		Student() : name_m("Null student"), scores_m() {}
		explicit Student(const std::string & s) : name_m(s), scores_m() {}
		explicit Student(int n) : name_m("Null student"), scores_m(n) {}
		Student(const std::string & s, int n) : name_m(s), scores_m(n) {}
		Student(const std::string & s, const ArrayDb & a): name_m(s), scores_m(a) {}
		Student(const char * str, const double * pd, int n) : name_m(str), scores_m(pd, n) {};
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
