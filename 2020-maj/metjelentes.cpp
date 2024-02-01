#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct metjelentes {
	string telepules;
	string ido;
	string irany;
	string erosseg;
	int ho;
} metjelent[500];

int N;

void f1() {
	ifstream f;
	f.open("tavirathu13.txt");

	int i = 0;
	while (f >> metjelent[i].telepules) {
		string szel;

		f >> metjelent[i].ido;
		f >> szel;

		metjelent[i].irany = szel.substr(0, 3);
		metjelent[i].erosseg = szel.substr(3, 2);

		f >> metjelent[i].ho;

		// cout << metjelent[i].telepules << " " << metjelent[i].ido << " " << metjelent[i].irany << " " << metjelent[i].erosseg << " " << metjelent[i].ho << endl;
		i++;
	}

	N = --i;

	f.close();
}

void f2() {
	cout << "2. feladat\nAdja meg egy település kódját! Település: ";
	string input;
	cin >> input;

	for (int i = N; i > 0; i--) {
		if (metjelent[i].telepules == input) {
			cout << "Az utolsó mérési adat a megadott településröl " << metjelent[i].ido.substr(0, 2) << ":" << metjelent[i].ido.substr(2, 2) << "-kor érkezett.\n";
			break;
		}
	}
}

void f3() {
	cout << "3. feladat\n";

	int max = 0;
	int min = 99;
	int max_hely, min_hely;

	for (int i = 0; i < N; i++) {
		if (metjelent[i].ho > max) {
			max = metjelent[i].ho;
			max_hely = i;
		}

		if (metjelent[i].ho < min) {
			min = metjelent[i].ho;
			min_hely = i;
		}
	}

	cout << "A legalacsonyabb hömérséklet: " << metjelent[min_hely].telepules << " " << metjelent[min_hely].ido.substr(0, 2) << ":" << metjelent[min_hely].ido.substr(2, 2) << " " << metjelent[min_hely].ho << " fok.\n";
	cout << "A legmagasabb hömérséklet: " << metjelent[max_hely].telepules << " " << metjelent[max_hely].ido.substr(0, 2) << ":" << metjelent[max_hely].ido.substr(2, 2) << " " << metjelent[max_hely].ho << " fok.\n";
}

void f4() {
	cout << "4. feladat\n";

	bool van = false;

	for (int i = 0; i < N; i++) {
		if (metjelent[i].irany == "000" && metjelent[i].erosseg == "00") {
			cout << metjelent[i].telepules << " " << metjelent[i].ido.substr(0, 2) << ":" << metjelent[i].ido.substr(2, 2) << endl;
			van = true;
		}
	}

	if (!van) {
		cout << "Nem volt szélcsend a mérések idején.\n";
	}
}

void f5() {
	cout << "5. feladat\n";

	int osszho[9];
	int n[9];
	int atlag[9];

	for (int i = 0; i < 9; i++) {
		osszho[i] = 0;
		n[i] = 0;
		atlag[i] = 0;
	}

	string varosok[9] = { "BP", "DC", "SM", "PA", "SN", "PR", "BC", "PP", "KE" };

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < N; i++) {
			if (metjelent[i].telepules == varosok[j]) {
				if (metjelent[i].ido.substr(0, 2) == "01" || metjelent[i].ido.substr(0, 2) == "07" || metjelent[i].ido.substr(0, 2) == "13" || metjelent[i].ido.substr(0, 2) == "19") {
					osszho[j] += metjelent[i].ho;
					n[j]++;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		cout << varosok[i] << " ";
		if (n[i] == 0) {
			cout << "NA\n";
		} else {
			atlag[i] = osszho[i] / n[i];
			cout << "Középhömérséklet: " << atlag[i] << endl;
		}

	}

	// valami nem jo es nem tudtam rajonni mi az
}

int main() {
	setlocale(LC_ALL, "");

	f1();
	f2();
	f3();
	f4();
	f5();
}
