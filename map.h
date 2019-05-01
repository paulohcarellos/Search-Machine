#pragma once

#include "collection.h";
#include <string>

using namespace std;

class Map {
public:

	//Cria um dicionario vazio
	Map();

	//Cria um dicionario unitario com documento x
	Map(const Collection::Document& x);

	//Cria um dicionario contendo o conjunto x
	Map(const Collection& x);

	//Cria um dicionario identico a outro
	Map(const Map& x);

	//Retorna o tamanho do dicionario
	int size() const;

	void print_doc(int i);
	void print_vector(int i);

	~Map();

private:

	Collection::Document* docs_;
	double** values_;

	int size_;

};