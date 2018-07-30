#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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

	vector<Review> books;
	Review temp;
	while (fillReview(temp))
		books.push_back(temp);

	if (books.size() > 0)
	{
		cout << "Thanks you , you entered the following "
			 << books.size() << " ratings:\n"
			 << "Raiting\tBook\n";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end());
	    cout << "sorted by title:\nRating\tBook\n";	
	}


}
