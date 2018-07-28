#include "studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::average() const
{
	if (scores_m.size() >0)
		return scores_m.sum() / scores_m.size();
	else
		return 0;
}

const string & Student::name() const
{
	return name_m;
}

double & Student::operator[](int i)
{
	return scores_m[i];
}

double Student::operator[](int i) const
{
	return scores_m[i];
}

ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = scores_m.size();
	if (lim > 0)
	{
		for (i= 0; i < lim; i++)
		{
			os << scores_m[i] << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if ( i % 5 != 0)
			os << endl;
					
	}
	else
		os << " empty array ";

	return os;
}

istream & operator>>(istream & is, Student & stu)
{
	is >> stu.name_m;
	return is;
}

istream & getline(istream & is, Student & stu)
{
	getline(is, stu.name_m);
	return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
	os << "Scores for " << stu.name_m << ":\n";
	stu.arr_out(os);
	return os;

}



































