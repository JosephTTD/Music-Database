#ifndef Album_H
#define Album_H

#include <string>
#include <vector>
#include "Track.h"
#include <iostream>

class Album
{
	std::string title;
	std::string artist;
	std::vector<Track*> tracks;

public:
	Album();
	Album(std::string title_in, std::string artist_in);
	Album(std::string title_in, std::string artist_in, std::vector<Track*> songs_in);
	Album(const Album& album); 

	std::string getTitle() const;
	std::string getArtist() const;
	std::vector<Track*> getTracks() const;

	void addTrack(Track* t);
	int songSize() const;
	Track* findLongest() const;
	Duration findAll() const;

	static bool asc(const Album* a1, const Album* a2); 
	static bool desc(const Album* a1, const Album* a2); 

	Album& operator=(const Album& a) {
		if (this != &a) {
			title = a.title;
			artist = a.artist;

			for (Track* t : tracks) { 
				delete t;
			}
			tracks.clear();

			for (Track* t : a.tracks) { 
				tracks.push_back(t);
			}
		}
		return *this;
	}
};


inline Album::Album()
{
	title = " ";
	artist = " ";
	tracks = std::vector<Track*>();
}
inline Album::Album(std::string title_in, std::string artist_in)
{
	title = title_in;

	artist = artist_in;

	tracks = std::vector<Track*>();
}
inline Album::Album(std::string title_in, std::string artist_in, std::vector<Track*> songs_in)
{
	title = title_in;
	artist = artist_in;
	tracks = songs_in;
}
inline Album::Album(const Album& album) { 
	title = album.title;
	artist = album.artist;
	tracks = std::vector<Track*>();
	for (Track* t : album.tracks) { 
		Track* newT = new Track(*t);
		tracks.push_back(newT);
	}
}


inline std::string Album::getTitle() const {
	return title;
}
inline std::string Album::getArtist() const {
	return artist;
}
inline std::vector<Track*> Album::getTracks() const {
	return tracks;
}
inline int Album::songSize() const {
	return (int)tracks.size();
}

inline void Album::addTrack(Track* t)
{
	tracks.push_back(t);
}

//---Operators------

//full set of relational Operators

/*inline int operator>(const Album& a1, const Album& a2){
   return static_cast<int>(a1) > static_cast<int>(d2);
}

inline bool operator==(const Album& a1, const Album& a2){
   return (a1 == a2);
}

inline bool operator!=(const Album& a1, const Album& a2){
   return static_cast<int>(d1)!= static_cast<int>(d2);
}

inline int operator<(const Album& a1, const Album& d2){
   return static_cast<int>(d1) < static_cast<int>(d2);
}

inline int operator>=(const Album& a1, const Album& a2){
   return !(a1 < a2);
}

inline int operator<=(const Album& a1, const Album& a2){
   return !(a1 > a2);
}*/


inline bool operator==(const Album& a1, const Album& a2) {
	return (a1.getArtist() == a2.getArtist() && a1.getTitle() == a2.getTitle());
}
inline bool operator!=(const Album & a1, const Album & a2) {
	return !(a1 == a2);
}

inline int operator<(const Album& a1, const Album& a2) { 
	return a1.songSize() < a2.songSize();
}
inline int operator>(const Album& a1, const Album& a2) { 
	return a1.songSize() > a2.songSize();
}
inline int operator>=(const Album& a1, const Album& a2) { 
	return !(a1 < a2);
}
inline int operator<=(const Album& a1, const Album& a2) { 
	return !(a1 > a2);
}

std::ostream& operator<<(std::ostream & os, const Album & a);
std::istream& operator>>(std::istream & is, Album & a);



#endif /*Album_H*/