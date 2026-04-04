//
// Created by aqwer on 4/3/2026.
//

#include <iostream>
#include <vector>
using namespace std;
class Banda{
  int n;
  int indexCrt;
  vector<int> numere;
  public:
  Banda(int n):n(n),numere(n,0),indexCrt(0){}
  void copiazaVal(const vector<int> &val){
      numere = val;
  }
 // În clasa Banda
void moveLeft(int N) {
    // Dacă vrei să se oprească la 0 în loc să nu facă nimic:
    //indexCrt = (N > indexCrt) ? 0 : indexCrt - N;
    if(N>indexCrt){
        indexCrt = 0;
    }
    else{
        indexCrt =indexCrt - N;
    }
}

void moveRight(int N) {
    // Dacă vrei să se oprească la capătul din dreapta:
    if (indexCrt + N >= n) {
        indexCrt = n - 1;
    } else {
        indexCrt += N;
    }
}
  void writeElement(int N){
      numere[indexCrt] = N;
  }
  int readElement(){
      return numere[indexCrt];
  }
  void increaseElement(int N){
      numere[indexCrt] += N;
  }
};
class Operatie{
   public:
   virtual ~Operatie() = default;
   virtual void executa_operatie(Banda &b) = 0;
};
class MoveLeft : public Operatie{
    int N;
   public:
   MoveLeft(int N):N(N){}
   void executa_operatie(Banda &b){
     b.moveLeft(N);
   }
};
class MoveRight : public Operatie{
  int N;
  public:
  MoveRight(int N): N(N){}
  void executa_operatie(Banda &b){
      b.moveRight(N);
  }
};
class WriteElement:public Operatie{
    int N;
    public:
    WriteElement(int N):N(N){}
    void executa_operatie(Banda &b){
        b.writeElement(N);
    }
};
class ReadElement: public Operatie{
    public:
    void executa_operatie(Banda &b){
        cout<<b.readElement()<<endl;
    }
};
class IncreaseElement: public Operatie{
  int N;
  public:
  IncreaseElement(int N):N(N){}
  void executa_operatie(Banda &b){
      b.increaseElement(N);
  }
};
int main(){
    int n,m;
    cin>>n>>m;
    Banda banda(n);
    vector<int> valori(n);
    for(int i=0;i<n;i++){
        cin>>valori[i];
    }
    banda.copiazaVal(valori);
    for(int i=0;i<m;i++){
        string operatie;
        cin>>operatie;
        Operatie* op = nullptr;
        if(operatie == "Stanga"){
            int N;
            cin>>N;
            op = new MoveLeft(N);
        }
        else if(operatie == "Dreapta"){
            int N;
            cin>>N;
            op = new MoveRight(N);
        }
        else if(operatie == "Scrie"){
            int N;
            cin>>N;
            op = new WriteElement(N);
        }
        else if(operatie == "Citeste"){
            op = new ReadElement();
        }
        else if(operatie == "Creste"){
            int N;
            cin>>N;
            op = new IncreaseElement(N);
        }
        if(op != nullptr){
        op->executa_operatie(banda);
        delete op;}
    }

    return 0;
}