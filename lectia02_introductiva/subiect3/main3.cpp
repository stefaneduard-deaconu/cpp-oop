//
// Created by aqwer on 3/12/2026.
//

#include <iostream>
#include <cmath>
using namespace std;

class Erbivor {
private:
    string ID;
    double greutate;
public:
    Erbivor(string i, double g) {
        ID = i;
        greutate = g;
    }
    string getId() {
        return ID;
    }
    double consumaMancare(double& cantitate_disponibila) {
        double consum = (greutate * cantitate_disponibila)/5000;
        if (cantitate_disponibila < 5) {
            consum = cantitate_disponibila;
        } else if (consum <5) {
            consum = 5;
        }
        cantitate_disponibila -= consum;
        return consum;
        }
    };

class Carnivor {
    private:
    string ID;
    double greutate;
public :
    Carnivor(string i, double g) {
    ID = i;
    greutate = g;
}
    string getId() {
    return ID;
}
    double consumaMancare(double& cantitate_disponibila) {
    double consum = ((exp(greutate/50)) * cantitate_disponibila )/370;
    if (cantitate_disponibila < 10) {
        consum = cantitate_disponibila;
    }  else if (consum < 10) {
        consum = 10;
    }
    cantitate_disponibila -= consum;
    return consum;
}
};

int main() {
    double CT_iarba, CT_carne;
    cin >> CT_iarba >> CT_carne;
    int N;
    cin >> N;
    string maxID;
    double maxConsum = -1;
    for (int i = 0; i < N; i++) {
        int tip;
        string id;
        double greutate;
        cin >> tip >> id >> greutate;

        if (tip == 1) {
            Erbivor e(id, greutate);
            double consum = e.consumaMancare(CT_iarba);
            if (consum > maxConsum) {
                maxConsum = consum;
                maxID = id;
            }
        }

        if (tip == 2) {
            Carnivor c(id, greutate);
            double consum = c.consumaMancare(CT_carne);
            if (consum > maxConsum) {
                maxConsum = consum;
                maxID = id;
            }
        }
    }
    cout << maxID << " " << maxConsum << endl;
    return 0;
}
