#include <iostream>
#include <fstream>

using namespace std;

// nem idorend
// nem dolgozott = nincs benne

struct futar {
	int nap; // 1-7
	int id; // 1-40
	int km; // km <= 30
} tavok[100];

int N;
bool szabad[7];
int fuvarszam[7];
int osszkm[7];
int fizetes = 0;

void f1() {
	ifstream f;
	f.open("tavok.txt");

	int i = 0;
	while (f >> tavok[i].nap >> tavok[i].id >> tavok[i].km) {
		// cout << tavok[i].nap << " " << tavok[i].id << " " << tavok[i].km << endl;
		i++;
	}

	f.close();

	N = i;
}

void f2() {
	cout << "2. feladat\n";

	for (int i = 0; i < N; i++) {
		if (tavok[i].nap == 1 && tavok[i].id == 1) {
			cout << "A het elso utja " << tavok[i].km << " km volt\n\n";
			break;
		}
	}
}

void f3() {
	cout << "3. feladat\n";

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (tavok[i].nap == 7 && tavok[i].id > max) {
			max = tavok[i].id;
		}
	}

	for (int i = 0; i < N; i++) {
		if (tavok[i].nap == 7 && tavok[i].id == max) {
			cout << "A het utolso utja " << tavok[i].km << " km volt\n\n";
			break;
		}
	}
}

void f4() {
	cout << "4. feladat\n";

	for (int i = 0; i < 7; i++) {
		szabad[i] = false;
	}

	for (int i = 0; i < N; i++) {
		szabad[tavok[i].nap - 1] = true;
	}

	for (int i = 0; i < 7; i++) {
		if (!szabad[i]) {
			cout << "A " << i + 1 << ". napon nem dolgozott\n";
		}
	}

	cout << "\n";
}

void f5() {
	cout << "5. feladat\n";

	for (int i = 0; i < 7; i++) {
		fuvarszam[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		fuvarszam[tavok[i].nap - 1]++;
	}

	int max = 0;
	for (int i = 0; i < 7; i++) {
		if (fuvarszam[i] > max) {
			max = fuvarszam[i];
		}
	}

	for (int i = 0; i < 7; i++) {
		if (fuvarszam[i] == max) {
			cout << "A " << i + 1 << ". napon volt a legtobb fuvar\n";
		}
	}

	cout << "\n";
}

void f6() {
	cout << "6. feladat\n";

	for (int i = 0; i < 7; i++) {
		osszkm[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		osszkm[tavok[i].nap - 1] += tavok[i].km;
	}

	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". nap: " << osszkm[i] << " km\n";
	}

	cout << "\n";
}

int szamolo(int km) {
	if (km <= 2) {
		return 500;
	} else if (km <= 5) {
		return 700;
	} else if (km <= 10) {
		return 900;
	} else if (km <= 20) {
		return 1400;
	} else if (km <= 30) {
		return 2000;
	}
}

void f7() {
	cout << "7. feladat\nAdjon meg egy tavolsagot ";
	int input_km;
	cin >> input_km;
	
	cout << szamolo(input_km) << " Ft\n\n";
}

void f8() {
	cout << "8. feladat\n";
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 40; j++) {
			for (int k = 0; k < N; k++) {
				if (tavok[k].nap == i + 1 && tavok[k].id == j + 1) {
					cout << i + 1 << ". nap " << j + 1 << ". ut:\t" << szamolo(tavok[k].km) << " Ft\n";
					fizetes += szamolo(tavok[k].km);
				}
			}
		}
	}

	cout << "\n";
}

void f9() {
	cout << "9. feladat\nA heti fizetes: " << fizetes << " Ft";
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
	f9();
}
