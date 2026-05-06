//
// Created by aqwer on 3/26/2026.
//

#include <iostream>
using namespace std;

class Persoana {
    protected:
    string nume;
    string prenume;
    public:
    Persoana() {
        nume = " ";
        prenume = " ";
    }
    friend istream& operator >> (istream& in, Persoana& p){
        in >> p.nume >> p.prenume;
        return in;
    }
    friend ostream& operator << (ostream& out, Persoana& p){
        out << p.nume << " " << p.prenume;
        return out;
    }

};

class Curs{
    private:
    int id;
    string nume;
    int nrCredite;
    public:
    Curs() {
        id = 0;
        nume = " ";
        nrCredite = 0;
    }
    friend istream& operator >> (istream& in, Curs& c){
        in >> c.id >> c.nume >> c.nrCredite;
        return in;
    }
    friend ostream& operator << (ostream& out, Curs &c){
        out << c.id << " " << c.nume << " " << c.nrCredite;
        return out;
    }
    int getCredite(){
        return nrCredite;
    }
    int getId(){
        return id;
    }
};

class Student : public Persoana{
    private:
    int nCursuri;
    int *idCursuri;
    int *note;
    public:
    Student() {
        nCursuri = 0;
        idCursuri = nullptr;
        note = nullptr;
    }
    friend istream& operator >> (istream& in, Student& s){
        in >> (Persoana&) s >> s.nCursuri;
        s.idCursuri = new int[s.nCursuri];
        for(int i = 0; i < s.nCursuri; i++){
            in >> s.idCursuri[i];
        }
        s.note = new int [s.nCursuri];
        for(int i = 0; i < s.nCursuri; i++){
            in >> s.note[i];
        }
        return in;
    }
    friend ostream& operator << (ostream& out, Student& s){
        out << (Persoana&) s ;
        return out;
    }
    double calculeazaBursa(Curs* cursuri, int n){
        float sumaNote = 0;
        float sumaCredite = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < nCursuri; j++){
                if(cursuri[i].getId() == idCursuri[j]){
                    sumaNote += note[j] * cursuri[i].getCredite();
                    sumaCredite += cursuri[i].getCredite();
                }
            }
        }
        float medie = sumaNote/sumaCredite;
        if(medie >= 8.50 && medie <= 9.00) return 500;
        if(medie >= 9.01 && medie <= 9.50) return 700;
        if(medie >= 9.51) return 1000;
        else return 0;
    }
    ~Student(){
        delete[] idCursuri;
        delete[] note;
    }
    int noteSub5(){
        for(int i = 0; i < nCursuri; i++){
            if(note[i] < 5) {
                return 1;
            }
         }
         return 0;
    }
};

int main() {
    int N, M;
    cin >> N;
    Student studenti[100];
    Curs cursuri[100];
    for(int i =0; i < N; i++){
        cin >> studenti[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> cursuri[i];
    }

    for(int i = 0; i < N; i++){
        if(studenti[i].calculeazaBursa(cursuri, M) > 0 && !studenti[i].noteSub5()){
            cout << studenti[i] << " " << studenti[i].calculeazaBursa(cursuri, M) << endl;
        }
    }
}



