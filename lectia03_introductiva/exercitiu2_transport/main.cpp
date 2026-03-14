#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// TODO Pasul 1: Definește clasa Transport (clasă de bază, pur virtuală)
//
// Două metode pur virtuale:
//   virtual double calculeazaPret() = 0;
//   virtual double getDistanta() = 0;
//
// Nu putem crea obiecte Transport direct (e clasă abstractă).

// TODO Pasul 2: Definește clasa AutobuzBilet : public Transport
//
// Atribute private: double pretBilet, distanta
// Constructor: AutobuzBilet(double pb, double d)
// Override calculeazaPret(): returnează pretBilet
// Override getDistanta(): returnează distanta

// TODO Pasul 3: Definește clasa Taxi : public Transport
//
// Atribute private: double tarifPornire, timpStationare, distanta
// Constructor: Taxi(double tp, double ts, double d)
// Override calculeazaPret():
//   double tarifStat = 10.0 * (1.0 + (timpStationare / 100.0) * (timpStationare / 100.0));
//   double tarifDist = 10.0 * exp(-distanta);
//   return tarifPornire + timpStationare * tarifStat + distanta * tarifDist;
// Override getDistanta(): returnează distanta

// TODO Pasul 4: Definește clasa Camion : public Transport
//
// Atribute private: double greutateMarfa, distanta
// Constructor: Camion(double gm, double d)
// Override calculeazaPret(): returnează greutateMarfa * distanta / 500.0
// Override getDistanta(): returnează distanta

//int main() {
    int n;
    cin >> n;

    // TODO Pasul 5: Creează un vector<Transport*> servicii
    // vector<Transport*> servicii;

    for (int i = 0; i < n; i++) {
        string tip;
        cin >> tip;

        // TODO Pasul 6: Citește datele și adaugă în vector
        //
        // if (tip == "AutobuzBilet") {
        //     double pretBilet, distanta;
        //     cin >> pretBilet >> distanta;
        //     servicii.push_back(new AutobuzBilet(pretBilet, distanta));
        // } else if (tip == "Taxi") {
        //     double tarifPornire, timpStationare, distanta;
        //     cin >> tarifPornire >> timpStationare >> distanta;
        //     servicii.push_back(new Taxi(tarifPornire, timpStationare, distanta));
        // } else if (tip == "Camion") {
        //     double greutateMarfa, distanta;
        //     cin >> greutateMarfa >> distanta;
        //     servicii.push_back(new Camion(greutateMarfa, distanta));
        // }
    }

    // TODO Pasul 5: Cerința A — Distanța maximă
    //
    // double distMax = 0;
    // for (int i = 0; i < servicii.size(); i++) {
    //     double d = servicii[i]->getDistanta();
    //     if (d > distMax) distMax = d;
    // }
    // cout << "A) " << fixed << setprecision(2) << distMax << endl;

    // TODO Pasul 5: Cerința B — Suma totală încasată
    //
    // double sumaIncasata = 0;
    // for (int i = 0; i < servicii.size(); i++) {
    //     sumaIncasata += servicii[i]->calculeazaPret();
    // }
    // cout << "B) " << fixed << setprecision(2) << sumaIncasata << endl;

    return 0;
}
