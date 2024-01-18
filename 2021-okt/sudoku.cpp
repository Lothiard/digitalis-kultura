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
			for (int j = 0; j < 3; j++) {
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
	case 4:
		for (int i = 4; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 5:
		for (int i = 4; i < 6; i++) {
			for (int j = 4; j < 6; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 6:
		for (int i = 4; i < 6; i++) {
			for (int j = 7; j < 9; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 7:
		for (int i = 7; i < 9; i++) {
			for (int j = 1; j < 3; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 8:
		for (int i = 7; i < 9; i++) {
			for (int j = 4; j < 6; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	case 9:
		for (int i = 7; i < 9; i++) {
			for (int j = 7; j < 9; j++) {
				if (sudoku[j][i] == szam) {
					return true;
				}
			}
		}
		break;
	}
}

string vizsgal(int szam, int oszlop, int sor) {
	oszlop = oszlop - 1;
	sor = sor - 1;

	if (sudoku[oszlop][sor] != 0) {
		return "A helyet már kitöltötték\n\n";
	} 

	for (int i = 0; i < 9; i++) {
		if (sudoku[i][sor] == szam) {
			return "Az adott sorban már szerepel a szám\n\n";
		}
	}

	for (int i = 0; i < 9; i++) {
		if (sudoku[oszlop][i] == szam) {
			return "Az adott oszlopban már szerepel a szám\n\n";
		}
	}

	if (van(resztabla(oszlop, sor), szam)) {
		return "Az adott résztáblázatban már szerepel a szám\n\n";
	}

	return "A lépés megtehetö\n\n";
}

void f1_2() {
	cout << "1. feladat\nAdja meg a bemeneti fájl nevét! ";
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

	cout << "Adja meg egy sor számát! "; cin >> sor;
	cout << "Adja meg egy oszlop számát! "; cin >> oszlop; cout << "\n";

	sor = sor - 1;
	oszlop = oszlop - 1;
}

void f3() {
	cout << "3. feladat\n";

	if (sudoku[oszlop][sor] == 0) {
		cout << "Az adott helyet még nem töltötték ki.\n";
	} else {
		cout << "Az adott helyen szereplö szám: " << sudoku[oszlop][sor] << "\n";
	}

	cout << "A hely a(z) " << resztabla(oszlop, sor) << " résztálához tartozik.\n\n";
}

void f4() {
	cout << "4. feladat\nAz üres helyek aránya: ";

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
		cout << "A kiválasztott sor: " << beirt[1][i] << " oszlop: " << beirt[2][i] << " a szám: " << beirt[0][i] << endl;
		cout << vizsgal(beirt[0][i], beirt[2][i], beirt[1][i]);
	}
}

int main() {
	setlocale(LC_ALL, "");

	f1_2();
	f3();
	f4();
	f5();
}
