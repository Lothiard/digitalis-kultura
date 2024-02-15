#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct radio {
	int nap; // 1 - 11
	int az; // 1 - 20
	string uzenet; 
} arr[200];

int N;
string ossz_uzenet[11];

void f1() {
	ifstream f;
	f.open("veetel.txt");

	int i = 0;
	while (f >> arr[i].nap >> arr[i].az) {
		f.ignore();
		getline(f, arr[i].uzenet, '\n');

		// cout << arr[i].nap << " " << arr[i].az << "\n" << arr[i].uzenet << endl;
		i++;
	}

	N = i;
	f.close();
}

void f2() {
	cout << "2. feladat:\n";

	cout << "Az elso uzenet rogzitoje: " << arr[0].az << "\n";
	cout << "Az utolso uzenet rogzitoje: " << arr[N - 1].az << "\n\n";
}

void f3() {
	cout << "3. feladat\n";

	for (int i = 0; i < N; i++) {
	int elso = 0;
	int hossz = 6;
		for (int j = 0; j < 90 - 6; j++) {
			if (arr[i].uzenet.substr(elso, hossz) == "farkas") {
				cout << arr[i].nap << ". nap " << arr[i].az << ". radioamator\n";
				break;
			} else {
				elso++;
			}
		}
	}
	cout << "\n";
}

void f4() {
	cout << "4. feladat\n";
	
	int sum[11];
	for (int i = 0; i < 10; i++) {
		sum[i] = 0;
	}

	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j].nap == i) {
				sum[i - 1]++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ". nap: " << sum[i] << " radioamator\n";
	}
	cout << "\n";
}

void f5() {
	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j].nap == i) {
				ossz_uzenet[i - 1] = arr[j].uzenet;
				break;
			}
		}
	}

	for (int i = 1; i < 11; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j].nap == i) {
				for (int k = 0; k < ossz_uzenet[i - 1].length(); k++) {
					if (arr[j].uzenet[k] != '#') {
						ossz_uzenet[i - 1][k] = arr[j].uzenet[k];
						if (arr[j].uzenet[k] == '$') {
							for (int l = k; l < ossz_uzenet[i - 1].length(); l++) {
								ossz_uzenet[i - 1][l] = '$';
							}
							break;
						}
					}
				}
			}
		}
	}

	ofstream f;
	f.open("adaas.txt");

	for (int i = 1; i < 11; i++) {

		f << ossz_uzenet[i - 1] << "\n";
	}

	f.close();
}

bool szame(string szo) {
	bool valasz = true;
	for (int i = 0; i < szo.length(); i++) {
		if (szo[i] < '0' || szo[i] > '9') {
			valasz = false;
		}
	}
	return valasz;
}

void f7() {
	cout << "7. feladat\n";
	int input_nap, input_szam;
	cout << "Adja meg a nap sorszamat! ";
	cin >> input_nap;
	cout << "Adja meg a radioamator sorszamat! ";
	cin >> input_szam;

	bool feljegyzes = false;
	bool info = false;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i].nap == input_nap && arr[i].az == input_szam) {
			feljegyzes = true;
			if (szame(arr[i].uzenet.substr(0, 1)) && szame(arr[i].uzenet.substr(2, 1))) {
				info = true;
				sum = arr[i].uzenet[0] - '0' + arr[i].uzenet[2] - '0';
				break;
			}
		}
	}

	if (!feljegyzes) cout << "Nincs ilyen feljegyzes\n";
	if (!info) cout << "Nincs informacio\n";
	else cout << "A megfigyelt egyedek szama: " << sum;
}

int main() {
	f1();
	f2();
	f3();
	f4();
	f5();
	f7();
}
