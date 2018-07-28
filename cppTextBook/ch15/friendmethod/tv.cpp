#include <iostream>
#include "tv.h"

bool TV::volUp()
{
	if (volume_m < MaxVal)
	{
		volume_m++;
		return true;
	}
	else
		return false;


}

bool TV::volDown()
{
	if (volume_m > MinVal)
	{
		volume_m--;
		return true;	
	}
	else
		return false;

}

void TV::chanUp()
{
	if (channel_m < maxChannel_m)
		channel_m++;
	else
		channel_m = 1;

}

void TV::chanDown()
{
	if (channel_m > 1)
		channel_m--;
	else
		channel_m = maxChannel_m;

}


void TV::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state_m == Off? "Off" : "On") << endl;
	if (state_m ==On)
	{
		cout << "Volume setting = " << volume_m << endl;
		cout << "Channel setting = " << channel_m << endl;
		cout << "Mode = " << (mode_m == Antenna ? "antenna" : "calbe") << endl;
		cout << "Input == " << (input_m == TVV ? "TV" : "DVD") << endl;
	
	
	}



}


