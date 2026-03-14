#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// TODO Pasul 1: Definește clasa Container
//
// Clasa de bază. Are o singură metodă:
//   virtual double calculeazaVolum() { return 0; }
//
// Exemplu:
// class Container {
// public:
//     virtual double calculeazaVolum() { ... }
// };

// TODO Pasul 2: Definește clasa Cub : public Container
//
// Atribut privat: double latura
// Constructor: Cub(double l)
// Override: double calculeazaVolum() override
//   Formula: latura * latura * latura

// TODO Pasul 2: Definește clasa Sfera : public Container
//
// Atribut privat: double raza
// Constructor: Sfera(double r)
// Override: double calculeazaVolum() override
//   Formula: 4.0 * M_PI * raza * raza * raza / 3.0

// TODO Pasul 2: Definește clasa Cilindru : public Container
//
// Atribute private: double raza, inaltime
// Constructor: Cilindru(double r, double h)
// Override: double calculeazaVolum() override
//   Formula: M_PI * raza * raza * inaltime

//int main() {
    int n;
    cin >> n;

    // TODO Pasul 3: Creează un vector<Container*> containere
    // vector<Container*> containere;

    for (int i = 0; i < n; i++) {
        string tip;
        cin >> tip;

        // TODO Pasul 3: Citește datele și adaugă în vector
        //
        // if (tip == "Cub") {
        //     double latura;
        //     cin >> latura;
        //     containere.push_back(new Cub(latura));
        // } else if (tip == "Sfera") {
        //     double raza;
        //     cin >> raza;
        //     containere.push_back(new Sfera(raza));
        // } else if (tip == "Cilindru") {
        //     double raza, inaltime;
        //     cin >> raza >> inaltime;
        //     containere.push_back(new Cilindru(raza, inaltime));
        // }
    }

    // TODO Pasul 4: Calculează volumul total
    //
    // double volumTotal = 0;
    // for (int i = 0; i < containere.size(); i++) {
    //     volumTotal += containere[i]->calculeazaVolum();
    // }
    // cout << fixed << setprecision(2) << volumTotal << endl;

    return 0;
}
