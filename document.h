#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Document {
public:

	//Cria um documento vazio
	Document();

	//Cria um documento indentico a outro
	Document(const Document& copy);

	//Cria um documento a partir de um arquivo
	Document(string name, string filename);

	//Retorna o tamanho do documento
	int doc_size() const;

	//Retorna nome do documento
	string name() const;

	//Retorna a palavra i do document
	string word(int i) const;

	//Retorna se a palavra aparece no documento
	bool appear(string word);

	//Retorna o "term frequency" da palavra
	double tf(string word) const;

	//Imprime na tela todas as palavras do documento
	void print();

private:

	int doc_size_;
	string name_;
	string* words_;
};