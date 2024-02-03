#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct busz {
    int megallo; // 0-29
    string datum;
    int id;
    string tipus;
    int ervenyesseg;
} jegy[2000];

int N;

void f1() {
    ifstream f;
    f.open("utasadat.txt");

    int i = 0;
    while (f >> jegy[i].megallo >> jegy[i].datum >> jegy[i].id >> jegy[i].tipus >> jegy[i].ervenyesseg) {
        // cout << jegy[i].megallo << " " << jegy[i].datum << " " << jegy[i].id << " " << jegy[i].tipus << " " << jegy[i].ervenyesseg << endl;
        i++;
    }

    N = i;

    f.close();
}

void f2() {
    cout << "2. feladat\nA buszra " << N << " utas akart felszállni. ";
}

void f3() {
    cout << "3. feladat\n";

    int ervenytelen = 0;
    for (int i = 0; i < N; i++) {
        string temp = to_string(jegy[i].ervenyesseg);

        if (temp.length() <= 2) {
            if (temp == "0") {
                ervenytelen++;
            }
        } else if (stoi(jegy[i].datum.substr(0, 8)) > jegy[i].ervenyesseg) {
            ervenytelen++;
        }
    }

    cout << "A buszra " << ervenytelen << " utas nem szállhatott fel.\n";
}

void f4() {
    cout << "4. feladat\n";

    int max = 0;
    int maxhely = 0;
    int sum[30];

    for (int i = 0; i < 30; i++) {
        sum[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        sum[jegy[i].megallo]++;
    }

    for (int i = 0; i < 30; i++) {
        if (max < sum[i]) {
            max = sum[i];
            maxhely = i;
        }
    }
    
    cout << "A legtöbb utas (" << max << " fö) a " << maxhely << ". megállóban próbált felszállni.\n";
}

void f5() {
    cout << "5. feladat\n";

    int ingyenes = 0;
    int kedvezmenyes = 0;

    for (int i = 0; i < N; i++) {
        if (jegy[i].tipus == "TAB" || jegy[i].tipus == "NYB") {
            kedvezmenyes++;

            string temp = to_string(jegy[i].ervenyesseg);

            if (temp.length() <= 2) {
                if (temp == "0") {
                    kedvezmenyes--;
                }
            } else if (stoi(jegy[i].datum.substr(0, 8)) > jegy[i].ervenyesseg) {
                kedvezmenyes--;
            }
        }
        else if (jegy[i].tipus == "NYP" || jegy[i].tipus == "RVS" || jegy[i].tipus == "GYK") {
            ingyenes++;

            string temp = to_string(jegy[i].ervenyesseg);

            if (temp.length() <= 2) {
                if (temp == "0") {
                    ingyenes--;
                }
            } else if (stoi(jegy[i].datum.substr(0, 8)) > jegy[i].ervenyesseg) {
                ingyenes--;
            }

        }
    }

    cout << "Ingyenesen utazók száma : " << ingyenes << " fö\nA kedvezményesen utazók száma : " << kedvezmenyes << " fö\n";
}

int napokszama(int e1, int h1, int n1, int e2, int h2, int n2) {
    h1 = (h1 + 9) % 12;
    e1 = e1 - h1 / 10;
    int d1 = 365 * e1 + e1 / 4 - e1 / 100 + e1 / 400 + (h1 * 306 + 5) / 10 + n1 - 1;
    h2 = (h2 + 9) % 12;
    e2 = e2 - h2 / 10;
    int d2 = 365 * e2 / 4 - e2 / 100 + e2 / 400 + (h2 * 306 + 5) / 10 + n2 - 1;

    return d2 - d1;
}

void f7() {
    ofstream f;
    f.open("figyelmeztetes.txt");

    for (int i = 0; i < N; i++) {
        string temp = to_string(jegy[i].ervenyesseg);
        if (temp.length() >= 2) {
            int e1 = stoi(jegy[i].datum.substr(0, 4));
            int h1 = stoi(jegy[i].datum.substr(4, 2));
            int n1 = stoi(jegy[i].datum.substr(6, 2));
            string e2 = to_string(jegy[i].ervenyesseg).substr(0, 4);
            string h2 = to_string(jegy[i].ervenyesseg).substr(4, 2);
            string n2 = to_string(jegy[i].ervenyesseg).substr(6, 2);

            if (napokszama(e1, h1, n1, stoi(e2), stoi(h2), stoi(n2) >= 3)) {
                f << jegy[i].id << " " << e2 << "-" << h2 << "-" << n2 << endl;
            }
        }
    }

    // ismeretlen okokbol error
  
    f.close();
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
