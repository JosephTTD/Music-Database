#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "Duration.h"

class Track
{
	std::string title;
	Duration duration;

public:
	Track(std::string title_in, Duration duration_in);
	Track(const Track& t); 
	Track();

	std::string getTitle() const;
	Duration getDuration() const;
	void setTitle(std::string title1);												
	void setDuration(Duration duration1);

	Track& operator=(const Track& t) { 
		if (this != &t) {
			title = t.title;
			duration = t.duration;
		}
		return *this;
	}

};


inline Track::Track(std::string title_in, Duration duration_in)
{
	title = title_in;
	duration = duration_in;
}

//Constructor Clone
inline Track::Track(const Track& t) 
{
	title = t.title;
	duration = t.duration;
}

//Constructor
inline Track::Track() 
{
	title = "N/A";
	duration = Duration();
}


inline std::string Track::getTitle() const {
	return title;
}
inline Duration Track::getDuration() const {
	return duration;
}
inline void Track::setTitle(std::string title1) {
	title = title1;
}
inline void Track::setDuration(Duration duration1) {
	duration = duration1;
}


inline int operator<(const Track& t1, const Track& t2) { 
	return t1.getDuration() < t2.getDuration();
}
inline int operator>(const Track& t1, const Track& t2) {
	return t1.getDuration() > t2.getDuration();
}
inline int operator>=(const Track& t1, const Track& t2) { 
	return !(t1 < t2);
}
inline bool operator==(const Track& t1, const Track& t2) {
	return (t1.getTitle() == t2.getTitle() && t1.getDuration() == t2.getDuration());
}
inline std::ostream& operator<<(std::ostream& out, const Track& t) {
	return out << t.getDuration() << " - " << t.getTitle();
}
inline bool operator!=(const Track & t1, const Track & t2) {
	return !(t1 == t2);
}
inline int operator<=(const Track& t1, const Track& t2) { 
	return !(t1 > t2);
}


std::istream& operator>>(std::istream & is, Track & t);

#endif /*TRACK_H*/


