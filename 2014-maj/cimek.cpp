#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 2001:0db8 kezdetu - dokumentacios
// 2001:0e kezdetu - globalis egyedi
// fc/fd kezdetu - helyi egyedi
// nullak elhagyhatoak
// vezeto 0 = 0
// 2 vagy tobb db 0 = ures
// ?

string ip[500];
int N;
int input;
string roviditett1 = "";
string roviditett2 = "";

void f1() {
	ifstream f;
	f.open("ip.txt");

	int i = 0;
	while (!f.eof()) {
		getline(f, ip[i]);
		// cout << ip[i] << endl;
		i++;
	}

	N = --i;
	f.close();
}

void f2() {
	cout << "2. feladat:\nAz allomanyban " << N << " darab adator van\n\n";
}

void f3() {
	cout << "3. feladat:\n";
	string min = "ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff";
	for (int i = 0; i < N; i++) {
		if (min > ip[i]) {
			min = ip[i];
		}
	}

	cout << "A legalacsonyabb tarlolt IP-cim:\n" << min << "\n\n";
}

void f4() {
	cout << "4. feladat:\n";
	int dok = 0;
	int glo = 0;
	int hel = 0;

	for (int i = 0; i < N; i++) {
		if (ip[i].substr(0, 9) == "2001:0db8") dok++;
		else if (ip[i].substr(0, 7) == "2001:0e") glo++;
		else if (ip[i].substr(0, 2) == "fc" || ip[i].substr(0, 2) == "fd") hel++;
	}

	cout << "Dokumentacios cim: " << dok << " darab\n";
	cout << "Globalis egyedi cim: " << glo << " darab\n";
	cout << "Helyi egyedi cim: " << hel << " darab\n\n";
}

void f5() {
	ofstream f;
	f.open("sok.txt");

	for (int i = 0; i < N; i++) {
		int nullak = 0;
		for (int j = 0; j < 38; j++) {
			if (ip[i][j] == '0') {
				nullak++;
			}
		}

		if (nullak >= 18) {
			f << i + 1 << " " << ip[i] << endl;
		}
	}

	f.close();
}

void f6() {
	cout << "6. feladat:\n";
	cout << "Kerek egy sorszamot: ";
	cin >> input;
	cout << ip[input - 1] << "\n";
	
	for (int i = 0; i < 40; i++) {
		if (ip[input - 1][i] == '0' && ip[input - 1][i + 1] == '0') {
			roviditett1 += ip[input - 1][i];
			while (ip[input - 1][i + 1] == '0') {
				i++;
			}
		} else if (ip[input - 1][i] == '0' && ip[input - 1][i + 1] != '0') {
			roviditett1 += "";
		} else {
 			roviditett1 += ip[input - 1][i];
		}
	}
	cout << roviditett1 << "\n\n";
}

void f7() {
	cout << "7. feladat:\n";

	bool lehet = false;
	for (int i = 0; i < roviditett1.length(); i++) {
		if (roviditett1.substr(i, 2) == ":0") {
			lehet = true;
			int j = i + 2;
			while (roviditett1.substr(j, 2) == ":0") {
				j += 2;
			}
			i = j;
		}
		roviditett2 += roviditett1[i];
	}

	if (!lehet) {
		cout << "Nem roviditheto tovabb.";
	} else {
		cout << roviditett2;
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
}
