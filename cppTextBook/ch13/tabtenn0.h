#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>

using std::string;

class TableTennisPlayer
{
	private:
		string firstName;
		string lastName;
		bool hasTable_m;

	public:
		TableTennisPlayer(const string & fn = "none",
						  const string & ln = "none",
						  bool ht = false);

		void name() const;
		bool hasTable() const {return hasTable_m;};
		void resetTable(bool v) { hasTable_m = v;};


};

#endif

