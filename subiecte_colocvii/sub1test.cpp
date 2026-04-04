//
// Created by aqwer on 3/14/2026.
//

#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;

class Gospodarie {
private:
    string numeCasa;
    unsigned int nZile;
    double *consumZilnic;
    double consumTotal;
public:
    Gospodarie() {
        numeCasa = " ";
        nZile = 0;
        consumZilnic = nullptr;
        consumTotal = 0;
    }

    Gospodarie(Gospodarie &gosp) {
        numeCasa = gosp.numeCasa;
        nZile = gosp.nZile;
        consumZilnic = new double[nZile];
        for (unsigned int i = 0; i < nZile; i++) {
            consumZilnic[i] = gosp.consumZilnic[i];
        }
        consumTotal = gosp.consumTotal;
    }

    friend istream& operator>>(istream& in, Gospodarie &g) {
        in >> g.numeCasa >> g.nZile;
        g.consumZilnic = new double[g.nZile];
        g.consumTotal = 0;
        for (unsigned int i = 0; i < g.nZile; i++) {
            in >> g.consumZilnic[i];
            g.consumTotal += g.consumZilnic[i];
        }
        return in;
    }

    ~Gospodarie() {
        delete[] consumZilnic;
    }

    string getNumeCasa() const {
        return numeCasa;
    }
    double getConsumTotal() const {
        return consumTotal;
    }
};

class FurnizorEnergie {
private:
    string numeFurnizor;
    double prag;
    double tarifRedus;
    double tarifNormal;
    unsigned int nClienti;
    Gospodarie *clienti;
public:
    FurnizorEnergie() {
        numeFurnizor = " ";
        prag = 0;
        tarifRedus = 0;
        tarifNormal = 0;
        nClienti = 0;
        clienti = nullptr;
    }

    friend istream& operator>>(istream& in, FurnizorEnergie &f) {
        in >> f.numeFurnizor >> f.prag >> f.tarifRedus >> f.tarifNormal >> f.nClienti;
        f.clienti = new Gospodarie[f.nClienti];
        for (unsigned int i = 0; i < f.nClienti; i++) {
            in >> f.clienti[i];
        }
        return in;
    }

    ~FurnizorEnergie() {
        delete[] clienti;
    }

    Gospodarie& operator[](unsigned int i) {
        return clienti[i];
    }

    double operator()(unsigned int index) {
        double consumTotal = clienti[index].consum_total();
        if (consumTotal <= prag) {
            return consumTotal * tarifRedus;
        }
        return prag * tarifRedus + (consumTotal - prag) * tarifNormal;
    }

    unsigned int getNCase() const { \
        return nClienti; }
};

int main() {
    FurnizorEnergie f;
    cin >> f;
    double val;
    cin >> val;

    bool nuExistaCuValoarea = true;
    for (unsigned i = 0; i < f.getNCase(); i++) {
        if (f(i) > val) {
            cout << fixed << setprecision(2)
                 << f[i].getNumeCasa() << " "
                 << f[i].getConsumTotal() << " "
                 << f(i) << endl;
            nuExistaCuValoarea = false;
        }
    }

    if (nuExistaCuValoarea) {
        cout << -1 << endl;
    }
}
