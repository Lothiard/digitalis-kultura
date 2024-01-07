#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MyStruct {
    int kezd_sorszam, kezd_nap, kezd_honap, veg_nap, veg_honap;
    string nev, tema;
}taborok[100];

int N = 0;

void f1() {
    ifstream be;
    be.open("taborok.txt");

    int i = 0;
    while(!be.eof()) {
        be >> taborok[i].kezd_honap >> taborok[i].kezd_nap >> taborok[i].veg_honap >> taborok[i].veg_nap >> taborok[i].nev >> taborok[i].tema;
        // cout << " " << taborok[i].kezd_honap << " " << taborok[i].kezd_nap << " " << taborok[i].veg_honap << " " << taborok[i].veg_nap << " " << taborok[i].nev << " " << taborok[i].tema << endl;
        i++;
    }

    cout << "Az adatsorok sz�ma: " << i - 1 << endl;


    be.close();
}

void f2() {
    cout << "2. feladat\n";

    for (int i = 0; i < 100; i++) {
        if (taborok[i].kezd_honap == 0) {
            N = i;
            break;
        }
    }

    cout << "Az adatsorok sz�ma: " << N << endl;
    cout << "Az el�sz�r r�gz�tett t�bor t�m�ja: " << taborok[0].tema << endl;
    cout << "Az utolj�ra r�gz�tett t�bor t�m�ja: " << taborok[N - 1].tema << endl;
}

void f3() {
    cout << "3. feladat\n";
    bool van = false;

    for (int i = 0; i < N; i++) {
        if (taborok[i].tema == "zenei") {
            van = true;
            cout << "Zenei t�bor kezd�dik " << taborok[i].kezd_honap << ". h� " << taborok[i].kezd_nap << ". napj�n.\n";
        }
    }

    if (!van) {
        cout << "Nem volt zenei t�bor.\n";
    }
}

void f4() {
    cout << "4. feladat\n";
    int max = 0;

    for (int i = 0; i < N; i++) {
        if (taborok[i].nev.length() > max) {
            max = taborok[i].nev.length();
        }
    }

    cout << "Legn�pszer�bbek:\n";

    for (int i = 0; i < N; i++) {
        if (max == taborok[i].nev.length()) {
            cout << taborok[i].kezd_honap << " " << taborok[i].kezd_nap << " " << taborok[i].tema << endl;
        }
    }
}

int sorszam(int honap, int nap) {
    // 14, 31, 31
    // 6.16, 7.31, 8.31
    // 1-15, 16-46, 47-77

    if (honap == 6) {
        return nap;
    } else if (honap == 7) {
        return nap + 15;
    } else {
        return nap + 46;
    }
}

void f6() {
    cout << "6. feladat\n";
    int temp_honap, temp_nap;
    int db = 0;

    cout << "h�nap: "; cin >> temp_honap;
    cout << "nap: "; cin >> temp_nap;

    int input = sorszam(temp_honap, temp_nap);

    for (int i = 0; i < N; i++) {
        if (sorszam(taborok[i].kezd_honap, taborok[i].kezd_nap) <= input && sorszam(taborok[i].veg_honap, taborok[i].veg_nap) >= input) {
            db++;
        }
    }

    cout << "Ekkor �ppen " << db << " t�bor tart.";
}

void f7() {
    cout << "7. feladat\n";
    char betu;
    cout << "Adja meg egy tanu� bet�jel�t: "; cin >> betu;

    vector<int> szamsor;
    vector<int> atvaltott;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < taborok[i].nev.length(); j++) {
            if (taborok[i].nev[j] == betu) {
                szamsor.push_back(i);
            }
        }
    }

    for (int i = 0; i < szamsor.size(); i++) {
        atvaltott.push_back(sorszam(taborok[szamsor[i]].kezd_honap, taborok[szamsor[i]].kezd_nap));
    }

    sort(atvaltott.begin(), atvaltott.end());

    for (int i = 0; i < szamsor.size(); i++) {
        cout << atvaltott[i] << " ";
    }

    ofstream ki;
    ki.open("egytanulo.txt");

    int j = 0;
    for (int i = 0; i < szamsor.size(); i++) {
        if (atvaltott)
        ki << taborok[szamsor[i]].kezd_honap << "." << taborok[atvaltott[j]].kezd_nap << ".-" << taborok[atvaltott[j]].veg_honap << "." << taborok[atvaltott[j]].veg_nap << ". " << taborok[atvaltott[j]].tema << endl;
        j++;
    }

    ki.close();
}

int main() {
    setlocale(LC_ALL, "");

    f1();
    f2();
    f3();
    f4();
    f6();
    f7();
}
