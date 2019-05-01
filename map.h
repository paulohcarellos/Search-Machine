#pragma once

#include "document.h";
#include <string>

using namespace std;

class Map {
public:

	//Cria um dicionario vazio
	Map();

	//Cria um dicionario unitario com documento x
	Map(const Document& x);

	//Cria um dicionario identico a outro
	Map(const Map& x);

	//Retorna o tamanho do dicionario
	int size() const;

	//Retorna o idf da palavra
	double idf(string s) const;

	//Adiciona um documento ao dicionario
	void append(const Document& x);

	void print_doc(int i);
	void print_vector(int i);

	~Map();

private:

	Document* docs_;
	double** values_;

	int size_;

};

