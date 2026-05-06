//
// Created by aqwer on 5/6/2026.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Forma {
protected:
    string nume;
public:
    virtual double aria() = 0;
    virtual double perimetru() = 0;
    virtual void citire(istream& in) = 0;
    friend ostream& operator << (ostream& out, const Forma& f) {
        out << f.nume;
        return out;
    }
    virtual ~Forma() {};
};

class Patrat : public Forma {
    private:
        double latura;
    public:
        Patrat() {
            latura = 0;
            nume = " ";
        }

    void citire(istream& in) { in >> nume >> latura; }

    virtual double aria() {
            return latura * latura;
        }
    virtual double perimetru() {
            return 4*latura;
        }
    friend istream& operator >> (istream& in, Patrat& p) {
            in >> p.nume >> p.latura;
            return in;
        }
};

class Dreptunghi : public Forma {
    private:
        double latime, lungime;
    public:
    Dreptunghi() {
        latime = 0;
        lungime = 0;
        nume = " ";
    }
    void citire(istream& in) override { in >> nume >> latime >> lungime; }

    virtual double aria() {
        return latime * lungime;
    }
    virtual double perimetru() {
        return 2*(latime + lungime);
    }
    friend istream& operator >> (istream& in, Dreptunghi& d) {
        in >> d.nume >> d.latime >> d.lungime;
        return in;
    }
};

class Cerc : public Forma {
    private:
    double raza;
    public:
    Cerc() {
        raza = 0;
        nume = " ";
    }
    void citire(istream& in) override { in >> nume >> raza; }

    virtual double aria() {
        return 3.14 * raza * raza;
    }
    virtual double perimetru() {
        return 2 * 3.14 * raza;
    }
    friend istream& operator >> (istream& in, Cerc& c) {
        in >> c.nume >> c.raza;
        return in;
    }
};

class Triunghi : public Forma {
    private:
    double A, B, C;
public:
    Triunghi() {
        A = 0;
        B = 0;
        C = 0;
        nume = " ";
    }
    void citire(istream& in) override { in >> nume >> A >> B >> C; }

    virtual double perimetru() {
        return (A + B + C);
    }
    virtual double aria() {
        double S =  perimetru() / 2.0;
        return sqrt(S * (S - A) * (S - B) * (S - C));
    }
    friend istream& operator >> (istream& in, Triunghi& t) {
        in >> t.nume >> t.A >> t.B >> t.C;
        return in;
    }
};

int main() {
    int N;
    string tip;
    cin >> N;
    Forma* forme[100];
    for ( int i = 0; i < N; i++) {
        cin >> tip;
        if (tip == "PATRAT") {
            forme[i] = new Patrat();
        }
        else if (tip == "DREPTUNGHI") {
            forme[i] = new Dreptunghi();
        }
        else if (tip == "CERC") {
            forme[i] = new Cerc();
        }
        else  {
            forme[i] = new Triunghi();
        }
        forme[i]->citire(cin);
    }
    double X;
    cin >> X;
    Forma* minim = nullptr;
    //gasim minim ititial

    for (int i = 0; i < N; i++) {
        if (forme[i]->perimetru() >= X) {
            if (minim == nullptr || forme[i]->aria() < minim->aria()) {
                minim = forme[i];
            }
        }
    }

    if (minim != nullptr) {
        cout << *minim;
    }
    else cout << "NU EXISTA" << endl;
    for(int i = 0; i < N; i++){
        delete forme[i];
    }
}



//4
//PATRAT PATRAT 4
//DREPTUNGHI DREPTUNGHI 3 5.2
//CERC CERC 3
//TRIUNGHI TRIUNGHI 3 4 5
//15