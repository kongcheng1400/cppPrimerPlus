#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool fillReview(Review & rr);
void showReview(const Review & rr);

int main()
{
	using namespace std;

	list<Review> books;
	Review temp;
	while (fillReview(temp))
		books.push_back(temp);

	if (books.size() > 0)
	{
		cout << "Thanks you , you entered the following "
			 << books.size() << " ratings:\n"
			 << "Raiting\tBook\n";
		for_each(books.begin(), books.end(), showReview);

	    //sort method
		books.sort(worseThan);
		cout << "sorted by title:\nRating\tBook\n";	
		for_each(books.begin(), books.end(), showReview);


		vector<Review> vBooks(books.begin(), books.end());
		random_shuffle(vBooks.begin(), vBooks.end());
		
		//copy from vector to list
		copy(vBooks.begin(), vBooks.end(), books.begin());

		cout << "after shuffling:\nRating\tBook\n";
		for_each(books.begin(), books.end(), showReview);
	}
	else
		cout << "No entries.";

	cout << "bye.\n";
	return 0;


}

bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.rating < r2.rating)
		return true;
	else
		return false;

}


bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool fillReview(Review & rr)
{
	using namespace std;
	cout << "Please enter the book name and raint, quit for quit\n";
	cout << "book name: ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	
	cout << "book rating: ";
	if (!(cin >> rr.rating))
		return false;
	
	while (cin.get() != '\n')
		continue;
	return true;
}


void showReview(const Review & rr)
{
	std::cout << rr.rating << '\t' << rr.title << std::endl;
}




































