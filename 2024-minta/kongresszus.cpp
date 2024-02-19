#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct kongresszus {
	string nev;
	int honap;
	int nap;
	int sorszam;
	int hossz;
	string cim;
	string kellek;
} arr[30];

int N;
string vege[4];
string ebedszunet[4];

string string_atvalto(int perc) {
	int ora = perc / 60;
	perc = perc % 60;
	string string_perc = to_string(perc);

	if (string_perc.length() == 1) {
		string_perc = "0" + to_string(perc);
	}

	string eredmeny = to_string(ora) + ":" + string_perc;

	return eredmeny;
}

int int_atvalto(int ora, int perc) {
	return ora * 60 + perc;
}

void f1() {
	ifstream f;
	f.open("eloadasok.txt");
	string teljesnev;

	int i = 0;
	while (!f.eof()) {
		getline(f, arr[i].nev, '\t');
		f >> arr[i].honap;
		f >> arr[i].nap;
		f >> arr[i].sorszam;
		f >> arr[i].hossz;
		f.ignore();
		getline(f, arr[i].cim, '\t');
		getline(f, arr[i].kellek, '\n');

		// cout << arr[i].nev << " " << arr[i].honap << " " << arr[i].nap << " " << arr[i].sorszam << " " << arr[i].hossz << " " << arr[i].cim << " " << arr[i].kellek << endl;

		i++;
	}

	N = --i;

	f.close();
}

void f2() {
	cout << "2. feladat\n";

	for (int j = 5; j < 9; j++) {
		int k = 1;
		cout << "november.: " << j << "\n";
		for (int i = 0; i < N; i++) {
			if (arr[i].nap == j) {
				if (arr[i].sorszam == k) {
					cout << "\t" << k << ". " << arr[i].nev << ": " << arr[i].cim << "\n";
					k++;
					i = 0;
				}
			}
		}
	}

	cout << "\n";
}

void f3() {
	cout << "3. feladat\n";

	for (int j = 5; j < 8; j++) {
		int perc = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i].nap == j) {
				perc += arr[i].hossz;
			}
		}
		cout << j - 4 << ". nap: " << string_atvalto(perc) << endl;
	}
	cout << "\n";
}

void f4() {
	cout << "4. feladat\n";

	int max = 0;	

	for (int i = 0; i < N; i++) {
		if (arr[i].nap == 6) {
			if (arr[i].hossz > max) {
				max = arr[i].hossz;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (arr[i].hossz == max) {
			cout << arr[i].nev << " " << arr[i].hossz << "\n";
		}
	}

	cout << "\n";
}

void f5() {
	cout << "5. feladat\n";

	for (int j = 5; j < 9; j++) {
		bool ebedszunet = false;
		int k = 1;
		int perc = 8 * 60;
		cout << "november.: " << j << " ";
		for (int i = 0; i < N; i++) {
			if (arr[i].nap == j) {
				if (arr[i].sorszam == k) {
					perc += arr[i].hossz;
					perc += 20;
					k++;
					i = 0;
					if (perc >= 12 * 60 && ebedszunet == false) {
						perc += 60;
						ebedszunet = true;
					}
				}
			}
		}
		vege[j - 5] = string_atvalto(perc);
		cout << vege[j - 5] << "\n";
	}
	cout << "\n";
}

void f6() {
	cout << "6. feladat\n";
	// harmadik nap = 7.
	
	for (int j = 5; j < 9; j++) {
		int perc = 8 * 60;
		for (int i = 0; i < N; i++) {
			if (arr[i].nap == j) {
				perc += arr[i].hossz;
				if (perc >= 12 * 60) {
					ebedszunet[j - 5] = string_atvalto(perc);
					break;
				}
			}
		}
	}

	cout << "Az ebedszunet " << ebedszunet[2] << "-kor kezdodik\n";

	cout << "\n";
}

void f7() {
	cout << "7. feladat\n";
	vector<pair<string, int>> eloado;

	bool van = false;
	for (int i = 0; i < N; i++) {
		if (arr[i].nev == arr[i + 1].nev) {
			int alkalom = 2;
			i++;
			van = true;

			while (arr[i].nev == arr[i + 1].nev) {
				i++;
				alkalom++;
			}

			eloado.push_back(make_pair(arr[i].nev, alkalom));
		}
	}

	for (auto i : eloado) {
		cout << i.first << " " << i.second << "\n";
	}

	cout << "\n";
}

void f8() {
	cout << "8. feladat\n";
	int input_nap, input_ora, input_perc;
	cout << "Adj meg napot (5-8)";
	cin >> input_nap;
	cout << "Adj meg orat (0-23)";
	cin >> input_ora;
	cout << "Adj meg percet (0-59)";
	cin >> input_perc;

	if (int_atvalto(input_ora, input_perc) < 8 * 60) {
		cout << "Meg nem kezdodott el.\n";
	} else if (string_atvalto(input_ora * 60 + input_perc) > vege[input_nap - 5]) {
		cout << "Mar veget ert.\n";
	} else if (ebedszunet[input_nap - 5] >= string_atvalto(input_ora * 60 + input_perc) && ebedszunet[input_nap - 5] <= string_atvalto(input_ora * 60 + input_perc + 60)) {
		cout << "Ebedszunet\n"; // nem mukodik
	}
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
