#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT, POL};
		
	private:
		double x_m;
		double y_m;
		Mode mode_m;
		
		double cal_mag() const;
		double cal_ang() const;
		void cal_x(double mag, double ang);
		void cal_y(double mag, double ang);
	
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		
		double xval() const {return x_m;}
		double yval() const {return y_m;}
		double magval() const {return cal_mag();}
		double angval() const {return cal_ang();}
	
		void polar_mode();
		void rect_mode();
		
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		
		friend std::ostream &
			operator<<(std::ostream & os, const Vector & v);
	
	};
}


#endif
