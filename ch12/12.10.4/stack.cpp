#include <iostream>
#include "stack.h"


Stack::Stack(int n)
{
	int size = 0;
	int top = 0;
	pitems = new Item[MAX];

}


Stack::~Stack()
{
	delete [] pitems;

}

Stack::Stack(const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[MAX];

	for (int i = 0; i < size; i++)
	{
		*(pitems + i) = *(st.pitems + i);
	
	}

}


Stack & Stack::operator=(const Stack & st)
{
	if (this == &st)
		return *this;
	
	for (int i = 0; i < st.size; i++)
		*(pitems + i) = *(st.pitems + i);

	size = st.size;
	top = st.top;
	return *this;

}

bool Stack::isempty() const
{
	return size == 0;

}

bool Stack::isfull() const
{
	return size == MAX;

}

bool Stack::push(const Item & item)
{
	if (isfull())
		return false;

	*(pitems+top) = item;
	size++;
	top++;
	return true;

}

bool Stack::pop(Item & item)
{
	if (isempty())
		return false;
	
	item = *(pitems + top - 1);
	size--;
	top--;
	return true;

}



