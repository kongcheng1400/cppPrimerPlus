#ifndef PAIR_H_
#define PAIR_H_

template <typename U, typename V> 
class Pair
{
	private:
		U first_m;
		V second_m;
	public:
		Pair(U f, V s)
		  : first_m(f), second_m(s) {};
		U & first() {return first_m;}
		V & second() {return second_m;}
		const U & first() const { return first_m;}
		const V & second() const {return second_m;}
};

#endif
