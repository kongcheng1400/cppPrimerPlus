#ifndef QUEUETP_H_
#define QUEUETP_H_
template <class T>
class QueueTp
{
	private:
		struct Node 
		{
			T element;
			struct Node * pNext;
		};
		Node * pHead;
		Node * pTail;
		int count;	

	public:
		QueueTp();
		bool enqueue(const T & e);
		bool dequeue(T& e);
		virtual ~QueueTp();
		int getCount() const {return count;};
};

template <class T>
QueueTp<T> :: QueueTp()
{
	pHead = NULL;
	pTail = NULL;
	count = 0;

}


template <class T>
QueueTp<T>::~QueueTp()
{
	while (pHead != NULL)
	{
		Node * pTmp = pHead;
		pHead = pHead->pNext;
		count--;
		delete pTmp;
	}
	pTail = NULL;

}

template <class T>
bool QueueTp<T>::enqueue(const T & e)
{
	Node * pTmp = new Node;
	pTmp->element = e;
	pTmp->pNext = NULL;

	if (pTail != NULL) {
		pTail->pNext = pTmp;
		pTail = pTmp;
	}
	if (count == 0) {  //if it's the first element!
		pHead = pTmp;
		pTail = pTmp;
	}
	count++;
	return true;
}


template <class T>
bool QueueTp<T>::dequeue(T & e)
{
	if (pHead == NULL)
		return false;
	else
	{
		Node * pTmp = pHead;
		pHead = pHead->pNext;
		count--;
		e = pTmp->element;
		delete pTmp;
		if (pHead == NULL) //queue is empty.
			pTail = NULL;
		return true;	
	}

}

#endif
