#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>

class Customer
{
	private:
		int customerID;
		int arrivedTime;
		int enqueuedTime;


	public:
		Customer();
		Customer(int cID, int arrTime);
		Customer(const Customer & cst);
		void setEnqueueTime(int inQTime) {enqueuedTime = inQTime;}
		int getArrivedTime() { return arrivedTime;}
		int getEnqueuedTime() {return enqueuedTime;}
		friend std::ostream & operator<<(std::ostream & os, Customer cust);

		Customer & operator=(const Customer & cst);

};

#endif
