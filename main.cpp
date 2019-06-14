#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <time.h>
#include "document.h"
#include "map.h"

using namespace std;
namespace fs = filesystem;

void printhash(vector<string> ranking);
void openfiles(string folder, vector<string> &filenames);
void createdocs(vector<string>& filenames, vector<Document>& docs);
void appenddocs(vector<Document>& docs, Map& map);

int main() {


	/*Map songs;
	Document bohemian = Document("Bohemian Rhapsody", "./Songs/Bohemian Rhapsody.txt");
	Document mockingbird = Document("Mockingbird", "./Songs/Mockinbird.txt");
	Document sweater = Document("Sweater Weather", "./Songs/Sweater Weather.txt");
	Document devil = Document("The Devil in I", "./Songs/The Devil in I.txt");
	Document mountains = Document("The Misty Mountains Cold", "./Songs/The Misty Mountains Cold.txt");
	Document heart = Document("If I Had a Heart", "./Songs/If I Had a Heart.txt");
	Document cinema = Document("Cinema", "./Songs/Cinema.txt");

	songs.append(bohemian);
	songs.append(mockingbird);
	songs.append(sweater);
	songs.append(devil);
	songs.append(mountains);
	songs.append(heart);
	songs.append(cinema);

	songs.init();*/
	
	time_t start;
	time_t append;
	time_t init;
	time(&start);

	Map map;

	string search;
	vector<string> ranking;
	vector<string> filenames;
	vector<Document> docs;

	openfiles("./Tests", filenames);
	createdocs(filenames, docs);
	appenddocs(docs, map);

	map.init();

	while (search != " ") {

		cout << "\n Search: ";
		getline(cin, search);
		ranking = map.perfect_hash(search);
		printhash(ranking);
		cout << "\n ";
		system("pause");
		system("CLS");
	}

	return 0;
}

void printhash(vector<string> ranking) {

	int i = 0;

	for (string j : ranking) {

		cout << " " << ++i << " - " << j << endl;
	}
}

void openfiles(string folder, vector<string> &filenames) {

	int size = 0;

	for (auto& file : fs::directory_iterator(folder))
		size++;

	filenames.reserve(size);

	for (auto& file : fs::directory_iterator(folder))
		filenames.push_back(file.path().string());

}

void createdocs(vector<string>& filenames, vector<Document>& docs) {

	int size = filenames.size();
	docs.reserve(filenames.size());

	for (int i=0; i<size; i++)
		docs.emplace_back(Document(filenames[i], filenames[i]));
}

void appenddocs(vector<Document>& docs, Map& map) {

	for (int i = 0; i < docs.size(); i++) {

		map.append(docs[i]);
		docs[i].~Document();
	}
}
