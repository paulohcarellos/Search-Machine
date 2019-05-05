#pragma once

#include "collection.h";
#include <string>

using namespace std;

class Map {
public:

	//Cria um dicionario vazio
	Map();

	//Cria um dicionario contendo o conjunto x
	Map(const Collection& x);

	//Retorna o tamanho do dicionario
	int size() const;
	
	string perfect_hash(const string& s);

	void print_words();
	void print_doc(int i);
	void print_vector();

	~Map();

private:

	Collection::Document* doc_;
	string* words_;

	int size_;
	int vsize_;
	double* idf_;
	double** values_;
};