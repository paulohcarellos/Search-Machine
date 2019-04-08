#include "document.h"

#include <iostream>
#include <string>

using namespace std;

Document::Document() {

	size_ = 0;

}

Document::Document(const Document &copy) {

	size_ = copy.size_;

	words_ = new string[size_];

	for (int i = 0; i < size_; i++) {

		words_[i] = copy.words_[i];

	}

}

void Document::append(string str) {

	Document copy = (*this);

	words_ = new string[size_ + 1];
	
	for (int i = 0; i < size_; i++) {

		words_[i] = copy.words_[i];

	}

	words_[size_] = str;
	size_++;

}

void Document::print() {

	for (int i = 0; i < size_; i++) {

		cout << words_[i] << endl;

	}
}

