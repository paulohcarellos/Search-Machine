#include "collection.h"

using namespace std;

Collection::Document::Document() {

	size_ = 0;
	words_ = new string;

	words_[0] = "404";
}

Collection::Document::Document(const Document& copy) {

	size_ = copy.size_;

	words_ = new string[size_];

	for (int i = 0; i < size_; i++) {

		words_[i] = copy.words_[i];
	}
}

Collection::Document::Document(string name, string filename) {

	size_ = 0;
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
			size_++;
		}

		doc.close();
		doc.open(filename);

		string word;
		words_ = new string[size_];

		int k = 0;

		for (int i = 0; i < size_; i++) {

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

int Collection::Document::size() {

	return size_;
}

string Collection::Document::name() {

	return name_;
}

bool Collection::Document::appear(string word) {

	for (int i = 0; i < size_; i++) {

		if (words_[i] == word) {

			return true;
		}
	}

	return false;
}

int Collection::Document::appearences(string word) {

	int occurrences = 0;

	for (int i = 0; i < size_; i++) {

		if (words_[i] == word) {

			occurrences++;
		}
	}

	return occurrences;
}

double Collection::Document::tf(string word) {

	return (double(this->appearences(word)) / double(size_));
}

void Collection::Document::print() {

	for (int i = 0; i < size_; i++) {

		cout << words_[i] << endl;

	}
}

Collection::Collection() {

	size_ = 0;
	docs_ = new Document;
}

Collection::Collection(const Collection& x) {

	size_ = x.size_;

	docs_ = new Document[size_];

	for (int i = 0; i < size_; i++) {

		docs_[i] = x.docs_[i];
	}
}

double Collection::itf(string word) {

	int n = 0;

	for (int i = 0; i < size_; i++) {
		if (docs_[i].appear(word)) {
			n++;
		}
	}

	if (n > 0) {

		return log10(double(size_) / double(n));
	}

	else {

		return 1;
	}
}

void Collection::append(const Document& doc) {

	Collection copy = Collection(*this);

	size_++;

	docs_ = new Document[size_];

	for (int i = 0; i < size_; i++) {

		if (i != size_ - 1) {

			docs_[i] = copy.docs_[i];
		}

		else {

			docs_[i] = doc;
		}
	}
}

void Collection::print_occurrences(string word) {

	for (int i = 0; i < size_; i++) {

		cout << "  " << docs_[i].name() << ": " << docs_[i].appearences(word) << endl;
	}
}

void Collection::print_tf(string word) {

	for (int i = 0; i < size_; i++) {

		cout << "  " << docs_[i].name() << ": " << docs_[i].tf(word) << endl;
	}
}

Collection::~Collection() {

}