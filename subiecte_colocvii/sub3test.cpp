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
    Persoana() { //
        nume = " ";
        prenume = " ";
    }
    friend istream& operator >> (istream& in, Persoana &p) {
        in >> p.nume;
        in >> p.prenume;
        return in;
    }
    friend ostream& operator << (ostream& out, Persoana &p) {
        out << p.nume << " " << p.prenume;
        return out;
    }
};

class Curs {
    private:
    int id;
    string nume;
    int numarCredite;
    public:
    Curs() {
        id = 0;
        nume = " ";
        numarCredite = 0;
    }
    friend istream& operator >> ( istream& in, Curs &c) {
        in >> c.id;
        in >> c.nume;
        in >> c.numarCredite;
        return in;
    }
    friend ostream& operator << (ostream& out, Curs &c) {
        out << c.id << " " << c.nume << " " << c.numarCredite;
        return out;
    }

    int getId() {
        return id;
    }
    int getCredite() {
        return numarCredite;
    }

};

class Student : public Persoana {
    private:
    int nCursuri;
    int* idCursuri;
    int* note;
    public:
    Student() {
        nCursuri = 0;
        idCursuri = nullptr;
        note = nullptr;
    }

    Student(Student &s) {
        nCursuri = s.nCursuri;
        idCursuri = new int [nCursuri];
        for(int i = 0; i < nCursuri; i ++) {
            idCursuri[i] = s.idCursuri[i];
        }
        note = new int[nCursuri];
        for ( int i = 0; i < nCursuri; i ++) {
            note[i] = s.note[i];
        }
    }

    // operatorul pus cu friend, nu are direct access la atribute.
    friend istream& operator >> (istream& in, Student &s) {
        in >> (Persoana&)s >> s.nCursuri; // deci citeste atributele din Persoana ale lui s
        s.idCursuri = new int [s.nCursuri];
        for (int i = 0; i < s.nCursuri; i ++) {
            in >> s.idCursuri[i];
        }
        s.note = new int [s.nCursuri];
        for ( int i = 0; i < s.nCursuri; i ++) {
            in >> s.note[i];
        }
        return in;
    }
    friend ostream& operator << (ostream& out, Student &s) {
        out << s.nCursuri;
        s.idCursuri = new int[s.nCursuri];
        for (int i =0; i < s.nCursuri; i ++) {
            out << s.idCursuri[i];
        }
        s.note = new int [s.nCursuri];
        for (int i =0; i < s.nCursuri; i ++) {
            out << s.note[i];
        }
    }

    double calculeazaBursa(Curs* cursuri, int n) {

        float sumaNote = 0, sumaCredite = 0;
        // parcurgem cursurile (de tip curs)
        for (int i = 0; i < n; i++) {
            // parcurgem cursurile facute de student (din clasa curenta)
            // in ideea ca poate gasim cursurl cursuri[i].getId()
            for ( int j = 0; j < nCursuri; j ++) {
                if(cursuri[i].getId() ==  idCursuri[j]) {
                    sumaNote += note[j] * cursuri[i].getCredite();
                    sumaCredite += cursuri[i].getCredite();
                }
            }
        }
        float medie = sumaNote/sumaCredite;
        if(medie >= 8.50 && medie <= 9.00) {
            return 500;
        }
        if(medie >= 9.01 && medie <= 9.50) {
            return 700;
        }
        if(medie > 9.51) {
            return 1000;
        }
        return 0;
        }

    int NoteSub5() {
        for ( int i = 0; i < nCursuri; i ++) {
            if (note[i] < 5) return 1;
        }
        return 0;
    }
    ~Student() {
        delete[] idCursuri;
        delete[] note;
    }
};


int main() {
    int N, M;
    cin >> N;
    Student student[100];
    for(int i = 0; i< N; i++) {
        cin >> student[i];
    }
    cin >> M;
    Curs cursuri[100];
    for(int i =0; i < M; i++) {
        cin >> cursuri[i];
    }
    for (int i =0; i < N; i ++) {
        if (student[i].calculeazaBursa(cursuri, M) > 0 && !student[i].NoteSub5() ) {
            cout << (Persoana&) student[i] << " " << student[i].calculeazaBursa(cursuri, M) << endl;
        }
    }
}



