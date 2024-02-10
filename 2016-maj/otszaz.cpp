#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// arak: 1-500, 2-450, 3-400, 4...-400
// 1-20 arucikk lehet egyszerre
// leghosszabb szo: 30

string penztar[1000];
int N;

int sorszam;
string arucikk;
int db;

int vasarloszam(int szam) {
	int f = 0;
	for (int i = szam; i > 0; i--) {
		if (penztar[i] == "F") f++;
	}

	return f + 1;
}

int ertek(int darab) {
	int fizetendo = 0;
	int egysegar = 500;
	
	for (int i = 0; i < darab; i++) {
		fizetendo += egysegar;
		if (egysegar > 450) {
			egysegar -= 50;
		}
	}

	return fizetendo;
}

void f1() {
	ifstream f;
	f.open("penztar.txt");

	int i = 0;
	while (!f.eof()) {
		getline(f, penztar[i], '\n');
		// cout << penztar[i] << endl;
		i++;
	}

	N = i;
	// cout << N;

	f.close();
}

void f2() {
	cout << "2. feladat\n";

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (penztar[i] == "F") sum++;
	}

	cout << "A fizetesek szama: " << sum << "\n\n";
}

void f3() {
	cout << "3. feladat\n";

	int db = 0;
	for (int i = 0; i < N; i++) {
		if (penztar[i] == "F") {
			break;
		} else {
			db++;
		}
	}

	cout << "Az elso vasarlo " << db << " darab arucikket vasarolt.\n\n";
}

void f4() {
	cout << "4. feladat\n";
	cout << "Adja meg egy vasarlas sorszamat! ";
	cin >> sorszam;
	cout << "Adja meg egy arucikk nevet! ";
	cin >> arucikk;
	cout << "Adja meg a vasarolt darabszamot! ";
	cin >> db;
	cout << "\n";
}

void f5() {
	cout << "5. feladat\n";
	
	int elso = 0;
	int utolso = 0;
	int osszes = 0;

	for (int i = 0; i < N; i++) {
		if (penztar[i] == arucikk) {
			elso = vasarloszam(i);
			break;
		}
	}
	for (int i = N; i > 0; i--) {
		if (penztar[i] == arucikk) {
			utolso = vasarloszam(i);
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		if (penztar[i] == arucikk) {
			osszes++;
			while (penztar[i] != "F") i++;
		}
	}

	cout << "Az elso vasarlas sorszama: " << elso << "\n";
	cout << "Az utolso vasarlas sorszama: " << utolso << "\n";
	cout << osszes << " vasarlas soran vettek belole.\n\n";
}

void f6() {
	cout << "6. feladat\n";
	cout << db << " darab vetelkor fizetendo: " << ertek(db) << "\n\n";
}

void f7() {
	cout << "7. feladat\n";

	int darab[20];
	string cikk[20];
	int index = 0;

	for (int i = 0; i < 20; i++) {
		darab[i] = 0;
	}

	// kivalasztott vasarlas elso eleme helyenek megtalalasa
	int f_szam = 0;
	int elsocikk = 0;
	for (int i = 0; i < N; i++) {
		if (penztar[i] == "F") {
			f_szam++;
			if (f_szam == sorszam - 1) {
				elsocikk = i + 1;
				break;
			}
		}
	}

	// mit muveltem 
	bool bennevan = false;
	for (int i = elsocikk; i < N; i++) {
		bennevan = false;
		if (penztar[i] == "F") break;

		for (int j = 0; j < 20; j++) {
			if (cikk[j] == penztar[i]) {
				bennevan = true;
			}
		}

		if (!bennevan) {
			cikk[index] = penztar[i];
			darab[index]++;
			index++;
		} else {
			for (int j = 0; j < 20; j++) {
				if (cikk[j] == penztar[i]) {
					darab[j]++;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 20; i++) {
		if (darab[i] == 0) break;
		cout << darab[i] << " " << cikk[i] << "\n";
	}
}

void f8() {
	ofstream f;
	f.open("osszeg.txt");

	int index = 0;
	int kezdes = 0;
	int darab[20];
	string cikk[20];
	int index_2 = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 20; j++) {
			darab[j] = 0;
			cikk[i] = "";
		}

		index = 0;

		for (int j = i; j < N; j++) {
			if (penztar[j] == "F") {
				kezdes = i;
				i = j + 1;
				break;
			}
		}

		bool bennevan = false;
		for (int j = kezdes; j < N; j++) {
			bennevan = false;
			if (penztar[j] == "F") {
				break;
			}

			for (int k = 0; k < 20; k++) {
				if (cikk[j] == penztar[j]) {
					bennevan = true;
				}
			}

			if (!bennevan) {
				cikk[index] = penztar[j];
				darab[index]++;
				index++;
			} else {
				for (int k = 0; k < 20; k++) {
					if (cikk[k] == penztar[j]) {
						darab[k]++;
						break;
					}
				}
			}
		}

		int fizetendo = 0;
		for (int j = 0; j < 20; j++) {
			if (darab[j] == 0) break;

			fizetendo += ertek(darab[j]);
		}

		f << index_2 << ": " << fizetendo << "\n";
		index_2++;
	}

	f.close();
}

int main() {
	f1();
	f2();
	f3();
	f4();
	f5();	
	f6();
	f7();
	f8();
}
