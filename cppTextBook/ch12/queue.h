#ifndef QUEUE_H_
#define QUEUE_H_


#include "customer.h"


typedef Customer Item;
class Queue
{
	enum {Q_SIZE = 10};
	
	private:
		struct Node {Item item; struct Node * next;};
		Node * front;
		Node * rear;
		int items;
		const int qsize;

		Queue(const Queue & q) : qsize(0){};
		Queue & operator=(const Queue & q) { return * this;}

	public:
		Queue(int qs = Q_SIZE);
		~Queue();
		bool isempty() const;
		bool isfull() const;
		int queuecount() const;
		bool enqueue(const Item & item);
		bool dequeue(Item & item);



};



#endif
