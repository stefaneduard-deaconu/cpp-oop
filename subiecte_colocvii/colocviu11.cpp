#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Forma {
protected:
    string nume;
public:
    virtual double aria() = 0;
    virtual double perimetru() = 0;
    virtual void citire(istream& in) = 0; // Metodă virtuală pentru citire
    virtual ~Forma() {} // Destructor virtual obligatoriu

    friend ostream& operator << (ostream& out, const Forma& f) {
        out << f.nume;
        return out;
    }
};

class Patrat : public Forma {
    double latura;
public:
    void citire(istream& in) override { in >> nume >> latura; }
    double aria() override { return latura * latura; }
    double perimetru() override { return 4 * latura; }
};

class Dreptunghi : public Forma {
    double latime, lungime;
public:
    void citire(istream& in) override { in >> nume >> latime >> lungime; }
    double aria() override { return latime * lungime; }
    double perimetru() override { return 2 * (latime + lungime); }
};

class Cerc : public Forma {
    double raza;
public:
    void citire(istream& in) override { in >> nume >> raza; }
    double aria() override { return 3.14 * raza * raza; }
    double perimetru() override { return 2 * 3.14 * raza; }
};

class Triunghi : public Forma {
    double A, B, C;
public:
    void citire(istream& in) override { in >> nume >> A >> B >> C; }
    double perimetru() override { return A + B + C; }
    double aria() override {
        double S = perimetru() / 2;
        return sqrt(S * (S - A) * (S - B) * (S - C));
    }
};

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<Forma*> forme; // Vectorul este mai sigur decât Forma* forme[100]
    string tip;

    for (int i = 0; i < N; i++) {
        cin >> tip;
        Forma* f = nullptr;
        if (tip == "PATRAT") f = new Patrat();
        else if (tip == "DREPTUNGHI") f = new Dreptunghi();
        else if (tip == "CERC") f = new Cerc();
        else if (tip == "TRIUNGHI") f = new Triunghi();

        if (f) {
            f->citire(cin);
            forme.push_back(f);
        }
    }

    double X;
    cin >> X;

    Forma* minim = nullptr;
    for (auto f : forme) {
        if (f->perimetru() >= X) {
            if (minim == nullptr || f->aria() < minim->aria()) {
                minim = f;
            }
        }
    }

    if (minim) cout << *minim << endl;
    else cout << "NU EXISTA" << endl;

    // Curățare memorie
    for (auto f : forme) delete f;

    return 0;
}