#include <utility>
#include <valarray>
#include <string>

using std::pair;
using std::valarray;
using std::string;

typedef valarray<int> ArrayInt;
typedef pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
	private:
		string brand;
		PairArray inventory;
		int numOfYears;

	public:
		Wine(const char * br, int yrs, int y[], int b[]);
		Wine(const char * br, int yrs);
		void getBottles();
		void show() const;
		int sum() const;
		const string & label() const {return brand;}
};
