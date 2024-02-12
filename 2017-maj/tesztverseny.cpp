#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct valaszok {
	string az;
	string valasz;
} arr[500];

string megoldas;
int N;

string input;
int input_hely;

struct pontok {
	string az;
	int pont;
} top[500];

void f1() {
	cout << "1. feladat: Az adatok beolvasasa\n\n";
	ifstream f;
	f.open("valaszok.txt");

	int i = 0;
	f >> megoldas;

	// cout << megoldas << "\n";
	while (f >> arr[i].az >> arr[i].valasz) {
		// cout << arr[i].az << " " << arr[i].valasz << "\n";
		i++;
	}

	N = i;

	f.close();
}

void f2() {
	cout << "2. feladat: A vetelkedon " << N << " versenyzo indult.\n\n";
}

void f3() {
	cout << "3. feladat: A versenyzo azonositoja = ";
	cin >> input;

	int i = 0;
	while (input != arr[i].az) {
		i++;
	}
	input_hely = i;

	cout << arr[input_hely].valasz << "\t(a versenyzo valasza)\n\n";
}

void f4() {
	cout << "4. feladat:\n";
	cout << megoldas << "\t(a helyes megoldas)\n";

	for (int i = 0; i < 14; i++) {
		if (megoldas[i] == arr[input_hely].valasz[i]) {
			cout << "+";
		} else {
			cout << " ";
		}
	}

	cout << "\t(A versenyzo helyes valaszai)\n\n";
}

void f5() {
	cout << "5. feladat: A feladat sorszama = ";
	int felszam;
	cin >> felszam;

	int helyes = 0;
	for (int i = 0; i < N; i++) {
		if (megoldas[felszam - 1] == arr[i].valasz[felszam - 1]) {
			helyes++;
		}
	}

	cout << "A feladatra " << helyes << " fo, a versenyzok " << fixed << setprecision(2) << (float)helyes / (float)N * 100.00 << "%-a adott helyes valaszt.\n\n";
}

void f6() {
	ofstream f;
	f.open("pontok.txt");

	// 1-5: 3
	// 6-10: 4
	// 11-13: 5
	// 14: 6

	for (int i = 0; i < N; i++) {
		int pontszam = 0;
		for (int j = 0; j < 14; j++) {
			if (arr[i].valasz[j] == megoldas[j]) {
				if (j <= 4) pontszam += 3;
				else if (j <= 9) pontszam += 4;
				else if (j <= 12) pontszam += 5;
				else if (j == 13) pontszam += 6;
			}
		}
		f << arr[i].az << " " << pontszam << "\n";

		top[i].az = arr[i].az;
		top[i].pont = pontszam;
	}
	
	f.close();
}

void f7() {
	cout << "7. feladat: A verseny legjobbjai:\n";

	vector<pontok> top1;
	vector<pontok> top2;
	vector<pontok> top3;

	// max meghatarozasa (56)
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	for (int i = 0; i < N; i++) {
		if (top[i].pont > max1) {
			max1 = top[i].pont;
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (top[i].pont == max1) {
			pontok temp;
			temp.az = top[i].az;
			temp.pont = top[i].pont;
			top1.push_back(temp);
		}
	}

	// "masodik max" meghatarozasa
	for (int i = 0; i < N; i++) {
		if (top[i].pont > max2 && top[i].pont < max1) {
			max2 = top[i].pont;
		}
	}

	for (int i = 0; i < N; i++) {
		if (top[i].pont == max2) {
			pontok temp;
			temp.az = top[i].az;
			temp.pont = top[i].pont;
			top2.push_back(temp);
		}
	}

	// 3.
	for (int i = 0; i < N; i++) {
		if (top[i].pont > max3 && top[i].pont < max2) {
			max3 = top[i].pont;
		}
	}

	for (int i = 0; i < N; i++) {
		if (top[i].pont == max3) {
			pontok temp;
			temp.az = top[i].az;
			temp.pont = top[i].pont;
			top3.push_back(temp);
		}
	}

	// kiiras
	for (pontok i : top1) {
		cout << "1. dij (" << i.pont << " pont): " << i.az << "\n";
	}

	for (pontok i : top2) {
		cout << "2. dij (" << i.pont << " pont): " << i.az << "\n";
	}

	for (pontok i : top3) {
		cout << "3. dij (" << i.pont << " pont): " << i.az << "\n";
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
