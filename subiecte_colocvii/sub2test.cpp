//
// Created by aqwer on 3/20/2026.
//


#include <iostream>
#include <string>

using namespace std;

// ==========================================
// Clasa Panou
// ==========================================
class Panou {
private:
    int id;
    string culoare;
    double lungime;
    double latime;
    double status;

public:
    Panou() {
        this->id = 0;
        this->culoare = "";
        this->lungime = 0.0;
        this->latime = 0.0;
        this->status = 0.0;
    }

    Panou(int id, string culoare, double lungime, double latime) {
        this->id = id;
        this->culoare = culoare;
        this->lungime = lungime;
        this->latime = latime;
        this->status = 0.0;
    }

    Panou(const Panou& other) {
        this->id = other.id;
        this->culoare = other.culoare;
        this->lungime = other.lungime;
        this->latime = other.latime;
        this->status = other.status;
    }

    Panou& operator=(const Panou& other) {
        if (this != &other) {
            this->id = other.id;
            this->culoare = other.culoare;
            this->lungime = other.lungime;
            this->latime = other.latime;
            this->status = other.status;
        }
        return *this;
    }

    ~Panou() {}

    int getId() const { return id; }
    string getCuloare() const { return culoare; }
    double getStatus() const { return status; }
    double getLungime() const { return lungime; }
    double getLatime() const { return latime; }

    void pictare_panou(double cantitateVopsea) {
        double ariaTotala = this->lungime * this->latime;
        if (ariaTotala > 0) {
            double ariaVopsita = cantitateVopsea / 0.25;
            double procent = (ariaVopsita / ariaTotala) * 100.0;
            this->status += procent;
            if (this->status > 100.0 - 1e-7) this->status = 100.0;
        } else {
            this->status = 100.0;
        }
    }

    friend istream& operator>>(istream& in, Panou& p) {
        in >> p.id >> p.culoare >> p.lungime >> p.latime;
        p.status = 0.0;
        return in;
    }
};

// ==========================================
// Clasa Robot
// ==========================================
class Robot {
private:
    int id;
    string culoare;
    double capacitateTanc;

public:
    Robot() {
        this->id = 0;
        this->culoare = "";
        this->capacitateTanc = 0.0;
    }

    Robot(int id, string culoare, double capacitateTanc) {
        this->id = id;
        this->culoare = culoare;
        this->capacitateTanc = capacitateTanc;
    }

    Robot(const Robot& other) {
        this->id = other.id;
        this->culoare = other.culoare;
        this->capacitateTanc = other.capacitateTanc;
    }

    Robot& operator=(const Robot& other) {
        if (this != &other) {
            this->id = other.id;
            this->culoare = other.culoare;
            this->capacitateTanc = other.capacitateTanc;
        }
        return *this;
    }

    ~Robot() {}

    int getId() const { return id; }
    string getCuloare() const { return culoare; }
    double getCapacitateTanc() const { return capacitateTanc; }

    void pictare(Panou& p) {
        if (this->culoare == p.getCuloare() && this->capacitateTanc > 0 && p.getStatus() < 100.0) {
            double ariaTotala = p.getLungime() * p.getLatime();
            if (ariaTotala > 0) {
                double necesarTotal = ariaTotala * 0.25;
                double vopseaNecesara = necesarTotal * (100.0 - p.getStatus()) / 100.0;
                double vopseaFolosita = (this->capacitateTanc < vopseaNecesara) ? this->capacitateTanc : vopseaNecesara;

                this->capacitateTanc -= vopseaFolosita;
                p.pictare_panou(vopseaFolosita);

                if (this->capacitateTanc < 1e-7) this->capacitateTanc = 0.0;
            } else {
                p.pictare_panou(0);
            }
        }
    }

    friend istream& operator>>(istream& in, Robot& r) {
        in >> r.id >> r.culoare >> r.capacitateTanc;
        return in;
    }
};

// ==========================================
// Functia MAIN
// ==========================================
int main() {
    int M;
    if (!(cin >> M)) return 0;

    Robot* roboti = new Robot[M];
    for (int i = 0; i < M; ++i) {
        cin >> roboti[i];
    }

    int K;
    cin >> K;
    Panou* panouri = new Panou[K];
    for (int i = 0; i < K; ++i) {
        cin >> panouri[i];
    }

    bool gasitPrimulRobotEpuizat = false;

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < M; ++j) {
            double capacitateInainte = roboti[j].getCapacitateTanc();
            roboti[j].pictare(panouri[i]);

            if (!gasitPrimulRobotEpuizat && capacitateInainte > 0 && roboti[j].getCapacitateTanc() == 0) {
                cout << roboti[j].getId() << " " << roboti[j].getCuloare() << " " << roboti[j].getCapacitateTanc() << "\n";
                gasitPrimulRobotEpuizat = true;
            }
        }
    }

    for (int i = 0; i < K; ++i) {
        cout << panouri[i].getId() << " "
             << panouri[i].getCuloare() << " "
             << (int)(panouri[i].getStatus() + 1e-6) << "%\n";
    }

    delete[] roboti;
    delete[] panouri;

    return 0;
}



