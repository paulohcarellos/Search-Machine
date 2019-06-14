#include "map.h"
#include "document.h"

Map::Map() {

	mapsize = 0;
}

void Map::append(Document x) {
	
	bool belong;
	int wordsize;
	int docsize = x.size();

	invindex.resize(mapsize + 1);
	invindex[mapsize].resize(mapwords.size() + docsize);
	string word;

	for (int i = 0; i < docsize; i++) {

		word = x.word(i);
		wordsize = mapwords.size();
		belong = false;

		for (int j = 0; j < wordsize; j++) {
			if (word == mapwords[j]) {

				invindex[mapsize][j] = true;
				belong = true;
				break;
			}
		}

		if (!belong) {

			mapwords.push_back(word);
			invindex[mapsize][mapwords.size() - 1] = true;
		}
	}
	docs.push_back(x);
	mapsize++;
}

void Map::init() {

	int freq;
	int size = mapwords.size();
	int docsize;
	string word;

	idf.reserve(size);
	vectors.resize(mapsize, vector<double>(size));

	for (int i = 0; i < size; i++) {

		freq = 0;
		word = mapwords[i];

		for (int j = 0; j < mapsize; j++) {

			invindex[j].resize(size);

			if (invindex[j][i])
				freq++;
		}

		idf.push_back(mapsize / freq);

		for (int j = 0; j < mapsize; j++)
			vectors[j][i] = docs[j].tf(word) * idf[i];
	}
}

Document Map::doc(int i) {

	if (i < mapsize) {

		return docs[i];
	}

	else {

		cout << "nonexistent document" << endl;
		return Document();
	}
}

vector<string> Map::perfect_hash(string search) {

	int size = mapwords.size();

	Document query(search);

	vector<double> vquery;
	vector<double> ranking(40);
	vector<int> position(40);
	vector<string> list;
	
	double sim;
	double sum1;
	double sum2;
	double sum3;	

	for (int i = 0; i < size; i++)
		vquery.push_back(query.tf(mapwords[i]) * idf[i]);
		

	for (int i = 0; i < mapsize; i++) {

		sum1 = 0;
		sum2 = 0;
		sum3 = 0;

		for (int j = 0; j < size; j++) {

			sum1 += vectors[i][j] * vquery[j];
			sum2 += vectors[i][j] * vectors[i][j];
			sum3 += vquery[j] * vquery[j];
		}

		sim = sum1 / (sqrt(sum2) * sqrt(sum3));

		for (int j = 0; j < 40; j++) {
			if (sim > ranking[j]) {

				ranking.insert(ranking.begin() + j, sim);
				position.insert(position.begin() + j, i);
				break;
			}
		}
	}

	int i = 0;

	for (int i = 0; i < 40; i++) {
		if (ranking[i] > 0) {

			list.push_back(docs[position[i]].name());
		}	
	}

	return list;
}

Map::~Map() {

	
}
