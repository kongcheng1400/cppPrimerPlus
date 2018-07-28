#include <iostream>
#include "tv.h"


int main()
{
	using std::cout;
	TV s42;
	cout << "Initial Setting for 42\" TV:\n";
	s42.settings();
	s42.onOff();
	s42.chanUp();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.chanUp();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	Remote grey;
	grey.setChan(s42, 10);
	grey.volUp(s42);
	grey.volUp(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	TV s58(TV::On);
	s58.setMode();
	grey.setChan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();

	grey.displayMode();
	s58.changeRemoteMode(grey);
	cout << "TV s58 change remote's mode:\n";
	grey.displayMode();



	return 0;



}
