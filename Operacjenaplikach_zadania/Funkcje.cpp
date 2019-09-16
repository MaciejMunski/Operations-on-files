#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

//Napisz funkcjê "split", która dostanie stringa i zwróci wskaŸnik na dynamicznie zaalokowan¹ tablicê stringów,
//gdzie ka¿dy element to jedno s³owo z wejœciowego stringa podzielonego spacj¹.
//Np: funkcja dostanie "ala ma kota"
//Powinna zwróciæ wskaŸnik na tablicê stringów{ "ala", "ma", "kota" }

class StrTab {
public:
	string* dane;
	int size;

	void print(char sep = ' ') {
		cout << dane[0];
		for (int i = 1; i < size; i++) {
			cout << sep << dane[i];
		}
	}

	int count(string s) {
		int n = 0;
		for (int i = 0; i < size; i++) {
			if (dane[i] == s)
				n++;
		}
		return n;
	}

	//ma znalezc w tab stringa o podanej w arg wartosci i zwrocic jego indeks, albo -1 jezeli nie znajdzie
	int find(string s) {
		for (int i = 0; i < size; i++) {
			if (dane[i] == s)
				return i;
		}
		return -1;
	}
};


/*nie uzywamy nigdy konstrukcji takiej jak:
for (...){
	if (...)
		return ...;
	else
		return ...;
}

else w tym przypadku NIE sprawi ze zwrocimy wartosc na koncu petli 
*/

StrTab split(string a)
{
	int ilspacji = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ' ')
			ilspacji++;
	}
	int size = ilspacji + 1;
	string* table = new string[size];
	int spacja;
	int poprzspacja = -1;
	for (int i = 0; i < size; i++) {
		spacja = a.find_first_of(' ', poprzspacja+1);
		table[i] = a.substr(poprzspacja + 1, spacja - poprzspacja - 1);
		poprzspacja = spacja;
	}
	return { table, size };

	//return StrTab{ table, size };

	/*StrTab wynik;
	wynik.dane = table;
	wynik.size = size;
	return wynik;*/
}


// ponizej do usuniecia w tej solucji split()
template<typename T>
T* extend(T* a, int size, int newsize) {
	T* b = new int[newsize];
	for (int i = 0; i < size; i++)
		b[i] = a[i];
	delete[] a;
	return b;
}

//mozna potraktowac jako alternatywe dla klasy StrTab i jej metody print.
//w przypadku funkcji niepowiazanej z klasa musimy zawsze przekazac do argumentu obiekt, na ktory chcemy cos wykonac
//w przypadku metody klasy domyslnie przy wywolaniu zapamietany jest obiekt na ktorym wywolalismy metode
//ale w obu przypadkach ostateczne dzialanie byloby takie samo
template<typename T>
void print(T* t, int size, char sep) {
	cout << t[0];
	for (int i = 1; i < size; i++) {
		cout << sep << t[i];
	}
	cout << endl;
}

//STL = Standard Template Library

template<typename T>
T min(T a, T b) {
	if (a < b)
		return a;
	else
		return b;
}

template<typename T1, typename T2>
auto multiply(T1 a, T2 b) {
	return a * b;
}

int maint2() {
	multiply(1, 5.78);
	double v = min<double>(2, 7.87);
	char c = min<char>('f', 'y');
	float f = min(6.4f, 0.001f);
	//int i = min(4, 4.65);

	string s;
	wstring ws;
	
	getline(cin, s);
	StrTab tab = split(s);
	//printStrTab(tab, ',');

	tab.print();
	cout << endl << tab.count("ala") << endl;

	StrTab tab2 = split("kot ma ale");
	tab2.print(';');



	delete[] tab.dane;
	return 0;
}

int main() {
	string s;
	getline(cin, s); // trzeba wpisac cala linijke
	StrTab tab = split(s);
	int i = tab.find("kot");
	cout << i << endl;
}


int main1() {
	ostringstream oss;
	double d = 923.34345;
	oss << "napis " << 54 << " " << d << endl << 1 << " END";
	string s = oss.str();
	cout << s <<endl << endl;


	istringstream iss(s);
	string a;
	int i;
	double f;
	iss >> a >> i >> f;

	cout << a << " " << i << " " << f << endl;

	string ok = "OK";
	ok += to_string(4454);
	cout << ok;
	return 0;
}