# Exercițiul 3: Alergători (Simulare un pas)

## Ce Trebuie Să Faci

Simulezi **un singur moment de timp** pentru mai mulți alergători (sprinteri și maratoniști). Afișezi cine parcurge cea mai mare distanță.

Formulele sunt identice cu cele din colocviu — dar fără regenerare și fără retragere.

---

## Formule

| Tip | deltaDistanta | deltaEnergie |
|-----|--------------|-------------|
| **Sprinter** | `100.0 / greutate + energie * 3.0` | `deltaDistanta / 10.0` |
| **Maratonist** | `exp(40.0 / greutate) + energie * 2.0` | `sqrt(deltaDistanta) / 3.0` |

La un moment de timp:
1. Calculezi `deltaDistanta` (cât aleargă)
2. Calculezi `deltaEnergie` (cât consumă)
3. `distanta += deltaDistanta`
4. `energie -= deltaEnergie`

---

## Pași

### Pasul 1: Clasa de bază Alergator

```cpp
class Alergator {
protected:
    string id;
    double greutate, energie, distanta;
public:
    Alergator(string id, double g, double e) {
        // TODO: salvează id, g, e; distanta = 0
    }

    virtual void alearga() = 0;

    double getDistanta() { return distanta; }
    string getId() { return id; }
};
```

**Ce e nou:** `protected` — derivatele pot accesa aceste atribute, dar codul din afara claselor nu.

---

### Pasul 2: Clasa Sprinter

```cpp
class Sprinter : public Alergator {
public:
    Sprinter(string id, double g, double e) : Alergator(id, g, e) {}

    void alearga() override {
        // TODO:
        // double delta = 100.0 / greutate + energie * 3.0;
        // distanta += delta;
        // energie -= delta / 10.0;
    }
};
```

**Ce e nou:** `: Alergator(id, g, e)` — apelăm constructorul clasei de bază.

---

### Pasul 3: Clasa Maratonist

```cpp
class Maratonist : public Alergator {
public:
    Maratonist(string id, double g, double e) : Alergator(id, g, e) {}

    void alearga() override {
        // TODO:
        // double delta = exp(40.0 / greutate) + energie * 2.0;
        // distanta += delta;
        // energie -= sqrt(delta) / 3.0;
    }
};
```

---

### Pasul 4: Citire și simulare în main()

```cpp
int n;
cin >> n;

vector<Alergator*> alergatori;
for (int i = 0; i < n; i++) {
    string tip, id;
    double greutate, energie;
    cin >> tip >> id >> greutate >> energie;

    if (tip == "SPRINTER") {
        alergatori.push_back(new Sprinter(id, greutate, energie));
    } else {
        alergatori.push_back(new Maratonist(id, greutate, energie));
    }
}

// Un singur moment de timp
for (int i = 0; i < alergatori.size(); i++) {
    alergatori[i]->alearga();
}

// Găsește cine a parcurs distanța maximă
// TODO: parcurge vectorul, compară getDistanta(), reține ID-ul maximului
```

---

### Pasul 5: Compilare și testare
```
g++ -o main main.cpp -lm
./main
```

**Input** (exemplul din colocviu):
```
5
SPRINTER MARVIN 70 10
SPRINTER BLAKE 60 8
MARATONIST KIPCHOGE 50 20
SPRINTER BOLT 62 20
MARATONIST KELVIN 55 14
```

**Output așteptat:**
```
BOLT
```

**Verificare manuală pentru BOLT:**
- deltaDistanta = 100.0/62 + 20*3 = 1.613 + 60 = 61.613
- Cea mai mare distanță → **BOLT**

---

## 💡 Gândește-te

La colocviu, simularea are **K pași** + regenerare energie + retragere sprinteri. Dar formula e exact aceeași!

---

## ✅ Checklist

- [ ] Clasa Alergator cu protected, virtual alearga() = 0
- [ ] Sprinter și Maratonist cu formulele corecte
- [ ] Constructor derivat apelează constructorul bazei
- [ ] vector<Alergator*> în main()
- [ ] Un singur moment de timp (un for cu alearga())
- [ ] Găsesc ID-ul cu distanța maximă
- [ ] Compilează și afișează BOLT
