//
// Created by aqwer on 4/9/2026.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Jucator {
protected:
    string nume;
    double energie;
    int nrLupte;
public:
    Jucator() { nume = " "; energie = 100; nrLupte = 0; }

    friend ostream& operator << (ostream& out, const Jucator& j) {
        out << j.nume << " " << fixed << setprecision(2) << j.getEnergie();
        return out;
    }
    bool esteMort() const { return energie <= 1e-9; } // Folosim o marja mica pt precizie double
    double getEnergie() const { return energie; }
};

class Erou : public Jucator {
private:
    double defensiva;
    double coefRefacere;
public:
    Erou() { defensiva = 0; coefRefacere = 0; }

    friend istream& operator >> (istream& in, Erou& e) {
        in >> e.nume >> e.defensiva >> e.coefRefacere;
        e.energie = 100; e.nrLupte = 0;
        return in;
    }

    double apara(double atacDat) { return atacDat / (1 + defensiva); }

    void scadeEnergieDinDaune(double atacDat) {
        double atac_blocat = apara(atacDat);
        energie -= (atacDat - atac_blocat) * 0.1;
        if (energie < 0) energie = 0;
    }

    void participaLupta() { nrLupte++; }

    void refacereEnergie() {
        if (nrLupte % 3 == 0 && energie > 0) {
            energie += (100 - energie) * coefRefacere;
            if (energie > 100) energie = 100;
        }
    }

    bool maiMare(Erou& altErou) {
        if (abs(energie - altErou.energie) > 1e-9) return energie > altErou.energie;
        return defensiva > altErou.defensiva;
    }
};

class Raufacator : public Jucator {
private:
    double atac;
    double agresivitate;
public:
    Raufacator() { atac = 0; agresivitate = 0; }

    friend istream& operator >> (istream& in, Raufacator& r) {
        in >> r.nume >> r.atac >> r.agresivitate;
        r.energie = 100; r.nrLupte = 0;
        return in;
    }

    double ataca() { return atac * agresivitate; }
    void participaLupta() { nrLupte++; }

    void scadeEnergieDinAtac() {
        energie -= 0.10 * ataca();
        if (energie < 0) energie = 0;
    }

    void cresteAtac(double daune) {
        if (nrLupte % 3 == 0 && energie > 0) {
            atac += agresivitate * daune * 0.1;
        }
    }

    bool maiMare(Raufacator& altRaufacator) {
        if (abs(energie - altRaufacator.energie) > 1e-9) return energie > altRaufacator.energie;
        return atac > altRaufacator.atac;
    }
};

int main() {
    double defensiva_oras;
    int N, M;
    if (!(cin >> defensiva_oras >> N >> M)) return 0;

    Erou eroi[100];
    Raufacator raufacatori[100];

    for (int i = 0; i < N; i++) cin >> eroi[i];
    for (int i = 0; i < M; i++) cin >> raufacatori[i];

    while (true) {
        Erou* maxErou = nullptr;
        for (int i = 0; i < N; i++) {
            if (!eroi[i].esteMort()) {
                if (maxErou == nullptr || eroi[i].maiMare(*maxErou)) maxErou = &eroi[i];
            }
        }

        Raufacator* maxRaufacator = nullptr;
        for (int i = 0; i < M; i++) {
            if (!raufacatori[i].esteMort()) {
                if (maxRaufacator == nullptr || raufacatori[i].maiMare(*maxRaufacator)) maxRaufacator = &raufacatori[i];
            }
        }

        // --- LOGICA DE FINAL (Aici e de obicei problema la testul 12) ---

        // 1. Daca nu mai sunt raufacatori, eroii au castigat
        if (maxRaufacator == nullptr) {
            cout << "Au castigat: eroii" << endl;
            for (int i = 0; i < N; i++) if (!eroi[i].esteMort()) cout << eroi[i] << endl;
            break;
        }

        // 2. Daca toti jucatorii sunt morti dar orasul rezista, eroii castiga
        if (maxErou == nullptr && maxRaufacator == nullptr && defensiva_oras > 0) {
             cout << "Au castigat: eroii" << endl;
             break;
        }

        // 3. Daca orasul cade sau nu mai sunt eroi, raufacatorii castiga
        if (defensiva_oras <= 0 || maxErou == nullptr) {
            cout << "Au castigat: raufacatorii" << endl;
            for (int i = 0; i < M; i++) if (!raufacatori[i].esteMort()) cout << raufacatori[i] << endl;
            break;
        }

        // --- LUPTA ---
        double valoare_atac = maxRaufacator->ataca();
        double daune_oras_runda = maxErou->apara(valoare_atac);

        defensiva_oras -= daune_oras_runda;

        maxErou->scadeEnergieDinDaune(valoare_atac);
        maxRaufacator->scadeEnergieDinAtac();

        maxErou->participaLupta();
        maxRaufacator->participaLupta();

        maxErou->refacereEnergie();
        maxRaufacator->cresteAtac(daune_oras_runda);
    }

    return 0;
}
