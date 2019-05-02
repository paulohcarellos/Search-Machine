#include "map.h"
#include "collection.h"

#include <string>

using namespace std;

Map::Map() {

	doc_ = new Collection::Document;
	values_ = new double*;

	size_ = 0;
}


Map::Map(const Collection& x) {

	size_ = x.size();

	doc_ = new Collection::Document[size_];

	for (int i = 0; i < size_; i++) {
		
		doc_[i] = Collection::Document(x.doc(i));
	}

	words_ = new string[2048];
	words_[0] = doc_[0].word(0);

	idf_ = new double[2048];

	string aux;
	vsize_ = 1;
	bool belong;

	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < doc_[i].doc_size(); j++) {

			belong = false;
			aux = doc_[i].word(j);

			for (int k = 0; k < vsize_; k++) {
				
				if (aux == words_[k]) {

					belong = true;
					break;
				}
			}

			if (!belong) {

				words_[vsize_] = aux;
				idf_[vsize_] = x.idf(aux);
				vsize_++;
			}
		}
	}

	values_ = new double* [size_];

	for (int i = 0; i < size_; i++) {

		values_[i] = new double[vsize_];
	}

	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < vsize_; j++) {

			values_[i][j] = doc_[i].tf(words_[j]) * idf_[j];
		}
	}
}

string Map::perfect_hash(const string& s) {

	Collection::Document search = Collection::Document(s);

	double* vsearch = new double[vsize_];

	for (int i = 0; i < vsize_; i++) {
		if (s == words_[i]) {

			vsearch[i] = search.tf(s) * idf_[i];
		}

		else {

			vsearch[i] = 0;
		}
	}

	double* similarity = new double[size_];

	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;

	int biggest = 0;

	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < vsize_; j++) {
			sum1 += values_[i][j] * vsearch[j];
			sum2 += pow(values_[i][j], 2);
			sum3 += pow(vsearch[j], 2);

		}

		similarity[i] = sum1 / (sqrt(sum2) * sqrt(sum3));

		if (similarity[i] > similarity[biggest]) {

			biggest = i;
		}
	}

	return doc_[biggest].name();
}

int Map::size() const {

	return size_;
}

void Map::print_words() {

	for (int i = 0; i < 1024; i++) {

		cout << words_[i] << endl;
	}
}

void Map::print_doc(int i) {

	doc_[i].print();
}

void Map::print_vector() {

	int i = 0;

	for (int j = 0; j < vsize_; j++) {
		cout << words_[i] << " ";
		for (int k = 0; k < size_; k++) {
			cout << values_[k][j] << " ";
		}
		cout << endl;
		i++;
	}
}

Map::~Map()
{
}