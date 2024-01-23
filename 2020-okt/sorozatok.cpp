#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct datum_t {
    int ev, honap, nap;
    bool elott(datum_t other) {
        if (other.ev > this->ev) return false;
        if (other.ev < this->ev) return true;
        if (other.honap > this->honap) return false;
        if (other.honap < this->honap) return true;
        if (other.nap > this->nap) return false;
        if (other.nap < this->nap) return true;
    }

    static datum_t konvert(string datum) {
        int ev, honap, nap;

        ev = atoi(datum.substr(0, 4).c_str());
        honap = atoi(datum.substr(5, 2).c_str());
        nap = atoi(datum.substr(8, 2).c_str());

        return datum_t{ ev, honap, nap };
    }
};

struct sorozatok {
    datum_t datum;
    bool hasDatum;
    string cim;
    string evad;
    int hossz;
    bool nezett;
}sorozat[400];


int N;

void f1() {
    ifstream f("lista.txt");

    string barmi;

    int i = 0;
    while (!f.eof()) {
        getline(f, barmi);
        if (barmi != "NI") {
            sorozat[i].datum = datum_t::konvert(barmi);
            sorozat[i].hasDatum = true;
        }
        getline(f, sorozat[i].cim);
        getline(f, sorozat[i].evad);
        f >> sorozat[i].hossz;
        f >> sorozat[i].nezett;
        f.ignore();
        // cout << sorozat[i].datum << " " << sorozat[i].cim << " " << sorozat[i].evad << " " << sorozat[i].hossz << " " << sorozat[i].nezett << endl;
        i++;
    }

    N = i; // 2. feladat

    f.close();
}

void f2() {
    cout << "2. feladat\n";

    int ismert = 0;
    for (int i = 0; i < N; i++) {
        if (sorozat[i].hasDatum) {
            ismert++;
        }
    }
    cout << "A lisában " << ismert << " db vetítési dátummal rendelkezö epizód van.\n\n";
}

void f3() {
    cout << "3. feladat\n";

    int megnezett = 0;
    for (int i = 0; i < N; i++) {
        if (sorozat[i].nezett) {
            megnezett++;
        }
    }

    cout << "A listában lévö epizódok " << setprecision(4) << (float)megnezett / (float)N * 100 << "%-át látta.\n\n";
}

void f4() {
    cout << "4. feladat\n";

    int osszesperc = 0;

    for (int i = 0; i < N; i++) {
        if (sorozat[i].nezett) {
            osszesperc += sorozat[i].hossz;
        }
    }

    int nap, ora, perc;
    nap = osszesperc / 60 / 24;
    ora = osszesperc / 60 % 24;
    perc = osszesperc % 60;
    cout << "Sorozatnézéssel " << nap << " napot " << ora << " órát " << perc << " percet töltött.\n\n";
}

void f5() {
    cout << "5. feladat\n";

    string datum;
    cout << "Adjon meg egy dátumot! ";
    cin >> datum;

    datum_t konvert = datum_t::konvert(datum);

    for (int i = 0; i < N; i++) {
        if (konvert.elott(sorozat[i].datum) && sorozat[i].nezett == 0 && sorozat[i].hasDatum) {
            cout << sorozat[i].evad << " " << sorozat[i].cim << endl;
        }
    }

    cout << endl;
}

string hetnapja(int ev, int honap, int nap) {
    string napok[7] = { "v", "h", "k", "sze", "cs", "p", "szo" };
    int honapok[12] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    if (honap < 3) {
        ev = ev - 1;
    }
    return napok[(ev + ev / 4 - ev / 100 + ev / 400 + honapok[honap - 1] + nap) % 7];
}

void f7() {
    cout << "7. feladat\n";
    cout << "Adja meg a hét napját (pédául cs)! Nap= ";
    string nap;
    cin >> nap;
    /*
    for (int i = 0; i < N; i++) {
        if (hetnapja() == nap) {

        }
    }
    folyt
    */
}

int main() {
    setlocale(LC_ALL, "");

    f1();
    f2();
    f3();
    f4();
    f5();
    f7();
}
