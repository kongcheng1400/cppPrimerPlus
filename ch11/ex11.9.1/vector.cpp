#include <cmath>
#include "vector.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR
{
     const double Rad_to_deg = 45.0 / atan(1.0);
     void Vector::set_mag()
     {
         mag_m = sqrt(x_m*x_m + y_m * y_m);
     }
     void Vector::set_ang()
     {
         if (x_m == 0.0 && y_m == 0.0)
             ang_m = 0.0;
         else
             ang_m = atan2(y_m, x_m);
     }
     void Vector::set_x()
     {
         x_m = mag_m * cos(ang_m);
     }
	 void Vector::set_y()
	 {
         y_m = mag_m * sin(ang_m);
     }
     Vector::Vector()
     {
         x_m = y_m = mag_m = ang_m = 0.0;
         mode_m = RECT;
     }
     Vector::Vector(double n1, double n2, Mode form)
     {
         mode_m = form;
         if (form == RECT)
         {
             x_m = n1;
             y_m = n2;
             set_mag();
             set_ang();
         }
         else if (form == POL)
         {
             mag_m = n1;
             ang_m = n2;
             set_x();
             set_y();
         }
         else
         {
             cout << "incorrect 3rd argument to Vector()--";
             cout << "vector set 0\n";
             x_m = y_m = mag_m = ang_m = 0.0;
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
             set_mag();
             set_ang();
         }
         else if (form == POL)
         {
             mag_m = n1;
             ang_m = n2;
             set_x();
             set_y();
         }
         else
         {
             cout << "incorrect 3rd argument to Vector()--";
             cout << "vector set 0\n";
             x_m = y_m = mag_m = ang_m = 0.0;
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
     Vector operator*(double n, const Vector & a)
     {
         return a * n;
     }
     std::ostream & operator<<(std::ostream & os, const Vector & v)
     {
         if (v.mode_m == Vector::RECT)
             os << "(x, y) = (" << v.x_m << " , " << v.y_m << ") ";
         else if (v.mode_m == Vector::POL)
         {
             os << "(m, a) = ( " << v.mag_m << " , " 
                << v.ang_m * Rad_to_deg << ")";
         }
         else
             os << "vector object mode is invalid";
             return os;
     }
}
