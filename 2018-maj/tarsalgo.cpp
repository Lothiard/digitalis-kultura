#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ajto {
	int ora; // 9 kezdes, 15 vegzes
	int perc;
	int id; // 1-100
	string kibe;
} tomb[1000];

int N;
int input_id;

int ido(string be, string ki) {
	int be_ora, be_perc, ki_ora, ki_perc;

	be_perc = stoi(be.substr(3, 2));
	ki_perc = stoi(ki.substr(3, 2));

	be_ora = stoi(be.substr(0, 2));
	ki_ora = stoi(ki.substr(0, 2));

	be_perc = be_perc + be_ora * 60;
	ki_perc = ki_perc + ki_ora * 60;

	
	return ki_perc - be_perc;
}

void f1() {
	fstream f;
	f.open("ajto.txt");

	int i = 0;
	while (f >> tomb[i].ora >> tomb[i].perc >> tomb[i].id >> tomb[i].kibe) {
		// cout << tomb[i].ora << " " << tomb[i].perc << " " << tomb[i].id << " " << tomb[i].kibe << endl;
		i++;
	}

	N = i;
	cout << N;

	f.close();
}

void f2() {
	cout << "2. feladat\n";

	cout << "Az elsö belépö: " << tomb[0].id << endl;

	for (int i = N; i > 0; i--) {
		if (tomb[i].kibe == "ki") {
			cout << "Az utolsó kilépö: " << tomb[i].id << "\n\n";
			break;
		}

	}
}

void f3() {
	ofstream f;
	f.open("athaladas.txt");

	for (int j = 1; j < 101; j++) {
		int sum = 0;
		f << j << " ";
		for (int i = 0; i < N; i++) {
			if (tomb[i].id == j) {
				sum++;
			}
		}
		f << sum << endl;
	}

	f.close();
}

void f4() {
	cout << "4. feladat\nA végén a társalgóban voltak: ";

	for (int j = 1; j < 101; j++) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (tomb[i].id == j) {
				temp++;
			}
		}

		if (temp % 2 == 1) {
			cout << j << " ";
		}
	}

	cout << "\n\n";
}

void f5() {
	cout << "5. feladat\n";

	int egyszerre = 0;
	int max = 0;
	string max_ido = "";

	for (int i = 0; i < N; i++) {
		if (tomb[i].kibe == "be") {
			egyszerre++;
		} else {
			egyszerre--;
		}

		if (egyszerre > max) {
			max_ido = to_string(tomb[i].ora) + ":" + to_string(tomb[i].perc);
		}
	}

	cout << "Például " << max_ido << "-kor voltak a legtöbben a társalgóban.\n\n";
}

void f6() {
	cout << "6. feladat\nAdja meg a személy azonosítóját! ";
	cin >> input_id;
	cout << endl;
}

void f7_8() {
	cout << "7. feladat\n";

	string ki, be;
	int sum = 0;
	bool vege = false;
	for (int i = 0; i < N; i++) {
		if (tomb[i].id == input_id) {
			be = to_string(tomb[i].ora) + ":" + to_string(tomb[i].perc);
			cout << be << "-";

			int j = i + 1;
			while (tomb[j].id != input_id && j < N) {
				j++;
			}

			if (j >= N) {
				ki = "15:00";
				vege = true;
				break;
			}

			ki = to_string(tomb[j].ora) + ":" + to_string(tomb[j].perc);

			if (to_string(tomb[i].perc).length() == 1) {
				be.insert(be.begin() + 3, '0');
			}
			if (to_string(tomb[j].perc).length() == 1) {
				ki.insert(ki.begin() + 3, '0');
			}
			if (to_string(tomb[i].ora).length() == 1) {
				be.insert(be.begin(), '0');
			}
			if (to_string(tomb[j].ora).length() == 1) {
				ki.insert(ki.begin(), '0');
			}

			cout << ki << endl;

			sum = sum + ido(be, ki);
			
			i = j + 1;
		}
	}

	if (vege) {
		sum = sum + ido(be, ki);
	}

	cout << "\n\n8. feladat\n";
	cout << "A(z) " << input_id << ". személy összesen " << sum << " percet volt bent, a megfigyelés végén a társalgóban volt.";
}

int main() {
	setlocale(LC_ALL, "");

	f1();
	f2();
	f3();
	f4();
	f5();
	f6();
	f7_8();
}
