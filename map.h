#pragma once
#include "document.h"

using namespace std;

class Map {
public:

	//Creates an empty map
	Map();

	//Appends a document to the map
	void append(Document x);

	//Initializes the map for searchs
	void init();

	//Returns the desired document
	Document doc(int i);

	//Return the name of the search's best match
	//MAP MUST BE INITIALIZED FIRST!
	vector<string> perfect_hash(string search);

	//Destrucs maps
	~Map();

private:

	int mapsize;
	vector<Document> docs;
	vector<string> mapwords;
	vector<vector<bool>> invindex;

	//Variables only initialized after the append of all the documents
	vector<double> idf;
	vector<vector<double>> vectors;
};
