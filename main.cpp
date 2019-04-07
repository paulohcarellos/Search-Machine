#include <iostream>
#include "vector.h"

using namespace std;

int main() {

	Vector v = Vector(5, 3);
	Vector w = Vector(3, 4);

	Vector sum = v + w;
	Vector sub = v - w;
	Vector vscl = v.scalar(5);
	Vector wscl = w.scalar(5);

	cout << " V = ( " << v.x() << " , " << v.y() << " )" << endl;
	cout << " W = ( " << w.x() << " , " << w.y() << " )" << endl;
	cout << endl;
	cout << " |V| = " << v.size() << endl;
	cout << " |W| = " << w.size() << endl;
	cout << endl;
	cout << " V + W = ( " << sum.x() << " , " << sum.y() << " )" << endl;
	cout << " V - W = ( " << sub.x() << " , " << sub.y() << " )" << endl;
	cout << endl;
	cout << " V * 5 = ( " << vscl.x() << " , " << vscl.y() << " )" << endl;
	cout << " W * 5 = ( " << wscl.x() << " , " << wscl.y() << " )" << endl;
	cout << "\n\n|n ";

	system("pause");
	return 0;

}