#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string foglaltsag[15];
string kategoria[15];

const int helyek_szama = 15 * 20;

int kategoriankent[5];

void f1() {
	ifstream f;
	f.open("foglaltsag.txt");

	for (int i = 0; i < 15; i++) {
		getline(f, foglaltsag[i], '\n');
		// cout << foglaltsag[i] << "\n";
	}

	f.close();
	f.open("kategoria.txt");

	for (int i = 0; i < 15; i++) {
		getline(f, kategoria[i], '\n');
		// cout << kategoria[i] << "\n";
	}

	f.close();
}

void f2() {
	cout << "2. feladat\n";
	int sor, oszlop;
	cout << "Adjon meg egy sort: ";
	cin >> sor;
	cout << "Adjon meg egy oszlopot: ";
	cin >> oszlop;

	if (foglaltsag[sor - 1][oszlop - 1] == 'o') {
		cout << "A hely foglalt\n\n";
	} else {
		cout << "A hely szabad\n\n";
	}
}

void f3() {
	cout << "3. feladat\n";
	int foglalt = 0;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			if (foglaltsag[i][j] == 'x') {
				foglalt++;
			}
		}
	}

	cout << "Az eloadasra eddig " << foglalt << " jegyet adtak el, ez a nezoter " << setprecision(2) << (float)foglalt / (float)helyek_szama * 100.00 << "%-a.\n\n";
}

void f4() {
	for (int i = 0; i < 5; i++) {
		kategoriankent[i] = 0;
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			if (foglaltsag[i][j] == 'x') {
				kategoriankent[kategoria[i][j] - '0' - 1]++;
			}
		}
	}

	int max = 0;
	int max_hely = 0;
	for (int i = 0; i < 5; i++) {
		if (kategoriankent[i] > max) {
			max = kategoriankent[i];
			max_hely = i + 1;
		}
	}

	cout << "A legtobb jegyet a(z) " << max_hely << ". arkategoriaban ertekesitettek.\n\n";
}

void f5() {
	cout << "5. feladat\n";
	
	int sum = 0;
	sum += kategoriankent[0] * 5000; // 1 - 5000
	sum += kategoriankent[1] * 4000; // 2 - 4000
	sum += kategoriankent[2] * 3000; // 3 - 3000
	sum += kategoriankent[3] * 2000; // 4 - 2000
	sum += kategoriankent[4] * 1500; // 5 - 1500

	cout << "Az eddig eladott jegyek altal szerzett bevetel osszege: " << sum << "\n\n";
}

void f6() {
	cout << "6. feladat\n";

	int egyedulallo = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			if (foglaltsag[i][j] == 'o') {
				if (j == 0) {
					if (foglaltsag[i][j + 1] == 'x') {
						egyedulallo++;
					}
				} else if (j == 19) {
					if (foglaltsag[i][j - 1] == 'x') {
						egyedulallo++;
					}
				} else {
					if (foglaltsag[i][j - 1] == 'x' && foglaltsag[i][j + 1] == 'x') {
						egyedulallo++;
					}
				}
			}
		}
	}

	cout << egyedulallo << " db egyedulallo hely van.\n\n"; // 23 helyett 35
}

void f7() {
	ofstream f;
	f.open("szabad.txt");

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			if (foglaltsag[i][j] == 'x') {
				f << foglaltsag[i][j];
			} else {
				f << kategoria[i][j];
			}
		}
		f << '\n';
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
}
