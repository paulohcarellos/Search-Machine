#include "document.h"

using namespace std;

Document::Document() {

	docsize = 0;
	docname = "";
	docwords = nullptr;
}

Document::Document(const string str) {

	docsize = 0;
	docname = "SEARCH";
	docwords = nullptr;

	for (unsigned int i = 0; i < str.size(); i++) {

		if (str[i + 1] == ' ' || str[i + 1] == '\0') {

			docsize++;
		}
	}

	if (docsize > 0) {
		
		int k = 0;

		string buffer;
		docwords = new string[docsize];

		for (int i = 0; i < str.size(); i++) {

			buffer += str[i];

			if (str[i + 1] == ' ' || str[i + 1] == '\0') {

				docwords[k] = this->format(buffer);
				buffer.clear();
				k++;
			}
		}
	}
}

Document::Document(string name, const string filename) {

	docsize = 0;
	docname = name;

	ifstream input;
	input.open(filename);

	if (!input) {

		docwords = nullptr;
		cout << "ERROR READING: " << name << endl;
	}

	else {

		string buffer;

		while (!input.eof()) {

			input >> buffer;
			docsize++;
		}

		input.seekg(ios::beg);

		docwords = new string[docsize];

		for (int i = 0; i < docsize; i++) {
			
			input >> buffer;
			docwords[i] = this->format(buffer);
		}
	}
}

int Document::size() const {

	return docsize;
}

string Document::name() const {

	return docname;
}

string Document::word(int i) const {

	return docwords[i];
}

bool Document::belong(const string& word) const {

	for (int i = 0; i < docsize; i++) {

		if (word == docwords[i]) {

			return true;
		}
	}

	return false;
}

int Document::tf(const string& word) const {

	int frequency = 0;

	for (int i = 0; i < docsize; i++) {

		if (word == docwords[i]) {

			frequency++;
		}
	}

	return frequency;
}
string Document::format(const string& str) {

	string formated;

	for (unsigned int i = 0; i < str.size(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {

			formated += str[i] + 32;
		}

		else if (str[i] >= 'a' && str[i] <= 'z') {

			formated += str[i];
		}

		else if (str[i] >= '0' && str[i] <= '9') {

			formated += str[i];
		}
	}
	
	return formated;
}

Document::~Document() {

	delete [] docwords;
}