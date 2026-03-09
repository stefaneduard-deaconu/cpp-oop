# Exercițiul 1: Containere cu Moștenire

## Ce Trebuie Să Faci

Refactorizezi clasele Cub, Sfera și Cilindru dintr-o clasă de bază `Container`.

La lectia02 ai făcut 3 clase separate, fiecare cu `calculeazaVolum()`. Acum le unificăm printr-o **clasă de bază** cu o **metodă virtuală**.

---

## Pași

### Pasul 1: Clasa de bază Container

Scrii clasa `Container` cu o metodă virtuală:

```cpp
class Container {
public:
    virtual double calculeazaVolum() {
        // TODO: returnează 0 (va fi suprascrisă de clase derivate)
    }
};
```

**Ce e nou:** Cuvântul `virtual` permite claselor derivate să ofere propria implementare.

---

### Pasul 2: Clasele derivate

Creezi cele 3 clase derivate. Exemplu pentru Cub:

```cpp
class Cub : public Container {
private:
    double latura;
public:
    Cub(double l) {
        // TODO: salvează l în latura
    }

    double calculeazaVolum() override {
        // TODO: returnează latura * latura * latura
    }
};
```

Apoi analog:
- **Sfera:** atribut `raza`, volum = `4.0 * M_PI * raza * raza * raza / 3.0`
- **Cilindru:** atribute `raza`, `inaltime`, volum = `M_PI * raza * raza * inaltime`

**Ce e nou:** `: public Container` = moștenire, `override` = confirmăm că suprascriem metoda din bază.

---

### Pasul 3: Vectorul de pointeri

În `main()`, folosești un singur vector pentru toate containerele:

```cpp
vector<Container*> containere;

// La citire:
if (tip == "Cub") {
    // TODO: citește latura, adaugă: containere.push_back(new Cub(latura));
} else if (tip == "Sfera") {
    // TODO: citește raza, adaugă: containere.push_back(new Sfera(raza));
} else if (tip == "Cilindru") {
    // TODO: citește raza și inaltime, adaugă: containere.push_back(new Cilindru(raza, inaltime));
}
```

**Ce e nou:** `vector<Container*>` — un vector de pointeri la clasa de bază. Poate conține Cub, Sfera, Cilindru.

---

### Pasul 4: Calculul volumului total

```cpp
double volumTotal = 0;
for (int i = 0; i < containere.size(); i++) {
    // TODO: volumTotal += containere[i]->calculeazaVolum();
}
// TODO: afișează volumTotal
```

**Ce e nou:** `->` în loc de `.` (lucrăm cu pointeri). C++ apelează automat versiunea corectă a metodei (Cub, Sfera sau Cilindru) — **polimorfism**.

---

### Pasul 5: Compilare și testare
```
g++ -o main main.cpp -lm
./main
```

**Input:**
```
3
Cub 5
Sfera 3
Cilindru 2 6
```

**Output așteptat:**
```
313.27
```

(125 + 113.097... + 75.398... ≈ 313.27)

---

## 💡 Gândește-te

De ce e mai bine cu moștenire decât cu 3 clase separate?
- Un singur vector în loc de 3
- Un singur `for` pentru calcul
- Dacă adaugi un nou tip (ex: Piramida), nu modifici nimic în `main()` — doar adaugi o clasă nouă

---

## ✅ Checklist

- [ ] Am scris clasa Container cu virtual calculeazaVolum()
- [ ] Am scris Cub, Sfera, Cilindru cu override
- [ ] Am folosit vector<Container*> în main()
- [ ] Am folosit new la citire
- [ ] Am folosit -> pentru apel metode
- [ ] Compilează: `g++ -o main main.cpp -lm`
- [ ] Afișează 313.27
