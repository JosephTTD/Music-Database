/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   main.cpp
  * Author: Joseph Dada
  *
  * Created on 07 April 2019, 19:51
  */

  /*
  1. Read in a Collection from the file albums.txt, provided via BlackBoard.
  2. Display the entire album Collection, arranged in alphabetical order of the album artist.
  If more than one album exists for a given artist, they should be displayed in alphabetical
  order of the album title.
  3. Display the total play time of all Pink Floyd albums in the collection.
  4. Display the album with the largest number of tracks.
  5. Display the details of the longest track in the album collection.
  */

#include <iostream>
#include <fstream>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"

using namespace std;

int main(int argc, char** argv) {

	/* string songs;
 ifstream file("albums.txt");
 if(file.is_open()){
	 while( getline (file, songs)) {
		 cout << songs << '\n';
	 }8
	 file.close();
 }
 else cout << "Unable to open file";*/

 /*Collection f;
 std::ifstream file;
 file.open("albums.txt");
 file >> f;*/

	//1. Read in a Collection from the file albums.txt
	Collection f;
	std::ifstream infile;
	infile.open("albums.txt");
	infile >> f;

	//2. Display the entire album Collection, arranged in alphabetical order of the album artist.
	std::cout << "------  Displaying Album Collection in Alphabetical order -----------" << std::endl;
	f.showAlbum(Album::asc);


	//3. Display total play time of all Pink Floyd albums in collection
	std::cout << "--------- Total Playtime of artist --------" << std::endl;
	std::cout << f.getTotalTime("Pink Floyd") << std::endl; 

	//4.Display album with the largest number of tracks
	std::cout << "--------- Album with most tracks  --------" << std::endl;
	std::cout << f.findLargestAlbum () << std::endl;

	//5.Display the details of the longest track in the album collection
	std::cout << "-------- Longest track in album collection ---------- " << std::endl;
	std::cout << f.findLongest() << std::endl;

	return EXIT_SUCCESS;
}
