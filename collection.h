#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Collection{
public:

	class Document {
	public:

		//Cria um documento vazio
		Document();

		//Cria um documento indentico a outro
		Document(const Document& copy);

		//Cria um documento a partir de um arquivo
		Document(string name, string filename);

		//Retorna o tamanho do documento
		int size();

		//Retorna nome do documento
		string name();

		//Retorna se a palavra aparece no documento
		bool appear(string word);

		//Retorna o numero de ocorrencias da palavra no documento
		int appearences(string word);

		//Retorna o "term frequency" da palavra
		double tf(string word);

		//Imprime na tela todas as palavras do documento
		void print();

	private:

		int size_;
		string name_;
		string* words_;
	};

	//Cria uma colecao de documentos vazia
	Collection();

	//Cria uma colecao de documentos identica a outra
	Collection(const Collection& x);

	//Retorna "inverse term frequency" da palavra
	double itf(string s);

	//Adiciona um documento a colecao
	void append(const Document& doc);

	void print_occurrences(string word);
	void print_tf(string word);

	~Collection();

private:

	int size_;
	Document* docs_;

	
};

