#include <cmath>
#include "vector.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR
{
     const double Rad_to_deg = 45.0 / atan(1.0);
     double Vector::cal_mag() const
     {
         return sqrt(x_m*x_m + y_m * y_m);
     }
     double Vector::cal_ang() const
     {
		 double ang = 0.0;
         if (x_m == 0.0 && y_m == 0.0)
             ang = 0.0;
         else
             ang = atan2(y_m, x_m);
		 return ang;
     }
     void Vector::cal_x(double mag, double ang)
     {
         x_m = mag * cos(ang);
     }
	 void Vector::cal_y(double mag, double ang)
	 {
         y_m = mag * sin(ang);
     }
     Vector::Vector()
     {
         x_m = y_m = 0.0;
         mode_m = RECT;
     }
     Vector::Vector(double n1, double n2, Mode form)
     {
         mode_m = form;
         if (form == RECT)
         {
             x_m = n1;
             y_m = n2;
         }
         else if (form == POL)
         {
             cal_x(n1, n2);
             cal_y(n1, n2);
         }
         else
         {
             cout << "incorrect 3rd argument to Vector()--";
             cout << "vector set 0\n";
             x_m = y_m = 0.0;
             mode_m = RECT;
         }
     }
	 void Vector::reset(double n1, double n2, Mode form)
	 {

         mode_m = form;
         if (form == RECT)
         {
             x_m = n1;
             y_m = n2;
         }
         else if (form == POL)
         {
             cal_x(n1, n2);
             cal_y(n1, n2);
         }
         else
         {
             cout << "incorrect 3rd argument to Vector()--";
             cout << "vector set 0\n";
             x_m = y_m = 0.0;
             mode_m = RECT;
         }

	 }

     Vector::~Vector()
     {}
     void Vector::polar_mode()
     {
         mode_m = POL;
     }
     void Vector::rect_mode()
     {
         mode_m = RECT;
     }
     Vector Vector::operator+(const Vector & b) const
     {
         return Vector(x_m + b.x_m, y_m + b.y_m);
     }
     Vector Vector::operator-(const Vector & b) const
     {
         return Vector(x_m - b.x_m, y_m- b.y_m);
     }
     Vector Vector::operator-() const
     {
         return Vector(-x_m, -y_m);
     }
     Vector Vector::operator*(double n) const
     {
         return Vector(n * x_m, n * y_m);
     }
     std::ostream & operator<<(std::ostream & os, const Vector & v)
     {
         if (v.mode_m == Vector::RECT)
             os << "(x, y) = (" << v.x_m << " , " << v.y_m << ") ";
         else if (v.mode_m == Vector::POL)
         {
             os << "(m, a) = ( " << v.magval() << " , " 
                << v.angval() * Rad_to_deg << ")";
         }
         else
             os << "vector object mode is invalid";
         return os;
     }
}
