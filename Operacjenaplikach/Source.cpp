#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* extend(int* a, int size, int newsize);
void printArray(int* a, int size);

/*const int WYJSCIE = 0;
const int DODAJ = 1;
const int WYCZYSC = 2;
const int ZAPISZ = 3;*/

enum Akcja {
	WYJSCIE, DODAJ, WYCZYSC, ZAPISZ, WYPISZ
};

int main() {

	ifstream baza("baza.txt");
	int rozm = 20;
	int* dane = new int[rozm];
	int i = 0;
	while (baza >> dane[i]) {
		++i;
		if (i == rozm) {
			dane = extend(dane, rozm, rozm * 2);
			rozm *= 2;
		}
	}

	cout <<
		"0: wyjscie\n"
		"1: dodaj liczbe\n"
		"2: wyczysc\n"
		"3: zapisz\n";
	//printArray(dane, i);

	int akcja;
	do {
		cin >> akcja;
		switch (akcja) {
		case WYJSCIE:
			break;
		case DODAJ:
			//....
			break; //break po case oznacza zakonczenie switcha
		case WYCZYSC:
			break;
		case ZAPISZ:
			break;
		case WYPISZ:
			printArray(dane, i);
			break;
		default:
			cout << "Niepoprawna akcja\n";
		}
	} while (akcja != WYJSCIE);


	

	//string s = "ala" "ma";

}

int* extend(int* a, int size, int newsize) {
	int* b = new int[newsize];
	for (int i = 0; i < size; i++)
		b[i] = a[i];
	delete[] a;
	return b;
}

void printArray(int* a, int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}
