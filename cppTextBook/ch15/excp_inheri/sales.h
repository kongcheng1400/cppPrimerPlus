#include <stdexcept>
#include <string>

class Sales
{
	public:
		enum {MONTHS = 12};
		class bad_index : public std::logic_error
		{
			private:
				int bi; //bad index value
			public:
				explicit bad_index(int ix, const std::string & s\
						= "Index error in sales object\n");
				int bi_val() const {return bi;}
				virtual ~bad_index() throw() {}
		};

		explicit Sales(int yy=0);
		Sales(int yy, const double * gr, int n);
		virtual ~Sales() {}
		int year() const { return year_m;}
		virtual double operator[](int i) const;
		virtual double & operator[](int i);

	private:
		double gross[MONTHS];
		int year_m;

};

class LabeledSales : public Sales
{
	public:
		class nbad_index : public Sales::bad_index
		{
			private:
				std::string lbl;
			public:
				nbad_index(const std::string & lb, int ix,
						const std::string &s = "Index error in Labeled Sales object\n");
				const std::string & label_val() { return lbl;}
				virtual ~nbad_index() throw() {}
		};

		explicit LabeledSales(const std::string & lb = "none", int yy = 0);
		LabeledSales(const std::string & lb, int yy, const double * gr, int n);
		virtual ~LabeledSales() {}
		const std::string & label() const { return label_m;}
		virtual double operator[](int i) const;
		virtual double & operator[](int i);

	private:
		std::string label_m;



};













































