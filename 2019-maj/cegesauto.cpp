#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct cegesauto {
    int nap; // 1-30
    string ora; // oo:pp
    string rendszam; // 6
    int azon; // 500-600
    int km; 
    bool kibe; // ki - 0, be - 1
} parkol[500];

int N;

void f1() {
    ifstream f;
    f.open("autok.txt");

    int i = 0;
    while (f >> parkol[i].nap >> parkol[i].ora >> parkol[i].rendszam >> parkol[i].azon >> parkol[i].km >> parkol[i].kibe) {
        // cout << parkol[i].nap << " " << parkol[i].ora << " " << parkol[i].rendszam << " " << parkol[i].azon << " " << parkol[i].km << " " << parkol[i].kibe << endl;
        i++;
    }

    N = --i;

    f.close();
}

void f2() {
    cout << "2. feladat\n";

    for (int i = N; i > 0; i--) {
        if (parkol[i].kibe == 0) {
            cout << parkol[i].nap << ". nap rendszám: " << parkol[i].rendszam << endl;
            break;
        }
    }
}

void f3() {
    cout << "3. feladat\nNap: ";
    int input;
    cin >> input;
    cout << "Forgalom a(z) " << input << ". napon:\n";

    string kiir;

    for (int i = 0; i < N; i++) {
        if (input == parkol[i].nap) {
            if (parkol[i].kibe == 1) kiir = "be"; else kiir = "ki";
            cout << parkol[i].ora << " " << parkol[i].rendszam << " " << parkol[i].azon << " " << kiir << endl;
        }
    }
}

void f4() {
    cout << "4. feladat\n";

    int nincsitt = 0;
    /*
    for (int j = 300; j < 310; j++) {
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (stoi(parkol[i].rendszam.substr(3, 3)) == j) {
                sum++;
            }
        }

        if (sum % 2 == 1) nincsitt++;
    }
    */
    // tok jo lenne ha nem lenne 5 az output 4 helyett

    for (int j = 300; j < 310; j++) {
        for (int i = N; i > 0; i--) {
            if (stoi(parkol[i].rendszam.substr(3, 3)) == j) {
                if (parkol[i].kibe == 0) {
                    nincsitt++;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    cout << "A hónap végén " << nincsitt << " autót nem hoztak vissza.\n";
}

void f5() {
    cout << "5. feladat\n";
     
    int elso[10]; int utolso[10];

    for (int j = 300; j < 310; j++) {
        for (int i = 0; i < N; i++) {
            if (stoi(parkol[i].rendszam.substr(3, 3)) == j) {
                elso[j - 300] = parkol[i].km;
                break;
            }
        }
    }

    for (int j = 300; j < 310; j++) {
        for (int i = N; i > 0; i--) {
            if (stoi(parkol[i].rendszam.substr(3, 3)) == j) {
                utolso[j - 300] = parkol[i].km;
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << "CEG" << i + 300 << " " << utolso[i] - elso[i] << "km\n";
    }
}

void f6() {
    cout << "6. feladat\n";

    int megtett = 0;
    int max = 0;
    int szemely = 0;

    for (int i = 0; i < N; i++) {
        if (parkol[i].kibe == 0) {
            int j = i + 1;
            while (parkol[i].rendszam != parkol[j].rendszam && j < N) {
                j++;
            }

            if (j >= N) break;

            megtett = parkol[j].km - parkol[i].km;
        
            if (megtett > max) {
                max = megtett;
                szemely = parkol[i].azon;
            }
        }
    }

    cout << "Leghosszabb út: " << max << " km, személy: " << szemely << endl;
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
