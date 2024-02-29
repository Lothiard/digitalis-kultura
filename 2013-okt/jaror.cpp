#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct jaror {
    int o, p, mp;
    string rendszam;
} jarmu[1000];

int N;

int mpbe(int o, int p, int mp) {
    return o * 3600 + p * 60 + mp;
}

void f1() {
    ifstream f;
    f.open("jarmu.txt");

    int i = 0;
    while (f >> jarmu[i].o >> jarmu[i].p >> jarmu[i].mp >> jarmu[i].rendszam) {
        // cout << " " << jarmu[i].o << " " << jarmu[i].p << " " << jarmu[i].mp << " " << jarmu[i].rendszam << "\n";
        i++;
    }

    N = i;
    
    f.close();
}

void f2() {
    cout << "2. feladat\n";

    cout << "Legalabb " << jarmu[N - 1].o - jarmu[0].o + 1 << " orat kellet dolgozniuk.\n\n";
}

void f3() {
    cout << "3. feladat\n";

    int ora = jarmu[0].o;

    for (int i = 0; i < N; i++) {
        if (jarmu[i].o != ora) {
            i++;
        } else {
            cout << ora << ". ora: " << jarmu[i].rendszam << "\n";
            ora++;
        }
    }

    cout << "\n";
}

void f4() {
    cout << "4. feladat\n";

    int B = 0;
    int K = 0;
    int M = 0;

    for (int i = 0; i < N; i++) {
        switch (jarmu[i].rendszam[0]) {
        case ('B'):
            B++;
            break;
        case ('K'):
            K++;
            break;
        case ('M'):
            M++;
            break;
        }
    }

    cout << "Buszok szama:\t" << B << "\n";
    cout << "Kamionok szama:\t" << K << "\n";
    cout << "Motorok szama:\t" << M << "\n\n";
}

void f5() {
    int kezd, veg;
    int max = 0;

    for (int i = 1; i < N; i++) {
        int temp = mpbe(jarmu[i].o, jarmu[i].p, jarmu[i].mp) - mpbe(jarmu[i - 1].o, jarmu[i - 1].p, jarmu[i - 1].mp);
        if (temp > max) {
            max = temp;
            kezd = i - 1;
            veg = i;
        }
    }

    cout << jarmu[kezd].o << ":" << jarmu[kezd].p << ":" << jarmu[kezd].mp << " - " << jarmu[veg].o << ":" << jarmu[veg].p << ":" << jarmu[veg].mp << "\n\n";
}

void f6() {
    cout << "6. feladat\nAdja meg a keresett rendszamot: ";
    string input;
    cin >> input;
    vector<string> lehetseges;
    bool helyes = true;

    for (int i = 0; i < N; i++) {
        helyes = true;
        for (int j = 0; j < input.length() - 1; j++) {
            if (jarmu[i].rendszam[j] != '*' || jarmu[i].rendszam[j] != input[j]) {
                helyes = false;
                break;
            }
        }

        if (helyes) {
            lehetseges.push_back(jarmu[i].rendszam);
        }
    }

    for (string i : lehetseges) {
        cout << i << "\n";
    }
}

int main() {
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
}
