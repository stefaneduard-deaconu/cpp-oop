//
// Created by aqwer on 3/11/2026.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class AutobuzBilet {
private:
    double pretBilet;
public: double calculeazaPret() {
    return pretBilet;
}
    AutobuzBilet(double p) {
        pretBilet = p;
    }
};

class Taxi   {
private:
    double tarifPornire;
    double timpStationare;
    double distantaParcursa;

public:
double calculeazaPret() {
    double tarifStationare = 10*(1+((timpStationare/100)*(timpStationare/100)));
    double tarifDistanta = 10* exp(-distantaParcursa);
   return tarifPornire + (timpStationare * tarifStationare) + (distantaParcursa * tarifDistanta);
 }
 Taxi(double tp, double ts, double dp) {
    tarifPornire = tp;
    timpStationare = ts;
    distantaParcursa = dp;
    }
};


    class Camion {
    private:
        double greutateMarfa;
        double distantaParcursa;
    public:
        double calculeazaPret() {
            return (greutateMarfa * distantaParcursa)/500;
        }
        Camion(double gm, double dp) {
            greutateMarfa = gm;
            distantaParcursa = dp;
        }
    };

int main() {
    int N;
    cin >> N;

    vector<double> preturi;
    for (int i = 0; i < N; i++) {
        int tip;
        cin >> tip;

        if (tip == 1) {
            double p;
            cin >> p;
            AutobuzBilet a(p);
            preturi.push_back(a.calculeazaPret());
        }

        if (tip == 2) {
            double tp, ts, dp;
            cin >> tp >> ts >> dp;
            Taxi t(tp, ts, dp);
            preturi.push_back(t.calculeazaPret());
        }

        if (tip == 3) {
            double gm, dp;
            cin >> gm >> dp;
            Camion c(gm, dp);
            preturi.push_back(c.calculeazaPret());
        }
    }

    double total = 0;
    for (double pret: preturi) {
        total += pret;
    }
    cout << total;
    return 0;
}
