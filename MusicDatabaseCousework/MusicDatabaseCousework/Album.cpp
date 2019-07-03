#include <locale>
#include <string>
#include "Album.h"
#include <algorithm> 

std::ostream& operator<<(std::ostream& os, const Album& a) 
{
	std::vector<Track*> tracks = a.getTracks();

	os << a.getArtist() << "  " << a.getTitle()
		<< " ( " << a.songSize() << " tracks  "
		<< a.findAll() << " ) " << std::endl;

	for (Track* track : tracks){
		os << "\t" << *track << std::endl;
	}

	return os;
}
std::istream& operator>>(std::istream& is, Album& a){
	char line[64], artist[64], title[64];


	is.getline(artist, 64, ' : ');
	is.getline(title, 64, '\n');
	a = Album(title, artist);


	while (!is.eof()) {
		Track* t = new Track();
		if (is >> *t) {
			a.addTrack(t); 
		}
		else {
			is.clear();
			delete t;
			return is;
		}
	}
	is.clear(std::ios_base::eofbit); 

	return is;
}

Track* Album::findLongest() const{
	Track* longest = tracks.at(0); 
	for (Track* track : tracks){
		if (*track > * longest){
			longest = track; 
		}
	}
	return longest;	

}

Duration Album::findAll() const{
	Duration d;
	for (Track* t : tracks) {
		d += t->getDuration();
	}
	return d;
}

bool Album::asc(const Album* a1, const Album* a2) {
	if (a1->getArtist() == a2->getArtist()) {
		return (a1->getTitle() < a2->getTitle());
	}
	return (a1->getArtist() < a2->getArtist()); 
}

bool Album::desc(const Album* a1, const Album* a2){
	if (a1->getArtist() == a2->getArtist()){
		return (a1->getTitle() > a2->getTitle()); 
	}
	return (a1->getArtist() > a2->getArtist());  
}
