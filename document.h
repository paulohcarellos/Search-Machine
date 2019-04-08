#pragma once

#include <string>
#include "vector.h"

using namespace std;

class Document {
public:

	//Cria um documento vazio
	Document();

	//Cria um documento indentico a outro

	Document(const Document &copy);

	//Adiciona uma palavra ao documento
	void append(string str);

	//Imprime na tela todas as palavras do documento
	void print();

private:

	int size_;
	string *words_;
		
};

