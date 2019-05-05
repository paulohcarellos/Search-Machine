#include <iostream>
#include <fstream>
#include <string>
#include "document.h"
#include "map.h"

using namespace std;

void print_hash(Document** ranking);

int main() {

	Document bohemian = Document("Bohemian Rhapsody", "./Songs/Bohemian Rhapsody.txt");
	Document mockingbird = Document("Mockingbird", "./Songs/Mockinbird.txt");
	Document sweater = Document("Sweater Weather", "./Songs/Sweater Weather.txt");
	Document devil = Document("The Devil in I", "./Songs/The Devil in I.txt");
	Document mountains = Document("The Misty Mountains Cold", "./Songs/The Misty Mountains Cold.txt");
	Document heart = Document("If I Had a Heart", "./Songs/If I Had a Heart.txt");
	Document cinema = Document("Cinema", "./Songs/Cinema.txt");

	Map songs = Map();

	songs.append(&bohemian);
	songs.append(&mockingbird);
	songs.append(&sweater);
	songs.append(&devil);
	songs.append(&mountains);
	songs.append(&heart);
	songs.append(&cinema);

	songs.init();

	string search;
	Document** ranking;

	while (search != " ") {

		cout << "\n Search: ";
		getline(cin, search);
		ranking = songs.perfect_hash(search);
		print_hash(ranking);
		cout << "\n ";
		system("pause");
		system("CLS");
	}

	return 0;
}

void print_hash(Document** ranking) {

	cout << "\n  Results:\n" << endl;

	for (int i = 0; i < 5; i++) {

		if (i == 0 && ranking[i] == nullptr) {

			cout << "   Your search did not match any documents" << endl;
			break;
		}

		else {

			if (ranking[i] == nullptr) {

				cout << "   " << i + 1 << " -    ---"  << endl;
			}

			else {

				cout << "   " << i + 1 << " - " << ranking[i]->name() << endl;
			}
		}	
	}
}
