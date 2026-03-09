# Exercițiul 2: Transport cu Polimorfism

## Ce Trebuie Să Faci

Creezi o clasă de bază `Transport` cu metode **pur virtuale** (`= 0`) și 3 clase derivate: AutobuzBilet, Taxi, Camion. Stochezi totul într-un singur `vector<Transport*>`.

La lectia02 ai calculat prețul cu 3 clase independente. Acum le unifici printr-o ierarhie.

---

## Pași

### Pasul 1: Clasa de bază Transport (pur virtuală)

```cpp
class Transport {
public:
    virtual double calculeazaPret() = 0;
    virtual double getDistanta() = 0;
};
```

**Ce e nou:** `= 0` face metoda **pur virtuală** — nu are implementare în bază. Orice clasă derivată **trebuie** să o implementeze. Nu poți crea `Transport t;` direct.

---

### Pasul 2: Clasa AutobuzBilet

```cpp
class AutobuzBilet : public Transport {
private:
    double pretBilet, distanta;
public:
    AutobuzBilet(double pb, double d) {
        // TODO: salvează pb și d
    }

    double calculeazaPret() override {
        // TODO: returnează pretBilet
    }

    double getDistanta() override {
        // TODO: returnează distanta
    }
};
```

---

### Pasul 3: Clasa Taxi

```cpp
class Taxi : public Transport {
private:
    double tarifPornire, timpStationare, distanta;
public:
    Taxi(double tp, double ts, double d) {
        // TODO: salvează tp, ts, d
    }

    double calculeazaPret() override {
        // TODO: Formula:
        // tarifStationare = 10.0 * (1.0 + (timpStationare / 100.0) * (timpStationare / 100.0))
        // tarifDistanta = 10.0 * exp(-distanta)
        // return tarifPornire + timpStationare * tarifStationare + distanta * tarifDistanta
    }

    double getDistanta() override {
        // TODO: returnează distanta
    }
};
```

---

### Pasul 4: Clasa Camion

```cpp
class Camion : public Transport {
private:
    double greutateMarfa, distanta;
public:
    Camion(double gm, double d) {
        // TODO: salvează gm și d
    }

    double calculeazaPret() override {
        // TODO: returnează greutateMarfa * distanta / 500.0
    }

    double getDistanta() override {
        // TODO: returnează distanta
    }
};
```

---

### Pasul 5: Vectorul de pointeri și cerințele

```cpp
vector<Transport*> servicii;
// ... citire (vezi Pasul 6)

// Cerința A: Distanța maximă
double distMax = 0;
for (int i = 0; i < servicii.size(); i++) {
    double d = servicii[i]->getDistanta();
    if (d > distMax) distMax = d;
}

// Cerința B: Suma totală încasată
double sumaIncasata = 0;
for (int i = 0; i < servicii.size(); i++) {
    sumaIncasata += servicii[i]->calculeazaPret();
}
```

**Observă:** Nu ai nevoie de `if` pe tip nicăieri — `->calculeazaPret()` apelează automat versiunea corectă.

---

### Pasul 6: Citirea cu construcție pe tip

```cpp
for (int i = 0; i < n; i++) {
    string tip;
    cin >> tip;
    if (tip == "AutobuzBilet") {
        double pretBilet, distanta;
        cin >> pretBilet >> distanta;
        servicii.push_back(new AutobuzBilet(pretBilet, distanta));
    } else if (tip == "Taxi") {
        // TODO: citește tarifPornire, timpStationare, distanta
        // servicii.push_back(new Taxi(...));
    } else if (tip == "Camion") {
        // TODO: citește greutateMarfa, distanta
        // servicii.push_back(new Camion(...));
    }
}
```

**Regulă importantă:** `if` pe tip e **doar** la citire. După ce ai construit obiectele, le tratezi **uniform** prin `Transport*`.

---

### Pasul 7: Compilare și testare
```
g++ -o main main.cpp -lm
./main
```

**Input:**
```
3
AutobuzBilet 5.0 12.0
Taxi 10.0 30.0 8.5
Camion 2000.0 150.0
```

**Output așteptat:**
```
A) 150.00
B) 625.82
```

---

## 💡 Gândește-te

La colocviu, vei avea **4** tipuri (inclusiv AutobuzAbonament) și **mai multe metode** (consum, amortizare, profit). Dar structura e aceeași!

---

## ✅ Checklist

- [ ] Clasa Transport cu metode pur virtuale (= 0)
- [ ] AutobuzBilet, Taxi, Camion cu override
- [ ] Formula Taxi e corectă (tarifStationare, tarifDistanta cu exp)
- [ ] vector<Transport*> în main()
- [ ] if pe tip e doar la citire
- [ ] Cerința A: distanță maximă
- [ ] Cerința B: sumă totală
- [ ] Compilează și afișează rezultatele corecte
