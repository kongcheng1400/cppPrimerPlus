#ifndef QUEUE_H_
#define QUEUE_H_

#include "customer.h"

typedef Customer Item;

struct Node 
{
	Item it;
	struct Node * pnext;
};

class Queue
{
	private:
		Node * head;
		Node * tail;
		int nodeCount;
		const int QSIZE;

	public:
		Queue(int size = 10);
		~Queue();

		bool isfull();
		bool isempty();
		bool enqueue(const Item &);
		bool dequeue(Item &);
		bool getHead(Item &);
};




#endif
