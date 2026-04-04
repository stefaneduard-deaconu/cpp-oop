//
// Created by aqwer on 4/4/2026.
//

#include <iostream>
#include <cmath>

using namespace std;

class Efect {
public:
    virtual int modificaSemnal(int semnal) = 0;
};

class Booster : public Efect {
private:
    int cantitate;

public:
    Booster() {
        cantitate = 0;
    }

    int modificaSemnal(int semnal) {
        return semnal + cantitate;
    }

    friend istream& operator >> (istream& in, Booster& b) {
        in >> b.cantitate;
        return in;
    }
};

class Clipper : public Efect {
private:
    int min_threshold;
    int max_threshold;

public:
    Clipper() {
        min_threshold = 0;
        max_threshold = 0;
    }

    int modificaSemnal(int semnal) {
        if (semnal > max_threshold) {
            return max_threshold;
        }
        else if (semnal < min_threshold) {
            return min_threshold;
        }
        else {
            return semnal;
        }
    }

    friend istream& operator >> (istream& in, Clipper& c) {
        in >> c.min_threshold;
        in >> c.max_threshold;
        return in;
    }
};

    class Bitcrusher: public Efect {
    private:
        int resolution;

    public:
        Bitcrusher() {
            resolution = 0;
        }
        int modificaSemnal(int semnal) {
            return (semnal / resolution)* resolution;
        }

        friend istream& operator >> (istream& in, Bitcrusher& b) {
            in >> b.resolution;
            return in;
        }
    };

class Semnal {
private:
    int S, semnale[100000] = {0};

public:
    Semnal() {
        S = 0;
    }

    friend istream &operator>>(istream &in, Semnal &s) {
        in >> s.S;
        for (int i = 0; i < s.S; i++) {
            in >> s.semnale[i];
        }
        return in;
    }

    void operator |=(Efect *efect) { //   Semnal |= Efect*    deci in main:     semnal |= efecte[i];
        for (int i = 0; i < S; i++) {
            semnale[i] = efect-> modificaSemnal(semnale[i]);
        }
    }

    friend ostream& operator << (ostream& out, Semnal& s) {
        for (int i = 0; i < s.S; i++) {
            out << s.semnale[i] << " ";
        }
        return out;
    }
};

int main() {
    Efect* efecte[100]; // verificam la rularea testelor daca nu cumva trebuie mai mult de 100
    Semnal semnal;
    cin >> semnal;
    int N;
    cin >> N;
    string tip;
    for (int i = 0; i<N; i++) {
        string tip;
        cin >> tip;
        if (tip == "BOOSTER") {
            efecte[i] = new Booster();
            cin >> (Booster&) *efecte[i];
        }
        else if (tip == "CLIPPER") {
            efecte[i] = new Clipper();
            cin >> (Clipper&) *efecte[i];
        }
        else {
            efecte[i] = new Bitcrusher();
            cin >> (Bitcrusher&) *efecte[i];
        }
    }
for (int i = 0; i < N;i++) {
    semnal |= efecte[i];
}

cout << semnal << endl;
}







