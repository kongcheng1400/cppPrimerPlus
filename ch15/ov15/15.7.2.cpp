class A;
class B
{
	friend A:bf(B & b);
	af(A & a);
}

class A
{
	friend B:af(A & a);
	bf(B & b) {...}

}
B::af(A & a)
{





















}
