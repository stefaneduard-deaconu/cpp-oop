#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// TODO Pasul 1: Definește clasa Animal (clasă de bază, abstractă)
//
// Atribute protected: string id, double greutate, bool viu
// Constructor: Animal(string id, double g) — viu = true
// Metodă pur virtuală: virtual double mananca(double& resursa) = 0;
// Metodă virtuală: virtual bool esteErbivor() = 0;
// Metode publice: bool esteViu(), string getId()

// TODO Pasul 2: Definește clasa Erbivor : public Animal
//
// Constructor: Erbivor(string id, double g) : Animal(id, g) {}
// Override mananca(double& resursa):
//   if (resursa <= 0) { viu = false; return 0; }
//   double mancare = greutate * resursa / 5000.0;
//   if (mancare < 5) mancare = 5;
//   if (mancare > resursa) mancare = resursa;
//   resursa -= mancare;
//   return mancare;
// Override esteErbivor(): return true;

// TODO Pasul 3: Definește clasa Carnivor : public Animal
//
// Constructor: Carnivor(string id, double g) : Animal(id, g) {}
// Override mananca(double& resursa):
//   if (resursa <= 0) { viu = false; return 0; }
//   double mancare = exp(greutate / 50.0) * resursa / 370.0;
//   if (mancare < 10) mancare = 10;
//   if (mancare > resursa) mancare = resursa;
//   resursa -= mancare;
//   return mancare;
// Override esteErbivor(): return false;

int main() {
    int n;
    cin >> n;

    // TODO Pasul 4: Creează un vector<Animal*> animale
    // vector<Animal*> animale;

    for (int i = 0; i < n; i++) {
        string tip, id;
        double greutate;
        cin >> tip >> id >> greutate;

        // TODO Pasul 4: Construiește obiectul corect
        //
        // if (tip == "ERBIVOR") {
        //     animale.push_back(new Erbivor(id, greutate));
        // } else {
        //     animale.push_back(new Carnivor(id, greutate));
        // }
    }

    double ct_iarba, ct_carne;
    cin >> ct_iarba >> ct_carne;

    int k;
    cin >> k;

    // TODO Pasul 5: Simulează K pași
    //
    // string idMaxPas1 = "";
    // double maxMancarePas1 = 0;
    //
    // for (int pas = 0; pas < k; pas++) {
    //     for (int i = 0; i < animale.size(); i++) {
    //         if (!animale[i]->esteViu()) continue;
    //
    //         double mancat;
    //         if (animale[i]->esteErbivor()) {
    //             mancat = animale[i]->mananca(ct_iarba);
    //         } else {
    //             mancat = animale[i]->mananca(ct_carne);
    //         }
    //
    //         // La primul pas, reține maximul
    //         if (pas == 0 && mancat > maxMancarePas1) {
    //             maxMancarePas1 = mancat;
    //             idMaxPas1 = animale[i]->getId();
    //         }
    //     }
    // }

    // TODO Pasul 6: Afișare
    //
    // cout << "a) " << idMaxPas1 << endl;
    //
    // int vii = 0;
    // for (int i = 0; i < animale.size(); i++) {
    //     if (animale[i]->esteViu()) vii++;
    // }
    // cout << "b) " << vii << endl;

    return 0;
}
