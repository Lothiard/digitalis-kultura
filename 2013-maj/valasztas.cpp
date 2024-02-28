#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

struct valasztas {
    int sorszam;
    int szavazat;
    string keresztnev;
    string vezeteknev;
    string part;
} arr[100];

int N;
const int letszam = 12345;
int szavazott = 0;

void f1() {
    ifstream f;
    f.open("szavazatok.txt");

    int i = 0;
    while (f >> arr[i].sorszam >> arr[i].szavazat >> arr[i].vezeteknev >> arr[i].keresztnev >> arr[i].part) {
        // cout << arr[i].sorszam << " " << arr[i].szavazat << " " << arr[i].keresztnev << " " << arr[i].vezeteknev << " " << arr[i].part << "\n";
        i++;
    }

    N = i;
    
    f.close();
}

void f2() {
    cout << "2. feladat\n";
    cout << "A helyhatosagi valasztason " << N << " kepviselojelolt indult\n";
}

void f3() {
    cout << "3. feladat\n";
    string input_keresztnev, input_vezeteknev;
    cin >> input_vezeteknev;
    cin >> input_keresztnev;

    bool van = false;
    for (int i = 0; i < N; i++) {
        if (input_vezeteknev == arr[i].vezeteknev && input_keresztnev == arr[i].keresztnev) {
            van = true;
            cout << "A kepviselo " << arr[i].szavazat << " szavazatot kapott\n";
        }
    }

    if (!van) {
        cout << "ilyen nevu kepviselo nem szerepel a nyilvantartasban!\n";
    }
}

void f4() {
    cout << "4. feladat\n";

    for (int i = 0; i < N; i++) {
        szavazott += arr[i].szavazat;
    }

    cout << "A valasztason " << szavazott << " allampolgar, a jogusultak " << fixed << setprecision(2) << (float)szavazott / (float)letszam * 100.00 << "%-a vett reszt.\n";
}

void f5() {
    cout << "5. feladat\n";

    string partok[5] = { "-", "GYEP", "HEP", "TISZ", "ZEP" };
    int partonkent[5] = { 0, 0, 0, 0, 0 };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++) {
            if (partok[i] == arr[j].part) {
                partonkent[i] += arr[j].szavazat;
            }
        }
    }

    cout << "Zoldsegevok partja=\t" << setprecision(4) << (float)partonkent[0] / (float)szavazott * 100.00 << "%\n";
    cout << "Fuggetlen jeloltek=\t" << setprecision(4) << (float)partonkent[1] / (float)szavazott * 100.00 << "%\n";
    cout << "Husevok partja=\t\t" << setprecision(4) << (float)partonkent[2] / (float)szavazott * 100.00 << "%\n";
    cout << "Tejivok Szovetsege=\t" << setprecision(4) << (float)partonkent[3] / (float)szavazott * 100.00 << "%\n";
    cout << "Zoldsegevok partja=\t" << setprecision(4) << (float)partonkent[4] / (float)szavazott * 100.00 << "%\n";
}

void f6() {
    cout << "6. feladat\n";

    int max = 0;
    vector<int> maxKepviselokHelye;

    for (int i = 0; i < N; i++) {
        if (arr[i].szavazat >= max) {
            max = arr[i].szavazat;
        }
    }

    for (int i = 0; i < N; i++) {
        if (arr[i].szavazat == max) {
            maxKepviselokHelye.push_back(i);
        }
    }

    cout << "A legtobb szavazatot elert kepviselo(k):\n";
    for (int i : maxKepviselokHelye) {
        cout << arr[i].vezeteknev << " " << arr[i].keresztnev << " ";
        if (arr[i].part == "-") {
            cout << "fuggetlen\n";
        } else {
            cout << arr[i].part << "\n";
        }
    }
}

void f7() {
    ofstream f;
    f.open("kepviselok.txt");

    int keruletek[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < N; i++) {
        if (keruletek[arr[i].sorszam - 1] < arr[i].szavazat) {
            keruletek[arr[i].sorszam - 1] = arr[i].szavazat;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[j].sorszam == i + 1 && arr[j].szavazat == keruletek[i]) {
                f << i + 1 << " " << arr[j].vezeteknev << " " << arr[j].keresztnev << " ";
                if (arr[j].part == "-") {
                    f << "fuggetlen\n";
                } else {
                    f << arr[j].part << "\n";
                }
            }
        }
    }

    f.close();
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
