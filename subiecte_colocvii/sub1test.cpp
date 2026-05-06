//
// Created by aqwer on 3/14/2026.
//

#include <iostream>
#include <iomanip>
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
    friend istream& operator >> (istream& in, Gospodarie& g){
        in >> g.numeCasa >> g.nZile;
        g.consumZilnic = new double[g.nZile];
        g.consumTotal = 0;
        for(unsigned int i = 0; i < g.nZile;i++){
            cin >> g.consumZilnic[i];
            g.consumTotal += g.consumZilnic[i];
        }
        return in;
    }
    friend ostream& operator << (ostream& out, Gospodarie& g) {
        out << fixed << setprecision(2) << g.numeCasa << " " <<g.consumTotal;
        return out;
    }
    ~Gospodarie(){
        delete[] consumZilnic;
    }

    double getConsumTotal() { return consumTotal;}
};

class FurnizorEnergie{
    private:
    string nume;
    double prag;
    double tarifRedus;
    double tarifNormal;
    unsigned int nClienti;
    Gospodarie* clienti;
    public:
    FurnizorEnergie(){
        nume = " ";
        prag = 0;
        tarifRedus = 0;
        tarifNormal = 0;
        nClienti = 0;
        clienti = nullptr;
    }
    friend istream& operator >> (istream& in, FurnizorEnergie& f){
        in >> f.nume >> f.prag >> f.tarifRedus >> f.tarifNormal >> f.nClienti;
        f.clienti = new Gospodarie[f.nClienti];
        for(unsigned int i = 0; i < f.nClienti; i++){
            in >> f.clienti[i];
        }
        return in;
    }
    unsigned int getNCase(){ return nClienti;}
    double calculFactura(double consumTotal){
        if(consumTotal <= prag){
            return consumTotal * tarifRedus;
        }
        else{
            return (prag * tarifRedus) + (consumTotal-prag) * tarifNormal;
        }
    }
    Gospodarie& operator[](unsigned int index){
        return clienti[index];
    }
    double operator()(unsigned int index){
        double consumTotal = clienti[index].getConsumTotal();
        return calculFactura(consumTotal);
    }
    ~FurnizorEnergie() {
        delete[] clienti;
    }
};

int main() {
    FurnizorEnergie f;
    cin >> f;

    double val;
    cin >> val;
    bool nuExista = true;
    for(unsigned int i = 0; i < f.getNCase(); i++){
        if(f(i) > val){
            cout << f[i] << " " << fixed << setprecision(2) << f(i) << endl;
            nuExista = false;
        }
    }
    if(nuExista) cout << -1 << endl;
}
