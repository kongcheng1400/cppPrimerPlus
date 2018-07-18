#include <string>
#include <valarray>
#include <utility>

using std::string;
using std::pair;
using std::valarray;

typedef valarray<int> ArrayInt;
typedef pair<ArrayInt, ArrayInt> PairArray;

class Wine : private string, private PairArray 
{
	private:
		int years;
	
	public:
		Wine(const char * br, int yrs, int y[], int b[]);
		Wine(const char * br, int yrs);
		void getBottles();
		void show() const;
		const string & label() const;
		int sum() const;

};
