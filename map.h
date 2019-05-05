#pragma once
#include "document.h"

using namespace std;

class Map {
public:

	//Creates an empty map
	Map();

	//Appends a document to the map
	void append(Document* x);

	//Initializes the map for searchs
	void init();

	//Return the name of the search's best match
	//MAP MUST BE INITIALIZED FIRST!
	string perfect_hash(string search);

	//Destrucs maps
	~Map();

private:

	int ndocs;
	Document** docpointers;

	//Variables only initialized after the append of all the documents
	int mapsize;
	string* mapwords;
	double* idf;
	double** invindex;
	double** vectors;
};

