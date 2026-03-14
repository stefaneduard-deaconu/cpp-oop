#include <iostream>
#include <vector>

using namespace std;

class Forma {
    public:
    virtual ~Forma() = default;

    virtual double getVolume() {
            return 0;
        }
        virtual double calculeazaSuprafata(){
            return 0;
        }
};

class Cub : public Forma{
    private:
        double latura ;
    public:
        Cub(double l) {
            latura = l;
        }
        double getVolume() override {
            return latura * latura * latura;
        }
        double calculeazaSuprafata() override{
            return 6 * latura * latura;
        }
};

class Sfera : public Forma {
    private:
        double raza;
    public:
        Sfera(double r){
            raza = r;
        }
        double getVolume() override {
            return (4* 3.14 * raza * raza * raza)/3;
        }
        double calculeazaSuprafata() override {
            return 4 * 3.14 * raza * raza;
        }
};

class Cilindru: public Forma{
    private:
        double raza, inaltime;
    public:
        Cilindru(double r, double i){
            raza = r;
            inaltime = i;
        }
        double getVolume() override{
            return (3.14 * raza * raza * inaltime);
        }
        double calculeazaSuprafata() override{
            return 2 * 3.14 * raza * (raza + inaltime);
        }
};

int main () {

    int N;
    cin >> N;
    vector<Forma*> forme;
    for (int i = 0;i<N;i++){
        int l, r, h, tipulFormei; // 1, 2 sau 3

        // aloci cate o noua forma
        Forma* f;
        cin >> tipulFormei;
        if (tipulFormei == 1) {
            cin >> l;
            f = new Cub(l);
        }
        if ( tipulFormei == 2) {
            cin >> r;
            f = new Sfera(r);
        }
        if ( tipulFormei == 3) {
            cin >> r >> h;
            f = new Cilindru(r, h);
        }

        forme.push_back(f);
    }
    
    // Rezolvarea cerintei

      double Volum = 0;
      double Suprafata = 0;
      for(Forma* f: forme){
        Volum += f->getVolume();
        Suprafata += f->calculeazaSuprafata();
      }  

      cout << Volum << endl << Suprafata << endl;
    // dezalocare finala
    for (Forma* f : forme) {
        delete f;
    }

}