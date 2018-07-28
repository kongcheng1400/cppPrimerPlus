#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class BaseDMA
{
	private:
		char * label_m;
		int rating_m;

	public:
		BaseDMA(const char * l = "null", int r = 0);
		BaseDMA(const BaseDMA & rs);
		virtual ~BaseDMA();
		BaseDMA & operator=(const BaseDMA & rs);
		friend std::ostream & operator<<(std::ostream & os, const BaseDMA & rs);
};

class LacksDMA : public BaseDMA
{
	private:
		enum {COL_LEN = 40};
		char color_m[COL_LEN];
	public:
		LacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
		LacksDMA(const char * c, const BaseDMA & rs);
		friend std::ostream & operator<<(std::ostream & os, const LacksDMA & rs);

};

class HasDMA : public BaseDMA
{
	private:
		char * style_m;
	public:
		HasDMA(const char * c = "none", const char * l = "null", int r = 0);
		HasDMA(const char * s, const BaseDMA & rs);
		HasDMA(const HasDMA & hs);
		~HasDMA();

		void operator=(const HasDMA & rs);
		friend std::ostream & operator<<(std::ostream & os, const HasDMA & rs);



};




#endif
