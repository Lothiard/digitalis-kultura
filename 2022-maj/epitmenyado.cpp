#include <iostream>
#include <fstream>
#include <map>
#include <utility>

using namespace std;

int A,B,C;

struct epito{
    int adoszam;
    string utca;
    string hazszam;
    char sav;
    int meret;
}telek[1000];

int N;

int ado(char adosav, int terulet) {
    int ar;
    switch (adosav) {
    case 'A':
        ar = A;
        break;
    case 'B':
        ar = B;
        break;
    case 'C':
        ar = C;
        break;
    }

    if (ar * terulet < 10000) {
        return 0;
    } else {
        return ar * terulet;
    }
}

void f1() {
    ifstream f;
    f.open("utca.txt");

    int i = 0;
    f >> A >> B >> C;
    while (!f.eof()) {
        f >> telek[i].adoszam >> telek[i].utca >> telek[i].hazszam >> telek[i].sav >> telek[i].meret;
        // cout << telek[i].adoszam << " " << telek[i].utca << " " << telek[i].hazszam << " " << telek[i].sav << " " << telek[i].meret << endl;
        i++;
    }

    i--;
    N = i;

    f.close();
}

void f2() {
    cout << "2. feladat. A mint�ban " << N << " telek szerepel\n";
}

void f3() {
    cout << "3. feladat. Egy tulajdonos ad�sz�ma: ";
    int input;
    cin >> input;

    bool van = false;
    for (int i = 0; i < N; i++) {
        if (input == telek[i].adoszam) {
            cout << telek[i].utca << " utca " << telek[i].hazszam << endl;
            van = true;
        }
    }

    if (!van) {
        cout << "Nem szerepel az �llom�nyban\n";
    }
}

void f5() {
    cout << "5. feladat.\n";
    int A[2] = { 0, 0 };
    int B[2] = { 0, 0 };
    int C[2] = { 0, 0 }; // {count, sum}

    for (int i = 0; i < N; i++) {
        switch (telek[i].sav) {
        case 'A':
            A[0]++;
            A[1] += ado(telek[i].sav, telek[i].meret);
            break;
        case 'B':
            B[0]++;
            B[1] += ado(telek[i].sav, telek[i].meret);
            break;
        case 'C':
            C[0]++;
            C[1] += ado(telek[i].sav, telek[i].meret);
            break;
        }
    }

    cout << "A s�vba " << A[0] << " telek esik, az ad� " << A[1] << " Ft.\n";
    cout << "B s�vba " << B[0] << " telek esik, az ad� " << B[1] << " Ft.\n";
    cout << "C s�vba " << C[0] << " telek esik, az ad� " << C[1] << " Ft.\n";
}

void f6() {
    cout << "6. feladat. A t�bb s�vba sorolt utc�k:\n";

    string temp_utca = telek[0].utca;
    char temp_sav = telek[0].sav;

    for (int i = 0; i < N; i++) {
        if (telek[i].utca == temp_utca) {
            if (temp_sav != telek[i].sav) {
                cout << telek[i].utca << endl;
                while (telek[i].utca == temp_utca) { i++; }
            }
        } else {
            temp_utca = telek[i].utca;
            temp_sav = telek[i].sav;
        }
    }
}

void f7() {
    ofstream f;
    f.open("fizetendo.txt");

    map<int, int> tablazat;

    for (int i = 0; i < N; i++) {
        tablazat[telek[i].adoszam] += ado(telek[i].sav, telek[i].meret);
    }

    for (auto i : tablazat) {
        f << i.first << " " << i.second << endl;
    }

    f.close();
}

int main() {
    setlocale(LC_ALL, "");
    f1();
    f2();
    f3();
    f5();
    f6();
    f7();
}
