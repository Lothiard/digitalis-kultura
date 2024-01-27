#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct kongresszus {
	string nev;
	int honap;
	int nap;
	int sorszam;
	int hossz;
	string cim;
	string kellek;
}kong[30];

int N;

void f1() {
	ifstream f;
	f.open("eloadasok.txt");
	string teljesnev;

	int i = 0;
	while(!f.eof()) {
		getline(f, kong[i].nev, '\t');
		f >> kong[i].honap;
		f >> kong[i].nap;
		f >> kong[i].sorszam;
		f >> kong[i].hossz;
		getline(f, kong[i].cim, '\t');
		getline(f, kong[i].kellek, '\n');

		// cout << kong[i].nev << " " << kong[i].honap << " " << kong[i].nap << " " << kong[i].sorszam << " " << kong[i].hossz << " " << kong[i].cim << " " << kong[i].kellek << endl;

		i++;
	}

	N = --i;

	f.close();
}

void f2() {
	cout << "2. feladat\n";



	for (int j = 5; j < 8; j++) {
		cout << "november " << j << ".:\n";
		int szam = 1;
		for (int i = 0; i < N; i++) {
			if (kong[i].nap == j) {
				cout << szam << ". " << kong[i].nev << ": " << kong[i].cim << endl;
				szam++;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	f1();
	f2();
}
