#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Document {
public:

	//Creates an empty document
	Document();

	//Creates an unnamed document from a string
	Document(const string str);

	//Creates a named document from an archive
	Document(string name, const string filename);

	//Returns size
	int size() const;

	//Returns docname
	string name() const;

	//Returns words[i];
	string word(int i) const;

	//Ruturns if word belongs to the document
	bool belong(string& word);

	//Returns the "term frequency" of the word
	int tf(string& word);

	//Standardizes the string
	string format(const string& str);
	
	//Destructs document
	~Document();

private:

	int docsize;
	string docname;
	vector<string> docwords;
};
