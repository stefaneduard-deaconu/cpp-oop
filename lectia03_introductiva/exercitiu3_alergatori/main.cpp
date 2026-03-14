#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// TODO Pasul 1: Definește clasa Alergator (clasă de bază, abstractă)
//
// Atribute protected: string id, double greutate, energie, distanta
// Constructor: Alergator(string id, double g, double e) — distanta = 0
// Metodă pur virtuală: virtual void alearga() = 0;
// Metode publice: double getDistanta(), string getId()

// TODO Pasul 2: Definește clasa Sprinter : public Alergator
//
// Constructor: Sprinter(string id, double g, double e) : Alergator(id, g, e) {}
// Override alearga():
//   double delta = 100.0 / greutate + energie * 3.0;
//   distanta += delta;
//   energie -= delta / 10.0;

// TODO Pasul 3: Definește clasa Maratonist : public Alergator
//
// Constructor: Maratonist(string id, double g, double e) : Alergator(id, g, e) {}
// Override alearga():
//   double delta = exp(40.0 / greutate) + energie * 2.0;
//   distanta += delta;
//   energie -= sqrt(delta) / 3.0;

//int main () {
    int n;
    cin >> n;

    // TODO Pasul 4: Creează un vector<Alergator*> alergatori
    // vector<Alergator*> alergatori;

    for (int i = 0; i < n; i++) {
        string tip, id;
        double greutate, energie;
        cin >> tip >> id >> greutate >> energie;

        // TODO Pasul 4: Construiește obiectul corect
        //
        // if (tip == "SPRINTER") {
        //     alergatori.push_back(new Sprinter(id, greutate, energie));
        // } else {
        //     alergatori.push_back(new Maratonist(id, greutate, energie));
        // }
    }

    // TODO Pasul 4: Simulează un singur moment de timp
    //
    // for (int i = 0; i < alergatori.size(); i++) {
    //     alergatori[i]->alearga();
    // }

    // TODO Pasul 4: Găsește cine a parcurs cel mai mult
    //
    // double distMax = 0;
    // string idMax = "";
    // for (int i = 0; i < alergatori.size(); i++) {
    //     if (alergatori[i]->getDistanta() > distMax) {
    //         distMax = alergatori[i]->getDistanta();
    //         idMax = alergatori[i]->getId();
    //     }
    // }
    // cout << idMax << endl;

    return 0;
}
