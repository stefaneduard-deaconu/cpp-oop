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
    int anFabricatie;
public:
    Masina() {
        marca = " ";
        anFabricatie = 0;
    }

    friend istream& operator >> (istream& in, Masina& m) {
        in >> m.marca >>  m.anFabricatie;
        return in;
    }
    friend ostream& operator << (ostream& out, Masina& m) {
        out << m.marca << " " << m.anFabricatie << " ";
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
        return out;
    }
    bool operator >= (double val) {
        return autonomieEstimata() >= val;
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

        return out;
    }
    bool operator >= (double val) {
        return autonomie() >= val;
    }
};

int main() {
    int N, M;
    double K;
    cin >> N >> M >> K;
    MasinaElectrica electrice[50];
    for (int i =0; i < N; i++) {
        cin >> electrice[i];
    }
    MasinaCombustibil combustibile[50];
    for (int i =0; i < M; i++) {
        cin >> combustibile[i];
    }

    bool gasit = false;
    for (int i = 0; i< N; i++) {
        if (electrice[i] >= K) {
            cout << electrice[i] << endl;
            gasit = true;
        }
    }

    for (int i = 0; i< M; i++) {
        if (combustibile[i] >= K) {
            cout << combustibile[i] << endl;
            gasit = true;
        }
    }
    if (!gasit) {
        cout << -1 << endl;
    }
}