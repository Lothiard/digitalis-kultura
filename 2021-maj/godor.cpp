#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int melyseg[2000];
int N;
int tavolsag;
int godorszam = 0; // 5. feladat


void f1() {
	ifstream f;
	f.open("melyseg.txt");

	int i = 0;
	while (!f.eof()) {
		f >> melyseg[i];
		i++;
	}

	N = i - 1;

	cout << "1. feladat\nA f�jl adatainak sz�ma: " << N << "\n\n";

	f.close();
}

void f2() {
	cout << "2. feladat\nAdjon meg egy t�vols�g�rt�ket! ";
	cin >> tavolsag;
	tavolsag = tavolsag - 1;
	cout << "ezen a helyen a felsz�n " << melyseg[tavolsag] << " m�lyen van.\n\n";
}

void f3() {
	cout << "3. feladat\n";
	
	int erintetlen = 0;
	for (int i = 0; i < N; i++) {
		if (melyseg[i] == 0) {
			erintetlen++;
		}
	}

	cout << setprecision(4) << "Az �rintetlen ter�let ar�nya " << (float)erintetlen / (float)N * 100.00 << "%.\n\n";
}

void f4() {
	ofstream f;
	f.open("godrok.txt");

	for (int i = 0; i < N; i++) {
		while (melyseg[i] != 0) {
			f << melyseg[i] << " ";
			i++;
			if (melyseg[i] == 0) {
				f << endl;
				godorszam++;
			}
		}
	}

	f.close();
}

void f5() {
	cout << "5. feladat\nA g�dr�k sz�ma: " << godorszam << "\n\n";
}

void f6() {
	cout << "6. feladat\n";

	if (melyseg[tavolsag] == 0) {
		cout << "Az adott helyen nincs g�d�r.";
	} else {
		cout << "a)\n";

		int kezdo, veg;
		int i = tavolsag;
		while (melyseg[i - 1] != 0) {
			i--;
		}
		kezdo = i + 1;

		while (melyseg[i + 1] != 0) {
			i++;
		}
		veg = i + 1;
		
		cout << "A g�d�r kezdete: " << kezdo << " m�ter, a g�d�r v�ge: " << veg << " m�ter.\n";

		cout << "b)\n"; // nem teljesen jo mert nem ismeri fel amikor egymas mellett egyforma melysegu godor van

		int legmelyebb = 0;
		int legmelyebb_hely;
		bool monoton = true;
		for (int i = kezdo - 1; i < veg - 1; i++) {
			if (melyseg[i] > legmelyebb) {
				legmelyebb = melyseg[i];
				legmelyebb_hely = i;
			}
		}

		for (int i = legmelyebb_hely; i > kezdo; i--) {
			if (melyseg[i] >= legmelyebb) {
				monoton = false;
				break;
			}
		}
		for (int i = legmelyebb_hely; i < veg; i++) {
			if (melyseg[i] >= legmelyebb) {
				monoton = false;
				break;
			}
		}

		if (monoton) {
			cout << "Folyamatosan m�ly�l.\n";
		} else {
			cout << "Nem m�ly�l folyamatosan.\n";
		}

		cout << "c)\n";
		cout << "A legnagyobb m�lys�ge: " << legmelyebb << " m�ter.\n";

		cout << "d)\n";
		int terfogat = 0;

		for (int i = kezdo; i < veg; i++) {
			terfogat = terfogat + melyseg[i] * 10;
		}

		cout << "A t�rfogata " << terfogat << " m^3.\n"; // nem jo

		cout << "e)\n"; // nah
	}
}

int main() {
	setlocale(LC_ALL, "");

	f1();
	f2();
	f3();
	f4();
	f5();
	f6();
}
