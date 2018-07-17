#ifndef STOCK_H_
#define STOCK_H_

class Stock
{
	private:
		char * name;
		int amount;
		double price;
		double totalvalue;

	public:
		Stock(const char *, int, double);
		~Stock();
		Stock();
		Stock(const Stock &);
		
		void show() const;
		const Stock & topval(const Stock &) const;








};





#endif
