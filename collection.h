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

		//Cria um documento a partir de uma string
		Document(const string& s);

		//Cria um documento indentico a outro
		Document(const Document& copy);

		//Cria um documento a partir de um arquivo
		Document(string name, string filename);

		//Retorna o tamanho do documento
		int doc_size() const;

		//Retorna nome do documento
		string name() const;

		//Retorna a palavra i do documento
		string word(int i) const;

		//Retorna se a palavra aparece no documento
		bool appear(string word);

		//Retorna o numero de ocorrencias da palavra no documento
		int appearences(string word) const;

		//Retorna o tf da palavra
		double tf(string word) const;

		//Imprime na tela todas as palavras do documento
		void print();

	private:

		int doc_size_;
		string name_;
		string* words_;
	};

	//Cria uma colecao de documentos vazia
	Collection();

	//Cria uma colecao de documentos identica a outra
	Collection(const Collection& x);

	//Retorna o tamanho da colecao
	int size() const;

	//Adiciona um documento a colecao
	void append(const Document& doc);

	//Retorna o documento i da colecao
	Collection::Document doc(int i) const;

	//Retorna idf da palavra
	double idf(string s) const;

	void print_occurrences(string word);
	void print_tf(string word);

	~Collection();

private:

	int c_size_;
	Document* docs_;
	
};

