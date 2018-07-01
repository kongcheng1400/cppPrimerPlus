#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
	public:
		enum format {ST, PND};
		static const int PndPerSt = 14;

	private:
		int st_m;
		double pnd_m;
		double pnd_left_m;
		format fmt_m;
		void pndToSt() {st_m = int(pnd_m)/PndPerSt; pnd_left_m = pnd_m - st_m * PndPerSt;}
		void stToPnd() {pnd_m = st_m * PndPerSt + pnd_left_m;}

	public:
		Stonewt(); 
		Stonewt(double pnd, format fmt=PND);
		Stonewt(int  st, double pnd, format fmt=ST);
		~Stonewt() {};
		Stonewt operator+(const Stonewt & st) const;
		Stonewt operator-(const Stonewt & st) const;
		Stonewt operator*(const double n) const;
		bool operator<(const Stonewt & st) const;
		bool operator>(const Stonewt & st) const;
		bool operator==(const Stonewt & st) const;
		friend Stonewt operator*(const double n, const Stonewt st);
		friend std::ostream & operator<<(std::ostream & os, const Stonewt st);


};

#endif
