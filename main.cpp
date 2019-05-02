#include <iostream>
#include <fstream>
#include <string>
#include "collection.h"
#include "map.h"

using namespace std;

int main() {

	Collection::Document bohemian = Collection::Document("Bohemian Rhapsody", "./Songs/Bohemian Rhapsody.txt");
	Collection::Document mockinbird = Collection::Document("Mockinbird", "./Songs/Mockinbird.txt");
	Collection::Document sweater = Collection::Document("Sweater Weather", "./Songs/Sweater Weather.txt");
	Collection::Document devil = Collection::Document("The Devil in I", "./Songs/The Devil in I.txt");
	Collection::Document mountains = Collection::Document("The Misty Mountains Cold", "./Songs/The Misty Mountains Cold.txt");
	Collection::Document heart = Collection::Document("If I Had a Heart", "./Songs/If I Had a Heart.txt");
	Collection::Document cinema = Collection::Document("Cinema", "./Songs/Cinema.txt");

	Collection songs = Collection();
	songs.append(bohemian);
	songs.append(mockinbird);
	songs.append(sweater);
	songs.append(devil);
	songs.append(mountains);
	songs.append(heart);
	songs.append(cinema);

	Map map = Map(songs);

	string input;
	getline(cin, input);

	Collection::Document test = Collection::Document(input);

	cout << map.perfect_hash(input) << endl;

	return 0;
}