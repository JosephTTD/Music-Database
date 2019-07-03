#ifndef Collection_H
#define Collection_H

#include <vector>
#include "Album.h"

class Collection
{
	std::vector<Album*> albums;

public:
	Collection();
	Collection(std::vector<Album*> albs);
	~Collection();

	std::vector<Album*> getAlbums() const;
	void addAlbum(Album* a);

	Duration getTotalTime(std::string artist);
	Album findLargestAlbum();
	Track findLongest();

	void sortAlbum(bool(*f)(const Album* a1, const Album* a2)); 
	void showAlbum(bool(*f)(const Album* a1, const Album* a2)); 

};

inline Collection::Collection()
{
	albums = std::vector<Album*>();
}
inline Collection::Collection(std::vector<Album*> albs)
{
	albums = albs;
}
inline Collection::~Collection() {
	for (Album* a : albums) {
		delete a;
	}
	albums.clear();
}


inline std::vector<Album*> Collection::getAlbums() const {
	return albums;
}

inline void Collection::addAlbum(Album* a)
{
	albums.push_back(a);
}


std::ostream& operator<<(std::ostream& out, const Collection& c);
std::istream& operator>>(std::istream& in, Collection& c);
#endif /*Collection_H*/