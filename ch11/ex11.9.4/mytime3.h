#ifndef MYTIME2_H_
#define MYTIME2_H_
class Time
{
private:
	int hours;
	int minutes;
	
public:
	Time();
	Time(int h, int m = 0);
	void addmin(int m);
	void addhr(int h);
	void reset(int h = 0, int m = 0);
	friend Time operator+(const Time & t1, const Time & t2) ;
	friend Time operator-(const Time & t1, const Time & t2) ;
	friend Time operator*(const Time & t1, double n) ;
	friend Time operator*(double m, const Time & t) {return t * m;}
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
	void show() const;
};


#endif
