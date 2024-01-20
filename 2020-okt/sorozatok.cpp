#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct sorozatok {
    string datum;
    string cim;
    string evad;
    int hossz;
    bool nezett;
}sorozat[400];

int N;

void f1() {
    ifstream f("lista.txt");

    int i = 0;
    while (!f.eof()) {
        getline(f, sorozat[i].datum);
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
        if (sorozat[i].datum != "NI") {
            ismert++;
        }
    }
    cout << "A lis�ban " << ismert << " db vet�t�si d�tummal rendelkez� epiz�d van.\n\n";
}

void f3() {
    cout << "3. feladat\n";

    int megnezett = 0;
    for (int i = 0; i < N; i++) {
        if (sorozat[i].nezett) {
            megnezett++;
        }
    }

    cout << "A list�ban l�v� epiz�dok " << setprecision(4) << (float)megnezett / (float)N * 100 << "%-�t l�tta.";
}

int main() {
    setlocale(LC_ALL, "");

    f1();
    f2();
    f3();
}
