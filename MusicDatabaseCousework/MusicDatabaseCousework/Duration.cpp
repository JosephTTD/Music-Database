#include "Duration.h"
#include <iostream>

//Static cast Duration into Integer for use in Operators
Duration::operator int() const {
	return (hours * 3600 + minutes * 60 + seconds);
}

std::istream& operator>>(std::istream & is, Duration & d)//Input
{
	char dl; 
	int hours, minutes, seconds; 


	if (is >> hours >> dl >> minutes >> dl >> seconds)
	{
		if (dl == ':') 
		{
			d = Duration(hours, minutes, seconds);
		}
		else 
		{
			is.clear(std::ios_base::failbit);
		}
	}

	return is;
}
