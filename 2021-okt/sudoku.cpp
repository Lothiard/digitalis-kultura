#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int sudoku[9][9];
int beirt[3][4];
int sor, oszlop;
const int meret = 9 * 9;

int resztabla(int oszlop, int sor) {
	oszlop++; sor++;
	if (sor <= 3) {
		if (oszlop <= 3) { return 1; }
		else if (oszlop >= 4 && oszlop <= 6) { return 2; }
		else { return 3; }
	} else if (sor >= 4 && sor <= 6) {
		if (oszlop <= 3) { return 4; }
		else if (oszlop >= 4 && oszlop <= 6) { return 5; }
		else { return 6; }
	} else if (sor >= 7){
		if (oszlop <= 3) { return 7; }
		else if (oszlop >= 4 && oszlop <= 6) { return 8; }
		else { return 9; }
	}
}

bool van(int resztabla, int szam) {
	switch (resztabla) {
	case 1:
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 0; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			for (int j = 4; j < 6; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++) {
			for (int j = 7; j < 9; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	}
}
	
// folyt
	

string vizsgal(int szam, int oszlop, int sor) {
	if (sudoku[oszlop][szam] != 0) {
		return "A helyet m�r kit�lt�tt�k\n";
	} 

	for (int i = 0; i < 9; i++) {
		if (sudoku[i][sor] == szam) {
			return "Az adott sorban m�r szerepel a sz�m\n";
		}
	}

	for (int i = 0; i < 9; i++) {
		if (sudoku[oszlop][i] == szam) {
			return "Az adott oszlopban m�r szerepel a sz�m\n";
		}
	}

	if (van(resztabla(oszlop, sor), szam)) {
		return "Az adott r�szt�bl�zatban m�r szerepel a sz�m\n";
	}
}

void f1_2() {
	cout << "1. feladat\nAdja meg a bemeneti f�jl nev�t! ";
	string input; cin >> input;
	ifstream f;
	f.open(input);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			f >> sudoku[j][i];
			// cout << sudoku[j][i] << " ";
		}
		// cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			f >> beirt[j][i];
			// cout << beirt[j][i] << " ";
		}
		// cout << endl;
	}

	f.close();

	cout << "Adja meg egy sor sz�m�t! "; cin >> sor;
	cout << "Adja meg egy oszlop sz�m�t! "; cin >> oszlop; cout << "\n";

	sor = sor - 1;
	oszlop = oszlop - 1;
}

void f3() {
	cout << "3. feladat\n";

	if (sudoku[oszlop][sor] == 0) {
		cout << "Az adott helyet m�g nem t�lt�tt�k ki.\n";
	} else {
		cout << "Az adott helyen szerepl� sz�m: " << sudoku[oszlop][sor] << "\n";
	}

	cout << "A hely a(z) " << resztabla(oszlop, sor) << " r�szt�l�hoz tartozik.\n\n";
}

void f4() {
	cout << "4. feladat\nAz �res helyek ar�nya: ";

	int nulla = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[j][i] == 0) {
				nulla++;
			}
		}
	}

	cout << setprecision(3) << (float)nulla / (float)meret * 100 << "%\n\n";
}

void f5() {
	cout << "5. feladat\n";

	for (int i = 0; i < 4; i++) {
		cout << "A kiv�lasztott sor: " << beirt[1][i] << " oszlop: " << beirt[2][i] << " a sz�m: " << beirt[0][i] << endl;

	}
}

int main() {
	setlocale(LC_ALL, "");

	f1_2();
	f3();
	f4();
	f5();
}
