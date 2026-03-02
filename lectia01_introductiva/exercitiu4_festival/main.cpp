#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TODO: Definește clasa Tranzactie aici, deasupra lui main()
//
// Ar trebui să aibă:
// - atribut privat: string nume
// - atribut privat: int nr_bilete
// - constructor: Tranzactie(string n, int nr)
// - metodă: string getNume()
// - metodă: int getNrBilete()
//
// Exemplu de structură:
// class Tranzactie {
// private:
//     string nume;
//     int nr_bilete;
// public:
//     Tranzactie(string n, int nr) { ... }
//     string getNume() { return nume; }
//     int getNrBilete() { return nr_bilete; }
// };

int main() {
    int N;
    // TODO: cin >> N;

    vector<Tranzactie> tranzactii;

    // TODO: Loop de N ori
    // for (int i = 0; i < N; i++) {
    //     string nume;
    //     int nr;
    //     cin >> nume >> nr;
    //     tranzactii.push_back(Tranzactie(nume, nr));
    // }

    // TODO: Afișează doar cei cu > 5 bilete
    // for (Tranzactie t : tranzactii) {
    //     if (t.getNrBilete() > 5) {
    //         cout << t.getNume() << " a cumparat " << t.getNrBilete() << " bilete" << endl;
    //     }
    // }

    return 0;
}
