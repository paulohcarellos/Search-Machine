#include "map.h"
#include "collection.h"

#include <string>

using namespace std;

Map::Map() {

	docs_ = new Collection::Document;
	values_ = new double*;

	size_ = 0;
}

Map::Map(const Collection::Document& x) {

	docs_ = new Collection::Document;
	docs_[0] = Collection::Document(x);

	values_ = new double*;
	values_[0] = new double[x.doc_size()];

	for (int i = 0; i < x.doc_size(); i++) {

		values_[0][i] = 0;
	}

	size_ = 1;
}

Map::Map(const Collection& x) {

	docs_ = new Collection::Document[x.size()];

	for (int i = 0; i < x.size(); i++) {
		docs_[i] = x.doc(i);
	}

	values_ = new double* [x.size()];

	for (int i = 0; i < x.size(); i++) {
		values_[i] = new double[x.doc(i).doc_size()];
	}

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x.doc(i).doc_size(); j++) {
			values_[i][j] = x.idf(x.doc(i).word(j)) * x.idf(x.doc(i).word(j));
		}
	}

	size_ = x.size();
}

Map::Map(const Map& x) {

	docs_ = new Collection::Document[x.size_];

	for (int i = 0; i < x.size_; i++) {
		docs_[i] = Collection::Document(x.docs_[i]);
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