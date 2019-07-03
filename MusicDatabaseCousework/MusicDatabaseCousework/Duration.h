#ifndef Duration_H
#define Duration_H

#include <exception>
#include <iomanip>


class Duration {

	int hours, minutes, seconds;

public:
	Duration(int hours, int minutes, int seconds);
	Duration(int secondsAcc);
	Duration();

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	operator int() const;
};



inline Duration::Duration(int hours_in, int minutes_in, int seconds_in) {
	if (hours_in < 0 || minutes_in < 0 || seconds_in < 0) {
		throw "This is invalid";
	}


	int secondsAcc = hours_in * 3600 + minutes_in * 60 + seconds_in; 
	this->hours = secondsAcc / 3600; 
	int remainder = secondsAcc % 3600; 
	this->minutes = remainder / 60; 
	remainder = remainder % 60; 
	this->seconds = remainder; 
}


inline Duration::Duration(int secondsAcc) {
	//If it's negative throw exception
	if (secondsAcc < 0) { 
		throw "This is invalid";
	}
	if (secondsAcc == 0) 
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	else
	{
		hours = secondsAcc / 3600; 
		int remainder = secondsAcc % 3600; 
		minutes = remainder / 60; 
		remainder = remainder % 60; 
		seconds = remainder; 
	}
}

inline Duration::Duration() 
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}



inline int Duration::getHours() const {
	return hours;
}
inline int Duration::getMinutes() const {
	return minutes;
}
inline int Duration::getSeconds() const {
	return seconds;
}


inline bool operator==(const Duration& d1, const Duration& d2) {
	return static_cast<int>(d1) == static_cast<int>(d2);
}
inline bool operator!=(const Duration& d1, const Duration& d2) { 
	return !(d1 == d2);
}
inline int operator-(const Duration & d1, const Duration & d2) { 
	return static_cast<int>(d1) - static_cast<int>(d2);
}
inline int operator+(const Duration & d1, const Duration & d2) { 
	return static_cast<int>(d1) + static_cast<int>(d2);
}
inline int operator>(const Duration& d1, const Duration& d2) {
	return static_cast<int>(d1) > static_cast<int>(d2);
}
inline int operator>=(const Duration& d1, const Duration& d2) {
	return !(d1 < d2);
}
inline int operator<=(const Duration& d1, const Duration& d2) {
	return !(d1 > d2);
}
inline void operator-=(Duration & d1, const Duration & d2) { 
	d1 = Duration(static_cast<int>(d1) - static_cast<int>(d2)); 
}
inline void operator+=(Duration & d1, const Duration & d2) { 
	d1 = Duration(static_cast<int>(d1) + static_cast<int>(d2)); 
}
inline int operator<(const Duration & d1, const Duration & d2) { 
	return static_cast<int>(d1) < static_cast<int>(d2);
}




inline std::ostream& operator<<(std::ostream & out, const Duration & d) 
{

	return out << std::setfill('0') << std::setw(2) << d.getHours() << " : " <<
		std::setfill('0') << std::setw(2) << d.getMinutes() << " : " <<  std::setfill('0') << std::setw(2) << d.getSeconds();
}
std::istream& operator>>(std::istream & is, Duration & d);

#endif /*Duration_H*/
