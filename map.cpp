#include "map.h"
#include "document.h"

#include <string>

using namespace std;

Map::Map() {

	docs_ = new Document;
	values_ = new double*;

	size_ = 0;
}

Map::Map(const Document& x) {

	docs_ = new Document;
	docs_[0] = Document(x);

	values_ = new double*;
	values_[0] = new double[x.doc_size()];

	for (int i = 0; i < x.doc_size(); i++) {

		values_[0][i] = 0;
	}

	size_ = 1;
}

Map::Map(const Map& x) {

	docs_ = new Document[x.size_];

	for (int i = 0; i < x.size_; i++) {
		docs_[i] = Document(x.docs_[i]);
	}

	values_ = new double* [x.size_];

	for (int i = 0; i < x.size_; i++) {
		values_[i] = new double[x.docs_[i].doc_size()];
	}

	for (int i = 0; i < x.size_; i++) {
		for (int j = 0; j < x.docs_[i].doc_size(); j++) {
			values_[i][j] = x.values_[i][j];
		}
	}

	size_ = x.size_;
}

int Map::size() const {

	return size_;
}

double Map::idf(string s) const {

	int nt = 0;

	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < docs_[i].doc_size(); j++) {
			if (docs_[i].word(j) == s) {
				nt++;
				break;
			}
		}
	}

	return log10(size_ / nt);
}

void Map::append(const Document & x) {

	Map copy = Map(*this);

	size_++;

	docs_ = new Document[size_];

	for (int i = 0; i < copy.size_; i++) {
		docs_[i] = Document(copy.docs_[i]);
	}

	docs_[size_ - 1] = Document(x);

	values_ = new double* [size_];

	for (int i = 0; i < copy.size_; i++) {
		values_[i] = new double[copy.docs_[i].doc_size()];
	}

	values_[size_ - 1] = new double[x.doc_size()];

	for (int i = 0; i < copy.size_; i++) {
		for (int j = 0; j < copy.docs_[i].doc_size(); j++) {
			values_[i][j] = copy.docs_[i].tf(copy.docs_[i].word(j)) * this->idf(copy.docs_[i].word(j));
		}
	}

	for (int i = 0; i < x.doc_size(); i++){

		values_[size_ - 1][i] = x.tf(x.word(i)) * this->idf(x.word(i));
	}
}

void Map::print_doc(int i) {

	docs_[i].print();
}

void Map::print_vector(int i) {

	for (int j = 0; j < docs_[i].doc_size(); j++) {

		cout << values_[i][j] << endl;
	}
}

Map::~Map()
{
}
