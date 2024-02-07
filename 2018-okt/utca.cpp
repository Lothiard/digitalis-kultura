#include <iostream>
#include <fstream>

using namespace std;

struct telek {
	int oldal; // 0-1
	int szelesseg; // 8-20
	char szin; // betu - szin, # - kesz kerites, nincs szin, : - nincs kerites
} utca[1000];
/*
struct paros {
	int hazszam;
	char szin;
} par[100];

struct paratlan {
	int hazszam;
	char szin;
} parat[100];
*/
int N;

int hazszamba(int sorszam) {
	int sum = 0;
	if (utca[sorszam].oldal == 0) {
		for (int i = sorszam; i > 0; i--) {
			if (utca[i].oldal == 0) {
				sum++;
			}
		}
	}

	return sum * 2;
}

int hazszambol(int hazszam) {
	int i = 0;
	if (hazszam % 2 == 0) {
		int sum = 0;
		while(sum != hazszam) {
			if (utca[i].oldal == 0) {
				sum = sum + 2;
			}
			i++;
		}
	} else {
		int sum = -1;
		while (sum != hazszam) {
			if (utca[i].oldal == 1) {
				sum = sum + 2;
			}
			i++;
		}
	}	
	return i - 1;
}

void f1() {
	ifstream f;
	f.open("kerites.txt");

	int i = 0;
	while (f >> utca[i].oldal >> utca[i].szelesseg >> utca[i].szin) {
		// cout << utca[i].oldal << " " << utca[i].szelesseg << " " << utca[i].szin << endl;
		i++;
	}

	f.close();
	
	N = i;
}

void f2() {
	cout << "2. feladat\nAz eladott telkek száma: " << N << "\n\n";
}

void f3() {
	cout << "3. feladat\n";

	int melyik; // 0 - paros, 1 - paratlan
	int hazszam;
	// a
	if (utca[N].oldal == 0) {
		cout << "A páros oldalon adták el az utolsó telket.\n";
		melyik = 0;
		hazszam = 2;
	} else {
		cout << "A páratlan oldalon adták el az utolsó telket.\n";
		melyik = 1;
		hazszam = 1;
	}

	// b
	for (int i = 0; i < N - 1; i++) {
		if (utca[i].oldal == melyik) hazszam = hazszam + 2;
	}

	cout << "Az utolsó telek házszáma: " << hazszam << "\n\n";
}

void f4() {
	cout << "4. feladat\n";
	/*
	int par_i = 0; int par_hazszam = 2; int par_hossz = 0;
	int parat_i = 0; int parat_hazszam = 1; int parat_hossz = 0;

	for (int i = 0; i < N; i++) {
		if (utca[i].oldal == 0) {
			par[par_i].hazszam = par_hazszam;
			par_hazszam = par_hazszam + 2;
			par[par_i].szin = utca[i].szin;
		} else {
			parat[parat_i].hazszam = parat_hazszam;
			parat_hazszam = parat_hazszam + 2;
			parat[parat_i].szin = utca[i].szin;
		}
	}

	par_hossz = par_i;
	parat_hossz = parat_i;

	for (int i = 0; i < par_hossz; i++) {
		if (par[i].szin == par[i - 1].szin || par[i].szin == par[i + 1].szin) {
			cout << "A szomszédossal egyezik a kerítés színe: " << i;
			break;
		}
	}
	*/
	// ordito faszsag

	char keresett_szin;
	bool talalt = false;

	for (int i = 0; i < N; i++) {
		if (utca[i].oldal == 0) {
			keresett_szin = utca[i].szin;
		}

		for (int j = i + 1; j < N; j++) {
			if (utca[j].oldal == 0) {
				if (utca[j].szin == keresett_szin) {
					cout << "A szomszédossal egyezik a kerítés színe: " << hazszamba(j) << "\n\n";
					talalt = true;
					break;
				}
			}
		}
		if (talalt) break;
	}
}

void f5() {
	cout << "5. feladat\nAdjon meg egy házszámot! ";
	int input;
	cin >> input;

	cout << "A kerítés színe / állapota: " << utca[hazszambol(input)].szin << endl;
	
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char szomszed1 = utca[hazszambol(input - 2)].szin;
	char szomszed2 = utca[hazszambol(input + 2)].szin;

	for (int i = 0; i < abc.length(); i++) {
		if (abc[i] == szomszed1 || abc[i] == szomszed2 || abc[i] == utca[hazszambol(input)].szin) {
			i++;
		} else {
			cout << "Egy lehetséges festési szín: " << abc[i];
			break;
		}
	}
}

void f6() {
	ofstream f;
	f.open("utcakep.txt");

	for (int i = 0; i < N; i++) {
		if (utca[i].oldal == 1) {
			for (int j = 0; j < utca[i].szelesseg; j++) {
				f << utca[i].szin;
			}
		}
	}
	f << endl;

	int sorszam = 1;
	for (int i = 0; i < N; i++) {
		if (utca[i].oldal == 1) {
			f << sorszam;
			sorszam = sorszam + 2;
			for (int j = 0; j < utca[i].szelesseg - 1; j++) {
				f << " ";
			}
		}
	}

	f.close();
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
