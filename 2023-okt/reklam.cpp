#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct reklam {
	int nap;
	string varos;
	int db;
}rendeles[1000];

int napok[3][3] = {
	{ 0, 0, 0 },// PL 
	{ 0, 0, 0 },// TV
	{ 0, 0, 0 } // NR
};

int osszeg(string nev, int nap) {
	int osszeg = 0;
	for (int i = 0; i < 1000; i++) {
		if (rendeles[i].nap == nap && rendeles[i].varos == nev) {
			osszeg++;
		}
	}
	return osszeg;
}

void f1() {
	ifstream f;
	f.open("rendel.txt");

	for (int i = 0; i < 1000; i++) {
		f >> rendeles[i].nap >> rendeles[i].varos >> rendeles[i].db;
		// cout << rendeles[i].db << " " << rendeles[i].varos << " " << rendeles[i].db << endl;
	}

	f.close();
}

void f2() {
	cout << "2. feladat:\n";
	int rendelesszam = 0;

	for (int i = 0; i < 1000; i++) {
		if (rendeles[i].nap != 0) {
			rendelesszam++;
		}
	}
	
	cout << "A rendelések száma: " << rendelesszam << endl;
}

void f3() {
	cout << "3. feladat:\n";
	cout << "Kérem, adjon meg egy napot: ";

	int input_nap;
	int db_nap = 0;
	cin >> input_nap;

	for (int i = 0; i < 1000; i++) {
		if (rendeles[i].nap != 0 && rendeles[i].nap == input_nap) {
			db_nap++;
		}
	}

	cout << "A rendelések száma az adott napon: " << db_nap << endl;
}

void f4() {
	cout << "4. feladat:\n";
	int napok[30]; // 1 ha van

	for (int i = 0; i < 30; i++) {
		napok[i] = 0;
	}

	int i = 1;
	while (i < 30) {
		for (int j = 0; j < 1000; j++) {
			if (rendeles[j].nap == i && rendeles[j].varos == "NR") {
				napok[i - 1] = 1;
				break;
			}
		}
		i++;
	}

	int darab = 0;

	for (int i = 0; i < 30; i++) {
		if (napok[i] == 0) {
			darab++;
		}
	}

	if (darab > 0) {
		cout << darab << " nap nem volt a reklámban nem érintett városból rendelés\n";
	} else {
		cout << "Minden nap volt a reklámban nem érintett városból\n";
	}
}

void f5() {
	cout << "5. feladat:\n";
	int max = 0;

	for (int i = 0; i < 1000; i++) {
		if (rendeles[i].db > max) {
			max = rendeles[i].db;
		}
	}

	for (int i = 0; i < 1000; i++) {
		if (max == rendeles[i].db) {
			cout << "A legnagyobb darabszám: " << max << ", a rendelés napja: " << rendeles[i].nap << endl;
		}
	}
}

void f7() {
	cout << "7. feladat:\n";
	int varosok[3] = { 0, 0, 0 }; //PL, TV, NR

	for (int i = 0; i < 1000; i++) {
		if (rendeles[i].nap == 21) {
			if (rendeles[i].varos == "PL") {
				varosok[0] += rendeles[i].db;
			}
			if (rendeles[i].varos == "TV") {
				varosok[1] += rendeles[i].db;
			}
			if (rendeles[i].varos == "NR") {
				varosok[2] += rendeles[i].db;
			}
		}
	}

	cout << "A rendelt termékek darabszáma a 21. napon PL: " << varosok[0] << " TV: " << varosok[1] << " NR: " << varosok[2] << endl;
}

void f8() {
	cout << "8. feladat:\n";

	for (int i = 0; i < 1000; i++) {
		if (rendeles[i].nap >= 1 && rendeles[i].nap <= 10 && rendeles[i].varos == "PL") {
			napok[0][0]++;
		}
		if (rendeles[i].nap >= 11 && rendeles[i].nap <= 20 && rendeles[i].varos == "PL") {
			napok[0][1]++;
		}
		if (rendeles[i].nap >= 21 && rendeles[i].nap <= 30 && rendeles[i].varos == "PL") {
			napok[0][2]++;
		}

		if (rendeles[i].nap >= 1 && rendeles[i].nap <= 10 && rendeles[i].varos == "TV") {
			napok[1][0]++;
		}
		if (rendeles[i].nap >= 11 && rendeles[i].nap <= 20 && rendeles[i].varos == "TV") {
			napok[1][1]++;
		}
		if (rendeles[i].nap >= 21 && rendeles[i].nap <= 30 && rendeles[i].varos == "TV") {
			napok[1][2]++;
		}

		if (rendeles[i].nap >= 1 && rendeles[i].nap <= 10 && rendeles[i].varos == "NR") {
			napok[2][0]++;
		}
		if (rendeles[i].nap >= 11 && rendeles[i].nap <= 20 && rendeles[i].varos == "NR") {
			napok[2][1]++;
		}
		if (rendeles[i].nap >= 21 && rendeles[i].nap <= 30 && rendeles[i].varos == "NR") {
			napok[2][2]++;
		}
	}

	cout << "Napok\t1..10\t11..20\t21..30\n";
	cout << "PL\t" << napok[0][0] << "\t" << napok[0][1] << "\t" << napok[0][2] << endl;
	cout << "TV\t" << napok[1][0] << "\t" << napok[1][1] << "\t" << napok[1][2] << endl;
	cout << "NR\t" << napok[2][0] << "\t" << napok[2][1] << "\t" << napok[2][2] << endl;
}

void kiiras() {
	ofstream ki;
	ki.open("kampany.txt");

	ki << "Napok\t1..10\t11..20\t21..30\n";
	ki << "PL\t" << napok[0][0] << "\t" << napok[0][1] << "\t" << napok[0][2] << endl;
	ki << "TV\t" << napok[1][0] << "\t" << napok[1][1] << "\t" << napok[1][2] << endl;
	ki << "NR\t" << napok[2][0] << "\t" << napok[2][1] << "\t" << napok[2][2] << endl;

	ki.close();
}

int main() {
	setlocale(LC_ALL, "");

	f1();
	f2();
	f3();
	f4();
	f5();
	f7();
	f8();
	kiiras();
}
