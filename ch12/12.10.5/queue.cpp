#include "queue.h"

Queue::Queue(int sz) : QSIZE(sz) 
{
	head = NULL;
	tail = NULL;
	nodeCount = 0;

}

Queue::~Queue()
{
	while(head != NULL)
	{
		Node * temp = head;
		head = head->pnext;
		delete temp;
		nodeCount--;
	}
}

bool Queue::isfull()
{
	return nodeCount == QSIZE;
}


bool Queue::isempty()
{
	return nodeCount == 0;
}


bool Queue::enqueue(const Item & itemIn)
{
	if (isfull())
	{
		std::cout << "\nQueue is full.\n";
		return false;
	}

	Node * pnode = new Node;
	pnode->it = itemIn; 
	pnode->pnext = NULL;

	if (isempty())// if there is only one node
	{
		head = pnode;
		tail = pnode;
	}
	else
   	{
		//enqueue at tail:
		tail->pnext = pnode;
		tail = pnode;
	}
	nodeCount++;

	return true;
}



bool Queue::dequeue(Item & itemOut)
{
	if (isempty())
		return false;

	itemOut = head->it;
	Node * pTemp = head;

	if (nodeCount == 1)
	{
		head = tail = NULL;
	
	}	
	else
	{
		head = head->pnext;
	
	}
	nodeCount--;
	delete pTemp;
	return true;
}

bool Queue::getHead(Item & itOut)
{
	if (isempty())
		return false;
	else
	{
		itOut = head->it;
		return true;
	}
}
