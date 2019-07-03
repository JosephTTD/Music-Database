#include "collection.h"
#include <algorithm>


Duration Collection::getTotalTime(std::string artist){
	Duration totalDuration;
	for (Album* a : albums) {
		if (a->getArtist() == artist) {
			totalDuration += a->findAll();
		}
	}
	return totalDuration;
}


Track Collection::findLongest() {
	Track* longestTrack = albums.at(0)->findLongest();
	for (Album* album : albums) {
		Track* t;			
		if (*(t = album->findLongest()) > * longestTrack) {							
			longestTrack = t;
		}
	}
	return Track(*longestTrack);
}

Album Collection::findLargestAlbum () {
	Album* largestAlbum = albums.at(0);
	for (Album* album : albums) {
		if (*album > * largestAlbum) {
			largestAlbum = album;
		}
	}
	return Album(*largestAlbum);
}

void Collection::sortAlbum(bool (*s)(const Album* a1, const Album* a2)){
	std::sort(albums.begin(), albums.end(), s);
}

void Collection::showAlbum(bool(*s)(const Album* a1, const Album* a2)){
	sortAlbum(s);
	std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const Collection& c) {
	std::vector<Album*> albs = c.getAlbums();
	for (Album* album : albs){
		out << *album;
	}
	return out;
}
std::istream& operator>>(std::istream& in, Collection& c) {
	char line[256];

	while (!in.eof()){
		Album* a = new Album();
		if (in >> *a){
			c.addAlbum(a);
		}
		else{
			in.clear();
			delete a;
			return in;
		}
	}
	return in;
}