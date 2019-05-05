#include <iostream>
#include <fstream>
#include <string>
#include "document.h"
#include "map.h"

using namespace std;

int main() {

	Document bohemian = Document("Bohemian Rhapsody", "./Songs/Bohemian Rhapsody.txt");
	Document mockinbird = Document("Mockinbird", "./Songs/Mockinbird.txt");
	Document sweater = Document("Sweater Weather", "./Songs/Sweater Weather.txt");
	Document devil = Document("The Devil in I", "./Songs/The Devil in I.txt");
	Document mountains = Document("The Misty Mountains Cold", "./Songs/The Misty Mountains Cold.txt");
	Document heart = Document("If I Had a Heart", "./Songs/If I Had a Heart.txt");
	Document cinema = Document("Cinema", "./Songs/Cinema.txt");

	Map songs = Map();

	songs.append(&bohemian);
	songs.append(&mockinbird);
	songs.append(&sweater);
	songs.append(&devil);
	songs.append(&mountains);
	songs.append(&heart);
	songs.append(&cinema);

	songs.init();

	string search;

	while (search != " ") {

		cout << " Search: ";
		getline(cin, search);
		cout << "\n  Result: " << songs.perfect_hash(search) << endl;
		cout << endl;
	}

	return 0;
}