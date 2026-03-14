//
// Created by aqwer on 3/14/2026.
//

#include <iostream>
#include <iomanip>
#include <vector>
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
        nZile = 0;                                                       //constructor implicit
        consumZilnic = nullptr;
        consumTotal = 0;
    }
    Gospodarie(string numeC, unsigned int nrzile, double *consumz, double consumt) {
        numeCasa = numeC;
        nZile = nrzile;
        // TODO consumZ este tipul double*, deci la copiere realoci
        //  regula se aplica la orice constructori
        consumZilnic = new double[nZile];
        for (unsigned int i = 0; i < nZile; i++) {
            consumZilnic[i] = consumz[i];
        }
        consumZilnic = consumz;                                          //constructor de initializare
        consumTotal = consumt;
    }
    Gospodarie(Gospodarie &gosp) {
        numeCasa = gosp.numeCasa;
        nZile = gosp.nZile;
        // daca ai un atribut la private de genul:     Tip* something;    este un array in C++ si trebuie realocat si in clasa
        consumZilnic = new double[nZile];
        for (unsigned int i = 0; i < nZile; i++) {
            consumZilnic[i] = gosp.consumZilnic[i];
        }
        consumTotal = gosp.consumTotal;
     }


    friend istream& operator>>(istream& in, Gospodarie &g) {
        in >> g.numeCasa;
        in >> g.nZile;
        g.consumZilnic = new double[g.nZile];
        for (unsigned int i = 0; i < g.nZile; i++) {
            in >> g.consumZilnic[i];
        }
        return in;
    }

    // destructor
    ~Gospodarie() {
        delete[] consumZilnic;
    }

    double getConsumTotal() {
        // desi e getter, consumTotal se calculeaza din consumZilnic,
        // deci e cel mai sigur sa il calculam de fiecare data.
        double consum = 0;
        for (unsigned int i = 0; i < nZile; i++) {
            consum += consumZilnic[i];
        }
        return consum;
    }

    // Alt+Insert to open the code generate, for creating getters, setters etc.
    string nume_casa() const {
        return numeCasa;
    }

    unsigned int n_zile() const {
        return nZile;
    }

    double * consum_zilnic() const {
        return consumZilnic;
    }

    double consum_total() const {
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
    FurnizorEnergie(string numeF, double pr, double tr, double tn, unsigned int nrclienti, Gospodarie *valClienti) {
        numeFurnizor = numeF;
        prag = pr;
        tarifRedus = tr;
        tarifNormal = tn;
        nClienti = nrclienti;
        clienti = new Gospodarie[nrclienti];
            for (unsigned int i = 0; i < nrclienti; i++) {
                clienti [i] = valClienti[i];
            }
    }
    FurnizorEnergie(FurnizorEnergie &f) {
        numeFurnizor = f.numeFurnizor;
        prag = f.prag;
        tarifRedus = f.tarifRedus;
        tarifNormal = f.tarifNormal;
        nClienti = f.nClienti;
        clienti = new Gospodarie[nClienti];
        for (unsigned int i = 0; i < nClienti; i++) {
            clienti [i] = f.clienti [i];
        }
    }
    double calculFactura(double consumTotal){
    }


    friend istream& operator>>(istream& in, FurnizorEnergie &f) {
        in >> f.numeFurnizor;
        in >> f.prag;
        in >> f.tarifRedus;
        in >> f.tarifNormal;
        in >> f.nClienti;
        f.clienti = new Gospodarie[f.nClienti];
        for (unsigned int i = 0; i < f.nClienti; i++) {
            in >> f.clienti[i];
        }
        return in;
    }

    // operator indexare
    Gospodarie& operator[] (unsigned int i) {
        return clienti [i];
    }
    // f[i];

    // TODO cerinte ne-a spus sa calculam factutoro folosing operatorul ()
    double operator()(unsigned int index) {
        // si sa returnezi aici factura pentru clienti[index];
        double consumTotal = clienti[index].getConsumTotal();
        double factura;
        if (consumTotal <= prag) {
            factura = consumTotal * tarifRedus;
        }
        if (consumTotal > prag) {
            factura = prag * tarifNormal + (consumTotal - prag)* tarifNormal;
        }
        // calculam factura
        // ...
        return factura;
    }
    // f(i);

    string nume_furnizor() const {
        return numeFurnizor;
    }

    double prag1() const {
        return prag;
    }

    double tarif_redus() const {
        return tarifRedus;
    }

    double tarif_normal() const {
        return tarifNormal;
    }

    unsigned int n_clienti() const {
        return nClienti;
    }

    Gospodarie * clienti1() const {
        return clienti;
    }
};

//
// int increase(int a) {
//     a++;
//     return a;
// }
// int increaseWithRef(int &a) {
//     a++;
//     return a;
// }

// int a = 2;
// increaseWithRef(a);
// cout << a; // ar afisa 3

int main() {
    FurnizorEnergie f;
    // int numeFurnizor, prag, tarifRedus, tarifNormal;
    cin >> f;
    double val;
    cin >> val;

    bool nuExistaCuValoarea = true;
    for (unsigned i = 0; i < f.n_clienti(); i++) {
        double valFactura = f(i);
        if (f(i) > val ) {
            cout << setprecision(2) << fixed <<  f[i].nume_casa() << " " << f[i].consum_total() << " " <<  f(i) << endl;
            nuExistaCuValoarea = false;
        }


    }

    if (nuExistaCuValoarea) {
        cout << -1 << endl;
    }

}
