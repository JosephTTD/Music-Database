#include "Track.h"


std::istream& operator>>(std::istream& is, Track& t) 
{
	char delimiter;
	Duration d;
	char title[256];


	if (is >> d >> delimiter)
	{
		if (delimiter == '-') 
		{
			is.getline(title, 256, '\n');
			std::string str_title = title;
			t = Track(str_title, d);
		}
		else 
		{
			is.clear(std::ios_base::failbit);
		}
	}

	return is;
}
