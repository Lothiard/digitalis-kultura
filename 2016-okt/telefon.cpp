#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct hivas {
	int kezd_ora, kezd_perc, kezd_masodperc;
	int vege_ora, vege_perc, vege_masodperc;
} hivas[1000];

int N;

int mpbe(int o, int p, int mp) {
	return mp + p * 60 + o * 3600;
}

void f2() {
	ifstream f;
	f.open("hivas.txt");

	int i = 0;
	while (f >> hivas[i].kezd_ora >> hivas[i].kezd_perc >> hivas[i].kezd_masodperc >> hivas[i].vege_ora >> hivas[i].vege_perc >> hivas[i].vege_masodperc) {
		// cout << hivas[i].kezd_ora << " " << hivas[i].kezd_perc << " " << hivas[i].kezd_masodperc << " " << hivas[i].vege_ora << " " << hivas[i].vege_perc << " " << hivas[i].vege_masodperc << endl;
		i++;
	}

	N = i;
}

void f3() {
	cout << "3. feladat\n";

	int j = 0;
	while (hivas[0].kezd_ora != j) {
		j++;
	}

	for (int i = 0; i < N; i++) {
		int	temp = 0;

		while (hivas[i].kezd_ora == j) {
			temp++;
			i++;
		}

		if (temp > 0) {
			cout << j << " ora " << temp << " hivas\n";
		} 
		j++;
		i--;
	}

	cout << "\n\n";
}

void f4() {
	cout << "4. feladat\n";

	int max = 0;
	int max_sor = 0;

	for (int i = 0; i < N; i++) {
		int temp = mpbe(hivas[i].vege_ora, hivas[i].vege_perc, hivas[i].vege_masodperc) - mpbe(hivas[i].kezd_ora, hivas[i].kezd_perc, hivas[i].kezd_masodperc);
		if (temp > max) {
			max = temp;
			max_sor = i + 1;
		}
	}

	cout << "A leghosszabb ideig vonalban levo hivo " << max_sor << ". sorban szerepel, a hivas hossza: " << max << " masodperc.\n\n";
}

void f5() {
	cout << "5. feladat\nAdjon meg egy idopontot! (ora perc masodperc) ";
	int ora, perc, masodperc;
	cin >> ora >> perc >> masodperc;

	int input = mpbe(ora, perc, masodperc);
	bool beszelo = false;
	int sum = 0;
	int hely;
	
	for (int i = 0; i < N; i++) {
		int kezd = mpbe(hivas[i].kezd_ora, hivas[i].kezd_perc, hivas[i].kezd_masodperc);
		int veg = mpbe(hivas[i].vege_ora, hivas[i].vege_perc, hivas[i].vege_masodperc);


		if (input >= kezd && input <= veg) {
			beszelo = true;
			hely = i + 1;

			for (int j = i - 2; j > 0; j--) {
				if (kezd < mpbe(hivas[j].vege_ora, hivas[j].vege_perc, hivas[j].vege_masodperc)) {
					sum++;
				}
			}

			for (int j = i + 1; j < N; j++) {
				if (veg > mpbe(hivas[j].kezd_ora, hivas[j].kezd_perc, hivas[j].kezd_masodperc) && veg < mpbe(hivas[j].vege_ora, hivas[j].vege_perc, hivas[j].vege_masodperc)) {
					sum++;
				}
			}
			break;
		}
	}

	if (!beszelo) {
		cout << "Nem volt beszelo\n\n";
	} else {
		cout << "A varakozok szama: " << sum << " a beszelo a " << hely << ". hivo\n\n";
	}
}

void f6() {
	cout << "6. feleadat\n";

	int muszak_vege = mpbe(12, 0, 0);
	int hely;

	for (int i = N - 1; i > 0; i--) {
		if (mpbe(hivas[i].kezd_ora, hivas[i].kezd_perc, hivas[i].kezd_masodperc) <= muszak_vege) {
			hely = i;
			break;
		}
	}

	// legnagzobb vegu visszafele, kivonni az utanalevo kezdetebol + az utanalevo vege
}

int main() {
	setlocale(LC_ALL, "");

	f2();
	f3();
	f4();
	f5();

	// cout << mpbe(12, 3, 36) - mpbe(11, 59, 53) - mpbe() << endl;

	f6();
}
