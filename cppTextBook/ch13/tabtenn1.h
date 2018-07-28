#ifndef TABTENN1_H_
#define TABTENN1_H_
#include <string>
using std::string;

class TableTennisPlayer
{
	private:
		string firstName_m;
		string lastName_m;
		bool hasTable_m;

	public:
		TableTennisPlayer(const string & fn = "none", const string & ln = "none",
						  bool ht = false);
		void name() const;
		bool hasTable() const {return hasTable_m;};
		void resetTalbe(bool v) {hasTable_m = v;};

};


class RatedPlayer: public TableTennisPlayer
{
private:
	unsigned int rating_m;

public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none",
				const string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
	unsigned int rating() const { return rating_m;}
	void resetRating(unsigned int r) {rating_m = r;}



};



#endif

