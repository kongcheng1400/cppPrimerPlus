#include "customer.h"

Customer::Customer()
{
	customerID = 0;
	arrivedTime = 0;
	enqueuedTime = 0;

}


Customer::Customer(int cID, int arrTime)
{
	customerID = cID;
	arrivedTime = arrTime;
	enqueuedTime = 0;

}

Customer::Customer(const Customer & cst)
{
	customerID = cst.customerID;
	arrivedTime = cst.arrivedTime;
	enqueuedTime = cst.enqueuedTime;
}


std::ostream & operator<<(std::ostream & os, Customer cust)
{
	os << "CID " << cust.customerID << " ArrTime: " << cust.arrivedTime;
	return os;
}

Customer & Customer::operator=(const Customer & cst)
{
	if (this == &cst)
		return *this;

	customerID = cst.customerID;
	arrivedTime = cst.arrivedTime;
	enqueuedTime = cst.enqueuedTime;
	return *this;
}

