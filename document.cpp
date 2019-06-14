#include "document.h"

using namespace std;

Document::Document() {

	docsize = 0;
	docname = "";
}

Document::Document(const string str) {

	docsize = 0;
	docname = "SEARCH";
	
	int i = 0;
	string buffer;

	while (i < str.size()) {
		
		buffer += str[i];

		if (str[i] == ' ' || i == str.size()-1) {

			docwords.push_back(this->format(buffer));
			buffer.clear();
			docsize++;
		}
		i++;
	}
}

Document::Document(string name, const string filename) {

	docsize = 0;
	docname = name;

	ifstream input;
	input.open(filename);

	if (!input) {

		cout << "ERROR READING: " << name << endl;
	}

	else {

		string buffer;

		while (!input.eof()) {

			input >> buffer;

			if (buffer.find("@") == string::npos) {

				docwords.push_back(this->format(buffer));
				docsize++;
			}
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

bool Document::belong(string& word) {

	for (int i = 0; i < docsize; i++)
		if (word == docwords[i])
			return true;

	return false;
}

int Document::tf (string& word) {

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

	docwords.clear();
}
