//
// Created by aqwer on 3/28/2026.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Masina {
protected:
    string marca;
    string model;
    int anFabricatie;
public:
    Masina() {
        marca = " ";
        model = " ";
        anFabricatie = 0;
    }
    string getMarca(){
        return marca;
    }
    friend istream& operator >> (istream& in, Masina& m) {
        in >> m.marca >>  m.model  >>  m.anFabricatie;
        return in;
    }
    friend ostream& operator << (ostream& out, Masina& m) {
        out << m.marca  << " " << m.model << " " << m.anFabricatie << " ";
        return out;
    }
};

class MasinaElectrica : public Masina {
private:
    double capacitateBaterie;
public:
    double const autonomieEstimata() {
        return 5*capacitateBaterie;
    }
    MasinaElectrica() {
        capacitateBaterie = 0;
    }
    friend istream& operator >> (istream& in, MasinaElectrica& m) {
        in >> (Masina&)m >> m.capacitateBaterie;
        return in;
    }
    friend ostream& operator << (ostream& out, MasinaElectrica& m) {
        out << fixed << setprecision(2) << (Masina&)m;
        out << fixed << setprecision(2) << m.capacitateBaterie << " ";
        out << fixed << setprecision(2) << m.autonomieEstimata();
        return out;
    }
};

class MasinaCombustibil : public Masina {
    private:
    double capacitateRezervor;
    double consumMediu;
public:
    MasinaCombustibil() {
        capacitateRezervor = 0;
        consumMediu = 0;
    }
    double const autonomie() {
        return (capacitateRezervor/consumMediu)*100;
    }
    friend istream& operator >> (istream& in, MasinaCombustibil& m) {
        in >> (Masina&)m >> m.capacitateRezervor >> m.consumMediu;
        return in;
    }
    friend ostream& operator << (ostream& out, MasinaCombustibil& m) {
        out << fixed << setprecision(2) << (Masina&)m;
        out << fixed << setprecision(2) << m.capacitateRezervor << " ";
        out << fixed << setprecision(2) << m.consumMediu << " ";
        out << fixed << setprecision(2) << m.autonomie();
        return out;
    }
};

int main() {
    int N, M;
    string marca;
    cin >> N >> M >> marca;
    MasinaElectrica electrice[50];
    for ( int i = 0; i < N; i++ ) {
        cin >> electrice[i];
    }
    MasinaCombustibil combustibile[50];
    for ( int i = 0; i < M; i++ ) {
        cin >> combustibile[i];
    }

    for (int i = 0; i < N-1; i ++) {
        for (int j = 0; j< N -i -1; j++) {
            if (electrice[j].autonomieEstimata() > electrice[j+1].autonomieEstimata()) {
                MasinaElectrica const temp = electrice[j];
                electrice[j]=electrice[j+1];
                electrice[j+1]=temp;            //bubble sort pt electrice, radule
            }
        }
    }

    for (int i = 0; i < M-1; i ++) {
        for (int j = 0; j< M -i -1; j++) {
            if (combustibile[j].autonomie() > combustibile[j+1].autonomie()) {
                MasinaCombustibil const temp = combustibile[j];
                combustibile[j]=combustibile[j+1];              //bubble sort pt combustibile
                combustibile[j+1]=temp;
            }
        }
    }

    bool gasit = false;
    for (int i = 0; i < N; i++) {
        if (electrice[i].getMarca() == marca) {
            cout << electrice[i] << endl;
            gasit = true;
        }
    }

    for (int i = 0; i < M; i++) {
        if (combustibile[i].getMarca() == marca) {
            cout << combustibile[i] << endl;
            gasit = true;
        }
    }

    if (!gasit) {
        cout << -1 << endl;
    }
}