#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
	private:
		enum {Lbs_per_stn = 14};
		int stone;
		double pds_left;
		double pounds;

	public:
		Stonewt(double lbs);
		Stonewt(int stn, double lbs);
		Stonewt();
		~Stonewt();

		void show_lbs() const;
		void show_stn() const;

		explicit operator double() const;
		explicit operator int() const;
		
		Stonewt operator*(double mul);
		friend Stonewt operator*(double mul, Stonewt & st);
	    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st) ;
};

#endif

