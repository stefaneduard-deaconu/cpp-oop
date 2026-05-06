//
// Created by aqwer on 3/20/2026.
//


#include <iostream>
#include <cmath>

using namespace std;

class Panou {
private:
    int id;
    string culoare;
    double lungime;
    double latime;
    double status;

public:
    Panou() {
        id = 0;
        culoare = "";
        lungime = 0;
        latime = 0;
        status = 0;
    }

    int getId() const { return id; }
    string getCuloare() const { return culoare; }
    double getLungime() const { return lungime; }
    double getLatime() const { return latime; }
    double getStatus() const { return status; }

    void pictare_panou(double cantitate){
        double aria = lungime * latime;
        double necesar_total = 0.25 * aria;
        if(necesar_total > 0){
            status += (cantitate / necesar_total) *100;
            if(status > 99.999) status = 100;
        }
    }

    friend istream& operator>>(istream& in, Panou& p) {
        in >> p.id >> p.culoare >> p.lungime >> p.latime;
        p.status = 0;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Panou& p) {
        out << p.id << " " << p.culoare << " " << (int)(p.status) << "%";
        return out;
    }
};

class Robot {
private:
    int id;
    string culoare;
    double capacitateTanc;

public:
    Robot() {
        id = 0;
        culoare = "";
        capacitateTanc = 0;
    }

    int getId() const { return id; }
    string getCuloare() const { return culoare; }
    double getCapacitate() const { return capacitateTanc; }

    void pictare(Panou& p) {
        if(culoare == p.getCuloare() && capacitateTanc > 0 && p.getStatus()<100){
            double aria = p.getLungime() * p.getLatime();
            double necesar_total = 0.25* aria;
            double necesar_ramas = necesar_total* ((100-p.getStatus())/100);
            if(capacitateTanc > necesar_ramas){
                p.pictare_panou(necesar_ramas);
                capacitateTanc -= necesar_ramas;
            }
            else{
                p.pictare_panou(capacitateTanc);
                capacitateTanc = 0;
            }
        }
    }
    friend istream& operator>>(istream& in, Robot& r) {
        in >> r.id >> r.culoare >> r.capacitateTanc;
        return in;
    }
};

int main() {
    int M;
    cin >> M;

    Robot* roboti = new Robot[M];
    for (int i = 0; i < M; i++) cin >> roboti[i];

    int K;
    cin >> K;
    Panou* panouri = new Panou[K];
    for (int i = 0; i < K; i++) cin >> panouri[i];

    int id_gol = -1;
    string culoare_gol = " ";

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < M; j++) {
            double vopsea_inainte = roboti[j].getCapacitate();
            roboti[j].pictare(panouri[i]);

            if (id_gol == -1 && vopsea_inainte > 0 && roboti[j].getCapacitate() == 0) {
                id_gol = roboti[j].getId();
                culoare_gol = roboti[j].getCuloare();
            }
        }
    }

    if (id_gol != -1) {
        cout << id_gol << " " << culoare_gol << " 0" << endl;
    }

    for (int i = 0; i < K; i++) {
        cout << panouri[i] << endl;
    }

    delete[] roboti;
    delete[] panouri;
}