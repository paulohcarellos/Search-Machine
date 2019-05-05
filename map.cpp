#include "map.h"
#include "document.h"

using namespace std;

Map::Map() {

	ndocs = 0;
	mapsize = 0;

	mapwords = nullptr;
	docpointers = nullptr;
	idf = nullptr;
	invindex = nullptr;
	vectors = nullptr;
}

void Map::append(Document* x) {
	
	if (ndocs == 0) {
		
		docpointers = new Document*;	
	}

	else {

		Document** copy = new Document*[ndocs];

		for (int i = 0; i < ndocs; i++) {

			copy[i] = docpointers[i];
		}

		docpointers = new Document*[ndocs + 1];

		for (int i = 0; i < ndocs; i++) {

			docpointers[i] = copy[i];
		}
	}

	docpointers[ndocs] = x;
	ndocs++;
}

void Map::init() {
	
	string* words = new string[2048];
	words[0] = docpointers[0]->word(0);

	int aux = 1;
	int max = 2048;

	bool belong;

	for (int i = 0; i < ndocs; i++) {
		for (int j = 0; j < docpointers[i]->size(); j++) {
			for (int k = 0; k < aux; k++) {

				belong = false;

				if (docpointers[i]->word(j) == words[k]) {

					belong = true;
					break;
				}
			}

			if (!belong) {

				if (aux == max) {

					string* copy = new string[max];

					for (int l = 0; l < max; l++) {

						copy[l] = words[l];
					}

					words = new string[max * 2];

					for (int l = 0; l < max; l++) {

						words[l] = copy[l];
					}
				}

				words[aux] = docpointers[i]->word(j);
				aux++;
			}
		}
	}

	mapsize = aux;

	mapwords = new string[mapsize];
	idf = new double[mapsize];
	invindex = new double* [mapsize];
	vectors = new double* [mapsize];

	for (int i = 0; i < mapsize; i++) {

		mapwords[i] = words[i];

		aux = 0;

		invindex[i] = new double[ndocs];
		vectors[i] = new double[ndocs];

		for (int j = 0; j < ndocs; j++) {

			invindex[i][j] = docpointers[j]->tf(words[i]);

			if (invindex[i][j] > 0) { aux++; }
		}

		idf[i] = log10(double(ndocs) / double(aux));
	}

	delete[] words;

	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < ndocs; j++) {
			
			vectors[i][j] = invindex[i][j] * idf[i];
		}
	}
}

string Map::perfect_hash(string search) {

	Document src = Document(search);

	int biggest = 0;
	double sum1, sum2, sum3;
	double* vsearch = new double[mapsize];
	double* similarity = new double[ndocs];	

	for (int i = 0; i < mapsize; i++) {

		vsearch[i] = double(src.tf(mapwords[i])) * idf[i];
	}

	for (int i = 0; i < ndocs; i++) {

		sum1 = 0;
		sum2 = 0;
		sum3 = 0;

		for (int j = 0; j < mapsize; j++) {

			sum1 += vectors[j][i] * vsearch[j];
			sum2 += vectors[j][i] * vectors[j][i];
			sum3 += vsearch[j] * vsearch[j];
		}

		similarity[i] = sum1 / (sqrt(sum2) * sqrt(sum3));

		if (similarity[i] >= similarity[biggest]) {

			biggest = i;
		}
	}

	return docpointers[biggest]->name();
}

Map::~Map() {

}