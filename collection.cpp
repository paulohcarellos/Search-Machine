#include "collection.h"

using namespace std;

Collection::Document::Document() {

	doc_size_ = 0;
	words_ = new string;

	words_[0] = "404";
}

Collection::Document::Document(const Document& copy) {

	doc_size_ = copy.doc_size_;

	words_ = new string[doc_size_];

	for (int i = 0; i < doc_size_; i++) {

		words_[i] = copy.words_[i];
	}
}

Collection::Document::Document(string name, string filename) {

	doc_size_ = 0;
	name_ = name;
	words_ = new string;

	ifstream doc;
	doc.open(filename);

	if (!doc) {

		words_[0] = "404";
		cout << "ERROR READING: " << name << endl;
	}

	else {

		string buffer;

		while (!doc.eof()) {

			doc >> buffer;
			doc_size_++;
		}

		doc.close();
		doc.open(filename);

		string word;
		words_ = new string[doc_size_];

		int k = 0;

		for (int i = 0; i < doc_size_; i++) {

			doc >> buffer;

			k = 0;

			for (int j = 0; j < buffer.size(); j++) {

				if (buffer[j] >= 'A' && buffer[j] <= 'Z') {

					word += buffer[j] + 32;
				}

				else if (buffer[j] >= 'a' && buffer[j] < 'z') {

					word += buffer[j];
				}

				else if (buffer[j] >= '0' && buffer[j] <= '9') {

					word += buffer[j];
				}

				else if (buffer[j] == '\0') {

					word += '\0';
					break;
				}

				else {

					continue;
				}

				k++;
			}

			words_[i] = word;
			word.erase();
		}
	}
}

int Collection::Document::doc_size() const {

	return doc_size_;
}

string Collection::Document::name() const {

	return name_;
}

string Collection::Document::word(int i) const {

	return words_[i];
}

bool Collection::Document::appear(string word) {

	for (int i = 0; i < doc_size_; i++) {

		if (words_[i] == word) {

			return true;
		}
	}

	return false;
}

int Collection::Document::appearences(string word) const {

	int occurrences = 0;

	for (int i = 0; i < doc_size_; i++) {

		if (words_[i] == word) {

			occurrences++;
		}
	}

	return occurrences;
}

double Collection::Document::tf(string word) const {

	return (double(this->appearences(word)) / double(doc_size_));
}

void Collection::Document::print() {

	for (int i = 0; i < doc_size_; i++) {

		cout << words_[i] << endl;

	}
}

Collection::Collection() {

	c_size_ = 0;
	docs_ = new Document;
}

Collection::Collection(const Collection& x) {

	c_size_ = x.c_size_;

	docs_ = new Document[c_size_];

	for (int i = 0; i < c_size_; i++) {

		docs_[i] = x.docs_[i];
	}
}

int Collection::size() const {

	return c_size_;
}

Collection::Document Collection::doc(int i) const {

	return docs_[i];
}

double Collection::idf(string word) const{

	int n = 0;

	for (int i = 0; i < c_size_; i++) {
		if (docs_[i].appear(word)) {
			n++;
		}
	}

	if (n > 0) {

		return log10(double(c_size_) / double(n));
	}

	else {

		return 1;
	}
}

void Collection::append(const Document& doc) {

	Collection copy = Collection(*this);

	c_size_++;

	docs_ = new Document[c_size_];

	for (int i = 0; i < c_size_; i++) {

		if (i != c_size_ - 1) {

			docs_[i] = copy.docs_[i];
		}

		else {

			docs_[i] = doc;
		}
	}
}

void Collection::print_occurrences(string word) {

	for (int i = 0; i < c_size_; i++) {

		cout << "  " << docs_[i].name() << ": " << docs_[i].appearences(word) << endl;
	}
}

void Collection::print_tf(string word) {

	for (int i = 0; i < c_size_; i++) {

		cout << "  " << docs_[i].name() << ": " << docs_[i].tf(word) << endl;
	}
}

Collection::~Collection() {

}