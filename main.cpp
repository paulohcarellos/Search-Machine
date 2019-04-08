#include <iostream>
#include <fstream>
#include <string>
#include "document.h"
#include "vector.h"

using namespace std;

void createdoc(Document &doc, ifstream &input);

int main() {

	ifstream D1;
	D1.open("d1.txt");

	Document bohemian = Document();

	createdoc(bohemian, D1);

	bohemian.print();

	system("pause");
	return 0;

}

void createdoc(Document &doc, ifstream &input) {

	int k = 0;

	char word[30];
	char newword[30];

	string s;

	while (!(input.eof())) {

		input >> word;

		k = 0;

		for (int i = 0; i < 20; i++) {

			if (word[i] >= 65 && word[i] <= 90) {

				newword[k] = word[i] + 32;
				k++;

			}

			if (word[i] >= 97 && word[i] <= 122) {

				newword[k] = word[i];
				k++;

			}

			if (word[i] >= 48 && word[i] <= 57) {

				newword[k] = word[i];
				k++;

			}

			if (word[i] == '\0') {

				newword[k] = '\0';
				break;

			}
		}

		s = newword;
		doc.append(s);
	}
}