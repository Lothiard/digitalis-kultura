#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct virag {
	int kezd, veg;
	char szin;
} virag[3000];

struct hatos {
	char szin;
	bool foglalt;
	int sorszam;
} hatos[3000];

int agyas;
int N;
vector<char> szinek;
int jelentkezes[3000];

void f1() {
	ifstream f;
	f.open("felajanlas.txt");

	f >> agyas;
	for (int i = 0; i < agyas; i++) {
		f >> virag[i].kezd >> virag[i].veg >> virag[i].szin;
		// cout << virag[i].kezd << " " << virag[i].veg << " " << virag[i].szin << endl;
	}

	f.close();
}

void f2() {
	cout << "2. feladat\n";

	int i = 0;
	while (virag[i].kezd != 0) {
		i++;
	}

	N = i;
	cout << "A felaj�nl�sok sz�ma: " << i << "\n\n";
}

void f3() {
	cout << "3. feladat\nA bej�rat mindk�t oldl�n �ltet�k:";

	for (int i = 0; i < N; i++) {
		if (virag[i].kezd > virag[i].veg) {
			cout << i + 1 << " ";
		}
	}
	cout << "\n\n";
}

void f4() {
	cout << "4. feladat\nAdja meg az �gy�s sorsz�m�t! ";
	int input; cin >> input;
	int felajanlasok = 0;

	for (int i = 0; i < N; i++) {
		if (virag[i].kezd <= input && virag[i].veg >= input) {
			felajanlasok++;
		}
	}

	cout << "A felaj�nl�k sz�ma: " << felajanlasok << endl;

	char valami = 0;
	for (int i = 0; i < N; i++) {
		if (virag[i].kezd <= input && virag[i].veg >= input) {
			valami = virag[i].szin;
			break;
		}
	}

	if (valami != 0) {
		cout << "A vir�g�gy�s sz�ne, ha csak az els� �ltet: " << valami << endl;
	} else {
		cout << "Ezt az �gy�st nem �ltetik be.\n";
	}

	
	for (int i = 0; i < N; i++) {
		if (virag[i].kezd <= input && virag[i].veg >= input) {
			bool found = false;
			for (char c : szinek) {
				if (virag[i].szin == c) {
					found = true;
				}
			}
			if (!found) {
				szinek.push_back(virag[i].szin);
			}
		}
	}
	
	// cout << "A vir�g�gy�s sz�nei: " << szinek[0];

	for (char c : szinek) {
		cout << c << " ";
	}
	
	
	cout << "\n\n";
}

void f5() {
	cout << "5. feladat\n";
	
	int osszeg = 0;
	bool mind = true;
	for (int i = 0; i < N; i++) {
		for (int j = virag[i].kezd; j < virag[i].veg; j++) {
			jelentkezes[j]++;
		}
	}

	for (int i = 0; i < agyas; i++) {
		osszeg += jelentkezes[i];
		if (jelentkezes[i] == 0) {
			mind = false;
		}
	}

	if (mind) {
		cout << "Minden �gy�s be�ltet�s�re van jelentkez�.\n";
	} else if (osszeg >= agyas) {
		cout << "�tszervez�ssel megoldhat� a be�ltet�s.\n";
	} else {
		cout << "A be�ltet�s nem oldhat� meg.\n";
	}
}

void f6() {
	ofstream f;
	f.open("szinek.txt");

	for (int i = 0; i < N; i++) {
		if (virag[i].kezd < virag[i].veg) { // normalis eset
			for (int j = virag[i].kezd; j < virag[i].veg; j++) {
				if (!hatos[j].foglalt) {
					hatos[j].foglalt = true;
					hatos[j].szin = virag[i].szin;
					hatos[j].sorszam = i + 1;
				}
			}
		} else { // overlap
			for (int j = virag[i].kezd; j < agyas; j++) {
				if (!hatos[j].foglalt) {
					hatos[j].foglalt = true;
					hatos[j].szin = virag[i].szin;
					hatos[j].sorszam = i + 1;
				}
			}
			for (int j = 0; j < virag[i].veg; j++) {
				if (!hatos[j].foglalt) {
					hatos[j].foglalt = true;
					hatos[j].szin = virag[i].szin;
					hatos[j].sorszam = i + 1;
				}
			}
		}
	}

	for (int i = 0; i < agyas; i++) {
		if (hatos[i].foglalt) {
			f << hatos[i].szin << " " << hatos[i].sorszam << endl;
		} else {
			f << "# 0\n";
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
