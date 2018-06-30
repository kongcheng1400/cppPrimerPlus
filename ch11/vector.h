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
		double mag_m;
		double ang_m;
		Mode mode_m;
		
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		
		double xval() const {return x_m;}
		double yval() const {return y_m;}
		double magval() const {return mag_m;}
		double angval() const {return ang_m;}
	
		void polar_mode();
		void rect_mode();
		
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream &
			operator<<(std::ostream & os, const Vector & v);
	
	};
}


#endif
