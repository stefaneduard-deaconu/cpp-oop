//
// Created by aqwer on 3/29/2026.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Materie {
private:
    string nume;
    double nota;

public: Materie() {
    nume = " ";
    nota = 0;
}

    string getNumeMaterie () {
        return nume;
    }
    double getNota() {
        return nota;
    }

    friend istream& operator >> (istream& in, Materie& M) {
    in >> M.nume;
    in >> M.nota;
    return in;
    }

    friend ostream& operator << (ostream& out, Materie& M){
        out << M.nume;
        out << M.nota;
        return out;
    }
};

class Persoana {
protected:
    string numePersoana;
    public:
    friend istream& operator >> (istream& in, Persoana& p){
        in >> p.numePersoana;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Persoana& p) {
        out << p.numePersoana;
        return out;
    }
};


class Elev : public Persoana {
private: vector<Materie> materii;

public:
friend istream& operator >> (istream& in, Elev& e){
    in >> (Persoana&)e;
    int N;
    in >> N;
    for(int i = 0; i < N; i ++){
        Materie m;
        in >> m;
        e.materii.push_back(m);
    }
    return in;
}

friend ostream& operator << (ostream& out, Elev& e) {
    out << (Persoana&)e;
    return out;
}

double operator () (string numeMaterie) const{
    for(int i = 0; i < materii.size();i++){
        Materie m = materii[i];
       if(m.getNumeMaterie() == numeMaterie){
           return m.getNota();
       }
    }
    return -1;
}
};


int main() {
    int K;
    cin >> K;
    vector<Elev> elevi(K);
    for(int i = 0; i < K; i++){
        cin >> elevi[i];
    }
    string numeMaterie;
    cin >> numeMaterie;
    double notaMaxima = -1;
    int index = -1;
    for(int i = 0; i < K; i++){
        double notaCurenta = elevi[i](numeMaterie);
        if(notaCurenta > notaMaxima){
            notaMaxima = notaCurenta;
            index = i;
        }
    }
        if(index != -1){
            cout << elevi[index];
        }

}


