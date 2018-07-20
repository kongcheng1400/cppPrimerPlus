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
		int getCount() const;
};
