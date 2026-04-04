//
// Created by aqwer on 3/26/2026.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Produs {
protected:
    string nume;
    double pret;
public:
    Produs() {
        nume = " ";
        pret = 0;
    }

    string getNume() {
        return nume;
    }

    double getPret() {
        return pret;
    }

    friend istream& operator>>(istream& in, Produs& p) {
        in >> p.nume;
        in >> p.pret;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Produs& p) {
        out << p.nume << " " << fixed << setprecision(2) << p.pret;
        return out;
    }
};

class Aliment : public Produs {
private:
    int termenValabilitate;
    string dataProductie;
public:
    Aliment() {
        termenValabilitate = 0;
        dataProductie = " ";
    }

    int calculZile(string dataActuala) {
        int d1, m1, y1, d2, m2, y2;
        sscanf(dataProductie.c_str(), "%d/%d/%d", &d1, &m1, &y1);
        sscanf(dataActuala.c_str(), "%d/%d/%d", &d2, &m2, &y2);
        int zileTrecute = (y2 - y1) * 360 + (m2 - m1) * 30 + (d2 - d1);
        return termenValabilitate - zileTrecute;
    }

    friend istream& operator>>(istream& in, Aliment& a) {
        in >> a.nume;
        in >> a.pret;
        in >> a.termenValabilitate;
        in >> a.dataProductie;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Aliment& a) {
        out << a.nume << " " << fixed << setprecision(2) << a.pret;
        out << " " << a.termenValabilitate << " " << a.dataProductie;
        return out;
    }
};

int main() {
    int N, K;
    cin >> N;
    Aliment alimente[50];
    for (int i = 0; i < N; i++) {
        cin >> alimente[i];
    }
    string dataActuala;
    cin >> dataActuala >> K;

    double maxPret = -1;
    bool gasit = false;

    for (int i = 0; i < N; i++) {
        int zile = alimente[i].calculZile(dataActuala);
        if (zile >= 0 && zile <= K) {
            cout << alimente[i] << endl;
            gasit = true;
            if (alimente[i].getPret() > maxPret) {
                maxPret = alimente[i].getPret();
            }
        }
    }

    if (!gasit) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < N; i++) {
            int zile = alimente[i].calculZile(dataActuala);
            if (zile >= 0 && zile <= K && alimente[i].getPret() == maxPret) {
                cout << alimente[i] << endl;
            }
        }
    }
    return 0;
}




