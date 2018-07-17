#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
	private:
		Item * pitems;		//holds stack items
		int size;
		int top;

	public:
		enum {MAX = 10};
		Stack(int n = MAX);
		Stack(const Stack & st);
		~Stack();
		Stack & operator=(const Stack & st);

		bool isempty() const;
		bool isfull() const;

		bool push(const Item & item); 
		bool pop(Item & item);








};






#endif
