#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABC
{
	private:
		char * label_m;
		int rating_m;
	
	public:
		ABC(const char * n = "nobody", int r = 0);
		ABC(const ABC & abcObj);
		virtual ~ABC();
		ABC & operator=(const ABC & obj);
		friend std::ostream & operator<<(std::ostream & os, const ABC & obj);
		virtual void view() = 0;
};



class BaseDMA : public ABC
{
	private:
		char * basic_m;

	public:
		BaseDMA(const char * l = "null", const char * b = "null", int r = 0);
		BaseDMA(const char * b, const ABC  & rs);
		virtual ~BaseDMA();
		virtual void view();
		BaseDMA & operator=(const BaseDMA & rs);
		friend std::ostream & operator<<(std::ostream & os, const BaseDMA & rs);
};

class LacksDMA : public ABC 
{
	private:
		enum {COL_LEN = 40};
		char color_m[COL_LEN];
	public:
		LacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
		LacksDMA(const char * c, const ABC  & rs);
		friend std::ostream & operator<<(std::ostream & os, const LacksDMA & rs);

		virtual void view();
};

class HasDMA : public ABC 
{
	private:
		char * style_m;
	public:
		HasDMA(const char * c = "none", const char * l = "null", int r = 0);
		HasDMA(const char * s, const ABC & rs);
		HasDMA(const HasDMA & hs);
		virtual ~HasDMA();
		HasDMA & operator=(const HasDMA & rs);
		friend std::ostream & operator<<(std::ostream & os, const HasDMA & rs);
		virtual void view();


};




#endif
