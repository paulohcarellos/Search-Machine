#include "document.h"

using namespace std;

Document::Document() {

	doc_size_ = 0;
	words_ = new string;

	words_[0] = "404";
}

Document::Document(const Document& copy) {

	doc_size_ = copy.doc_size_;

	words_ = new string[doc_size_];

	for (int i = 0; i < doc_size_; i++) {

		words_[i] = copy.words_[i];
	}
}

Document::Document(string name, string filename) {

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

int Document::doc_size() const {

	return doc_size_;
}

string Document::name() const {

	return name_;
}

string Document::word(int i) const {

	return words_[i];
}

bool Document::appear(string word) {

	for (int i = 0; i < doc_size_; i++) {

		if (words_[i] == word) {

			return true;
		}
	}

	return false;
}

double Document::tf(string word) const {

	int tf = 0;

	for (int i = 0; i < doc_size_; i++) {

		if (words_[i] == word) {

			tf++;
		}
	}

	return tf;
}

void Document::print() {

	for (int i = 0; i < doc_size_; i++) {

		cout << words_[i] << endl;

	}
}